#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>

#include <gal/config.h>
//#include <gal/free.hpp>

#include <gal/network/message.h>
#include <gal/network/communicating.h>

gal::network::communicating::communicating( int socket ):
	socket_(socket),
	read_msg_(new gal::network::message),
	terminate_(false)
{
	GALAXY_DEBUG_FUNCTION;
	
	printf("socket = %i\n", socket);
}
void	gal::network::communicating::start()
{
	write_thread_ = std::thread(std::bind(&communicating::thread_write_dispatch, this ) );
	read_thread_ = std::thread(std::bind(&communicating::thread_read_header, this ) );
}
void	gal::network::communicating::write(gal::network::message::shared_t msg)
{	
	GALAXY_DEBUG_FUNCTION;

	{
		std::lock_guard<std::mutex> lk( mutex_ );

		write_queue_.push_back( msg );
	}

	cv_.notify_one();
}
void	gal::network::communicating::close()
{	
	GALAXY_DEBUG_FUNCTION;

	{
		std::lock_guard<std::mutex> lk( mutex_ );

		terminate_ = true;
	}
	cv_.notify_all();

	write_thread_.join();
	read_thread_.join();

	::close( socket_ );
}
void	gal::network::communicating::thread_write_dispatch()
{
	GALAXY_DEBUG_FUNCTION;

	while ( 1 )
	{
		std::unique_lock<std::mutex> lk( mutex_ );

		printf("wait\n");
		
		do
		{
			cv_.wait( lk );
		}
		while ( write_queue_.empty() && !terminate_ );
		
		printf("notified\n");

		//cv_.wait( lk, [&] { return ( !write_queue_.empty() || terminate_ ); } );
		
		if ( terminate_ )
		{
			printf("terminated\n");
			return;
		}		
		
		printf("create write thread\n");
		
		std::thread t(
				std::bind(
					&gal::network::communicating::thread_write,
					this, write_queue_.front() ) );
		t.detach();

		write_queue_.pop_front();
	}
}
void	gal::network::communicating::thread_write(gal::network::message::shared_t message)
{
	GALAXY_DEBUG_FUNCTION;

	printf("sending message of length %i\n", (int)message->length());
	
	int result = ::send(socket_, message->data(), message->length(), 0 );
	
	if ( result < 0 )
	{
		/// \todo pass exception to main thread ( or whoever )
	}
	if ( result < (int)message->length() )
	{
		// ???
	}
}
void	gal::network::communicating::thread_read()
{
	GALAXY_DEBUG_FUNCTION;

	while ( 1 )
	{
		{
			std::lock_guard<std::mutex> lk( mutex_ );

			if ( terminate_ )
			{
				return;
			}
		}

		try
		{
			thread_read_header();
		}
		catch(...)
		{
			/// \todo pass exception to main thread ( or whoever )
		}
	}
}
void	gal::network::communicating::thread_read_header()
{
	GALAXY_DEBUG_FUNCTION;

	//if ( !socket_->is_open() ) exit(0);//gal::cerr << "SOCKET NOT OPEN" << endl;
	if ( !read_msg_->data() ) exit(0); //gal::cerr << "WTF!" << std::endl;


	printf("waiting for %i bytes\n", message::header_length);
	// wail until all data is available
	int bytes = ::recv(socket_, read_msg_->data(), message::header_length, MSG_WAITALL);
	
	if ( bytes < 0 )
	{
		perror("recv:");
		exit(0);
	}

	if ( bytes == 0 )
	{
		printf("on data\n");
		exit(0);
	}

	if ( bytes < message::header_length )
	{
		printf("not enough data\n");
		exit(0);
	}
	
	handle_do_read_header();
}
void	gal::network::communicating::thread_read_body()
{
	GALAXY_DEBUG_FUNCTION;
	
	printf("waiting for %i bytes\n", (int)read_msg_->body_length());
	// wail until all data is available
	int bytes = ::recv(socket_, read_msg_->body(), read_msg_->body_length(), MSG_WAITALL);
	
	if(bytes < 0)
	{
		perror("recv:");
		exit(0);
	}

	if(bytes == 0)
	{
		printf("on data\n");
		exit(0);
	}

	if(bytes < message::header_length)
	{
		printf("not enough data\n");
		exit(0);
	}

	handle_do_read_body();
}

void	gal::network::communicating::handle_do_read_header()
{
	GALAXY_DEBUG_FUNCTION;

	if ( read_msg_->decode_header() )
	{	
		thread_read_body();
	}
	else
	{
		printf("header decode failed\n");

		std::thread(&gal::network::communicating::close, this).detach();
	}
}
void	gal::network::communicating::handle_do_read_body()
{
	GALAXY_DEBUG_FUNCTION;

	if(bool(process_body_))
	{
		printf("process_body_\n");

		process_body_( read_msg_ );
	}

	thread_read_header();
}




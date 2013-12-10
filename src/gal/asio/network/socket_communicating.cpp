#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>

#include <jess/define.hpp>
#include <jess/scoped_ostream.hpp>
#include <jess/ostream.hpp>
#include <jess/free.hpp>

#include <jess/asio/message.hpp>
#include <jess/asio/network/socket_communicating.hpp>

jess::asio::network::socket_communicating::socket_communicating( int socket ):
	socket_(socket),
	read_msg_( new jess::asio::message ),
	write_thread_( std::bind( &socket_communicating::thread_write_dispatch, this ) ),
	read_thread_( std::bind( &socket_communicating::thread_read_header, this ) )
{
}
void	jess::asio::network::socket_communicating::write( jess::asio::message::shared_t msg )
{
	{
		std::lock_guard<std::mutex> lk( mutex_ );

		write_queue_.push_back( msg );
	}

	cv_.notify_one();
}
void	jess::asio::network::socket_communicating::close()
{
	{
		std::lock_guard<std::mutex> lk( mutex_ );

		terminate_ = true;
	}
	cv_.notify_all();

	write_thread_.join();
	read_thread_.join();

	::close( socket_ );
}
void	jess::asio::network::socket_communicating::thread_write_dispatch()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	while ( 1 )
	{
		std::unique_lock<std::mutex> lk( mutex_ );
		
		do
		{
			cv_.wait( lk );
		}
		while ( write_queue_.empty() && !terminate_ );

		//cv_.wait( lk, [&] { return ( !write_queue_.empty() || terminate_ ); } );

		if ( terminate_ )
		{
			return;
		}		
		
		std::thread t( std::bind( &jess::asio::network::socket_communicating::thread_write, this, write_queue_.front() ) );
		t.detach();

		write_queue_.pop_front();
	}
}
void	jess::asio::network::socket_communicating::thread_write( jess::asio::message::shared_t message )
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	int result = ::send( socket_, message->data(), message->length(), 0 );

	if ( result < 0 )
	{
		/// \todo pass exception to main thread ( or whoever )
	}
	if ( result < (int)message->length() )
	{
		// ???
	}
}
void	jess::asio::network::socket_communicating::thread_read()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

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
void	jess::asio::network::socket_communicating::thread_read_header()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	//if ( !socket_->is_open() ) jess::cerr << "SOCKET NOT OPEN" << endl;
	
	//if ( !read_msg_->data() ) jess::cerr << "WTF!" << std::endl;
	
	int bytes = ::recv( socket_, read_msg_->data(), message::header_length, MSG_WAITALL );
	
	if ( bytes < 0 )
	{

	}
	
	if ( bytes == 0 )
	{

	}
	
	if ( bytes < message::header_length )
	{

	}
	
	handle_do_read_header();
}
void	jess::asio::network::socket_communicating::thread_read_body()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	int bytes = ::recv( socket_, read_msg_->data(), read_msg_->length(), MSG_WAITALL );

	if ( bytes < 0 )
	{

	}

	if ( bytes == 0 )
	{

	}

	if ( bytes < message::header_length )
	{

	}

	handle_do_read_body();
}

void	jess::asio::network::socket_communicating::handle_do_read_header()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	if ( read_msg_->decode_header() )
	{
		thread_read_body();
	}
	else
	{
		sos << "header decode failed" << std::endl;

		std::thread( &jess::asio::network::socket_communicating::close, this ).detach();
	}
}
void	jess::asio::network::socket_communicating::handle_do_read_body()
{
	jess::scoped_ostream sos( &jess::clog, JESS_FUNCSIG );

	if ( bool( process_body_ ) )
	{
		sos << "process_body_" << std::endl;

		process_body_( read_msg_ );
	}
}




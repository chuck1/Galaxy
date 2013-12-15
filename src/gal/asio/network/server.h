#ifndef __JESS_ASIO_NETWORK_SOCKET_SERVER_HPP__
#define __JESS_ASIO_NETWORK_SOCKET_SERVER_HPP__

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>

#include <gal/asio/network/communicating.h>

//typedef std::shared_ptr<boost::asio::io_service>      boost_io_service_ptr;
//typedef std::shared_ptr<boost::asio::ip::tcp::socket> boost_socket_ptr;

namespace gal
{
	namespace asio
	{
		namespace network
		{


			/// socket server
			class server//: public gal::asio::network::communicating
			{
			public:
				/// ctor
				server(unsigned short,int);//boost_io_service_ptr io_service, const boost::asio::ip::tcp::endpoint& endpoint);


			private:
				void thread_accept();
				
				std::thread						thread_accept_;
				std::mutex						mutex_;
				
				unsigned short						local_port_;
				int							socket_;

			public:
				gal::asio::network::communicating::vector_t		clients_;
				gal::asio::message::function_t				process_body_;

			};
		}
	}
}








#endif




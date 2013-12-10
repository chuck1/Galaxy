#ifndef __JESS_ASIO_NETWORK_SOCKET_COMMUNICATING_HPP__
#define __JESS_ASIO_NETWORK_SOCKET_COMMUNICATING_HPP__

#include <cstdlib>
#include <deque>
#include <vector>
#include <iostream>
#include <thread>

#include <sys/socket.h>

#include <jess/asio/message.hpp>

namespace jess
{
	namespace asio
	{
		namespace network
		{
			/** %socket %communicating
			 */
			class socket_communicating
			{
				public:
					/** pointer
					 */
					typedef std::shared_ptr<socket_communicating>	shared_t;
					/** deque
					 */
					typedef std::vector<shared_t>			vector_t;
				public:
					/** ctor
					 */
					socket_communicating( int socket );
					/** write
					 */
					void					write( jess::asio::message::shared_t );
					/** close
					 */
					void					close();
				protected:
					/** thread write
					 */
					void					thread_write( jess::asio::message::shared_t );
					/** thread write dispath
					 */
					void					thread_write_dispatch();
					/** thread read
					 */
					void					thread_read();
					/** thread read header
					 */
					void					thread_read_header();
					/** thread read body
					 */
					void					thread_read_body();
					/** handle read header
					 */
					void					handle_do_read_header();
					/** handle read body
					 */
					void					handle_do_read_body();
					/** handle write
					 */
					void					handle_do_write();
				protected:
					/** socket
					 */
					int					socket_;
					/** message
					 */
					jess::asio::message::shared_t		read_msg_;
					/** message deque
					 */
					jess::asio::message::deque_t		write_queue_;
					/** process body
					 */
					jess::asio::message::function_t		process_body_;
					/** terminate
					 */
					bool					terminate_;
					/** thread write
					 */
					std::thread				write_thread_;
					/** thread read
					 */
					std::thread				read_thread_;
					/** condition variable
					 */
					std::condition_variable			cv_;
					/** mutex
					 * mutex for write_queue_ and terminate_
					 */
					std::mutex				mutex_;
			};
		}
	}
}




#endif






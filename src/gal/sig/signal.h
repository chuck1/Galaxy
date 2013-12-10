#ifndef __JESS_SIGNAL_HPP__
#define __JESS_SIGNAL_HPP__

#include <memory>
#include <deque>

#include <gal/sig/connection.h>

namespace gal
{
namespace sig
{
	template <typename... Args> class signal
	{
		public:
			typedef gal::sig::connection<Args...> conn_t;

			conn_t*		connect( std::function<int(Args...)> handle )
			{
				conn_t* connection = new conn_t( handle );

				connections_.push_front( connection );

				return connection;
			}
			void		disconnect( conn_t* connection )
			{
				connections_.erase( connection );
			}
			void		operator()( Args... args )
			{
				auto it = connections_.begin();
				conn_t* connection = NULL;

				while (  it != connections_.end() )
				{
					connection = (*it);
					if ( connection == NULL )
					{
						connections_.erase( it );
						continue;
					}
					else
					{
						if ( connection->handle_(args...) )
						{
							break;
						}
						++it;
					}
				}
			}
		private:
			std::deque<conn_t*>	connections_;
	};
}
}

#endif

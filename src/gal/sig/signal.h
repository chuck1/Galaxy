#ifndef __JESS_SIGNAL_HPP__
#define __JESS_SIGNAL_HPP__

#include <stdio.h>

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
				typedef gal::sig::connection<Args...>	conn_t;
				typedef std::shared_ptr<conn_t>		shared_t;
				typedef std::weak_ptr<conn_t>		weak_t;
				
				shared_t	connect(std::function<int(Args...)> handle)
				{
					shared_t connection(new conn_t(handle));
					
					connections_.push_front(connection);
					
					return connection;
				}
				int		bring_to_front(shared_t a)
				{
					if(disconnect(a)) return 1;
					
					connections_.push_front(a);

					return 0;
				}
				int		disconnect(shared_t b)
				{
					auto it = connections_.begin();
					weak_t connection;

					while(it != connections_.end())
					{
						connection = (*it);
						
						// cleanup
						if(connection.expired())
						{
							connections_.erase(it);
							continue;
						}
						
						if(connection.lock() == b) 
						{
							connections_.erase(it);
							return 0;
						}
						++it;
					}

					printf("connection not found\n");
					return 1;
				}
				void		operator()(Args... args)
				{
					auto it = connections_.begin();
					weak_t connection;

					while(it != connections_.end())
					{
						connection = (*it);
						if(connection.expired())
						{
							printf("erasing\n");
							connections_.erase(it);
							continue;
						}
						else
						{
							if(connection.lock()->handle_(args...))
							{
								break;
							}
							++it;
						}
					}
				}
			private:
				std::deque<weak_t>	connections_;
		};
	}
}

#endif

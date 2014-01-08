#ifndef __GALAXY_NETWORK_ARRAY_H__
#define __GALAXY_NETWORK_ARRAY_H__

#include <vector>

#include <gal/config.h>
#include <gal/network/message.h>

namespace gal
{
	namespace network
	{
		template <class T> class vector
		{
			public:
				typedef std::vector<T> vec;

				vector(): size_(0) {}
				void	write(message_shared msg)
				{
					size_ = vector_.size();

					msg->write(&size_, sizeof(typename vec::size_type));

					T t;
					for(auto it = vector_.begin(); it != vector_.end(); ++it)
					{
						t = *it;

						msg->write(&t, sizeof(T));
					}
				}
				void	read(message_shared msg)
				{
					msg->read(&size_, sizeof(typename vec::size_type));

					T t;
					vector_.clear();
					for(typename vec::size_type i = 0; i < size_; ++i)
					{
						msg->read(&t, sizeof(T));

						vector_.push_back(t);
					}
				}
				size_t size()
				{	
					return (sizeof(typename vec::size_type) + (vector_.size() * sizeof(T)));
				}

				vec		vector_;
				typename vec::size_type	size_;
		};
		template <class T> class vector_ext
		{
			public:
				typedef std::shared_ptr<T> Ts;
				typedef std::vector<Ts> vec;
				

				vector(): size_(0) {}
				void	write(message_shared msg)
				{
					size_ = vector_.size();
					
					msg->write(&size_, sizeof(typename vec::size_type));
					
					Ts t;
					for(auto it = vector_.begin(); it != vector_.end(); ++it)
					{
						t = *it;
						assert(t);
						
						t->write(msg);
					}
				}
				void	read(message_shared msg)
				{
					msg->read(&size_, sizeof(typename vec::size_type));

					Ts t;
					vector_.clear();
					for(typename vec::size_type i = 0; i < size_; ++i)
					{
						t.reset(new T);
						
						t->read(msg);
						
						vector_.push_back(t);
					}
				}
				
				vec		vector_;
				typename vec::size_type	size_;
		};
		
	}
}


#endif


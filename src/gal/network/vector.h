#ifndef __GALAXY_NETWORK_ARRAY_H__
#define __GALAXY_NETWORK_ARRAY_H__

#include <vector>

#include <gal/config.h>
#include <gal/network/message.h>
#include <gal/network/message_ext.h>

namespace gal
{
	namespace network
	{
		template <class T> class vector
		{
			public:
				typedef std::vector<T> vec;

				vector() {}
				void write(message_shared msg) {
					
					size_t s = vec_.size();
					
					msg->write(&s, sizeof(typename vec::size_type));
					
					T t;
					for(auto it = vec_.begin(); it != vec_.end(); ++it)
					{
						t = *it;
						
						msg->write(&t, sizeof(T));
					}
				}
				void read(message_shared msg) {
					
					size_t s;
					
					msg->read(&s, sizeof(typename vec::size_type));
					
					T t;
					vec_.clear();
					for(typename vec::size_type i = 0; i < s; ++i)
					{
						msg->read(&t, sizeof(T));

						vec_.push_back(t);
					}
				}
				size_t size() {	
					size_t s;
					s += sizeof(typename vec::size_type);
					s += (vec_.size() * sizeof(T));
					return s;
				}
				
				vec vec_;
		};
		template <class... Args> class vector_ext
		{
			public:
				typedef std::tuple<std::shared_ptr<Args>...> tup;
				typedef std::vector<tup> vec;
				typedef typename vec::size_type size_type;



				vector_ext(): size_(0) {}
				void	write(message_shared msg)
				{
					size_ = vec_.size();

					msg->write(&size_, sizeof(size_type));

					tup t;
					for(auto it = vec_.begin(); it != vec_.end(); ++it)
					{
						t = *it;
						assert(t);

						t->write(msg);
					}
				}
				void	reset(tup t) {
					
				}
				void	read(message_shared msg)
				{
					size_type s;

					msg->read(&s, sizeof(typename vec::size_type));

					tup t;
					vec_.clear();
					for(typename vec::size_type i = 0; i < size_; ++i)
					{
						t.reset(new T);

						t->read(msg);

						vec_.push_back(t);
					}
				}
				size_t	size()
				{
					size_t s = sizeof(typename vec::size_type);

					T_s t;
					for(auto it = vec_.begin(); it != vec_.end(); ++it) {
						t = *it;
						assert(t);
						s += t->size();
					}
				}

				vec				vec_;
				typename vec::size_type		size_;
		};

	}
}


#endif


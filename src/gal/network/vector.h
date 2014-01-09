#ifndef __GALAXY_NETWORK_ARRAY_H__
#define __GALAXY_NETWORK_ARRAY_H__

#include <vector>

#include <gal/config.h>
#include <gal/network/message.h>
#include <gal/network/message_ext.h>

namespace gal
{
	
	template<int... S> void reset_tup(seq<S...>, tup t) {
                pass{(reset(std::get<S>(t)), 1)...};
        }
	
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
				typedef typename gens<sizeof...(Args)>::type seq_type;
				typedef typename vec::size_type size_type;



				vector_ext() {}
				
				template<int... S> void write_expand(seq<S...>, tup t, message_shared msg) {
                			pass{(std::get<S>(t)->write(msg), 1)...};
        			}
				template<int... S> void read_expand(seq<S...>, tup t, message_shared msg) {
                			pass{(std::get<S>(t)->read(msg), 1)...};
        			}
				template<int... S> size_t size_expand(seq<S...>, tup t, message_shared msg) {
					size_t s = 0;
                			pass{(s += std::get<S>(t)->write(msg), 1)...};
        			}
				
				
				void	write(message_shared msg)
				{
					size_type s = vec_.size();
					
					msg->write(&s, sizeof(size_type));
					
					seq_type s;
					for(auto it = vec_.begin(); it != vec_.end(); ++it) {
						write_expand(s, t, msg);
					}
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
		};

	}
}


#endif


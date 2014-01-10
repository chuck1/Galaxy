#ifndef __GALAXY_NETWORK_ARRAY_H__
#define __GALAXY_NETWORK_ARRAY_H__

#include <vector>

#include <gal/config.h>
#include <gal/network/message.h>
#include <gal/network/message_ext.h>

namespace gal {
	namespace network {
		template <class T> struct vector {
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
				template<int... S> size_t size_expand(seq<S...>, tup t) {
					size_t size = 0;
					pass{(size += std::get<S>(t)->size(), 1)...};
					return size;
				}


				void	write(message_shared msg)
				{
					size_type size = vec_.size();

					msg->write(&size, sizeof(size_type));

					seq_type s;
					for(auto it = vec_.begin(); it != vec_.end(); ++it) {
						write_expand(s, *it, msg);
					}
				}


				void	read(message_shared msg)
				{
					size_type size;

					msg->read(&size, sizeof(typename vec::size_type));

					tup t;
					vec_.clear();
					seq_type s;
					for(typename vec::size_type i = 0; i < size; ++i)
					{
						read_expand(s, t, msg);

						vec_.push_back(t);
					}
				}
				size_t size()
				{
					size_t size = sizeof(typename vec::size_type);
					
					tup t;
					seq_type s;
					for(auto it = vec_.begin(); it != vec_.end(); ++it) {
						size += size_expand(s, t);
					}
					
					return size;
				}

				vec vec_;
		};

	}
}


#endif


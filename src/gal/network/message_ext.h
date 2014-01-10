#ifndef __JESS_ASIO_MESSAGE_EXT_H__
#define __JESS_ASIO_MESSAGE_EXT_H__

#include <assert.h>

#include <gal/util.h>
#include <gal/network/message.h>

namespace gal {
	namespace network {
		template<typename... Args> struct message_ext {
			
			typedef typename gens<sizeof...(Args)>::type seq_t;
			
			message_ext() {
				reset_tuple(tup_);
			}
			
			
			template<int... S> void write_expand(seq<S...>, message_shared msg) {
				pass{(std::get<S>(tup_)->write(msg), 1)...};
			}
			template<int... S> void read_expand(seq<S...>, message_shared msg) {
				pass{(std::get<S>(tup_)->read(msg), 1)...};
			}
			template<int... S> size_t size_expand(seq<S...>) {
				size_t size = 0;
				pass{(size += std::get<S>(tup_)->size(), 1)...};
				return size;
			}
			
			
			void write(message_shared msg) {
				seq_t s;
				write_expand(s, msg);
			}
			void read(message_shared msg) {
				seq_t s;
				read_expand(s, msg);
			}
			size_t size() {
				seq_t s;
				return size_expand(s);
			}
			
			std::tuple<std::shared_ptr<Args>...> tup_;
		};
	}
}

#endif

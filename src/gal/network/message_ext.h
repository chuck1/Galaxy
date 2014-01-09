#ifndef __JESS_ASIO_MESSAGE_EXT_H__
#define __JESS_ASIO_MESSAGE_EXT_H__

#include <assert.h>

#include <gal/network/message.h>

namespace gal {
	
	template<int ...> struct seq { };
	
	template<int N, int ...S> struct gens : gens<N-1, N-1, S...> { };
	
	template<int ...S> struct gens<0, S...> { typedef seq<S...> type; };
	
	// for calling functions
	struct pass { template<typename ...T> pass(T...) {} };
	
	// for allocating tuple of pointers
	
	template<typename T> void reset(std::shared_ptr<T>& t) {
		t.reset(new T);
	}
	
	template<int... S, typename... Args> void reset_tuple(seq<S...>, std::tuple<Args...>& tup) {
	        pass{(reset(std::get<S>(tup)), 1)...};
	}
	
	template<typename... Args> void reset_tuple(std::tuple<Args...>& tup) {
	        typename gens<sizeof...(Args)>::type s;
	        reset_tuple(s, tup);
	}

	namespace network {

		template<typename... Args> struct message_ext {
			
			typedef typename gens<sizeof...(Args)>::type seq_t;
			
			message_ext() {
				
				seq_t s;
				reset_tup(s);
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

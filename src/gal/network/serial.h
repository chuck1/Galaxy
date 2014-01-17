#ifndef __GALAXY_NETWORK_SERIAL_H__
#define __GALAXY_NETWORK_SERIAL_H__

#include <gal/config.h>
#include <gal/util.h>

#include <gal/network/message.h>


namespace gal {
        namespace network {
                template<typename T> struct serial {
                        void write(gal::network::message_shared msg) {
                                msg->write(this, sizeof(T));
                        }
                        void read(gal::network::message_shared msg) {
                                msg->read(this, sizeof(T));
                        }
                        size_t size() {
                                return sizeof(T);
                        }
		};


		template<typename... Args> struct serial_ext {
			typedef typename gens<sizeof...(Args)>::type seq_type;                  
			typedef std::tuple<std::shared_ptr<Args>...> tuple;

			serial_ext() {
				reset_tuple(tup_);
			}
			
			
			
			template<int i> void read_expand(message_shared msg) {
				auto p = std::get<i>(tup_);
				
				assert(p);
				//assert(std::get<i>(tup_));
				
				p->read(msg);
				//std::get<i>(tup_)->read(msg);
			}
			
			
			
			template<int... S> void write_expand(seq<S...>, message_shared msg) {
				pass{(std::get<S>(tup_)->write(msg), 1)...};
			}
			template<int... S> void read_expand(seq<S...>, message_shared msg) {
				//pass{(std::get<S>(tup_)->read(msg), 1)...};
				pass{(read_expand<S>(msg), 1)...};
			}
			template<int... S> size_t size_expand(seq<S...>) {
				size_t size = 0;
				pass{(size += std::get<S>(tup_)->size(), 1)...};
				return size;
			}


			void write(message_shared msg) {
				seq_type s;
				write_expand(s, msg);
			}
			void read(message_shared msg) {
				seq_type s;
				read_expand(s, msg);
			}
			size_t size() {
				seq_type s;
				return size_expand(s);
			}




			tuple tup_;
		};
	}
}

#endif

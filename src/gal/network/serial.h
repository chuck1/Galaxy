#ifndef __GALAXY_NETWORK_SERIAL_H__
#define __GALAXY_NETWORK_SERIAL_H__

namespace gal {
        namespace network {
                template<typename T> struct serial {
                        void write(gal::message::message_shared msg) {
                                msg->write(this, sizeof(T));
                        }
                        void read(gal::message::message_shared msg) {
                                msg->read(this, sizeof(T));
                        }
                        size_t size() {
                                return sizeof(T);
                        }
                };
        }
}

#endif

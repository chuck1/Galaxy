#ifndef __JESS_ASIO_MESSAGE_EXT_H__
#define __JESS_ASIO_MESSAGE_EXT_H__

#include <assert.h>

#include <gal/network/message.h>

struct pass {template<typename ...T> pass(T...) {}};

namespace gal
{
	namespace network
	{
		template<class... Args> class message_ext
		{
			public:
				message_ext(message_shared msg): msg_(msg) {assert(msg);}
				void  write_expand(std::shared_ptr<Args>... args)
				{	
					pass{(args->write(msg_), 1)...};
				}
				void  read_expand(std::shared_ptr<Args>... args)
				{
					pass{(args->read(msg_), 1)...};
				}
			private:
				message_shared	msg_;
		};
	}
}

#endif

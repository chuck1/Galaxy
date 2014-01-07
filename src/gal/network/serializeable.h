#ifndef __GALAXY_NETWORK_SERIALIZEABLE_H__
#define __GALAXY_NETWORK_SERIALIZEABLE_H__

#include <vector>

#include <gal/config.h>
#include <gal/network/message.h>

namespace gal
{
	namespace network
	{
		class serializeable
		{
			public:
				serializeable(){}
				virtual ~serializeable(){}
				
				virtual void	write(message_shared msg) = 0;
				virtual void	read(message_shared msg) = 0;
				virtual size_t	size() = 0;
		};
	}
}


#endif


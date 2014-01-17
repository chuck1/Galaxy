#ifndef __GALAXY_CONFIG_H__
#define __GALAXY_CONFIG_H__

#define GALAXY_DEBUG_0_FUNCTION printf("%s\n",__PRETTY_FUNCTION__)
#define GALAXY_DEBUG_1_FUNCTION printf("%s\n",__PRETTY_FUNCTION__)
#define GALAXY_DEBUG_2_FUNCTION //printf("%s\n",__PRETTY_FUNCTION__)

#include <memory>

namespace gal {
	namespace timer {
		class timer;
		typedef std::shared_ptr<timer>		timer_s;
	}
	
	namespace network {
		class message;
		typedef std::shared_ptr<message>	message_shared;
		typedef std::shared_ptr<message>	message_s;
	}
}

#endif

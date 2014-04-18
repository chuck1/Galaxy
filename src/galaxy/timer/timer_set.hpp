#ifndef __GALAXY_TIMER_SET__
#define __GALAXY_TIMER_SET__

#include <set>
#include <memory>

#include <galaxy/timer/timer.hpp>

namespace gal {
	namespace timer {
		class timer_set {
			public:
				typedef std::set<timer_s,timer_less> set_type;
				
				void		step(double);
				
				set_type	set_;
		};
	}
}

#endif



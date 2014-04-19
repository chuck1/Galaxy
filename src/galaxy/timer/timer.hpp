#ifndef __GALAXY_TIMER__
#define __GALAXY_TIMER__

#include <assert.h>

#include <galaxy/config.hpp>

namespace gal {
	namespace timer {
		class timer {
			public:
				timer(double);
				
				virtual void	activate() = 0;
				
				double		time_;
		};


		class timer_less {
			public:
				bool operator()(const timer_s& lhs, const timer_s& rhs) {
					assert(rhs);
					assert(lhs);
					return (lhs->time_ < rhs->time_);
				}

		};
	}
}

#endif



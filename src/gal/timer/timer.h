#ifndef __GALAXY_TIMER__
#define __GALAXY_TIMER__

namespace gal {
	namespace timer {
		class timer {
			public:

				virtual void	activate() = 0;
				
				double		time_;
		};


		class timer_less {
			bool operator()(const timer& lhs, const timer& rhs) {
				return (lhs.time_ < rhs.time_);
			}

		};
	}
}

#endif



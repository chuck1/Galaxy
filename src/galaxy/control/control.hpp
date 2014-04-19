#ifndef __GALAXY_CONTROL_H__
#define __GALAXY_CONTROL_H__

#include <math/vec3.hpp>

namespace gal {
	namespace control {
		class control {
			public:
				control();
				float	f(float, float);
				
				float	coeff_p_;
				float	coeff_d_;

		};
	}
}

#endif


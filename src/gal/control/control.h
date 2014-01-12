#ifndef __GALAXY_CONTROL_H__
#define __GALAXY_CONTROL_H__

#include <math/vec3.h>

namespace gal {
	namespace control {
		class control {
			public:
				control();
				float	f(float, float, double);
				float	f(float, double);
				
				int	t;
				
				double	time0;
				double	time1;


				float	e0;
				float	e1;

				float	x0;
				float	x1;
				float	v;
				float	i;
				
				float	coeff_p;
				float	coeff_d;
				float	coeff_i;


		};
	}
}

#endif


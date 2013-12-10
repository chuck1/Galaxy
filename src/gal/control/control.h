#ifndef __GALAXY_CONTROL_H__
#define __GALAXY_CONTROL_H__

#include <math/vec3.h>

namespace gal
{
	namespace control
	{
		template <typename T> class value;
		{
			public:
				void				subscribe(sig::signal&);
			protected:
				std::vector<sig::connection*>	conn_;
				float				v;
		};

		class control
		{
			public:

				math::vec3	x;
				math::vec3	u;
				math::vec3	a;

				math::vec3	o;
				math::vec3	w;
				math::vec3	t;


		};
	}
}

#endif


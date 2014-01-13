#include <gal/control/control.h>


gal::control::control::control():
	t(0),
	v(0),
	i(0),
	coeff_p(   1.0f),
	coeff_d(-100.0f),
	coeff_i(   0.0f)
{

}
float gal::control::control::f(float e, float v, double time) {

	// force
	float force = e1 * coeff_p + v * coeff_d;
	
	return force;
}




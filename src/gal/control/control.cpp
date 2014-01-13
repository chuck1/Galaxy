#include <gal/control/control.h>


gal::control::control::control():
	coeff_p_(0.0f),
	coeff_d_(0.0f)
{

}
float gal::control::control::f(float e, float v, double time) {

	// force
	float force = e1 * coeff_p + v * coeff_d;
	
	return force;
}




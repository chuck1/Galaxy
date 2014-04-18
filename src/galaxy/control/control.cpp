#include <galaxy/control/control.hpp>


gal::control::control::control():
	coeff_p_(0.0f),
	coeff_d_(0.0f)
{

}
float gal::control::control::f(float e, float v) {

	// force
	float force = e * coeff_p_ + v * coeff_d_;
	
	return force;
}




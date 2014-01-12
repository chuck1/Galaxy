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
float gal::control::control::f(float nx, float ntarget, double time) {
	x0 = x1;
	x1 = nx;
	
	time0 = time1;
	time1 = time;
	
	float e = ntarget - x1;
	
	// velocity
	double dt = 0;
	
	if(t > 0)
	{
		dt = time1 - time0;
		
		v = (x1 - x0) / dt;
	}
	
	// integral
	i += e * dt;
	
	// force
	float force = e * coeff_p + v * coeff_d + i * coeff_i;
	
	return force;
}
float gal::control::control::f(float e, double time) {

	e0 = e1;
	e1 = e;
	
	time0 = time1;
	time1 = time;
	
	// velocity
	double dt = 0;
	
	if(t > 0)
	{
		dt = time1 - time0;
		
		v = (e1 - e0) / dt;
	}
	
	// integral
	i += e1 * dt;
	
	// force
	float force = e1 * coeff_p + v * coeff_d + i * coeff_i;
	
	return force;
}
int	t;

float	x0;
float	x1;
float	v0;
float	v1;
float	a;

float	p;
float	d;
float	i;










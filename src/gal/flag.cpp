#include <gal/flag.h>

bool		gal::flag::all(unsigned int f)
{
	return ((flag_ & f) == f);
}
unsigned int	gal::flag::mask(unsigned int f)
{
	return (flag_ & f);
}
void		gal::flag::toggle(unsigned int f)
{
	flag_ ^= f;
}



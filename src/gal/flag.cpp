#include <stdio.h>

#include <gal/flag.h>

gal::flag::flag():
	flag_(0)
{}
void		gal::flag::set(unsigned int f)
{
	flag_ |= f;
}
void		gal::flag::unset(unsigned int f)
{
	flag_ &= !f;
}
void		gal::flag::toggle(unsigned int f)
{
	flag_ ^= f;
}
bool		gal::flag::all(unsigned int f)
{
	//printf("%i %i\n",flag_,f);
	
	return ( ( flag_ & f ) == f );
}
bool		gal::flag::any(unsigned int f)
{
	//printf("%i %i\n",flag_,f);
	
	return ( flag_ & f );
}
unsigned int	gal::flag::mask(unsigned int f)
{
	return (flag_ & f);
}



#include <gal/flag.h>

bool	gal::flag::all(unsigned int f)
{
	return ((flag_ & f) == f);
}


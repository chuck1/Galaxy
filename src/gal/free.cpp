#include <gal/except.hpp>
#include <gal/free.hpp>

void		gal::assert(bool a)
{
	if (!a)
	{
		throw gal::except("assertion");
	}
}
void		gal::assert(bool a, char const * c)
{
	char msg[256];
	
	if (!a)
	{
		strcat(msg, "assertion: \"");
		strcat(msg, c);
		strcat(msg, "\" failed");
		throw gal::except(msg);
	}
}


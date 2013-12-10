#include <gal/gal.h>

class foo: public gal::map_value
{
	
};
int main()
{
	gal::map m;
	
	m.push(new foo);
	
}


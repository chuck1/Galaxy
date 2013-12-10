#include <gal/gal.h>

class foo
{
	public:
		int	i_;
};

int main()
{
	gal::map<foo> m;

	m.push<foo>(new foo);
}


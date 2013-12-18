#include <gal/gal.h>

class foo
{
	public:
		void	fun(){}
		int	i_;
};

int main()
{
	gal::map<foo> m;
	
	m.push<foo>(std::shared_ptr<foo>(new foo));

	m.foreach<foo>(
			std::bind(&foo::fun, std::placeholders::_1)
		 );
}



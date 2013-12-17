#include <stdio.h>

#include <gal/sig/signal.h>
#include <gal/sig/connection.h>

int fun(int a, int b)
{
	printf("fun %i\n", b);
}
int main()
{
	gal::sig::signal<int> s;	
	std::shared_ptr<gal::sig::connection<int> > c_0;
	std::shared_ptr<gal::sig::connection<int> > c_1;
	std::shared_ptr<gal::sig::connection<int> > c_2;

	c_0 = s.connect(std::bind(&fun,std::placeholders::_1,0));
	c_1 = s.connect(std::bind(&fun,std::placeholders::_1,1));
	
	s(0);
	
	c_2 = s.connect(std::bind(&fun,std::placeholders::_1,2));
	
	s(1);
	
	s.disconnect(c_2);
	
	s(2);
	
	s.bring_to_front(c_0);

	s(0);

	return 0;
}



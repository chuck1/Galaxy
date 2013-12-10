#include <iostream>

#include <jess/signal/signal.hpp>

using namespace std;

bool foo( int a, int b )
{
	cout << "foo " << a << " " << b << endl;
	return ( a < 3 );
}
bool bar( int a, int b )
{
	cout << "bar " << a << " " << b << endl;
	return false;
}


int main( int argc, char ** argv )
{
	jess::signal::signal<int,int> s;

	std::shared_ptr< jess::signal::connection<int,int> > c2 = s.connect( bar );
	std::shared_ptr< jess::signal::connection<int,int> > c1 = s.connect( foo );

	s(1,2);
	s(4,2);

	return 0;
}



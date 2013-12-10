#include <iostream>

#include <jess/maze/rk.hpp>
#include <jess/maze/dfs.hpp>

int main( int argc, char ** argv )
{
	if( argc != 3 )
	{
		std::cout << "usage: maze_1 <x> <y>" << std::endl;
		return 0;
	}
	
	int x = atoi( argv[1] );
	int y = atoi( argv[2] );

	jess::maze::description desc( x, y );
	
	jess::maze::dfs m( desc );

	m.run();

	return 0;
}



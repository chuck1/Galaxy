#include <iostream>

#include <galaxy/command.hpp>

using namespace std;

int main( int argc, char ** argv ) {
	gal::command cl( argc, argv );
	
	//cout << cl.get_program_name() << endl;
	//cout << cl.get_argc() << endl;
	//cout << cl.unused_args_buf_size() << endl;
	
	cl.run();
	
	
	//cl.get_unused_args( str, 64 );

	//cout << str << endl;

	//cout << cl.has_switch( "abc" ) << endl;

	return 0;
}



#include <iostream>

#include <galaxy/command.hpp>

using namespace std;

int main( int argc, char ** argv ) {
	gal::Command cl(argc, argv);
	
	gal::Command::Arg* a1 = new gal::Command::Arg;
	a1->short_ = 0;
	a1->long_ = "help";
	
	cl.add(a1);
	
	//cout << cl.get_program_name() << endl;
	//cout << cl.get_argc() << endl;
	//cout << cl.unused_args_buf_size() << endl;
	
	cl.run();
	
	cl.print();
	cl.print_args();
	
	//cl.get_unused_args( str, 64 );

	//cout << str << endl;

	//cout << cl.has_switch( "abc" ) << endl;

	return 0;
}



#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <execinfo.h>
#include <cxxabi.h>


#include <galaxy/stack_trace.hpp>
#include <galaxy/except.hpp>


//gal::except::except(char const * message, int ec, bool inclSysMsg) throw():
//	ec_(ec)
gal::except::except() throw(): flag_(0)
{
	/*
	if (inclSysMsg)
	{
		strcat(message_, message);
		strcat(message_, ": ");
		strcat(message_, strerror(errno));
	}
	
	printf("%s\n", message_);
	*/
	//print_stacktrace();
}
gal::except::~except() throw()
{
}
const char*	gal::except::what() const throw()
{
	return "galaxy exception";
}





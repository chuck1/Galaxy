#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <execinfo.h>
#include <cxxabi.h>


#include <gal/stack_trace.h>
#include <gal/except.h>


gal::except::except(char const * message, int ec, bool inclSysMsg) throw():
	ec_(ec)
{
	message_ = new char[256];
	
	if (inclSysMsg)
	{
		strcat(message_, message);
		strcat(message_, ": ");
		strcat(message_, strerror(errno));
	}
	
	printf("%s\n", message_);
	
	print_stacktrace();
}
gal::except::~except() throw()
{
}
const char*	gal::except::what() const throw()
{
	return message_;
}





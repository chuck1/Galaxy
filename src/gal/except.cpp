#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <execinfo.h>
#include <cxxabi.h>


#include <jess/stack_trace.hpp>

#include <jess/except.hpp>


jess::except::except(const std::string& message, int ec, bool inclSysMsg)throw() : message_(message), ec_(ec)
{
	if (inclSysMsg)
	{
		message_.append(": ");
		message_.append(strerror(errno));
	}

	printf("%s\n",message_.c_str());

	print_stacktrace();
}
jess::except::~except() throw()
{
}
const char*	jess::except::what() const throw()
{
	return message_.c_str();
}





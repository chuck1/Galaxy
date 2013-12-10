#ifndef __JESS_FREE_HPP__
#define __JESS_FREE_HPP__

#define GAL_ASSERT(x) gal::assert(x,#x)

namespace gal
{
	void	assert(bool);
	void	assert(bool,char const *);
}

#endif









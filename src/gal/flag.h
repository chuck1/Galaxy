#ifndef __GAL_FLAG_H__
#define __GAL_FLAG_H__

namespace gal
{
	class flag
	{
		public:
			bool		all(unsigned int);
			unsigned int	mask(unsigned int);
			void		toggle(unsigned int);
		private:
			unsigned int	flag_;
	};
}

#endif

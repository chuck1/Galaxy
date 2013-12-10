#ifndef __GAL_FLAG_H__
#define __GAL_FLAG_H__

namespace gal
{
	class flag
	{
		public:
			flag();
			bool		any(unsigned int);
			bool		all(unsigned int);
			void		set(unsigned int);
			void		unset(unsigned int);
			void		toggle(unsigned int);
			unsigned int	mask(unsigned int);
		private:
			unsigned int	flag_;
	};
}

#endif

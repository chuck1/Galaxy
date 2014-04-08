#ifndef __JESS_EXCEPT_EXCEPT_HPP__
#define __JESS_EXCEPT_EXCEPT_HPP__

#include <exception>
#include <string>

namespace gal
{
	class except: public std::exception
	{
	public:
		/// error codes
/*
		struct error_code
		{
			/// enum
			enum e
			{
				eDEFAULT = 0,
				eEXIT
			};
		};
	*/	
		
		//except(char const *, int ec = error_code::eDEFAULT,bool incl_sys_msg = false) throw();
		except() throw();	
		
		~except() throw();
		
		const char* what() const throw();
		
	private:
		int		ec_;
	};
}	




#endif
















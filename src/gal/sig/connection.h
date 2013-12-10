#ifndef __SIG_CONNECTION_HPP__
#define __SIG_CONNECTION_HPP__

#include <functional>

namespace SIG
{
	template <typename... Args> class signal;

	template <typename... Args> class connection
	{
		public:
			friend class SIG::signal<Args...>;
		protected:
			connection( std::function<int(Args...)> handle ):
				handle_( handle )
		{

		}
		public:
			~connection()
			{

			}
		protected:
			std::function<int(Args...)>	handle_;
	};
}

#endif





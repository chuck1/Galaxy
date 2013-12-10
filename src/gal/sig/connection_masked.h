#ifndef __JESS_SIGNAL_CONNECTION_MASKED_HPP__
#define __JESS_SIGNAL_CONNECTION_MASKED_HPP__

#include <functional>

#include <SIG/connection.hpp>

namespace SIG
{
	template <typename... Args> class signal;

	template <typename... Args> class connection_masked:
		public jess::signal::connection<Args...>
	{
		public:
			friend class jess::signal::signal<Args...>;
		protected:
			/** \brief ctor
			 */
			connection_masked( std::function<void(Args...)> handle, std::function<bool(Args...)> handle_block ):
				jess::signal::connection<Args...>( handle ),
				handle_block_( handle_block )
		{

		}
		public:
			virtual ~connection_masked()
			{

			}
		protected:
			/** \brief block
			 */
			virtual bool			block( Args... args )
			{
				return handle_block_( args... );
			}
			/** \brief handle block
			 */
			std::function<bool(Args...)>	handle_block_;
	};
}
#endif



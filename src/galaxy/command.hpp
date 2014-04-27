#ifndef _COMMANDLINE_H
#define _COMMANDLINE_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

#include <stdint.h>

/// Container for command-line arguments.
/// This class assumes argument 0 is always the executable path!

namespace gal {
	class Command {
		public:
			/** @brief %Arg */
			struct Arg {
				char				short_;
				std::string			long_;

				bool				takes_val_;
				//bool			set_;
				std::vector<std::string>	val_;
			};	
			
			/** @brief COnstructor */
			Command(int argc, char const * const * argv);
			/** @brief Add Args.
			 * Add %arg to list of available args. Takes ownership of object.
			 */
			void	add(gal::Command::Arg*);
			
			/** @brief Parse the line. */
			void	run();
			
		private:
			void	parse_arg( char const * const * );
			void	parse( char const * const * );
			void	parse_opt( char const * const * );
			void	parse_val( char const * const * );
			
			bool	is_short(char const *);
			bool	is_long(char const *);	
			bool	is_val(char const *);
			
		public:
			void 	print_args();
			void	print();
			void	print_short(std::pair<const char, Command::Arg*>&);
			void	print_long(std::pair<const std::string, Command::Arg*>&);
			
		private:
			/// number of arguments
			uint32_t				argc_;
			/// charactor string
			char const * const *			argv_;
			/// unknown
			//void*					m_freeme;
			/// unknown
			//static const unsigned int		invalidArgNum = 0xFFFFFFFFU;
			/// unknown
			//bool*					m_argUsed;

			/** @brief map
			 * map of possible long commands
			 */
			std::unordered_map<char, Command::Arg*>			map_short_;
			std::unordered_map<std::string, Command::Arg*>		map_long_;
			
			Command::Arg*						last_arg_;
	};



	char**		CommandLineToArgvA( const char *cmdLine, unsigned int &_argc );
	bool		isSwitchChar(char c);

}

#endif




#ifndef _COMMANDLINE_H
#define _COMMANDLINE_H

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

#include <stdint.h>

/// Container for command-line arguments.
/// This class assumes argument 0 is always the executable path!


class command
{
	public:
		struct arg
		{
			char				short_;
			std::string			long_;
			
			bool				takes_val_;
			//bool			set_;
			std::vector<char const *>	val_;
		};	



		/// ctor
		command( uint32_t argc, char const *const* argv );
		/*		/// ctor
				command( const char* args );
		/// dtor
		~command();
		/// copy ctor
		command( command const & );
		/// ctor
		command();
		/// assignment
		command					operator=( command const & );
		/// has a given command-line switch?*/
		/** e.g. s=="foo" checks for -foo */
		/*bool					has_switch( const char* s, const unsigned int argNum = invalidArgNum ) const;*/
		/** \brief get value
		 * gets the value of a switch.
		 * e.g. s="foo" returns "bar" if '-foo=bar' is in the commandline.
		 */
		/*		const char*				get_value( const char* s, unsigned int argNum = invalidArgNum ) const;
		/// return how many command line arguments there are
		unsigned int				get_argc() const;

		/// what is the program name
		const char*				get_program_name() const;

		/// get the string that contains the unsued args
		unsigned int				unused_args_buf_size() const;

		/// get the string that contains the unsued args
		const char*				get_unused_args( char* buf, unsigned int bufSize ) const;

		/// if the first argument is the given command.
		bool					isCommand( const char* s ) const;

		///! get the first argument assuming it isn't a switch.
		///  e.g. for the command-line "myapp.exe editor -foo" it will return "editor".
		const char*				getCommand() const;

		/// get the raw command-line argument list...
		unsigned int				getArgC() const { return m_argc; }
		/// get the raw command-line argument list...
		const char* const*			getArgV() const { return m_argv; }
		*/

		// complete revision----------------------------------------------------
		void	add( command::arg );

		void	run();
		void	parse_arg( char const * const * );
		void	parse( char const * const * );
		void	parse_opt( char const * const * );
		void	parse_val( char const * const * );

		bool	is_short( char const * );
		bool	is_long( char const * );	
		bool	is_val( char const * );

		void 	print_args();
		void	print();
		void	print_short( std::pair<const char, command::arg*>& );
		void	print_long( std::pair<const std::string, command::arg*>& );

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

		//--------------------------------------------------------------------
		/** \brief map
		 * map of possible long commands
		 */
		std::unordered_map<char, command::arg*>			map_short_;
		std::unordered_map<std::string, command::arg*>		map_long_;
		
		command::arg*						last_arg_;
};



char**		CommandLineToArgvA( const char *cmdLine, unsigned int &_argc );
bool		isSwitchChar( char c );



#endif




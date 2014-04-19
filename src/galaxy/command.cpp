#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <galaxy/command.hpp>

using namespace std;


/*bool str_pred::operator()( char const * a, char const * b ) const
{
	if( strcmp(a,b)==0 )
	{
		printf( "'%s'=='%s'\n", a, b );
		return true;
	}
	else
	{
		printf( "'%s'!='%s'\n", a, b );
		return false;
	}
}*/

void	gal::command::add( command::arg a )
{
	command::arg* b = new command::arg(a);

	if( b->short_ != '-' )
	{
		map_short_[b->short_] = b;
	}

	if ( !b->long_.empty() )
	{
		map_long_[b->long_] = b;
	}
}

void	gal::command::run()
{
	if( argc_ > 1 )
	{
		parse( argv_+1 );
	}
}
void	gal::command::parse( char const * const * v )
{
	char const * c = *v;
	
	if( c[0]=='-' )
	{
		parse_opt( v );
	}
	else
	{
		parse_val( v );
	}
}
bool	gal::command::is_short( char const * c )
{
	if( strlen(c) < 2 )
	{
		return false;
	}
	
	if( c[1]=='-' )
	{
		return false;
	}
	
	if( c[0]=='-' )
	{
		return true;
	}
	
	return false;
}
bool	gal::command::is_long( char const * c )
{
	if( strlen(c) < 3 )
	{
		return false;
	}
	
	if( c[0]=='-' && c[1]=='-' && c[2]!='-' )
	{
		return true;
	}
	
	return false;
}
bool	gal::command::is_val( char const * c )
{
	if( strlen(c) == 0 )
	{
		return false;
	}
	
	if( c[0]!='-' )
	{
		return true;
	}
	
	return false;
}



void	gal::command::parse_opt( char const * const * v )
{
	char const * c = *v;
	
	if( strlen(c)==1 )
	{
		printf( "error '%s'\n", c );
	}
	else if( c[1]=='-' )
	{
		// long
		if( strlen(c)==2 )
		{
			printf( "error '%s'\n", c );
		}
		else
		{
			auto it = map_long_.find( c+2 );

			if( it != map_long_.end() )
			{
				printf( "long option '%s'\n", c+2 );
				
				last_arg_ = it->second;
				
				if( ++v < ( argv_ + argc_ ) )
					parse(v);
			}
			else
			{
				printf( "long option '%s' not found\n", c+2 );
			}

		}
	}
	else
	{
		// short
		size_t i = 1;

		while( i < strlen(c) )
		{
			auto it = map_short_.find( c[i] );

			if( it != map_short_.end() )
			{
				printf( "short option '%c'\n", c[i] );

				last_arg_ = it->second;
				
				if( ++v < ( argv_ + argc_ ) )
					parse(v);

			}
			else
			{
				printf( "short option '%c' not found\n", c[i] );
			}

			++i;
		}
	}
}
void	gal::command::parse_val( char const * const * v )
{
	char const * c = *v;

	printf( "value '%s'\n", c );
	
	if( last_arg_ )
	{
		last_arg_->val_.push_back(c);
	}
	
	if( ++v < ( argv_ + argc_ ) )
		parse(v);

}
void	gal::command::print_args()
{
	for( uint32_t i = 0; i < argc_; ++i )
	{
		printf( "%s\n", argv_[i] );
	}
}
void	gal::command::print()
{
	printf("print %i %i\n", (int)map_short_.size(), (int)map_long_.size() );

	for( auto it = map_short_.begin(); it !=  map_short_.end(); ++it ) {
		print_short( *it );
	}
	
	for( auto it = map_long_.begin(); it !=  map_long_.end(); ++it ) {
		print_long( *it );
	}

}
void	gal::command::print_short( std::pair<const char,command::arg*>& p )
{
	command::arg* a = p.second;

	printf("short: %c ",a->short_);

	for( auto it = a->val_.begin(); it != a->val_.end(); ++it )
	{
		printf( "%s ", *it );
	}
	printf( "\n" );
}
void	gal::command::print_long( std::pair<const std::string,command::arg*>& p )
{
	command::arg* a = p.second;
	
	printf("long: %s ",a->long_.c_str() );
	
	for( auto it = a->val_.begin(); it != a->val_.end(); ++it )
	{
		printf( "%s ", *it );
	}
	printf( "\n" );
}

//0000000000000000000000000000000000000000000000000000000000000000

gal::command::command( uint32_t argc, char const*const* argv ):
	argc_( argc ),
	argv_( argv ),
	last_arg_( NULL )
{
}
/*command::command(const char *args)
  {
  m_argUsed  = NULL;
  m_argc   = 0;
  m_argv   = 0;
  m_freeme = 0;

  unsigned int argc = 0;
  char       **argv = CommandLineToArgvA(args, argc);

  if(argv)
  {
  m_argc   = argc;
  m_argv   = argv;
  m_freeme = argv;
  }
  else
  {
  throw except("");
  }
  m_argUsed = new bool[m_argc];

  for(unsigned int i = 0; i < m_argc; i++)
  {
  m_argUsed[i] = false;
  }
  }
  command::~command(void)
  {
  if(m_freeme)
  {
  free(m_freeme);
  m_freeme = NULL;
  }
  if(m_argUsed)
  {
  delete[] m_argUsed;
  m_argUsed = NULL;
  }
  }
  unsigned int	command::get_argc(void) const
  {
  return(m_argc);
  }
  const char*	command::get_program_name(void) const
  {
  return(m_argv[0]);
  }
  unsigned int	command::unused_args_buf_size(void) const
  {
  unsigned int bufLen = 0;

  for(unsigned int i = 1; i < m_argc; i++)
  {
  if((!m_argUsed[i]) && isSwitchChar(m_argv[i][0]))
  {
  bufLen += (unsigned int) strlen(m_argv[i]) + 1;	// + 1 is for the space between unused args
  }
  }

  if ( bufLen != 0 )
  {
  bufLen++;	// if there are unused args add a space for the '\0' char.
  }

  return(bufLen);
  }
  const char*	command::get_unused_args(char *buf, unsigned int bufSize) const
  {
  if( bufSize != 0 )
  {
buf[0] = '\0';
for(unsigned int i = 1; i < m_argc; i++)
{
	if((!m_argUsed[i]) && isSwitchChar(m_argv[i][0]))
	{
		string::strncat( buf, bufSize, m_argv[i], strlen(m_argv[i]) ); //physx::string::strcat_s(buf, bufSize, m_argv[i]);
		string::strncat( buf, bufSize, " ", 1 ); //physx::string::strcat_s(buf, bufSize, " ");
	}
}
}

return(buf);
}
bool		command::has_switch(const char *s, unsigned int argNum) const
{
	// has a given command-line switch?
	// e.g. s=="foo" checks for -foo

	bool has = false;
	//PX_ASSERT(*s);
	if(*s)
	{
		unsigned int n = (unsigned int) strlen(s);
		unsigned int firstArg;
		unsigned int lastArg;
		if(argNum != invalidArgNum)
		{
			firstArg = argNum;
			lastArg  = argNum;
		} else {
			firstArg = 1;
			lastArg  = m_argc - 1;
		}
		for(unsigned int i=firstArg; i<=lastArg; i++)
		{
			const char *arg = m_argv[i];
			// allow switches of '/', '-', and double character versions of both.

			//if( ( isSwitchChar(*arg) && !physx::string::strnicmp( arg+1, s, n ) && ( ( arg[n+1]=='\0')||(arg[n+1]=='='))) || ( isSwitchChar(*(arg+1)) && !physx::string::strnicmp( arg+2, s, n ) && ( ( arg[n+2]=='\0')||(arg[n+2]=='='))) )
			if 
				(
				 ( isSwitchChar(*arg) && !strncmp( arg+1, s, n ) && ( ( arg[n+1]=='\0' )||( arg[n+1]=='=' ) ) ) ||
				 ( isSwitchChar(*(arg+1)) && !strncmp( arg+2, s, n ) && ( ( arg[n+2]=='\0')||(arg[n+2]=='=') ) )
				)
				{
					m_argUsed[i] = true;
					has = true;
					break;
				}
		}
	}
	else
	{
		throw except("");
	}

	return has;
}
const char*	command::get_value(const char *s,  unsigned int argNum) const
{
	// gets the value of a switch... 
	// e.g. s="foo" returns "bar" if '-foo=bar' is in the command.
	const char *value = 0;
	//PX_ASSERT(*s);
	if(*s)
	{
		unsigned int firstArg;
		unsigned int lastArg;
		if(argNum != invalidArgNum)
		{
			firstArg = argNum;
			lastArg  = argNum;
		}
		else
		{
			firstArg = 1;
			lastArg  = m_argc - 1;
		}

		for(unsigned int i=firstArg; i<=lastArg; i++) 
		{
			const char *arg = m_argv[i];
			if(isSwitchChar(*arg)) {
				arg++;

				if(isSwitchChar(*arg))
				{
					// is it a double dash arg?  '--'
					arg++;
				}

				const char *st=s;

				for (; *st && *arg && toupper(*st)==toupper(*arg) && *arg!='='; st++,arg++)
				{
				}

				if (!*st && *arg=='=')
				{
					m_argUsed[i] = true;
					value = arg+1;
					break;
				}

				if(!*st && !*arg && ((i+1)<m_argc) && (!isSwitchChar(*m_argv[i+1])))
				{
					m_argUsed[i] = true;
					value = m_argv[i+1];
					break;
				}
			}
		}
	} 
	else
	{
		throw except("");
	}

	return value;
}
bool		command::isCommand(const char *s) const
{
	//! if the first argument is the given command.
	bool has = false;
	const char *command = getCommand();

	//if(command && !physx::string::stricmp(command, s))
	if( command && !strcmp(command, s) ) {
		has = true;
	}
	return has;
}
const char*	command::getCommand(void) const
{
	//! get the first argument assuming it isn't a switch.
	//  e.g. for the command-line "myapp.exe editor -foo" it will return "editor".
	const char *command = 0;
	if(m_argc > 1 && !isSwitchChar(*m_argv[1]))
	{
		command = m_argv[1];
	}
	return command;
}



char**		CommandLineToArgvA(const char* cmdLine, unsigned int& _argc)
{
	char**		argv     = 0;
	char*		_argv    = 0;
	unsigned int	len      = 0;
	unsigned int	argc     = 0;
	char		a        = 0;
	unsigned int	i        = 0;
	unsigned int	j        = 0;
	bool		in_QM    = false;
	bool		in_TEXT  = false;
	bool		in_SPACE = true;

	len   = (unsigned int)strlen(cmdLine);
	i     = ((len+2)/2)*sizeof(char*) + sizeof(char*);
	argv  = (char **)malloc(i + (len+2)*sizeof(char));
	_argv = (char *)(((char *)argv)+i);
	argv[0] = _argv;

	i = 0;

	a = cmdLine[i];
	while(a)
	{
		if(in_QM)
		{
			if(a == '\"')
			{
				in_QM = false;
			}
			else
			{
				_argv[j] = a;
				j++;
			}
		}
		else
		{
			switch(a)
			{
				case '\"':
					in_QM = true;
				in_TEXT = true;
				if(in_SPACE)
				{
					argv[argc] = _argv+j;
					argc++;
				}
				in_SPACE = false;
				break;
				case ' ':
				case '\t':
				case '\n':
				case '\r':
				if(in_TEXT)
				{
					_argv[j] = '\0';
					j++;
				}
				in_TEXT = false;
				in_SPACE = true;
				break;
				default:
				in_TEXT = true;
				if(in_SPACE)
				{
					argv[argc] = _argv+j;
					argc++;
				}
				_argv[j] = a;
				j++;
				in_SPACE = false;
				break;
			}
		}
		i++;
		a = cmdLine[i];
	}
	_argv[j] = '\0';
	argv[argc] = 0;
	_argc = argc;
	return argv;
}
bool		isSwitchChar( char c )
{
	return (c == '-' || c == '/');
}







*/

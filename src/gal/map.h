#ifndef __JESS_MAP_HPP__
#define __JESS_MAP_HPP__

#include <map>

#include <memory>

#include <jess/except.hpp>

namespace gal
{
	class map;
	class map_value
	{
		public:
			friend class map;
		private:
			i_;
	};
	class map
	{
		public:
			map()
				:next_(0),
			{}
			template <class U> int	push(U* u)
			{
				if(u == NULL)
				{
					return 1;
				}

				map_[next_++] = u;
			}
			T*			at(int a)
			{
				auto it = map_.find( a );
				if ( it == map_.end() )
				{
					return std::shared_ptr<T>();
				}
				else
				{
					return ( it->second );
				}
			}
			void			foreach( std::function<void(T*)> func )
			{
				T* t = 0;
				auto it = map_.begin();
				for ( ; it != map_.end(); ++it )
				{
					t = (it->second).get();
					if ( t )
					{
						func( t );
					}
					else
					{
						throw jess::except( "null pointer" );
					}
				}
			}
			void			clear()
			{
				map_.clear();
			}
			void			erase( int a )
			{
				auto it = map_.find(a);
				if(it != map_.end())
				{
					map_.erase(a);
				}
			}
		private:
			std::map<int,T*>	map_;
			int			next_;
	};	
}

#endif




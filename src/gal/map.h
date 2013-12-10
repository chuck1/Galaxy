#ifndef __JESS_MAP_HPP__
#define __JESS_MAP_HPP__

#include <map>
#include <memory>
#include <functional>

#include <gal/except.h>

namespace gal
{
	template <class T> 
	class map
	{
		public:
			map()i
				:next_(0)
			{}
			template <class U> int	push(U* u)
			{
				if(u == NULL)
				{
					return 1;
				}
				
				u->
				
				map_[next_++] = u;
			}
			map_value*		at(int a)
			{
				auto it = map_.find( a );
				if(it == map_.end())
				{
					return NULL;
				}
				else
				{
					return (it->second);
				}
			}
			void			foreach( std::function<void(map_value*)> func )
			{
				map_value* v = NULL;
				auto it = map_.begin();
				for ( ; it != map_.end(); ++it )
				{
					v = it->second;
					if(v != NULL)
					{
						func(v);
					}
					else
					{
						throw gal::except("null pointer");
					}
				}
			}
			void			clear()
			{
				map_.clear();
			}
			void			erase(int a)
			{
				auto it = map_.find(a);
				if(it != map_.end())
				{
					map_.erase(a);
				}
			}
		private:
			std::map<int,map_value*>	map_;
			int			next_;
	};	
}

#endif




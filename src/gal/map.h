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
			map()
				:next_(0)
			{}
			template <class U> int	push(std::shared_ptr<U> u)
			{
				if(u == NULL)
				{
					return 1;
				}
				
				u->i_ = next_;
				
				map_[next_] = u;
				
				return next_++;
			}
			std::shared_ptr<T>		at(int a)
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
			void				foreach(std::function<void(T*)> func)
			{
				std::shared_ptr<T> t;
				auto it = map_.begin();
				for(; it != map_.end(); ++it)
				{
					t = it->second;
					//U* u = (U*)t;
					if(t)
					{
						func(t.get());
					}
					else
					{
						throw gal::except("null pointer");
					}
				}
			}
			void					clear()
			{
				map_.clear();
			}
			void					erase(int a)
			{
				auto it = map_.find(a);
				if(it != map_.end())
				{
					map_.erase(a);
				}
			}
		//private:
			std::map<int,std::shared_ptr<T> >	map_;
			int					next_;
	};	
}

#endif




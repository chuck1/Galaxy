/*

	gal::map()
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
			gal::map_value*			gal::at(int a)
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
			void			gal::foreach( std::function<void(gal::map_value*)> func )
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
			void			gal::clear()
			{
				map_.clear();
			}
			void			gal::erase( int a )
			{
				auto it = map_.find(a);
				if(it != map_.end())
				{
					map_.erase(a);
				}
			}
*/

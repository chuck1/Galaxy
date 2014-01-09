#ifndef __JESS_ASIO_MESSAGE_EXT_H__
#define __JESS_ASIO_MESSAGE_EXT_H__

#include <assert.h>

#include <gal/network/message.h>


// for unpacking tuple

template<int ...> struct seq { };

template<int N, int ...S> struct gens : gens<N-1, N-1, S...> { };

template<int ...S> struct gens<0, S...> { typedef seq<S...> type; };

// for calling functions
struct pass { template<typename ...T> pass(T...) {} };

// for allocating tuple of pointers

template<typename T> void reset(std::shared_ptr<T>& t) {
	t.reset(new T);
}

template<int... S, typename... Args> void reset_tuple(seq<S...>, std::tuple<Args...> tup) {
	pass{(reset(std::get<S>(tup)), 1)...};
}






// main
class message: public std::enable_shared_from_this<message> {};

template<typename... Args> class message_ext {
	public:
		typedef typename gens<sizeof...(Args)>::type seq_t;
		message_ext() {
			//typename gens<sizeof...(Args)>::type s;
			seq_t s;
			reset_tup(s);
		}
		template<int... S> void reset_tup(seq<S...>) {
			pass{(reset(std::get<S>(tup_)), 1)...};
		}
		void write() {
			seq_t s;
			write_expand(s);
		}
		template<int... S> void write_expand(seq<S...>) {
			pass{(std::get<S>(tup_)->write(msg_), 1)...};
		}
		void write_expand(std::shared_ptr<Args>... args) {
			pass{(assert(args), 1)...};
			pass{(args->write(msg_), 1)...};
		}
		std::shared_ptr<message> msg_;
		std::tuple<std::shared_ptr<Args>...> tup_;
};

template <typename T> struct vector {
	typedef std::shared_ptr<T> T_s;
	typedef std::vector<T_s> vec;
	void write(std::shared_ptr<message> msg) {
		T_s t;
		for(auto it = vec_.begin(); it != vec_.end(); ++it) {
			t = *it;
			assert(t);
			t->write(msg);
		}
	}	
	vec vec_;
};

struct ser1 {
	void write(std::shared_ptr<message>) { printf("ser1 write\n"); }
};
struct ser2 {
	void write(std::shared_ptr<message>) { printf("ser2 write\n"); }
};

typedef message_ext<ser2,vector<ser1> > me1;

int main() {
	//std::shared_ptr<vector<ser1> > v1(new vector<ser1>);
	//std::shared_ptr<ser2> s2(new ser2);
	std::shared_ptr<me1> m(new me1);

	std::get<1>(m->tup_)->vec_.emplace_back(new ser1);
	//m->write_expand(s2,v1);
	m->write();
}






















namespace gal
{
	namespace network
	{
		template<class... Args> class message_ext
		{
			public:
				message_ext(message_shared msg): msg_(msg) {assert(msg);}
				void  write_expand(std::shared_ptr<Args>... args)
				{	
					pass{(args->write(msg_), 1)...};
				}
				void  read_expand(std::shared_ptr<Args>... args)
				{
					pass{(args->read(msg_), 1)...};
				}
			private:
				message_shared	msg_;
		};
	}
}

#endif

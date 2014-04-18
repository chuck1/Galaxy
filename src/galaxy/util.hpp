#ifndef __GALAXY_UTIL_H__
#define __GALAXY_UTIL_H__

#include <memory>

namespace gal {
	template<int ...> struct seq {};

	template<int N, int ...S> struct gens: gens<N-1, N-1, S...> {};

	template<int ...S> struct gens<0, S...> {
		typedef seq<S...> type;
	};

	struct pass {
		template<typename ...T> pass(T...) {}
	};

	template<typename T> void reset(std::shared_ptr<T>& t) {
		t.reset(new T);
	}

	template<int... S, typename... Args> void reset_tuple(seq<S...>, std::tuple<Args...>& tup) {
		pass{(reset(std::get<S>(tup)), 1)...};
	}

	template<typename... Args> void reset_tuple(std::tuple<Args...>& tup) {
		typename gens<sizeof...(Args)>::type s;
		reset_tuple(s, tup);
	}
}

#endif


#include <galaxy/timer/timer_set.hpp>

void gal::timer::timer_set::step(double time) {


	auto it = set_.begin();
	while(it != set_.end()) {

		auto t = *it;

		if(time > t->time_) {
			t->activate();
			
			//it = set_.erase(it);
		}
		else {
			++it;
		}

	}


}



#include <stdio.h>

#include <galaxy/timer/timer_set.hpp>

class foo: public gal::timer::timer
{
	public:
		foo(double time): gal::timer::timer(time) {}

		void	activate() {printf("hello\n");}
};

typedef std::shared_ptr<foo> foo_s;

int main() {
	gal::timer::timer_set s;

	s.set_.insert(foo_s(new foo(1.0)));
	
	printf("%i\n", (int)s.set_.size());
	s.step(0.4);
	printf("%i\n", (int)s.set_.size());
	s.step(0.8);
	printf("%i\n", (int)s.set_.size());
	s.step(1.2);
	printf("%i\n", (int)s.set_.size());
	s.step(1.6);
	printf("%i\n", (int)s.set_.size());
}



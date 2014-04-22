#include <cstdio>

#include <galaxy/flag.hpp>
#include <galaxy/network/vector.hpp>
#include <galaxy/network/serial.hpp>
#include <galaxy/map.hpp>

class foo {
	public:
		void	i(int i) {i_ = i;}
	
		void	speak() {
			printf("foo %i\n", i_);
		}

		int	i_;

};

class bar: public gal::flag<> {
	
	unsigned int	f() {return flag_;}
	void		f(unsigned int flag) {flag_ = flag;}
	

	unsigned int flag_;
};

template<int i> struct ser {
	void write(gal::network::message_shared msg) {
		printf("write ser%i\n", i);
	}
	void read(gal::network::message_shared msg) {
		printf("read ser%i\n", i);
	}
	size_t size() {
		return 0;
	}
};

typedef gal::network::serial<int, gal::network::base> ser0;
typedef gal::network::serial_ext<gal::network::vector_ext<ser<0>>> ser_ext;
typedef gal::network::vector_ext<int,float> vec0;

int main() {

	gal::map<foo> m;

	m.push_back<foo>(std::shared_ptr<foo>(new foo));
	m.push_back<foo>(std::shared_ptr<foo>(new foo));
	m.push_back<foo>(std::shared_ptr<foo>(new foo));
	m.push_back<foo>(std::shared_ptr<foo>(new foo));

	m.foreach<foo>(std::bind(&foo::speak, std::placeholders::_1));

	auto it = m.find(0);

	it = m.erase(it);

	/*

	bar b;
	b.set(0);
	
	// message
	gal::network::message_shared msg(new gal::network::message);
	
	std::shared_ptr<ser_ext> s;
	
	s->write(msg);
	s->read(msg);
	s->size();

	*/
}



#include <gal/gal.h>
#include <gal/flag.h>
#include <gal/network/vector.h>
#include <gal/network/serial.h>

class foo
{
	public:
		void	fun(){}
		int	i_;
		void	i(int i) {i_ = i;}
};

class bar: public gal::flag<>
{
	
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

typedef gal::network::serial_ext<gal::network::vector_ext<ser<0>>> ser_ext;

int main()
{
	gal::map<foo> m;
	m.push_back<foo>(std::shared_ptr<foo>(new foo));
	m.foreach<foo>(std::bind(&foo::fun, std::placeholders::_1));
	
	bar b;
	b.set(0);
	
	// message
	gal::network::message_shared msg(new gal::network::message);
	
	std::shared_ptr<ser_ext> s;
	
	s->write(msg);
	s->read(msg);
	s->size();
}



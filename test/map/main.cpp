#include <gal/gal.h>
#include <gal/flag.h>
#include <gal/network/vector.h>
#include <gal/network/message_ext.h>

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

int main()
{
	gal::map<foo> m;
	m.push_back<foo>(std::shared_ptr<foo>(new foo));
	m.foreach<foo>(std::bind(&foo::fun, std::placeholders::_1));
	
	
	
	bar b;
	b.set(0);
	
	
	std::shared_ptr<gal::network::message_ext<>> msg;
	
	msg->write_expand();
}



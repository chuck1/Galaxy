#include <gal/network/client.h>
#include <gal/network/server.h>

void	client();
void	server();
void	process(gal::network::message::shared_t msg);

int port = 0;

class Server: public gal::network::server
{
	public:
		Server(int,int);
		void	callback_accept(int);
};
class Communicating: virtual public gal::network::communicating
{
	public:
		typedef std::shared_ptr<communicating> shared_t;
		
		Communicating(int s): gal::network::communicating(s)
		{}
		void	process(gal::network::message::shared_t msg)
		{
			printf("process %i\n", (int)msg->body_length());
			printf("'%s'\n", msg->body());
		}
};
class Client: virtual public gal::network::client, virtual public Communicating
{
	public:
		Client(char const *, unsigned short);
};

Client::Client(char const * addr, unsigned short port):
	gal::network::client(addr, port),
	Communicating(::socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)),
	gal::network::communicating(::socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))
{
}


Server::Server(int port,int len):
	gal::network::server(port,len)
{

}
void Server::callback_accept(int s)
{
	Communicating::shared_t c(new Communicating(s));
	
	c->start();
	
	clients_.push_back(c);
}



int main(int argc, char ** argv)
{
	if(argc != 3)
	{
		printf("usage: %s <type> <port>\n", argv[0]);
		return 1;
	}

	port = atoi(argv[2]);

	if(strcmp(argv[1], "c") == 0) client();
	if(strcmp(argv[1], "s") == 0) server();
	return 0;
}
void	client()
{
	printf("client\n");

	Client client("127.0.0.1",port);

	char s[128];

	gal::network::message::shared_t msg(new gal::network::message);

	while(1)
	{
		scanf("%s",s);


		msg->set(s, strlen(s));

		printf("body = '%s'\n", msg->body());

		client.write(msg);
	}
}
void	server()
{
	printf("server\n");
	
	Server server(port,10);
	
	while(1)
	{

	}
}






#include <gal/network/client.h>
#include <gal/network/server.h>

void	client();
void	server();
void	process(gal::network::message::shared_t msg);

int port = 0;

class communicating: virtual public gal::network::communicating
{
	public:
		communicating(int s): gal::network::communicating(s)
		{}
		void	process(gal::network::message::shared_t msg)
		{
			printf("process %i\n", (int)msg->body_length());
			printf("'%s'\n", msg->body());
		}
};

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

	gal::network::client client("127.0.0.1",port);

	char s[128];

	gal::network::message::shared_t msg(new gal::network::message);

	while(1)
	{
		scanf("%s",s);


		memcpy(msg->body(), s, strlen(s));

		printf("body = '%s'\n", msg->body());

		msg->body_length(strlen(s));
		msg->encode_header();

		client.write(msg);
	}
}
void	server()
{
	printf("server\n");

	gal::network::server<communicating> server(port,10);

	while(1)
	{

	}
}






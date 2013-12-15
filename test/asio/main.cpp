#include <gal/asio/network/client.h>
#include <gal/asio/network/server.h>

void	client();
void	server();
void	process(gal::asio::message::shared_t msg);

int port = 0;

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

	gal::asio::network::client client("127.0.0.1",port);

	char s[128];

	gal::asio::message::shared_t msg(new gal::asio::message);

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

	gal::asio::network::server server(port,10);

	server.process_body_ = &process;

	while(1)
	{
		
	}
}
void	process(gal::asio::message::shared_t msg)
{
	printf("process %i\n", (int)msg->body_length());
	printf("'%s'\n", msg->body());
}





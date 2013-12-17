#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>

#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in


#include <gal/config.h>
#include <gal/network/server.h>

/*
gal::asio::network::server::server(unsigned short localPort, int queueLen):
	socket_(::socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)),
	thread_accept_(std::bind(&server::thread_accept, this)),
	local_port_(localPort)
{
	GALAXY_DEBUG_FUNCTION;


}
void	gal::network::server::thread_accept()
{
	GALAXY_DEBUG_FUNCTION;

	sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(local_port_);
	
		
	
	int c = bind (socket_, (struct sockaddr *)&addr, sizeof(addr));
	if(c < 0)
	{
		perror("bind:");  
	}

	listen(socket_,5);

	socklen_t len = sizeof(addr);
	
	while(1)
	{
		
		int s = ::accept(socket_, (struct sockaddr *)&addr, &len);
		if(s < 0)
		{
			perror("accept:");
			exit(0);
		}


		{
			std::lock_guard<std::mutex> lk(mutex_);
			
			communicating::shared_t client(new communicating(s));
			client->process_body_ = process_body_;
			client->start();
			
			clients_.push_back(client);
		}
	}
}
*/


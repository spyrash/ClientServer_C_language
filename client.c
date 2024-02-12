#include <sys/socket.h>

int main() {
	// using the domain AF_INET for IPv4 Internets protocols
	// using SOCK_STREAM as a regular tcp socket
	// using default protocol
	// this one will return a file descriptor of the socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// binding the socket to a certain address to listen
	// using the internet domain socket
	// htons handle the order of bytes between the machine and the socket
	struct sockaddr_in socketAddress = {
		AF_INET,
		htons(1234),
		0
	};
	
	bind(socketfd, &socketAddress, sizeof(socketAddress));
	
	// mark the socketfd in order to accept incoming connection using accept( by the server)
	listen(socketfd, 100);
	// accept the connection 
	accept(socketfd, 0, 0);
	
	return 1;
}

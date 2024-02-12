#include <sys/socket.h>

int main() {
	// using the domain AF_INET for IPv4 Internets protocols
	// using SOCK_STREAM as a regular tcp socket
	// using default protocol
	// this one will return a file descriptor of the socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// binding the socket to a certain address to listen
	bind(
}

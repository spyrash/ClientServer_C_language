#include <sys/socket.h>
#include <poll.h>
#include <arpa/inet.h>
#include <stdio.h>

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
        htons(9999),
        0
    };
	
	bind(socketfd, &socketAddress, sizeof(socketAddress));
	
	// mark the socketfd in order to accept incoming connection using accept( by the server)
	listen(socketfd, 100);
	// accept the connection, and return the file descriptor of the accepted connection
	int acceptedfd = accept(socketfd, 0, 0);
	
	// create two structure for poll
    struct pollfd fds[2] = {
        {
			0,
            POLLIN,
            0
        },
        {
            socketfd,
            POLLIN,
            0
        }
    };
    
    while (1 == 1) {
    char buffer[256] = {0};
    // it waits for one of a set of file
    // descriptors to become ready to perform I/O
    poll(fds, 2, 50000);
    
    // POLLIN => There is data to read.
    if (fds[0].revents & POLLIN) {
		read(0, buffer, 255);
		send(acceptedfd, buffer, 255, 0);
	}
	else if (fds[1].revents & POLLIN) {
		if (0 == recv(socketfd, buffer, 255, 0)) {
			return 0;
			}

            printf("%s\n", buffer);
		}
	}

	return 1;
}

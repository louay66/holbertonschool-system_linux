#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

/**
 * main - program tha build a socket listening
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */

int main(void)
{
	struct sockaddr_in addrport;
	int socketid;

	socketid = socket(AF_INET, SOCK_STREAM, 0);
	if (socketid < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(12345);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socketid, (struct sockaddr *)&addrport, sizeof(addrport)) < 0)
	{
		perror("bind failed");
		return (EXIT_FAILURE);
	}
	if (listen(socketid, 10) < 0)
	{
		perror("listen failed");
		return (EXIT_FAILURE);
	}
	printf("Server listening on port 12345\n");
	while (1)
		;
	return (EXIT_SUCCESS);
}

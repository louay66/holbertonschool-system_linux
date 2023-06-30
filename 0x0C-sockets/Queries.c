#include "http.h"

/**
 * main - program tha build a socket listening
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */

int main(void)
{
	return (setup_socket());
}

/**
 * parse_request - parse a request and get queries
 * @clientId: client identifier
 * @buf: request buffer
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */
int parse_request(int clientId, char *buf)
{
	char *delim = " \t\r\n";
	char *path, *dict, *key, *value, *saveptr, *querie;

	strtok(buf, delim);
	path = strtok(NULL, delim);
	path = strtok_r(path, "?", &saveptr);
	printf("Path: %s\n", path);
	querie = strtok_r(NULL, "&", &saveptr);
	while (querie)
	{
		key = strtok_r(querie, "=", &dict);
		value = strtok_r(NULL, "=", &dict);
		printf("Query: \"%s\" -> \"%s\"\n", key, value);
		querie = strtok_r(NULL, "&", &saveptr);
	}
	return (send_response(clientId, RESPONSE_200));
}

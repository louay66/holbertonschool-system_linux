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
 * parse_request - parse a request and get body
 * @clientId: client identifier
 * @buf: request buffer
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */
int parse_request(int clientId, char *buf)
{
	char *delim = " \t\r\n";
	char *path, *key, *value, *saveptr, *querie, *dict;
	int count = 0;

	querie = strtok_r(buf, delim, &saveptr);
	path = strtok_r(NULL, delim, &saveptr);
	printf("Path: %s\n", path);

	querie = strtok_r(NULL, "\n", &saveptr);
	while (querie)
	{
		if (count > 6)
		{
			key = strtok_r(querie, "=", &dict);
			value = strtok_r(dict, "&", &dict);
			printf("Body param: \"%s\" -> \"%s\"\n", key, value);
			querie = strtok_r(dict, "\n", &saveptr);
		}
		else
		{
			querie = strtok_r(NULL, "\n", &saveptr);
		}
		count++;
	}
	return (send_response(clientId, RESPONSE_200));
}

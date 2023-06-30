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
 * parse_request - parse a request and get heders
 * @clientId: client identifier
 * @buf: request buffer
 * Return: if successful return EXIT_SUCCESS otherwise EXIT_FAILURE
 */
int parse_request(int clientId, char *buf)
{
	char *delim = " \t\r\n";
	char *key, *value, *saveptr, *querie, *dict;
	int count = 0;

	querie = strtok_r(buf, delim, &saveptr);

	while (querie)
	{
		if (count > 2)
		{
			key = strtok_r(querie, ":", &dict);
			value = strtok_r(dict + 1, delim, &dict);
			printf("Header: \"%s\" -> \"%s\"\n", key, value);
			querie = strtok_r(dict, delim, &saveptr);
		}
		else
		{
			querie = strtok_r(NULL, delim, &saveptr);
		}
		count++;
	}
	return (send_response(clientId, RESPONSE_200));
}



#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int lines;

	lines = 1;

	printf("Archivo 1-------------\n");

	fd = open("lorem.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 2-------------\n");

	fd = open("41_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	printf("Archivo 3-------------\n");

	fd = open("41_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	fd = open("42_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 4 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	fd = open("42_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 5 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	fd = open("43_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 6 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	fd = open("43_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 7 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	fd = open("alternate_line_nl_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 8 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	fd = open("alternate_line_nl_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("Archivo 9 -------------\n%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	printf("Archivo 10-------------\n");

	fd = open("big_line_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 11-------------\n");

	fd = open("big_line_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);


	//********************************************************************************************* */

	printf("Archivo 12-------------\n");

	fd = open("empty.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 13-------------\n");

	fd = open("multiple_line_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 14-------------\n");

	fd = open("multiple_line_with_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 15-------------\n");

	fd = open("multiple_nlx5.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	//********************************************************************************************* */

	printf("Archivo 16-------------\n");

	fd = open("nl.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);

	return 0;
}

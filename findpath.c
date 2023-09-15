#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - finds a file in current path
 * @ac: argument count
 * @av: argument string array
 * Return: always 0
 */
int main(int ac, char **av)
{

struct stat file_st;
/* declare buffer for getting current path */
char buff[4096];
/* check if filename is specified correctly */
if (ac != 2)
{
	printf("%s\n", "correct usage is: ./which filename");
	return (0);
}
/* get current directory and append filename to it */
if (getcwd(buff, sizeof(buff)) == NULL)
	printf("%s\n", "get current directory fail");
strcat(buff, "/");
strcat(buff, av[1]);
/* find file using stat() and handle error */
if (stat(buff, &file_st) == -1)
	printf("%s\n", "file not found");
else
	printf("%s\n", "file found!!");
return (0);
}

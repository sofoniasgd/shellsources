#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

extern char **environ;
void printdir(char **directory, int len[]);
/**
 * main - prints every directory contained in value of key 'PATH'
 * @ac: argument count
 * @av: argumnet pointer
 * @env: enviroment pointer
 * Return: always 0
 *
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
char *path, *delim, *pathcpy;
int i, d;
/*declare directory pointer array and length array */
char **directory;
int *len;
size_t length;
(void)len;
/* get value of PATH parameter and handle error */
path = getenv("PATH");
if (path == NULL)
{
	printf("%s\n", "getenv failed!!");
	return (0);
}
/* find length of path and copy it to new variable */
length = strlen(path) + 1;
pathcpy = malloc(length * sizeof(char));

/* traverse path and assign start of new path to directory[] */
printf("path is: %s\n", path);
i = 0;
d = 1;
printf("d[0]==> %s\n", path);
while (*(path + i) != '\0')
{
	if (*(path + i) == ':')
	{
		printf("d[%i]==> %s\n", d, (path + i + 1));

		d++;
	}
	i++;
}
printf("directory assign done with %i directories\n", d);
/* create pointer array to store path directories */
directory = malloc(sizeof(char *));
delim = ":\n";
i = 0;
directory[i] = strtok(path, delim);
while (directory[i] != NULL)
{
	printf("d[%i] ==> %s\n", i, directory[i]);
	i++;
	directory[i] = strtok(NULL, delim);
}
printf("path is: %s\n", path);
return (0);
}




/**
 * printdir - prints directories from PATH variable
 * @directory: pointer to PATH variable
 * @len: length of each respective directory(no terminating null)
 * Return: none
 */
void printdir(char **directory, int len[])
{
int i, j;
i = 0;
/* print only first len[i] characters of directory[i] */
while (directory[i] != NULL)
{
	for (j = 0; j < len[i]; j++)
	{
		putchar(*(directory[i] + j));
	}
	printf("\n");
	i++;
}
}

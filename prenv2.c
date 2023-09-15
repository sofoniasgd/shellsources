#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
char *_getenv(const char *name);
/**
 * main - prints the address (3rd parameter) environ and env argument
 * @ac: argument count
 * @av: argumnet pointer
 * Return: always 0
 *
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
size_t n;
char *name, *match;
ssize_t ret;
/* get name to search from stdin and handle failure/if */
printf("%s\n $- ", "please enter the parameter name to search");
ret = getline(&name, &n, stdin);
if (ret == -1)
{
	printf("%s\n", "getline error !");
	return (0);
}
/* call the function and print result of search */
match = _getenv(name);
if (match == NULL)
{
	printf("%s\n", "no match!!");
	return (0);
}
printf("match found ===> %s\n", match);
return (0);
}
/**
 * _getenv - gets an enviroment variable matching "name"
 * @name: key to look for in enviroment
 * Return: pointer to value of key "name"
 */
char *_getenv(const char *name)
{
int i, k;
/* lopp to traverse all enviroment variables */
i = 0;
while (environ[i] != NULL)
{
	/* get key name length */
	k = 0;
	while (*(environ[i] + k) != '=')
	{
		k++;
	}
	/* compare name to environ[i] */
	/* if found, return starting address of value */
	if (strncmp(name, environ[i], k) == 0)
	{
		return ((environ[i] + k + 1));
	}
	i++;
}
/*didnt find enviroment variable = return NULL */
return (NULL);
}

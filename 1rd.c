#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * custok - custom implementationn of the strtok() function
 * @str: string to be parsed
 * @delim: delimiting byte
 * Return: string of the new token
 */
char *custok(char *str, const char *delim)
{
int i, j;
char * ret;
/* create a static pointer to store starting location of the function*/
static char *strc;
if (delim == NULL)
	{
	printf("%s", "error!");
	exit(0); }
/* both str and strc are NULL=> error!! */
if (strc == NULL && str == NULL)
	{
	printf("%s", "error!");
	exit(0); }
/*if str is NULL, str was specified on a previous call*/
if (str != NULL)
	strc = str;
i = 0;
printf("%c", *delim);
printf("%s", "before whileloop\n");
while (*(strc + i) != *delim || *(strc + i) != '\0')
{
	i++;
	printf("i- %i", i);
}
/* malloc for new token of length i */
printf("%s", "after whileloop\n");
ret = malloc((i + 1) * sizeof(char));
if (ret == NULL)
	exit(0);
/* strore the token to new location with ending '\0' */
for (j = 0; j < i; j++)
	*(ret + j) = *(strc + j);
*(ret + i) = '\0';
/* update new starting location to after the token */
strc = (strc + i + 1);
return (ret);
}
/**
 * main - prints entered lines
 *
 * Return: always 0
 */

int main(__attribute__((unused))int ac, __attribute__((unused))char *av[])
{
int i;
size_t n;
char *line, *words;
ssize_t ret;
char *delim;
printf("$ ");
words = NULL;
n = 0;
/* read a line of data from stdin to *line */
ret = getline(&line, &n, stdin);
if (ret == (-1))
	return (0);
i = 0;
delim = " \n";
/*print n and ret*/
printf("&n ==> %ld\n", n);
printf("ret ==> %ld\n", ret);
/* print the words from stdin */
words = strtok(line, delim);
while (words != NULL)
	{
	printf("- %i=> %s -\n", i, words);
	words = strtok(NULL, delim);
	i++;
	}
printf("%s\n", "end");
return (0);
}

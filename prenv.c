#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
/**
 * main - prints the environ variable
 * Return: always 0
 *
 */
int main(void)
{
int i;
i = 0;
while (environ[i] != NULL)
{
	printf("%s\n", environ[i]);
	i++;
}
return (0);
}

#include <stdio.h>
#include<stddef.h>
/**
 * main - prints all arguments
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
int i;
i = 0;
while (av[i] != NULL)
	{
	printf("%s\n", av[i]);
	i++;
	}
return (0);
}

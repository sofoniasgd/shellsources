#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
/**
 * main - prints the address (3rd parameter) environ and env argument
 * @ac: argument count
 * @av: argumnet pointer
 * @env: enviroment pointer
 * Return: always 0
 *
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
/* check the difference between third parameter */
/* of environ variable and env argument */

printf("--environ 3rd parameter(address)--\n%p\n", (void *)environ);
printf("--env 3rd parameter(address)--\n%p\n", (void *)env);
return (0);
}

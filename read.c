#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/**
 * main - uses read() to get string from stdin
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
  char* buff[1024];
int i;
  ssize_t len, nbyte;
  printf("$ ");
  len = read(FILENO_STDIN, buff, size_t nbyte);
return (0);
}

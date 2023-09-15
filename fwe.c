#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 * main - super simple shell- runs one command five times
 * Return: none
 */
int main(void)
{
int i, status;
pid_t current_pid;
char *args[] = {"ls", "-l", "/tmp", NULL};
char *ppath = "/bin/ls";
char *env[] = {NULL};
status = 0;

/* start a for loop for code that runs 5 times */
for (i = 0; i < 5; i++)
	{
	/* create fork and handle failure/if */
	current_pid = fork();
	if (current_pid == -1)
		{
		perror("fork failure!");
		exit(0); }
	/* in child process - execute command(handle failure too) */
	if (current_pid == 0)
		{
		printf("child process - %i\n", i);
		if (execve(ppath, args, env) == -1)
			perror("execute(execve) Error!");
		}
	/* in father process- wait for child */
	else if (current_pid > 0)
		{
		wait(&status);
		if (status > 0)
			perror("process termination error!");
		}
	}
return (0);
}

#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("Current pid is %u\n", my_pid);
    if (child_pid == 0)
    {
	    
        printf("%s\n", "child process stuff");
        printf("(%u) child pid\n", my_pid);
    }
    else
    {
        printf("%s\n", "father process stuff");
        printf("(%u) father pid \n", my_pid);
    }
    return (0);
}

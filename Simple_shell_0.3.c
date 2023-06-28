#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


#define PROMPT ":) "
#define BUFFER_SIZE 1024
#define MAX_ARGS 64


/**
 * main - Entry point for the program
 *
 * Return: 0 on success
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[MAX_ARGS];
pid_t pid;
int status;

while (1)
{
printf("%s", PROMPT);
if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
printf("\n");
break;
}
buffer[strlen(buffer) - 1] = '\0';

char *token;
int i = 0;
token = strtok(buffer, " ");
while (token != NULL && i < MAX_ARGS - 1)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;

if (access(args[0], X_OK) == -1)
{
printf("%s: command not found\n", args[0]);
continue;
}

pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}
return (0);
}

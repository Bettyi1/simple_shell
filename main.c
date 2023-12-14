#include "shell.h"
/**
 * main - function provides source code
 * @c: description
 * @env: description
 * Return: 0
 */
int main(int c, char **env)
{
	int status, input = 0;
	char *buffer = NULL,  *prompt = "Irungu$$$$$$ ", *arg[] = {NULL, NULL};
	size_t size = 0;
	ssize_t count_char;
	pid_t child_id;
	(void)c;
	while (true)
	{
		_shellp(prompt);
		count_char = getline(&buffer, &size, stdin);/*usr input*/
		if (count_char == -1)
		{
			_shellp("Exiting irungu$$.");
			free(buffer);
			exit(0);
		}
		while (buffer[input])
		{
			if (buffer[input] == '\n')
			buffer[input] = 0;
			++input;
		}
		arg[0] = strdup(buffer);
		child_id = fork();/*initialize fork()*/
		if (child_id == -1)
		{
			_shellp("fork");
			free(buffer);
			exit(0);
		}
		else if (child_id == 0)
		{
			if (execve(arg[0], arg, env) == -1)
			_shellp("command error\n");
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}

/*
** EPITECH PROJECT, =pdate=
** Project =pname=
** File description:
** Main file
*/

#include "main.h"
#include "gnl.h"

void init_env(shell_t *shell, char **nenv)
{
	int i = 0;
	int j = 0;
	int len = 0;

	for (int k = 0; nenv[k]; len++, k++);
	shell->env = malloc(sizeof(char *) * (len + 1));
	while (nenv[i] != NULL) {
		shell->env[i] = malloc(sizeof(char) * (my_strlen(nenv[i]) + 1));
		while (nenv[i][j] != '\0') {
			shell->env[i][j] = nenv[i][j];
			j++;
		}
		shell->env[i][j] = '\0';
		j = 0;
		i++;
	}
}

void disp_prompt(void)
{
	if (isatty(0))
		my_putstr("$> ");
}

void my_exec(shell_t *shell)
{
	shell->path = my_str_to_word_array(shell->buffer, ' ');
	//printf("path = %s\n", shell->path[0]);
	shell->my_fork = fork();
	if (shell->my_fork != 0) {
		wait(&(shell->my_fork));
		shell->my_fork = WTERMSIG(shell->my_fork);
	} else
		execve(shell->path[0], shell->path, shell->env);
	free(shell->path);
}

void read_input(shell_t *shell)
{
	size_t read = 0;
	int fd = 0;
	int i = 0;

	fd = getline(&shell->buffer, &read, stdin);
	for (; shell->buffer[i] != '\n' && shell->buffer[i] != '\0'; i++);
	shell->buffer[i] = '\0';
}

void shell_loop(shell_t *shell)
{
	disp_prompt();
	while (shell->status == -1) {
		read_input(shell);
		disp_prompt();
		my_exec(shell);
	}
}

int main(int ac, char **av, char **nenv)
{
	shell_t *shell = malloc(sizeof(shell_t));

	(void)ac;
	(void)av;
	shell->my_fork = 0;
	shell->status = -1;
	shell->buffer = malloc(sizeof(char) * 200);
	init_env(shell, nenv);
	shell_loop(shell);
	return (0);
}

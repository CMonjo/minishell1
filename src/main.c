/*
** EPITECH PROJECT, =pdate=
** Project =pname=
** File description:
** Main file
*/

#include "main.h"

// void display_shell(char **path)
// {
// 	int my_fork = 0;
//
// 	my_fork = fork();
// 	if (my_fork != 0) {
// 		wait(&my_fork);
// 		my_fork = WTERMSIG(my_fork);
// 	} else
// 		execve(path[0], path, NULL);
// }
//
// int main(int ac, char **av)
// {
// 	char **path = malloc(sizeof(char *) * 1000);
//
// 	if (ac < 2)
// 		return 84;
// 	path = my_str_to_word_array(av[1]);
// 	display_shell(path);
// 	return (0);
// }

void disp_prompt(void)
{
	if (isatty(0))
		my_putstr("$> ");
}


void prompt(shell_t *shell)
{
	disp_prompt();
	while (shell->status == -1 && read(0, shell->buffer, 200)) {
		disp_prompt();
		if (read(0, shell->buffer, 200)) {
			shell->path = my_str_to_word_array(shell->buffer, ' ');
			shell->my_fork = fork();
			if (shell->my_fork != 0) {
				wait(&shell->my_fork);
				shell->my_fork = WTERMSIG(shell->my_fork);
			} else
				execve(shell->path[0], shell->path, NULL);
		}
	}
}

void init_env(shell_t *shell, char **nenv)
{
	int i = 0;
	int j = 0;

	while (nenv[i][j] != '\0') {
		while (nenv[i][j] != '\0') {
			printf("ok\n");
			shell->env[i][j] = nenv[i][j];
			j++;
		}
		shell->env[i][j] = '\0';
		j = 0;
		i++;
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
	shell->env = malloc(sizeof(char *) * (strlen(nenv)));
	init_env(shell, nenv);
	//prompt(shell);

	for (int i = 0; shell->env[i] != NULL; i++) {
		write(1, shell->env[i], my_strlen(shell->env[i]));
		printf("\n");
	}
	return (0);
}

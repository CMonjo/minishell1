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
void prompt(shell_t *shell)
{
	while (1) {
		my_putstr("$> ");
		if (read(1, shell->buffer, 200))
			printf("Buff = %s\n", shell->buffer);
			shell->path = my_str_to_word_array(shell->buffer, '/');
			//free(buffer);
			shell->my_fork = fork();
			if (shell->my_fork != 0) {
				wait(&shell->my_fork);
				shell->my_fork = WTERMSIG(shell->my_fork);
			} else
				execve(shell->path[0], shell->path, NULL);

	}
}

void init_env(shell, char **nenv)
{

}

int main(int ac, char **av, char **nenv)
{
	shell_t *shell = malloc(sizeof(shell_t));

	(void)ac;
	(void)av;
	shell->my_fork = 0;
	shell->buffer = malloc(sizeof(char) * 200);
	init_env(shell, nenv);
	prompt(shell);

	// for (int i = 0; str[i] != NULL; i++) {
	// 	write(1, str[i], my_strlen(str[i]));
	// 	printf("\n");
	return (0);
}

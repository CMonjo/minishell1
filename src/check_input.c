/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Input file
*/

#include "main.h"

void display_env(shell_t *shell)
{
	for (int i = 0; shell->env[i] != NULL; i++) {
			printf("%s\n", shell->env[i]);
	}
}

void check_command(shell_t *shell, nenv_t *nenv)
{
	shell->filepath = malloc(sizeof(char) *
	(my_strlen(shell->command[0]) + 2));
	shell->filepath = shell->command[0];
	if (shell->filepath[0] != '/')
		shell->filepath = my_strcat("/", shell->filepath);
	for (int i = 0; nenv->path[i]; i++) {
		shell->path_bin = malloc(sizeof(char) *
		(my_strlen(nenv->path[i]) + my_strlen(shell->filepath) + 1));
		shell->path_bin = my_strcpy(shell->path_bin, nenv->path[i]);
		shell->path_bin = my_strcat(shell->path_bin, shell->filepath);
		if (access(shell->path_bin, X_OK) == 0)
			break;
		free(shell->path_bin);
		shell->path_bin = NULL;
	}
	if (shell->path_bin == NULL) {
		my_putstr(shell->command[0]);
		my_putstr(": Command not found.\n");
	} else
		my_exec(shell);
}

int check_path_command(shell_t *shell)
{
	if (shell->command[0][0] == '/') {
		if (access(shell->command[0], X_OK) == 0) {
			shell->path_bin = malloc(sizeof(char)
			* (my_strlen(shell->command[0]) + 1));
			shell->path_bin = shell->command[0];
			my_exec(shell);
		} else {
			my_putstr(shell->command[0]);
			my_putstr(": Command not found.\n");
		}
		return (1);
	}
	return (0);
}

int parse_command(shell_t *shell, nenv_t *nenv)
{
	int tmp = 0;

	tmp = read_command(shell);
	if (check_path_command(shell) == 1)
		return (0);
	if (tmp == 1)
		return (1);
	else if (tmp == 0)
		check_command(shell, nenv);
	return (0);
}

int read_input(shell_t *shell, nenv_t *nenv)
{
	size_t read = 0;
	int fd = 0;

	shell->filepath = NULL;
	shell->buffer = NULL;
	fd = getline(&shell->buffer, &read, stdin);
	if (fd == -1)
		return (1);
	if (shell->buffer[fd - 1] == '\n')
		shell->buffer[fd - 1] = '\0';
	if (shell->buffer[0] != '\0') {
		shell->command = my_str_to_word_array(shell->buffer, ' ');
		parse_command(shell, nenv);
	}
	return (0);
}

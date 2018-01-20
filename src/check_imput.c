/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Input file
*/

#include "main.h"

void my_exec(shell_t *shell)
{
	shell->my_fork = fork();
	if (shell->my_fork != 0) {
		wait(&(shell->my_fork));
		shell->my_fork = WTERMSIG(shell->my_fork);
	} else
		execve(shell->path_bin, shell->command, shell->env);
	for (int k = 0; shell->command &&
		shell->command[k]; free(shell->command[k]), k++);
}

void display_env(shell_t *shell)
{
	for (int i = 0; shell->env[i] != NULL; i++) {
			printf("%s\n", shell->env[i]);
	}
}

void check_command(shell_t *shell, nenv_t *nenv)
{
	shell->path_bin = NULL;
	shell->filepath = malloc(sizeof(char) * (my_strlen(shell->command[0]) + 2));
	shell->filepath = shell->command[0];
	if (shell->filepath[0] != '/')
		shell->filepath = my_strcat("/", shell->filepath);
	else {
		printf("hello\n");
	}
	for (int i = 0; nenv->path[i]; i++) {
		shell->path_bin = malloc(sizeof(char) * (my_strlen(nenv->path[i]) + my_strlen(shell->filepath) + 1));
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

int read_command(shell_t *shell)
{
	if (my_strcmp(shell->command[0], "exit") == 0) {
		if (shell->command[1] != NULL)
			shell->status = my_getnbr(shell->command[1]);
		printf("%d\n", shell->status);
		return (1);
	}
	if (my_strcmp(shell->command[0], "env") == 0) {
		display_env(shell);
		return (2);
	}
	return (0);
}

int parse_command(shell_t *shell, nenv_t *nenv)
{
	int tmp = 0;

	tmp = read_command(shell);
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


//
// int parse_command(shell_t *shell, nenv_t *nenv)
// {
// 	int tmp = 0;
//
// 	tmp = read_command(shell);
// 	if (tmp == 1)
// 		return (1);
// 	else if (tmp == 0 && shell->buffer[0] != '\0') {
// 		shell->command = my_str_to_word_array(shell->buffer, ' ');
// 		check_command(shell, nenv);
// 	}
// 	return (0);
// }
//
// int read_input(shell_t *shell, nenv_t *nenv)
// {
// 	size_t read = 0;
// 	int fd = 0;
//
// 	shell->filepath = NULL;
// 	shell->buffer = NULL;
// 	fd = getline(&shell->buffer, &read, stdin);
// 	if (fd == -1)
// 		return (1);
// 	if (shell->buffer[fd - 1] == '\n')
// 		shell->buffer[fd - 1] = '\0';
// 	parse_command(shell, nenv);
// 	return (0);
// }

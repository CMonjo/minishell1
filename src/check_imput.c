/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Input file
*/

#include "main.h"

void check_command(shell_t *shell, nenv_t *nenv)
{
	char *path = NULL;

	shell->filepath = malloc(sizeof(char) * (my_strlen(shell->command[0]) + 2));
	shell->filepath = shell->command[0];
	if (shell->filepath[0] != '/')
		shell->filepath = my_strcat("/", shell->filepath);
	//REGARDER SI JE TAPE LA COMMANDE /BIN/LS DIRECTEMENT POUR TESTER AVEC ACCESS DANS CONCAT
	for (int i = 0; nenv->path[i]; i++) {
		path = malloc(sizeof(char) * (my_strlen(nenv->path[i]) + my_strlen(shell->filepath) + 1));
		path = my_strcpy(path, nenv->path[i]);
		path = my_strcat(path, shell->filepath);
		if (access(path, X_OK) == 0)
			break;
		free(path);
		path = NULL;
	}
	if (path == NULL) {
		my_putstr(shell->command[0]);
		my_putstr(": Command not found.\n");
	} else
		my_exec(shell, nenv, path);
}

int read_command(shell_t *shell)
{
	if (my_strcmp(shell->buffer, "exit") == 0) {
		shell->status = 0;
		return (1);
	}
	return (0);
}

void read_input(shell_t *shell, nenv_t *nenv)
{
	size_t read = 0;
	int fd = 0;

	shell->buffer = NULL;
	fd = getline(&shell->buffer, &read, stdin);
	if (shell->buffer[fd - 1] == '\n')
		shell->buffer[fd - 1] = '\0';
	if (read_command(shell) == 1)
		return;
	if (shell->buffer[0] != '\0') {
		shell->command = my_str_to_word_array(shell->buffer, ' ');
		check_command(shell, nenv);
	}
}

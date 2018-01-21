/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** CD Builtin file
*/

#include "main.h"


void cd_deplacement_error(shell_t *shell, struct stat *statt)
{
	if (S_ISDIR(statt->st_mode) == 1) {
		if (chdir(shell->command[1]) == -1) {
			write(2, shell->command[1],
				my_strlen(shell->command[1]));
			write(2, ": Permission denied.\n", 21);
		}
	} else {
		write(2, shell->command[1], my_strlen(shell->command[1]));
		write(2, ": Not a directory.\n", 19);
	}
}

void cd_deplacement(shell_t *shell)
{
	struct stat statt;

	stat(shell->command[1], &statt);
	if (access(shell->command[1], F_OK) == 0)
		cd_deplacement_error(shell, &statt);
	else {
		write(2, shell->command[1], my_strlen(shell->command[1]));
		write(2, ": No such file or directory.\n", 29);
	}
}

void cd_check_error(shell_t *shell, nenv_t *nenv)
{
	if (shell->command[1][0] == '-' && shell->command[1][1] != 0)
		write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
	else if (shell->command[1][0] == '-')
		chdir(nenv->get_oldpwd);
	else
		cd_deplacement(shell);
}

void check_cd(shell_t *shell, nenv_t *nenv)
{
	if (shell->command[1] == NULL || shell->command[1][0] == '~')
		chdir(nenv->get_home);
	else if (shell->command[1] != NULL && shell->command[2] != NULL)
		write(2, "cd: Too many arguments.\n", 24);
	else
		cd_check_error(shell, nenv);
}

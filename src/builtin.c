/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Input file
*/

#include "main.h"

void check_exit_status(shell_t *shell)
{
	if (my_str_isnum(shell->command[1]) == 0)
		my_putstr("exit: Expression Syntax.\n");
	else if (my_str_isnum(shell->command[1]) == 2)
		my_putstr("exit: Badly formed number.\n");
	else {
		shell->status = my_getnbr(shell->command[1]);
		shell->status %= 256;
	}
}

void check_cd(shell_t *shell, nenv_t *nenv)
{
	printf("1 :  PWD = %s\nOLD = %s\n", nenv->get_pwd, nenv->get_oldpwd);
	struct stat statt;
	int get_new_env = 0;

	if (shell->command[1] == NULL || shell->command[1][0] == '~') {
		chdir(nenv->get_home);
		get_new_env = 0;
	}
	else if (shell->command[1] != NULL && shell->command[2] != NULL)
		write(2, "cd: Too many arguments.\n", 24);
	else if (shell->command[1][0] == '-' && shell->command[1][1] != 0)
		write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
	else if (shell->command[1][0] == '-') {
		chdir(nenv->get_oldpwd);
		get_new_env = 0;
	} else {
		stat(shell->command[1], &statt);
		if (access(shell->command[1], F_OK) == 0) {
			if (S_ISDIR(statt.st_mode) == 1) {
				if (chdir(shell->command[1]) == -1) {
					write(2, shell->command[1], my_strlen(shell->command[1]));
					write(2, ": Permission denied.\n", 21);
				}
			} else {
				write(2, shell->command[1], my_strlen(shell->command[1]));
				write(2, ": Not a directory.\n", 19);
			}
		} else {
			write(2, shell->command[1], my_strlen(shell->command[1]));
			write(2, ": No such file or directory.\n", 29);
		}
	}
	if (get_new_env == 0)
		get_env(shell, nenv);
	printf("2 :  PWD = %s\nOLD = %s\n", nenv->get_pwd, nenv->get_oldpwd);
}

int read_command_cd_env(shell_t *shell, nenv_t *nenv)
{
	if (my_strcmp(shell->command[0], "cd") == 0) {
		check_cd(shell, nenv);
		return (1);
	}
	if (my_strcmp(shell->command[0], "setenv") == 0) {
		printf("type = setenv\n");
		return (1);
	}
	if (my_strcmp(shell->command[0], "unsetenv") == 0) {
		printf("type = unsetenv\n");
		return (1);
	}
	return (0);
}

int read_command(shell_t *shell, nenv_t *nenv)
{
	if (my_strcmp(shell->command[0], "exit") == 0) {
		if (shell->command[1] != NULL)
			check_exit_status(shell);
		else
			shell->status = 0;
		return (1);
	}
	if (my_strcmp(shell->command[0], "env") == 0) {
		display_env(shell);
		return (2);
	}
	if (read_command_cd_env(shell, nenv) == 1)
		return (1);
	return (0);
}

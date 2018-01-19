/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Main file
*/

#include "main.h"

void disp_prompt(void)
{
	if (isatty(0))
		my_putstr("$> ");
}

void get_env(shell_t *shell, nenv_t *nenv)
{
	free_get_env(nenv);
	nenv->get_path = get_str_env(shell, nenv, "PATH=");
	if (nenv->get_path == NULL) {
		nenv->path = NULL;
	} else
		nenv->path = my_str_to_word_array(nenv->get_path, ':');
	free(nenv->get_path);
	nenv->get_home = get_str_env(shell, nenv, "HOME=");
	if (nenv->get_home == NULL) {
		nenv->home = NULL;
	} else
		nenv->home = my_str_to_word_array(nenv->get_home, '/');
	free(nenv->get_home);
	nenv->get_pwd = get_str_env(shell, nenv, "PWD=");
	if (nenv->get_pwd == NULL) {
		nenv->pwd = NULL;
	} else
		nenv->pwd = my_str_to_word_array(nenv->get_pwd, '/');
	free(nenv->get_pwd);
	nenv->get_oldpwd = get_str_env(shell, nenv, "OLDPWD=");
	if (nenv->get_oldpwd == NULL) {
		nenv->oldpwd = NULL;
	} else
		nenv->oldpwd = my_str_to_word_array(nenv->get_oldpwd, '/');
	free(nenv->get_oldpwd);

	// for (int i = 0; nenv->path[i] != NULL; i++) {
	// 	write(1, nenv->path[i], my_strlen(nenv->path[i]));
	// 	write(1, "\n", 1);
	// }
	// write(1, "\n\n", 2);
	// for (int i = 0; nenv->home[i] != NULL; i++) {
	// 	write(1, nenv->home[i], my_strlen(nenv->home[i]));
	// 	write(1, "\n", 1);
	// }
	// write(1, "\n\n", 2);
	// for (int i = 0; nenv->pwd[i] != NULL; i++) {
	// 	write(1, nenv->pwd[i], my_strlen(nenv->pwd[i]));
	// 	write(1, "\n", 1);
	// }
	// write(1, "\n\n", 2);
	// for (int i = 0; nenv->oldpwd && nenv->oldpwd[i] != NULL; i++) {
	// 	write(1, nenv->oldpwd[i], my_strlen(nenv->oldpwd[i]));
	// 	write(1, "\n", 1);
	// }
}

void my_exec(shell_t *shell)
{
	// shell->my_fork = fork();
	// if (shell->my_fork != 0) {
	// 	wait(&(shell->my_fork));
	// 	shell->my_fork = WTERMSIG(shell->my_fork);
	// } else {
	// 	execve(shell->command[0], shell->command, shell->env);
	// }
	for (int k = 0; shell->command &&
		shell->command[k]; free(shell->command[k]), k++);
}

void check_command(shell_t *shell)
{
	shell->filepath = malloc(sizeof(char) * (my_strlen(shell->command[0]) + 2));
	shell->filepath = shell->command[0];
	if (shell->filepath[0] != '/')
		shell->filepath = my_strcat("/", shell->filepath);
}

void read_input(shell_t *shell, nenv_t *nenv)
{
	size_t read = 0;
	int fd = 0;

	shell->buffer = NULL;
	fd = getline(&shell->buffer, &read, stdin);
	if (shell->buffer[fd - 1] == '\n')
		shell->buffer[fd - 1] = '\0';
	if (shell->buffer[0] != '\0') {
		shell->command = my_str_to_word_array(shell->buffer, ' ');
		check_command(shell);
	}
}

void shell_loop(shell_t *shell, nenv_t *nenv)
{
	while (shell->status == -1) {
		disp_prompt();
		read_input(shell, nenv);
		get_env(shell, nenv);
		//my_exec(shell);
		if (isatty(0) == 0)
			return;
	}
}

int main(int ac, char **av, char **new_env)
{
	shell_t *shell = malloc(sizeof(shell_t));
	nenv_t *nenv = malloc(sizeof(nenv_t));

	(void)ac;
	(void)av;
	shell->my_fork = 0;
	shell->status = -1;
	init_env(shell, new_env);
	shell_loop(shell, nenv);
	return (0);
}

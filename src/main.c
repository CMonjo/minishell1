/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Main file
*/

#include "main.h"

void free_shell(shell_t *shell, nenv_t *nenv)
{
	int j = 0;

	for (j = 0; nenv->path && nenv->path[j]; free(nenv->path[j]), j++);
	for (j = 0; nenv->home && nenv->home[j]; free(nenv->home[j]), j++);
	for (j = 0; nenv->pwd && nenv->pwd[j]; free(nenv->pwd[j]), j++);
	for (j = 0; nenv->oldpwd && nenv->oldpwd[j]; free(nenv->oldpwd[j]), j++);
	for (j = 0; shell->env && shell->env[j]; free(shell->env[j]), j++);
	if (shell->buffer != NULL)
		free(shell->buffer);
	if (shell->filepath != NULL)
		free(shell->filepath);
}

void disp_prompt(void)
{
	if (isatty(0)) {
		my_putstr(getcwd(NULL, 0));
		my_putstr(" $> ");
	}
}

int main(int ac, char **av, char **new_env)
{
	shell_t *shell = malloc(sizeof(shell_t));
	nenv_t *nenv = malloc(sizeof(nenv_t));

	(void)ac;
	(void)av;
	shell->my_fork = 0;
	shell->status = 260;
	while (shell->status == 260) {
		if (init_env(shell, new_env) == 1)
			break;
		disp_prompt();
		get_env_path_home(shell, nenv);
		if (read_input(shell, nenv) == 1)
			break;
	}
	free_shell(shell, nenv);
	if (shell->status == 260)
		shell->status = 0;
	return (shell->status);
}

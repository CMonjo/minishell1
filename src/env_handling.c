/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Main file
*/

#include "main.h"

void init_struct_env(nenv_t *nenv)
{
	nenv->i = 0;
	nenv->j = 0;
	nenv->k = 0;
}

void init_env(shell_t *shell, char **new_env)
{
	int len = 0;

	for (int k = 0; new_env[k]; len++, k++);
	shell->env = malloc(sizeof(char *) * (len + 1));
	if (shell->env == NULL)
		printf("funct pour sortir de la loop\n");
	for (int i = 0, j = 0; new_env[i]; i++, j = 0) {
		shell->env[i] = malloc(sizeof(char) * (my_strlen(new_env[i]) + 1));
		if (shell->env[i] == NULL)
			printf("funct pour sortir de la loop\n");
		for (; new_env[i][j] != '\0'; j++)
			shell->env[i][j] = new_env[i][j];
		shell->env[i][j] = '\0';
	}
	shell->env[len] = NULL;
}

void check_env(shell_t *shell, nenv_t *nenv, char *my_env)
{
	while (shell->env[nenv->i] && shell->env[nenv->i][nenv->j] != '=') {
		if (shell->env[nenv->i][nenv->j] == my_env[nenv->k]) {
			nenv->j++;
			nenv->k++;
		} else {
			nenv->i++;
			nenv->j = 0;
			nenv->k = 0;
		}
	}
}

char *get_str_env(shell_t *shell, nenv_t *nenv, char *my_env)
{
	char *newstr = NULL;

	init_struct_env(nenv);
	check_env(shell, nenv, my_env);
	if (shell->env[nenv->i] != NULL) {
		newstr = malloc(sizeof(char) *
		(my_strlen(shell->env[nenv->i]) + 1));
		for (int l = 0; l != my_strlen(shell->env[nenv->i]);
		newstr[l] = '\0', l++);
		for (nenv->j++, nenv->k = 0; shell->env[nenv->i] &&
			shell->env[nenv->i][nenv->j]
			!= '\0'; nenv->k++, nenv->j++)
			newstr[nenv->k] = shell->env[nenv->i][nenv->j];
	}
	if (newstr) {
		return (newstr);
	}
	return (NULL);
}

void free_get_env(nenv_t *nenv)
{
	static int i = 0;
	int j = 0;

	if (i == 0)
		i = 1;
	else {
		for (j = 0; nenv->path &&
			nenv->path[j]; free(nenv->path[j]), j++);
		for (j = 0; nenv->home &&
			nenv->home[j]; free(nenv->home[j]), j++);
		for (j = 0; nenv->pwd &&
			nenv->pwd[j]; free(nenv->pwd[j]), j++);
		for (j = 0; nenv->oldpwd &&
			nenv->oldpwd[j]; free(nenv->oldpwd[j]), j++);
	}
}

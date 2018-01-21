/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** env handling file
*/

#include "main.h"

int init_env(shell_t *shell, char **new_env)
{
	int len = 0;

	for (int k = 0; new_env[k]; len++, k++);
	if (!(shell->env = malloc(sizeof(char *) * (len + 1))))
		return (shell->status = 0);
	for (int i = 0, j = 0; new_env[i]; i++, j = 0) {
		if (!(shell->env[i] = malloc(sizeof(char)
		* (my_strlen(new_env[i]) + 1))))
			return (shell->status = 0);
		for (; new_env[i][j] != '\0'; j++)
			shell->env[i][j] = new_env[i][j];
		shell->env[i][j] = '\0';
	}
	shell->env[len] = NULL;
	return (0);
}

void free_get_env(nenv_t *nenv)
{
	static int i = 0;
	int j = 0;

	if (i == 0)
		i = 1;
	else {
		free(nenv->get_oldpwd);
		free(nenv->get_pwd);
		free(nenv->get_home);
		free(nenv->get_path);
		for (j = 0; nenv->path &&
			nenv->path[j]; free(nenv->path[j]), j++);
	}
}

void get_env(shell_t *shell, nenv_t *nenv)
{
	free_get_env(nenv);
	nenv->get_path = get_str_env(shell, nenv, "PATH=");
	if (nenv->get_path == NULL) {
		nenv->path = NULL;
	} else
		nenv->path = my_str_to_word_array(nenv->get_path, ':');
	nenv->get_home = get_str_env(shell, nenv, "HOME=");
	nenv->get_pwd = get_str_env(shell, nenv, "PWD=");
	nenv->get_oldpwd = get_str_env(shell, nenv, "OLDPWD=");
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

	nenv->i = 0;
	nenv->j = 0;
	nenv->k = 0;
	check_env(shell, nenv, my_env);
	if (shell->env[nenv->i] != NULL) {
		newstr = malloc(sizeof(char) *
		(my_strlen(shell->env[nenv->i]) + 1));
		for (int tmp = 0; tmp != my_strlen(shell->env[nenv->i]);
		newstr[tmp] = '\0', tmp++);
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

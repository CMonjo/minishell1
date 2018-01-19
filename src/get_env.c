/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** get env file
*/

#include "main.h"

void get_env_both_pwd(shell_t *shell, nenv_t *nenv)
{
	nenv->get_pwd = get_str_env(shell, nenv, "PWD=");
	if (nenv->get_pwd == NULL) {
		nenv->pwd = NULL;
	} else
		nenv->pwd = my_str_to_word_array(nenv->get_pwd, '/');
	nenv->get_oldpwd = get_str_env(shell, nenv, "OLDPWD=");
	if (nenv->get_oldpwd == NULL) {
		nenv->oldpwd = NULL;
	} else
		nenv->oldpwd = my_str_to_word_array(nenv->get_oldpwd, '/');
	free(nenv->get_oldpwd);
	free(nenv->get_pwd);
	free(nenv->get_home);
	free(nenv->get_path);
}

void get_env_path_home(shell_t *shell, nenv_t *nenv)
{
	free_get_env(nenv);
	nenv->get_path = get_str_env(shell, nenv, "PATH=");
	if (nenv->get_path == NULL) {
		nenv->path = NULL;
	} else
		nenv->path = my_str_to_word_array(nenv->get_path, ':');
	nenv->get_home = get_str_env(shell, nenv, "HOME=");
	if (nenv->get_home == NULL) {
		nenv->home = NULL;
	} else
		nenv->home = my_str_to_word_array(nenv->get_home, '/');
	get_env_both_pwd(shell, nenv);
}

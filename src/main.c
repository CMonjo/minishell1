/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Main file
*/

#include "main.h"

void free_get_env(nenv_t *nenv)
{
	static int i = 0;

	if (i == 0)
		i = 1;
	else if (nenv->path) {
		for (int k = 0; nenv->path[k]; free(nenv->path[k]), k++);
	}
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

void disp_prompt(void)
{
	if (isatty(0))
		my_putstr("$> ");
}

void init_struct_env(nenv_t *nenv)
{
	nenv->i = 0;
	nenv->j = 0;
	nenv->k = 0;
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

void get_env(shell_t *shell, nenv_t *nenv)
{
	init_struct_env(nenv);
	free_get_env(nenv);
	nenv->get_path = get_str_env(shell, nenv, "PATH=");
	if (nenv->get_path == NULL) {
		nenv->path = NULL;
	} else
		nenv->path = my_str_to_word_array(nenv->get_path, ':');
	free(nenv->get_path);
	init_struct_env(nenv);
	nenv->get_home = get_str_env(shell, nenv, "HOME=");
	if (nenv->get_home == NULL) {
		nenv->home = NULL;
	} else
		nenv->home = my_str_to_word_array(nenv->get_home, '/');
	free(nenv->get_home);
	init_struct_env(nenv);
	nenv->get_pwd = get_str_env(shell, nenv, "PWD=");
	if (nenv->get_pwd == NULL) {
		nenv->pwd = NULL;
	} else
		nenv->pwd = my_str_to_word_array(nenv->get_pwd, '/');
	free(nenv->get_pwd);
	init_struct_env(nenv);

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
	// for (int i = 0; nenv->oldpwd[i] != NULL; i++) {
	// 	write(1, nenv->oldpwd[i], my_strlen(nenv->oldpwd[i]));
	// 	write(1, "\n", 1);
	// }
}

void my_exec(shell_t *shell)
{
	shell->command = my_str_to_word_array(shell->buffer, ' ');
	//CONCAT LA COMMANDE AVEC UN '/' AU DEBUT
	printf("%s\n", shell->command[0]);
	printf("%s\n", shell->command[1]);
	// shell->my_fork = fork();
	// if (shell->my_fork != 0) {
	// 	wait(&(shell->my_fork));
	// 	shell->my_fork = WTERMSIG(shell->my_fork);
	// } else {
	// 	execve(shell->command[0], shell->command, shell->env);
	// }
	if (shell->command) {
		for (int k = 0; shell->command[k]; free(shell->command[k]), k++);
	}
}

void read_input(shell_t *shell)
{
	size_t read = 0;
	int fd = 0;

	shell->buffer = NULL;
	fd = getline(&shell->buffer, &read, stdin);
	// FAIRE ATTENTION AUX TESTS MOULI QUI SE FONT EN TTY ET QUI N'A PAS DE \0 && \n
	//if (shell->buffer[fd - 1] == '\n')
		shell->buffer[fd - 1] = '\0';
}

void shell_loop(shell_t *shell, nenv_t *nenv)
{
	while (shell->status == -1) {
		disp_prompt();
		read_input(shell);
		get_env(shell, nenv);
		my_exec(shell);
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

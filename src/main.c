/*
** EPITECH PROJECT, 2017
** Project minishell1
** File description:
** Main file
*/

#include "main.h"

void init_env(shell_t *shell, char **nenv)
{
	int len = 0;

	for (int k = 0; nenv[k]; len++, k++);
	shell->env = malloc(sizeof(char *) * (len + 1));
	if (shell->env == NULL)
		printf("funct pour sortir de la loop\n");
	for (int i = 0, j = 0; nenv[i]; i++, j = 0) {
		shell->env[i] = malloc(sizeof(char) * (my_strlen(nenv[i]) + 1));
		if (shell->env[i] == NULL)
			printf("funct pour sortir de la loop\n");
		for (; nenv[i][j] != '\0'; j++)
			shell->env[i][j] = nenv[i][j];
		shell->env[i][j] = '\0';
	}
}

void disp_prompt(void)
{
	if (isatty(0))
		my_putstr("$> ");
}

char *get_str_env(shell_t *shell, char *my_env)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *newstr;

	//A METTRE A LA NORME
	//CAS : si j'ai pas trouvé l'env que je voulais je vais return quelque chose de mauvais (segfault)
	//SI WHILE AVEC != NULL -> segfault à voir demain
	printf("%s\n", my_env);
	while (shell->env[i][j] != '=' || shell->env[i] != NULL) {
		if (shell->env[i][j] == my_env[k]) {
			j++;
			k++;
		} else {
			i++;
			j = 0;
			k = 0;
		}
	}
	newstr = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 1));
	k = 0;
	j++;
	while (shell->env[i][j] != '\0') {
		newstr[k] = shell->env[i][j];
		k++;
		j++;
	}
	printf("ok\n");
	return (newstr);
}

void get_env(shell_t *shell)
{
	char *new_env = get_str_env(shell, "PATH=");
	shell->path = my_str_to_word_array(new_env, ':');
	// char *new_env = get_str_env(shell, "HOME=");
	// shell->home = my_str_to_word_array(new_env, '/');
	// char *new_env = get_str_env(shell, "PWD=");
	// shell->pwd = my_str_to_word_array(new_env, '/');
	// char *new_env = get_str_env(shell, "OLDPWD=");
	// shell->oldpwd = my_str_to_word_array(new_env, '/');
	//CONCAT CHAQUE ENV AVEC UN '/' A LA FIN
	for (int i = 0; shell->path[i] != NULL; i++) {
		write(1, shell->path[i], my_strlen(shell->path[i]));
		printf("\n");
	}
}

void my_exec(shell_t *shell)
{
	shell->command = my_str_to_word_array(shell->buffer, ' ');
	shell->my_fork = fork();
	if (shell->my_fork != 0) {
		wait(&(shell->my_fork));
		shell->my_fork = WTERMSIG(shell->my_fork);
	} else {
		execve(shell->command[0], shell->command, shell->env);
	}
	free(shell->command);
}

void read_input(shell_t *shell)
{
	size_t read = 0;
	int fd = 0;

	// FAIRE ATTENTION AUX TESTS MOULI QUI SE FONT EN TTY ET QUI N'A PAS DE \0 && \n
	shell->buffer = NULL;
	fd = getline(&shell->buffer, &read, stdin);
	shell->buffer[fd - 1] = '\0';
}

void shell_loop(shell_t *shell)
{
	while (shell->status == -1) {
		disp_prompt();
		read_input(shell);
		get_env(shell);
		my_exec(shell);
	}
}

int main(int ac, char **av, char **nenv)
{
	shell_t *shell = malloc(sizeof(shell_t));

	(void)ac;
	(void)av;
	shell->my_fork = 0;
	shell->status = -1;
	init_env(shell, nenv);
	shell_loop(shell);
	return (0);
}

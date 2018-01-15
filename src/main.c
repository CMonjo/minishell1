/*
** EPITECH PROJECT, =pdate=
** Project =pname=
** File description:
** Main file
*/

#include "main.h"

// int calc_args(char **path)
// {
// 	int i = 0;
//
// 	while (path[i] != NULL)
// 		i++;
// 	i -= 1;
// 	return (i);
// }
//
// void execute_prog(int my_fork)
// {
// 	printf("Program terminated.\n");
// 	printf("Status:");
// 	if (my_fork == 11)
// 		printf(" Segmentation Fault\n");
// 	else
// 		printf(" OK\n");
// }
//
// void display_shell(int nb_arg, char **path)
// {
// 	int my_fork = 0;
// 	printf("program name: %s\n", path[0]);
// 	printf("Nb args: %d\n", nb_arg);
// 	printf("PID: %d\n", getpid());
// 	my_fork = fork();
// 	if (my_fork != 0) {
// 		wait(&my_fork);
// 		my_fork = WTERMSIG(my_fork);
// 		execute_prog(my_fork);
// 	} else {
// 		printf("Child PID: %d\n", getpid());
// 		execve(path[0], path, NULL);
// 	}
// }
//
// int main(int ac, char **av)
// {
// 	int nb_arg = 0;
// 	char **path = malloc(sizeof(char *) * 1000);
//
// 	if (ac < 2)
// 		return 84;
// 	path = my_str_to_word_array(av[1]);
// 	nb_arg = calc_args(path);
// 	display_shell(nb_arg, path);
// 	return (0);
// }


int main()
{
	int rd = 0;
	int my_fork = 0;
	char *buffer = malloc(sizeof(char) * 200);

	while (1) {
		my_putstr(">");
		if (rd == read(1, buffer, 200))
			printf("buffer\n");
			my_fork = fork();
			if (my_fork != 0) {
				wait(&my_fork);
				my_fork = WTERMSIG(my_fork);
			} else
				execve(buffer, &buffer, NULL);
	}
	return (0);
}

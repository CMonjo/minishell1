/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <fcntl.h>
	#include "tools.h"
	#include "shell.h"
	char *my_strcat(char *dest, char const *src);
	void init_env(shell_t *shell, char **new_env);
	void check_env(shell_t *shell, nenv_t *nenv, char *my_env);
	char *get_str_env(shell_t *shell, nenv_t *nenv, char *my_env);
	void free_get_env(nenv_t *nenv);
	void init_struct_env(nenv_t *nenv);
#endif

/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <fcntl.h>
	#include "tools.h"
	#include "shell.h"
	void free_shell(shell_t *shell, nenv_t *nenv);
	void disp_prompt(void);
	void my_exec(shell_t *shell);
	void check_command(shell_t *shell, nenv_t *nenv);
	int read_input(shell_t *shell, nenv_t *nenv);
	void init_struct_env(nenv_t *nenv);
	int init_env(shell_t *shell, char **new_env);
	void check_env(shell_t *shell, nenv_t *nenv, char *my_env);
	char *get_str_env(shell_t *shell, nenv_t *nenv, char *my_env);
	void free_get_env(nenv_t *nenv);
	void get_env(shell_t *shell, nenv_t *nenv);
	void check_exit_status(shell_t *shell);
	int read_command(shell_t *shell, nenv_t *nenv);
	void display_env(shell_t *shell);
#endif

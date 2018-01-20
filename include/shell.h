/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef _SHELL_H_
	#define _SHELL_H_
	#include "main.h"
	typedef struct shell_s {
		int status;
		int my_fork;
		char *buffer;
		char **env;
		char **command;
		char *filepath;
		char *path_bin;
	} shell_t;

	typedef struct nenv_s {
		int i;
		int j;
		int k;
		char **path;
		char **home;
		char **pwd;
		char **oldpwd;
		char *get_path;
		char *get_home;
		char *get_pwd;
		char *get_oldpwd;
	} nenv_t;
#endif

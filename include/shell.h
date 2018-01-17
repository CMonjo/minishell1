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
		char **path;
		char **home;
		char **pwd;
		char **oldpwd;
		char **env;
		char **command;
	} shell_t;
#endif

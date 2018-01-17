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
		int my_fork;
		char *buffer;
		char **path;
		char **env;
	} shell_t;
#endif

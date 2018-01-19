/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** Copies a string into another
*/

#include "main.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (i <= my_strlen(src)) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

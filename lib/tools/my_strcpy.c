/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** Copies a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int cpt = 0;

	while (cpt <= my_strlen(src)) {
		dest[cpt] = src[cpt];
		cpt += 1;
	}
	dest[cpt] = '\0';
	return (dest);
}

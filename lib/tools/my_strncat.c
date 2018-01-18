/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** put a src string after a dest string for only n characters.
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
	int len = my_strlen(dest);
	int i = 0;

	while (i < nb && src[i] != '\0') {
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

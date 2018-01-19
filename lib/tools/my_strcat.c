/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenates two strings
*/

#include "main.h"

char	*my_strcat(char *dest, char const *src)
{
	char *new = malloc(sizeof(char) *
	(my_strlen(dest) + my_strlen(src) + 1));
	int i = 0;
	int e = 0;

	for (; dest[e] != '\0';) {
		if (dest[e] != ' ') {
			new[e] = dest[e];
			e++;
		}
	}
	while (src[i] != '\0') {
		if (src[i] != ' ') {
			new[e] = src[i];
			e++;
		}
		i++;
	}
	new[e] = '\0';
	return (new);
}

/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenates two strings
*/

#include "main.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i += 1;
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i + 1] = '\0';
	printf("dest = %s\n", dest);
	return (dest);
}

/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenates two strings
*/

#include "main.h"

// char *my_strcat(char *dest, char const *src)
// {
// 	int i = 0;
// 	int j = 0;
// 	char *new_str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
//
// 	for (int k = 0; dest[k]; new_str[k] = dest[k], k++);
// 	printf("src = [%s]\n", src);
// 	printf("new str [%s]\ndest = [%s]\n", new_str, dest);
// 	printf("ok\n");
// 	while (new_str[i] != '\0')
// 		i += 1;
// 	while (src[j] != '\0') {
// 		new_str[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	new_str[i + 1] = '\0';
// 	//free(dest);
// 	printf("new_str = %s\n", new_str);
// 	return (new_str);
// }

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

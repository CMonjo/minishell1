/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Concat str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int wordcount(char const *str)
{
	int word = 0;
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))
			if (!((str[i + 1] >= 65 && str[i + 1] <= 90) || (str[i + 1] >= 97 && str[i + 1] <= 122)  || (str[i + 1] >= 48 && str[i + 1] <= 57)))
				word++;
		i++;
	}
	return (word);
}

char **fill_letters(char **position_string, char const *str)
{
	int	x = 0;
	int	y = 0;
	int	i = 0;

	while (str[i] != '\0') {
		position_string[y] = malloc(sizeof(char) * (my_strlen(str)));
		while (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= '0' && str[i] <= '9') || str[i] == '/' || str[i] == '_' || str[i] == '-' || str[i] == '.')) {
			i++;
			if (str[i] == '\0') {
				position_string[y] = NULL;
				return (position_string);
			}
		}
		while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '/'
		|| str[i] == '_' || str[i] == '-' || str[i] == '.') {
			position_string[y][x] = str[i];
			x++;
			i++;
		}
		position_string[y][x] = '\0';
		y++;
		x = 0;
	}
	position_string[y] = NULL;
	return (position_string);
}

char **my_str_to_word_array(char const *str)
{
	char **position_string;
	int counted_word;

	counted_word = wordcount(str);
	position_string = malloc(sizeof(char *) * counted_word);
	position_string = fill_letters(position_string, str);
	return (position_string);
}

/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Concat str
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

int how_many_words(char *str, char separator)
{
	int word = 1;
	int i = 0;

	for (;str[i] == separator; i++);
	for (;str[i] != '\0'; i++) {
		if (str[i] == separator && str[i + 1]
			!= separator && str[i + 1] != '\0')
			word++;
	}
	return (word);
}

int count_word(char *str, char separator)
{
	static int i = 0;
	int k = 0;

	for (; str[i] == separator; i++);
	for (; str[i] && str[i] != separator; i++, k++);
	if (str[i])
		i++;
	return (k);
}

char **fill_str(char **new_str, char *str, char separator)
{
	int y = 0;

	for (int x = 0, i = 0, word = 0; str[i] != '\0'; y++, x = 0) {
		word = count_word(str, separator);
		new_str[y] = malloc(sizeof(char) * (word + 1));
		word = 0;
		for (; str[i] == separator; i++);
		for (;str[i] && str[i] != separator;
			new_str[y][x] = str[i], x++, i++);
		if (str[i])
			i++;
		for (; str[i] == separator; i++);
		new_str[y][x] = '\0';
	}
	new_str[y] = NULL;
	return (new_str);
}

char **my_str_to_word_array(char *str, char separator)
{
	int nb_word = how_many_words(str, separator);
	char **new_str;

	new_str = malloc(sizeof(char *) * (nb_word + 1));
	new_str = fill_str(new_str, str, separator);
	return (new_str);
} 

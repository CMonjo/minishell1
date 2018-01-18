/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** replace a dest str by a src str only for n characters.
*/

char *my_strncpy(char *dest, char const *src, int nb)
{
	int i = 0;

	while (i < nb && dest[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/

int		my_strncmp(char const *s1, char const *s2, int n)
{
	int		i = 0;

	if (!s1 || !s2 || n == 0)
		return (0);
	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}

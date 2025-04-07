/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:23:41 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/31 15:15:52 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_bzero:
** Sets the first n bytes of the memory
area pointed to by s to zero.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n != 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

/*
** ft_strlen:
** Returns the length
of the string s.
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
** ft_strjoin:
** Concatenates two strings s1 and s2
into a new allocated string.
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (s1 && s1[j] != '\0')
		result[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

/*
** ft_calloc:
** Allocates memory for an array
of count elements of
size bytes each and sets it to zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

/*
** ft_strchr:
** Locates the first occurrence
of c in the string s.
** Returns a pointer to the located
character or NULL if not found.
*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

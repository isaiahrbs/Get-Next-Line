/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:24:42 by irobinso          #+#    #+#             */
/*   Updated: 2024/10/31 15:27:04 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* Combines buffer and buf into a new string,
frees buffer, and returns the new string.*/

char	*ft_free_buffer(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

/* Advances buffer past the newline character
and returns the remaining data as new_buffer.*/
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i + j])
		j++;
	new_buffer = malloc(sizeof(char) * (j + 1));
	if (!new_buffer)
		return (free(buffer), NULL);
	j = -1;
	while (buffer[i + ++j] != '\0')
		new_buffer[j] = buffer[i + j];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

/*Extracts a line (up to and including '\n')
from buffer and returns it as a new string.*/
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

/*
 * Reads data from the specified file descriptor (fd) into
  a temporary buffer.
 * This data is appended to the result string (res) until:
 * - A newline character (\n) is encountered, or
 * - The end of the file (EOF) is reached.
 *
 * The function handles dynamic memory allocation for both
 *  the buffer and the result string.
 * If a newline is found, the function stops reading further and
 *  returns the updated result string.
 * If an error occurs during reading, the function returns NULL
 *  and frees allocated memory.
 ! in short, takes chunk by chunk and see if there is a newline.
 */
char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		read_byte;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!res)
		res = ft_calloc(1, sizeof(char));
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), NULL);
		buffer[read_byte] = '\0';
		res = ft_free_buffer(res, buffer);
		if (!res)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

/* Main function to get the next line from fd 
(fd which is the file that you call)
: reads data, extracts the next line,
 and updates the buffer.*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h> // For open()
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
	// Open test file in read-only mode
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
	// Call get_next_line until it returns NULL
    {
        printf("Line: %s", line);
        free(line);
		// Free the memory allocated by get_next_line
    }

    close(fd); // Close the file after reading
    return 0;
}*/

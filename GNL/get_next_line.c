/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ily4s <ily4s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:30:12 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/11/04 13:13:07 by ily4s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	find_new_line(const char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **stash, ssize_t data_size)
{
	char	*left;
	char	*line;
	int		new_line;

	new_line = find_new_line(*stash);
	if (new_line == -1 && !data_size)
		new_line = (int)ft_strlen(*stash) - 1;
	line = cut_str(*stash, new_line);
	if (!line)
		return (NULL);
	left = ft_strdup(*stash + new_line + 1);
	if (!left)
	{
		free(line);
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = left;
	return (line);
}

static int	read_buffer(int fd, char **stash, ssize_t *data_size)
{
	char	*buffer;
	char	*old_stash;

	*data_size = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (find_new_line(*stash) == -1 && *data_size)
	{
		*data_size = read(fd, buffer, BUFFER_SIZE);
		if (*data_size == -1)
		{
			free(buffer);
			*stash = NULL;
			return (0);
		}
		buffer[*data_size] = '\0';
		old_stash = *stash;
		*stash = ft_strjoin(*stash, buffer);
		free(old_stash);
	}
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	ssize_t		data_size;

	if (!read_buffer(fd, &stash[fd], &data_size))
		return (NULL);
	if (!stash[fd] || !stash[fd][0])
		return (NULL);
	return (extract_line(&stash[fd], data_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:14:43 by abiru             #+#    #+#             */
/*   Updated: 2022/11/30 23:15:26 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	*get_next(char *tmp)
{
	char	*nl;
	char	*next;
	int		i;

	if (*tmp == '\0' || !ft_strchr(tmp, '\n'))
	{
		free(tmp);
		return (NULL);
	}
	nl = ft_strchr(tmp, '\n');
	next = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - nl_pos(tmp) + 1));
	if (!next)
	{
		free(tmp);
		return (NULL);
	}
	i = 0;
	while (nl[++i])
		next[i - 1] = nl[i];
	next[i - 1] = 0;
	free(tmp);
	return (next);
}

char	*get_line(char *tmp)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (*tmp == '\0')
		return (NULL);
	line = (char *)malloc(sizeof(char) * nl_pos(tmp) + 2);
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] && tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_line(int fd, char *fd_table)
{
	int		char_read;
	char	*nl;
	char	*buffer;

	char_read = 1;
	if (read(fd, 0, 0) == -1)
	{
		free(fd_table);
		return (NULL);
	}
	nl = ft_strchr(fd_table, '\n');
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!nl && char_read > 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		buffer[char_read] = 0;
		fd_table = join_free(fd_table, buffer);
		nl = ft_strchr(buffer, '\n');
	}
	free(buffer);
	return (fd_table);
}

char	*get_next_line(int fd)
{
	static char	*fd_table[256];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fd_table[fd])
		fd_table[fd] = ft_strdup("");
	fd_table[fd] = read_line(fd, fd_table[fd]);
	if (!fd_table[fd])
		return (NULL);
	line = get_line(fd_table[fd]);
	fd_table[fd] = get_next(fd_table[fd]);
	return (line);
}

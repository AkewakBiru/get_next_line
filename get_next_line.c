/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:34:35 by abiru             #+#    #+#             */
/*   Updated: 2022/11/13 14:20:36 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef
#define BUFFER_SIZE 42
#endif

char *join_char()
{

}

char *line(int fd)
{
	char	*read_line;
	char	*buffer;
	int		nl_pos;

	read_line = NULL;
	buffer = calloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	nl_pos = strchr(buffer, '\n');
	while (!nl_pos)
	{

	}
	return (read_line);
}


char	*get_next_line(int fd)
{
	char	*fd_table[256];
	char	*file_read;
	char	*line;

	if (fd < 0)
		return (NULL);

	read_line(fd, line);
}
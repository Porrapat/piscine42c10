/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

#include "ft_tail.h"
#include "ft_tail_utils.h"
#include "ft_console_io.h"
#include "ft_strncpy.h"

int	open_file(char *executable, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		show_error(executable, path);
	return (fd);
}

int	close_file(char *executable, char *path, int fd)
{
	int	result;

	result = close(fd);
	if (result < 0)
		show_error(executable, path);
	return (result);
}

void	show_error(char *executable, char *path)
{
	if (errno == 0)
		return ;
	write_str_err(basename(executable));
	write_str_err(": ");
	write_str_err(path);
	write_str_err(": ");
	write_str_err(strerror(errno));
	write_str_err("\n");
	errno = 0;
}

char	*read_full(int fd, unsigned long *total_read)
{
	unsigned int	byte_read;
	char			buffer[DEFAULT_BUFFER_SIZE];
	char			*old;
	char			*dest;

	*total_read = 0;
	dest = malloc(0);
	byte_read = read(fd, buffer, DEFAULT_BUFFER_SIZE);
	while (byte_read != 0)
	{
		if (errno != 0)
			return (dest);
		old = dest;
		dest = malloc((*total_read + byte_read) * sizeof(char));
		if (!dest)
			return (0);
		ft_str_sized_copy(dest, old, *total_read);
		ft_str_sized_copy(dest + *total_read, buffer, byte_read);
		*total_read += byte_read;
		free(old);
		byte_read = read(fd, buffer, DEFAULT_BUFFER_SIZE);
	}
	return (dest);
}

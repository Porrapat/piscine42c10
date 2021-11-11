/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "display_file.h"

bool	display_file(char *path)
{
	int				file_descriptor;
	unsigned int	byte_read;
	char			buffer[BUFFER_SIZE];

	file_descriptor = open(path, O_RDONLY);
	if (file_descriptor < 0)
		return (false);
	byte_read = read(file_descriptor, buffer, BUFFER_SIZE);
	while (byte_read > 0)
	{
		if (byte_read == (unsigned int)-1)
			return (false);
		write(1, &buffer[0], byte_read);
		byte_read = read(file_descriptor, buffer, BUFFER_SIZE);
	}
	close(file_descriptor);
	return (true);
}

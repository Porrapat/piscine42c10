/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_UTILS_H
# define FT_FILE_UTILS_H

# include "ft_args_parser.h"

# define BUFFER_SIZE_1K 1024
# define UINT unsigned int
# define T_OPT t_options

int		ft_open_file(t_options *options);

int		ft_close_file(int fd);

bool	ft_show_error(t_options *options);

char	*ft_read_multiple(T_OPT *opts, int count, UINT *len, int total);

char	*ft_read_full(int fd, unsigned int *length);

char	*ft_extend_array(char *ori, char *n_cont, UINT old_len, UINT *len);

#endif

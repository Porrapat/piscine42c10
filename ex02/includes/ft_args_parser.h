/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_PARSER_H
# define FT_ARGS_PARSER_H

# include <stdbool.h>

# define NOTHING -1

typedef struct s_options
{
	int	byte_to_read;
}				t_options;

bool			parse_args(char **args, int count);

bool			process_tail(char **args, int count, int i, t_options *opts);

bool			proc_option(char **args, int count, int *i, t_options *opts);

void			display_usage(char *exec);

void			display_error(char *exec, char *error, char *cause, bool limit);

#endif

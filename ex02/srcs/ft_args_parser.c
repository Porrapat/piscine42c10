/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>

#include "ft_atoi.h"
#include "ft_console_io.h"
#include "ft_args_parser.h"
#include "ft_tail.h"

#define ERR_ILLEGAL_OPT "illegal option"
#define ERR_ILLEGAL_OFF "illegal offset"
#define ERR_OPT_REQ_ARG "option requires an argument"

bool	parse_args(char **args, int count)
{
	t_options	options;
	int			index;

	options.byte_to_read = NOTHING;
	index = 1;
	while (index < count)
	{
		if (args[index][0] == '-' && args[index][1] != '\0')
		{
			if (args[index][1] == 'c')
			{
				if (!proc_option(args, count, &index, &options))
					return (false);
			}
			else
				return (false);
		}
		else
			break ;
		index++;
	}
	return (process_tail(args, count, index, &options));
}

bool	process_tail(char **args, int count, int index, t_options *opts)
{
	bool	result;
	int		total;

	result = true;
	total = count - index;
	if (total == 0)
		stdin_tail(opts);
	else
	{
		while (index < count)
		{
			if (!tail(args[0], args[index], opts, total))
				result = false;
			index++;
		}
	}
	return (result);
}

bool	proc_option(char **args, int count, int *index, t_options *opts)
{
	int		atoi;

	if (*index + 1 < count)
	{
		if (opts->byte_to_read == NOTHING)
		{
			*index += 1;
			atoi = ft_abs_strict_atoi(args[*index]);
			if (atoi != -1)
			{
				opts->byte_to_read = atoi;
				return (true);
			}
			display_error(args[0], ERR_ILLEGAL_OFF, args[*index], false);
			return (false);
		}
		display_usage(args[0]);
		return (false);
	}
	display_error(args[0], ERR_OPT_REQ_ARG, (char *)(args[*index] + 1), true);
	display_usage(args[0]);
	return (false);
}

void	display_usage(char *exec)
{
	write_str_err("usage: ");
	write_str_err(basename(exec));
	write_str_err(" [-c #] [file ...]\n");
}

void	display_error(char *exec, char *error, char *cause, bool limit)
{
	write_str_err(basename(exec));
	write_str_err(": ");
	write_str_err(error);
	write_str_err(" -- ");
	if (limit)
		write_char_err(*cause);
	else
		write_str_err(cause);
	write_str_err("\n");
}

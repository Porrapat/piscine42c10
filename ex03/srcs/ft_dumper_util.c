/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumper_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_dumper.h"

int	is_not_star_flag(bool star_flag)
{
	int	to_return;

	if (!star_flag)
		to_return = 2;
	else
		to_return = 0;
	return (to_return);
}

int	get_max_from_i_lines_length(UINT i, UINT lines, UINT length)
{
	int	result;

	if (i == lines - 1)
		result = length % 16;
	else
		result = 16;
	return (result);
}

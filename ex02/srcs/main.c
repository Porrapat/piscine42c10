/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:52:59 by porrapat          #+#    #+#             */
/*   Updated: 2021/11/09 23:53:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_tail.h"
#include "ft_args_parser.h"

int	main(int argc, char **argv)
{
	if (!parse_args(argv, argc))
		return (1);
	return (0);
}

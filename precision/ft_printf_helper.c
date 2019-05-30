/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:38:52 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/30 15:44:28 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	fill(char fill, int len)
{
	int idx;

	idx = -1;
	while (++idx < len)
		ft_putchar(fill);
}

int	isOneOf(char target, char * str)
{
	int idx;

	idx = -1;
	while (str[++idx])
		if (str[idx] == target)
			return (1);
	return (0);
}

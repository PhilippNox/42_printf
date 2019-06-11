/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:38:52 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 21:31:38 by wgorold          ###   ########.fr       */
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

int	length_utf8(char *str)
{
	int idx;
	int out;

	idx = 0;
	out = 0;
	while (str[idx])
	{
		idx += ft_utf8step(str);
		out++;
	}
	return (UTF8COUNT) ? (out) : idx;
}

int	length_unicode(wchar_t *str)
{
	int idx;
	int out;

	idx = 0;
	out = 0;
	while (str[idx])
	{
		out += unicodestep(str[idx]);
		idx++;
	}
	return (UTF8COUNT) ? (idx) : out;
}

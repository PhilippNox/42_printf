/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 00:16:13 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	int idx;
	int printed;

	if (!s)
		return (0);
	printed = 0;
	idx = 0;
	while (*(s + idx))
	{
		idx += ft_pututf8(s + idx);
		printed++;
	}
	return (UTF8COUNT) ? (printed) : idx;
}

int	ft_putstrn(char const *s, int len)
{
	int idx;
	int printed;

	if (!s)
		return (0);
	printed = 0;
	idx = 0;
	while (*(s + idx) && printed < len)
	{
		idx += ft_pututf8(s + idx);
		printed++;
		if (!UTF8COUNT)
			printed = idx;
	}
	return (printed);
}

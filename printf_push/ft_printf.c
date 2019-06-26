/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 20:18:25 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

static int	end(va_list *ap, int total)
{
	va_end(*ap);
	write_boost(NULL, 1);
	return (total);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			idx;
	int			total;
	t_task		task;
	t_task		*last;

	if (!format)
		return (0);
	va_start(ap, format);
	total = 0;
	idx = 0;
	while (*(format + idx))
	{
		if (*(format + idx) != '%')
		{
			idx += ft_pututf8(format + idx);
			total += 1;
			continue;
		}
		init_task(&task);
		idx += set_task(&task, (char *)format + idx + 1, &ap) + 1;
		total += make_task(&task, &ap);
		last = &task;
	}
	return (end(&ap, total));
}

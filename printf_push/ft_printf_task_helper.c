/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_task_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:42:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 23:42:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	init_task(t_task *input)
{
	input->minus = 0;
	input->plus = 0;
	input->space = 0;
	input->hash = 0;
	input->zero = ' ';
	input->width = -1;
	input->precision = -1;
	input->length = '.';
	input->type = '0';
}

void	print_task(t_task *input)
{
	ft_putstr("\n\tinput->minus=     ");
	if (input->minus)
		ft_putstr("✅");
	ft_putstr("\n\tinput->plus=      ");
	if (input->plus)
		ft_putstr("✅");
	ft_putstr("\n\tinput->space=     ");
	if (input->space)
		ft_putstr("✅");
	ft_putstr("\n\tinput->hash=      ");
	if (input->hash)
		ft_putstr("✅");
	ft_putstr("\n\tinput->zero=      ");
	if (input->zero != ' ')
		ft_putstr("✅");
	ft_putstr("\n\n\tinput->width=     ");
	ft_putnbr(input->width);
	ft_putstr("\n\tinput->precision= ");
	ft_putnbr(input->precision);
	ft_putstr("\n\tinput->length=    ");
	ft_putchar(input->length);
	ft_putstr("\n\tinput->type=      ");
	ft_putchar(input->type);
	ft_putstr("\n");
}

int		make_task(t_task *input, va_list *ap)
{
	if (input->type == 'C' || (input->type == 'c' && input->length == 'l'))
		return (make_bc(input, ap));
	if (input->type == 'c' || input->type == '%')
		return (make_c(input, ap));
	if (input->type == 'S' || (input->type == 's' && input->length == 'l'))
		return (make_bs(input, ap));
	if (input->type == 's')
		return (make_s(input, ap));
	if (input->type == 'p')
		return (make_p(input, ap));
	if (input->type == 'd' || input->type == 'i' || input->type == 'D')
		return (make_d(input, ap));
	if (input->type == 'o' || input->type == 'O')
		return (make_o(input, ap));
	if (input->type == 'u' || input->type == 'U')
		return (make_u(input, ap));
	if (input->type == 'x' || input->type == 'X')
		return (make_x(input, ap));
	if (input->type == 'f' || input->type == 'F')
		return (make_f(input, ap));
	if (input->type != '0')
		return (make__(input));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:42:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/19 17:44:32 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	set_task(t_task *input, char *start, va_list *ap)
{
	int add_total;
	int val;

	add_total = 1;
	if (*start == '\0' || !isOneOf(*start, "cCsSpdDioOuUxXgfF%-+ #.0123456789*hlLzj"))
	{
		input->type = *start;
		return (*start == '\0') ? (0) : (1);
	}
	if (isOneOf(*start, "cCsSpdDioOuUxXgfF%"))
	{
		input->type = *start;
		if (input->precision == -1)
		{
			if (input->type == 'f' || input->type == 'F')
				input->precision = 6;
		}
		return (1);
	}
	if (*start == '-')
		input->minus = 1;
	else if (*start == '+')
		input->plus = 1;
	else if (*start == ' ')
		input->space = 1;
	else if (*start == '#')
		input->hash = 1;
	else if (*start == '0')
		input->zero = '0';
	else if (*start == '.')
	{
		if (*(start + 1) == '*')
			val = va_arg(*ap, int);
		else if (*(start + 1) == '-' || (*(start + 1) == '+')
				|| (*(start + 1) > 47 && *(start + 1) < 58))
			val = ft_atoi(start + 1, &add_total);
		else
		{
			val = 0;
			add_total--;
		}
		add_total++;
		if (val < 0)
		{
			if (*(start + 1) != '*')
			{
				input->width = -val;
				input->minus = 1;
				input->precision = (*(start + 1) == '*') ? input->precision : 0; //test_s_12
			}
		}
		else
			input->precision = val;
	}
	else if (*start == '*')
	{
		val = va_arg(*ap, unsigned long);
		if (val < 0)
		{
			input->width = -val;
			input->minus = 1;
		}
		else
			input->width = val;
	}
	else if (*start > 48 && *start < 58)
		input->width = ft_atoi(start, &add_total);
	else if (*start == 'h' || *start == 'l' || *start == 'L'
		|| *start == 'z' || *start == 'j')
	{
		if (*start == 'l' && *(start + 1) == 'l')
			val = 'l' + add_total++;
		else if (*start == 'h' && *(start + 1) == 'h')
			val = 'h' + add_total++;
		else
			val = *start;
		input->length = (input->length < val) ? val : input->length;
	}
	return set_task(input, start + add_total, ap) + add_total;
}

int	make_task(t_task *input, va_list *ap)
{
	if (input->type == 'C' || (input->type == 'c' && input->length == 'l'))
		return make_bc(input, ap);
	if (input->type == 'c' || input->type == '%')
		return make_c(input, ap);
	if (input->type == 'S' || (input->type == 's' && input->length == 'l'))
		return make_bs(input, ap);
	if (input->type == 's')
		return make_s(input, ap);
	if (input->type == 'p')
		return make_p(input, ap);
	if (input->type == 'd' || input->type == 'i' || input->type == 'D')
		return make_d(input, ap);
	if (input->type == 'o' || input->type == 'O')
		return make_o(input, ap);
	if (input->type == 'u' || input->type == 'U')
		return make_u(input, ap);
	if (input->type == 'x' || input->type == 'X')
		return make_x(input, ap);
	if (input->type == 'f' || input->type == 'F')
		return make_f(input, ap);
	if (input->type != '0') // 0 is a part of flags and values so can't be a last char
		return make__(input);
	return (0);
}

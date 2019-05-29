/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 20:14:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c && ./a.out
// man 3 stdarg
// va_list ap, ap2;

// if (*start > 48 && *start < 58)
	//int val = ft_atoi(start, &add_total); ft_putstr("\nval = "); ft_putnbr(val);ft_putstr("\nadd_total = "); ft_putnbr(add_total);ft_putstr("\n");

typedef	struct	s_task
{
	char minus;
	char plus;
	char space;
	char hash;
	char zero;

	unsigned long width;
	unsigned long precision;
	char length;
	char type;
} t_task;

void	init_task(t_task *input)
{
	input->minus = 0;
	input->plus = 0;
	input->space = 0;
	input->hash = 0;
	input->zero = 0;

	input->width = 0;
	input->precision = 0;
	input->length = 'n';
	input->type = 'n';
}

void	print_task(t_task *input)
{
	ft_putstr("\tinput->minus=     ");
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
	if (input->zero)
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

int	isOneOf(char target, char * str)
{
	int idx;

	idx = -1;
	while (str[++idx])
		if (str[idx] == target)
			return (1);
	return (0);
}

int	set_task(t_task *input, char *start, va_list *ap)
{
	unsigned long add_total;

	add_total = 1;
	if (isOneOf(*start, "cspdiouxXgf%"))
	{
		input->type = *start;
		return (1);
	}
	if (*start == '-')
		input->minus = 1;
	if (*start == '+')
		input->plus = 1;
	if (*start == ' ')
		input->space = 1;
	if (*start == '#')
		input->hash = 1;
	if (*start == '0')
		input->zero = 1;
	if (*start == '.')
	{
		if (*(start + 1) == '*')
			input->precision = va_arg(*ap, unsigned long);
		else
			input->precision = (unsigned long)ft_atoi(start + 1, &add_total);
		add_total++;
	}
	if (*start == '*')
		input->width = va_arg(*ap, unsigned long);
	if (*start > 48 && *start < 58)
		input->width = (unsigned long)ft_atoi(start, &add_total);
	if (*start == 'h' || *start == 'l' || *start == 'L')
	{
		if (*start == 'l' && *(start + 1) == 'l')
			input->length = 'l' + add_total++;
		else if (*start == 'h' && *(start + 1) == 'h')
			input->length = 'l' + add_total++;
		else
			input->length = *start;
	}
	return set_task(input, start + add_total, ap) + add_total;
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char *s;
	int idx;
	int total;
	t_task task;

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
		print_task(&task);
	}
	va_end(ap);
	return (total);
}

int main ()
{
	//ft_putnbr(ft_printf("8 🦑 ok👈\n"));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 010d]ok👈\n"));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*d]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78d]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.*d]ok👈\n", 10, 42));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78hhd]ok👈\n", 10));
	ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78Lg]ok👈\n", 10));
	ft_putstr("\n");
}

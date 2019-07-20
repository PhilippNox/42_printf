/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_1_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 16:28:42 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_t_str_f(t_str_f *input)
{
	int idx;

	idx = -1;
	ft_putstr("exp_ent: ");
	ft_putunbr(input->exp_ent);
	ft_putstr("\nidx_ent: ");
	ft_putunbr(input->idx_ent);
	ft_putstr("\nentiere: ");
	while (++idx < input->idx_ent)
		ft_putchar(input->ent[idx] + 48);
	idx = -1;
	ft_putstr("\n,,,,");
	ft_putstr("\nexp_frc: ");
	ft_putunbr(input->exp_frc);
	ft_putstr("\nidf: ");
	ft_putunbr(input->idf);
	ft_putstr("\nfractio: ");
	while (++idx < input->idf)
		ft_putchar(input->frc[idx] + 48);
	ft_putstr("\n");
}

void	print_t_str_f_full(t_str_f *input)
{
	int idx;

	if (input->sign == '-')
		ft_putchar('-');
	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar(input->ent[idx] + 48);
	ft_putchar('.');
	idx = input->exp_frc + 1;
	while (--idx > input->idf)
		ft_putchar('0');
	while (--idx > -1)
		ft_putchar(input->frc[idx] + 48);
}

void	print_t_str_f_human(t_str_f *input)
{
	print_t_str_f_full(input);
	ft_putstr("\n");
}

void	show_float(t_longd input)
{
	ft_putstr("t_longd:\n{");
	ft_putstr("\n\t sign: ");
	ft_putnbr(input.t_parts_ld.sign);
	ft_putstr("\n\t exp : ");
	ft_putnbr(input.t_parts_ld.exp);
	ft_putstr("\n\t frac: ");
	ft_putunbr(input.t_parts_ld.frac);
	ft_putstr("\n}\n");
}

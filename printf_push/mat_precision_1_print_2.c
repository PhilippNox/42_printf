/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_11_print_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 16:53:21 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	debug_print(t_str_f *add, int power, int curr)
{
	ft_putstr("power_tab[idx]: ");
	ft_putnbr(power);
	ft_putstr("\t curr: ");
	ft_putnbr(curr);
	ft_putstr("\t val: ");
	print_t_str_f_human(add);
	ft_putstr("\n");
}

void	debug_print_final(t_str_f *final)
{
	ft_putstr("\t\t\t\t       final: ");
	print_t_str_f_human(final);
	ft_putstr("\n");
}

void	t_str_f_print_ent(t_str_f *input)
{
	int		idx;

	idx = input->idx_ent;
	if (idx == 0)
		ft_putchar('0');
	while (--idx > -1)
		ft_putchar(input->ent[idx] + 48);
}

void	t_str_f_print_frc(t_str_f *input, int pos)
{
	int		idx;

	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - idx - 1 >= input->idf)
			ft_putchar('0');
		else if (input->exp_frc - idx - 1 >= 0)
			ft_putchar(input->frc[input->exp_frc - idx - 1] + 48);
		else
			ft_putchar('0');
	}
}

void	t_str_f_print_full_simple(t_str_f *input, int pos)
{
	int		idx;

	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar(input->ent[idx] + 48);
	ft_putchar('.');
	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - idx - 1 >= input->idf)
			ft_putchar('0');
		else if (input->exp_frc - idx - 1 >= 0)
			ft_putchar(input->frc[input->exp_frc - idx - 1] + 48);
		else
			ft_putchar('0');
	}
}

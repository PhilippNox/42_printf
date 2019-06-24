/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mat_precision_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/08 00:57:03 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c && ./a.out

#include "longd.h"

void	up_rounding(t_str_f *input, unsigned int pos)
{
	t_str_f tmp;
	t_str_f add;

	init_t_str_f(&add);
	tmp = *input;
	if (pos > 0)
	{
		add.frc[0] = 1;
		add.idf = 1;
		add.exp_frc = pos;
		sum_t_str_f_frc(input, &tmp, &add);
		return ;
	}
	add.ent[0] = 1;
	add.idx_ent = 1;
	add.exp_ent = 0;
	sum_t_str_f_ent(input, &tmp, &add);
}

void	t_str_f_round(t_str_f *input, unsigned int pos)
{
	if (pos + 1 > (unsigned int)input->exp_frc)
		return ;
	if (pos + 1 < (unsigned int)input->exp_frc)
	{
		if (input->exp_frc - pos - 1 >= (unsigned int)input->idf)
			return ;
		if (input->frc[input->exp_frc - pos - 1] < 5)
			return ;
		return (up_rounding(input, pos));
	}
	// if (pos + 1 == input->exp_frc)
	if (input->frc[input->exp_frc - pos - 1] < 5)
		return ;
	if (input->frc[input->exp_frc - pos - 1] > 5)
		return (up_rounding(input, pos));
	if (input->frc[input->exp_frc - pos] % 2 == 0)
		return ;
	else
		return (up_rounding(input, pos));
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

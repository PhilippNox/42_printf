/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_mat_precision_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 22:12:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c t_str_f.c float.c && ./a.out

#include "longd.h"

void	up_rounding(t_str_f *input, unsigned int pos)
{
	t_str_f tmp;
	t_str_f add;
	init_t_str_f(&add);
	if (pos > 0)
	{
		add.frc[0] = 1;
		add.idx_frc = 1;
		add.exp_frc = pos;
		tmp = *input;
		if (DEBUG_ROUNDING)
			print_t_str_f_human(&add);
		sum_t_str_f_frc(input, &tmp, &add);
		return ;
	}
	add.ent[0] = 1;
	add.idx_ent = 1;
	add.exp_ent = 0;
	tmp = *input;
	if (DEBUG_ROUNDING)
		print_t_str_f_human(&add);
	sum_t_str_f_ent(input, &tmp, &add);
	return ;

}

void	t_str_f_round(t_str_f *input, unsigned int pos)
{
	//print_t_str_f(input);
	//print_t_str_f_human(input);
	if (pos + 1 > input->exp_frc)
	{
		if (DEBUG_ROUNDING)
			ft_putstr("precision more then digits \n");
		return ;
	}
	if (pos + 1 < input->exp_frc)
	{
		if (input->exp_frc - pos - 1 >= input->idx_frc)
		{
			if (DEBUG_ROUNDING)
				ft_putstr("in zero bridge\n");
			return ;
		}
		if (input->frc[input->exp_frc - pos - 1] < 5)
		{
			if (DEBUG_ROUNDING)
			{
				ft_putstr("less then 5:  ");
				ft_putchar(input->frc[input->exp_frc - pos - 1] + 48);
				ft_putstr("\n");
			}
			return ;
		}
		if (DEBUG_ROUNDING)
			ft_putstr("up cause more then 5: ");
		up_rounding(input, pos);
		return ;
	}
	// if (pos + 1 == input->exp_frc)
	if (input->frc[input->exp_frc - pos - 1] < 5)
	{
		if (DEBUG_ROUNDING)
		{
			ft_putstr("less then 5:  ");
			ft_putchar(input->frc[input->exp_frc - pos - 1] + 48);
			ft_putstr("\n");
		}
		return ;
	}
	if (input->frc[input->exp_frc - pos - 1] > 5)
	{
		up_rounding(input, pos);
		return ;
	}
	// input->frc[input->exp_frc - pos - 1] > 5
	if (input->frc[input->exp_frc - pos] % 2 == 0)
	{
		if (DEBUG_ROUNDING)
		{
			ft_putstr("equial to 5 and !%2:  ");
			ft_putchar(input->frc[input->exp_frc - pos] + 48);
			ft_putstr("\n");
		}
		return ;
	}
	else
	{
		if (DEBUG_ROUNDING)
			ft_putstr("equial to 5 and %2: ");
		up_rounding(input, pos);
		return ;
	}
}

void	t_str_f_print_ent(t_str_f *input, char *out, int *idxo)
{
	int		idx;

	if (input->sign == '-')
		out[(*idxo)++] = '-';
	idx = input->idx_ent;
	while (--idx > -1)
		out[(*idxo)++] = input->ent[idx] + 48;
}

void	t_str_f_print_full_simple(t_str_f *input, int pos)
{
	int		idx;

	if (input->sign == '-')
		ft_putchar('-');
	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar(input->ent[idx] + 48);
	ft_putchar('.');

	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - idx - 1 >= input->idx_frc)
			ft_putchar('0');
		else if (input->exp_frc - idx - 1 >= 0)
			ft_putchar(input->frc[input->exp_frc - idx - 1] + 48);
		else
			ft_putchar('0');
	}
}

void	t_str_f_print_full(t_str_f *input, char *out, int *idxo, int pos)
{
	int		idx;

	t_str_f_print_ent(input, out, idxo);
	out[(*idxo)++] = '.';

	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - 1 - idx >= input->idx_frc)
			out[(*idxo)++] = '0';
		else if (input->exp_frc - 1 - idx >= 0)
			out[(*idxo)++] = input->frc[input->exp_frc - 1 - idx] + 48;
		else
			out[(*idxo)++] = '0';
	}

	/*
	idx = input->exp_frc + 1;
	while (--idx > input->idx_frc)
		out[(*idxo)++] = '0';
	while (--idx > -1)
		out[(*idxo)++] = input->frc[idx] + 48;
		*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mat_precision_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/28 19:23:26 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	init_t_str_f(t_str_f *input)
{
	int idx;

	input->sign = '+';
	idx = -1;
	while (++idx < LEN_STR_ENT)
		input->ent[idx] = '\0';
	idx = -1;
	while (++idx < LEN_STR_FRC)
		input->frc[idx] = '\0';
	input->idx_ent = 0;
	input->idx_frc = 0;
	input->exp_ent = 0;
	input->exp_frc = 0;
}

void	init_t_str_f_frc(t_str_f *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_FRC)
		input->frc[idx] = '\0';
	input->idx_frc = 0;
	input->exp_frc = 0;
}

void	init_t_str_f_ent(t_str_f *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_ENT)
		input->ent[idx] = '\0';
	input->idx_ent = 0;
	input->exp_ent = 0;
}

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
		ft_putchar(input->ent[idx]);
	idx = -1;
	ft_putstr("\n,,,,");
	ft_putstr("\nexp_frc: ");
	ft_putunbr(input->exp_frc);
	ft_putstr("\nidx_frc: ");
	ft_putunbr(input->idx_frc);
	ft_putstr("\nfractio: ");
	while (++idx < input->idx_frc)
		ft_putchar(input->frc[idx]);
	ft_putstr("\n");
}

void	print_t_str_f_human(t_str_f *input)
{
	int idx;

	if (input->sign == '-')
		ft_putchar('-');
	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar(input->ent[idx]);
	ft_putchar('.');
	idx = input->exp_frc + 1;
	while (--idx > input->idx_frc)
		ft_putchar('0');
	while (--idx > -1)
		ft_putchar(input->frc[idx]);
	ft_putstr("\n");
}

void	power_pos(t_str_f *input)
{
	int idx;
	int val;
	int add_val;

	if (DEBUG_POWER)
		print_t_str_f_human(input);
	idx = -1;
	add_val = 0;
	while (++idx < input->idx_ent)
	{
		val = (input->ent[idx] - 48) * 2 + add_val;
		input->ent[idx] = (val % 10) + 48;
		add_val = val / 10;
	}
	if (add_val)
	{
		input->ent[input->idx_ent++] = add_val + 48;
		input->exp_ent++;
	}
	if (DEBUG_POWER)
	{
		ft_putstr(" -> ");
		print_t_str_f_human(input);
		ft_putstr("\n");
	}
	if (DEBUG_POWER_IDX)
	{
		ft_putnbr(input->idx_ent);
		ft_putstr("\n");
	}
}

void	power_neg(t_str_f * input)
{
	int idx;
	int val;
	int add_val;

	if (DEBUG_POWER)
		print_t_str_f_human(input);
	idx = -1;
	add_val = 0;
	input->exp_frc++;
	while (++idx < input->idx_frc)
	{
		val = (input->frc[idx] - 48) * 5 + add_val;
		input->frc[idx] = (val % 10) + 48;
		add_val = val / 10;
	}
	if (add_val)
		input->frc[input->idx_frc++] = add_val + 48;
	if (DEBUG_POWER)
	{
		ft_putstr(" -> ");
		print_t_str_f_human(input);
		ft_putstr("\n");
	}
	if (DEBUG_POWER_IDX)
	{
		ft_putnbr(input->idx_frc);
		ft_putstr("\n");
	}
}

void	power2form(t_str_f *input, int pwr, int curr)
{
	int idx;

	if (pwr == 0 || (pwr > 0 && curr == 0))
	{
		init_t_str_f(input);
		input->ent[0] = '1';
		input->idx_ent = 1;
		input->exp_ent = 0;
	}
	if (pwr == -1 || (pwr < 0 && curr == 0))
	{
		init_t_str_f(input);
		input->frc[0] = '5';
		input->idx_frc = 1;
		input->exp_frc = 1;
	}
	idx = -1;
	if (pwr > 0)
	{
		while (++idx + curr < pwr)
			power_pos(input);
	}
	else
	{
		if (curr == 0)
			idx = 0;
		while (++idx + pwr < curr)
			power_neg(input);
	}
}

void	set_sign(t_str_f *result, unsigned int sign)
{
	if (sign)
		result->sign = '-';
	else
		result->sign = '+';
}

void	sum_t_str_f_frc(t_str_f *result, t_str_f *a, t_str_f *b)
{
	t_str_f *start;
	t_str_f *add;
	int idx;
	int add_val;
	int val;
	int shift;

	init_t_str_f_frc(result);
	start = a;
	add = b;
	result->exp_frc = a->exp_frc;
	if (a->exp_frc < b->exp_frc)
	{
		start = b;
		add = a;
		result->exp_frc = b->exp_frc;
	}

	shift = start->exp_frc - add->exp_frc;
	idx = 0;
	add_val = 0;
	while (start->frc[idx] || add->frc[idx - shift])
	{
		if (idx - shift < 0)
		{
			result->frc[result->idx_frc++] = start->frc[idx];
		}
		else if (idx >= start->idx_frc)
		{
			val = add->frc[idx - shift] - 48 + add_val ;
			result->frc[result->idx_frc++] = (val % 10) + 48;
			add_val = val / 10;
		}
		else
		{
			val = start->frc[idx] + add->frc[idx - shift] - 48 * 2 + add_val ;
			result->frc[result->idx_frc++] = (val % 10) + 48;
			add_val = val / 10;
		}
		++idx;
	}
	if (add_val)
	{
		result->frc[result->idx_frc++] = add_val + 48;
	}
}

void	sum_t_str_f_ent(t_str_f *result, t_str_f *a, t_str_f *b)
{
	t_str_f *start;
	t_str_f *add;
	int idx;
	int add_val;
	int val;

	init_t_str_f_ent(result);
	start = a;
	add = b;
	result->exp_ent = a->exp_ent;
	if (a->exp_ent < b->exp_ent)
	{
		start = b;
		add = a;
		result->exp_ent = b->exp_ent;
	}

	idx = 0;
	add_val = 0;
	while (start->ent[idx] || add->ent[idx])
	{
		if (!add->ent[idx])
			val = start->ent[idx] - 48 + add_val;
		else if (!start->ent[idx])
			val = add->ent[idx] - 48 + add_val;
		else
			val = start->ent[idx] + add->ent[idx] - 48 * 2 + add_val;
		result->ent[result->idx_ent++] = (val % 10) + 48;
		add_val = val / 10;
		++idx;
	}
	if (add_val)
	{
		result->ent[result->idx_ent++] = add_val + 48;
		result->exp_ent++;
	}
}

/*
void	sum_t_str_f(t_str_f *result, t_str_f *a, t_str_f *b)
{
	t_str_f *start;
	t_str_f *add;
	int idx;
	int add_val;
	int val;

	init_t_str_f(result);
	start = a;
	add = b;
	if (a->idx_frc < b->idx_frc)
	{
		start = b;
		add = a;
	}

	idx = -1;
	add_val = 0;
	while (++idx < start->idx_frc)
	{
		if (idx < start->idx_frc - add->idx_frc)
		{
			result->frc[result->idx_frc++] = start->frc[idx];
		}
		else if (!add->frc[idx - start->idx_frc + add->idx_frc])
			result->frc[result->idx_frc++] = start->frc[idx];
		else
		{
			val = start->frc[idx] + add->frc[idx - start->idx_frc + add->idx_frc] - 48 * 2 + add_val ;
			result->frc[result->idx_frc++] = (val % 10) + 48;
			add_val = val / 10;
		}
	}
	idx = -1;
	while (start->ent[++idx] || add->ent[idx])
	{
		if (!add->ent[idx])
			val = start->ent[idx] - 48 + add_val;
		else if (!start->ent[idx])
			val = add->ent[idx] - 48 + add_val;
		else
			val = start->ent[idx] + add->ent[idx] - 48 * 2 + add_val;
		result->ent[result->idx_ent++] = (val % 10) + 48;
		add_val = val / 10;
	}
	if (add_val)
		result->ent[result->idx_ent++] = add_val + 48;
}
*/

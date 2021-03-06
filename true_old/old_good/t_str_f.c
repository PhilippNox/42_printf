/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/23 17:18:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c mem_float.c str_rev_parts.c && ./a.out

#include "printf.h"

void	init_t_str_f(t_str_f *input)
{
	int idx;

	input->sign = '+';
	idx = -1;
	while (++idx < LEN_STR_NUM)
	{
		input->ent[idx] = '\0';
		input->frc[idx] = '\0';
	}
	input->idx_ent = 0;
	input->idx_frc = 0;
}

void	print_t_str_f(t_str_f *input)
{
	int idx;

	idx = -1;
	ft_putstr("entiere: ");
	while (++idx < LEN_STR_NUM && input->ent[idx])
		ft_putchar(input->ent[idx]);
	idx = -1;
	ft_putstr("\nfractio: ");
	while (++idx < LEN_STR_NUM && input->frc[idx])
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
	idx = input->idx_frc;
	ft_putchar('.');
	while (--idx > -1)
		ft_putchar(input->frc[idx]);
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
		input->ent[input->idx_ent++] = add_val + 48;
	if (DEBUG_POWER)
	{
		ft_putstr(" -> ");
		print_t_str_f_human(input);
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
	input->frc[input->idx_frc++] = '0';
	while (++idx < input->idx_frc - 1)
	{
		val = (input->frc[idx] - 48) * 5 + add_val;
		input->frc[idx] = (val % 10) + 48;
		add_val = val / 10;
	}
	if (add_val)
		input->frc[idx] = add_val + 48;
	if (DEBUG_POWER)
	{
		ft_putstr(" -> ");
		print_t_str_f_human(input);
		ft_putstr("\n");
	}
}

void	power2(t_str_f *input, int pwr)
{
	if (pwr == 0 || pwr == -1)
	{
		init_t_str_f(input);
		if (pwr == 0)
		{
			input->ent[0] = '1';
			input->idx_ent = 1;
		}
		if (pwr == -1)
		{
			input->frc[0] = '5';
			input->idx_frc = 1;
		}
		return ;
	}
	power2(input, (pwr > 0) ? pwr - 1 : pwr + 1);
	if (pwr > 0)
		power_pos(input);
	else
		power_neg(input);
}

void	power2form(t_str_f *input, int pwr, int curr)
{
	if (curr != 0 && pwr - curr == 0)
		return;
	if (curr < 0)
	{
		power2form(input, pwr + 1, curr);
		power_neg(input);
		return ;
	}
	else if (curr > 0)
	{
		power2form(input, pwr - 1, curr);
		power_pos(input);
		return ;
	}
	power2(input, pwr);
}

void	set_sign(t_str_f *result, unsigned int sign)
{
	if (sign)
		result->sign = '-';
	else
		result->sign = '+';
}

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

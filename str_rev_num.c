/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:33:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/17 15:36:23 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c str_rev_num.c && ./a.out

#include <stdio.h>
#include <string.h>
#define LEN_STR_NUM 400

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);

typedef	struct		s_str
{
	char	num[LEN_STR_NUM];
	int		exp;
	int		idx_cur;
}	t_str;

void	init_t_str(t_str *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_NUM)
		input->num[idx] = '\0';
	input->exp = 0;
	input->idx_cur = 0;
}

void	print_t_str(t_str *input)
{
	int idx;

	ft_putchar('E');
	ft_putnbr(input->exp);
	ft_putchar(' ');
	idx = -1;
	while (input->num[++idx])
		ft_putchar(input->num[idx]);
	ft_putchar('\n');
}

void	print_t_str_human(t_str *input)
{
	int idx;
	int exp_show;

	idx = 0;
	while (input->num[idx])
		idx++;
	idx--;
	exp_show = (input->exp < 0) ? input->exp + idx : input->exp;
	ft_putchar(input->num[idx]);
	ft_putchar('.');
	while (--idx > -1)
		ft_putchar(input->num[idx]);
	ft_putchar(' ');
	ft_putchar('E');
	ft_putnbr(exp_show);
	ft_putchar('\n');
}

void	power_job(t_str *input, int idx, int add_val, int base)
{
	int val;

	if (!input->num[idx] && !add_val)
	{
		if (base == 5)
			input->exp -= 1;
		return ;
	}
	if (!input->num[idx])
	{
		input->num[idx] = add_val + 48;
		input->idx_cur += 1;
		input->exp += (base == 5) ? -1 : 1;
		return ;
	}
	val = (input->num[idx] - 48)* base + add_val;
	input->num[idx] = (val % 10) + 48;
	input->idx_cur += 1;
	power_job(input, idx + 1, val / 10, base);
}

void	power2(t_str *input, int pwr)
{
	if (pwr == 0)
	{
		init_t_str(input);
		input->num[0] = '1';
		input->idx_cur += 1;
		input->exp = 0;
		return ;
	}
	power2(input, (pwr > 0) ? pwr - 1 : pwr + 1);
	power_job(input, 0, 0, (pwr > 0) ? 2 : 5);
}

void	sum_job_neg(int idx, t_str *result, t_str *a, t_str *b, int add_val, int shift)
{
	int val;

	//print_t_str(result);
	//printf("exp_a=%d\texp_b=%d\t\tidx=%d\tcheck=%d\n", a->exp, b->exp, idx, idx + (a->exp - b->exp));
	// idx_cur
	if (idx + (a->exp - b->exp) < 0)
	{
		result->num[idx - shift] = a->num[idx];
		sum_job_neg(idx + 1, result, a, b, 0, shift);
		return ;
	}
	if (!a->num[idx] && !b->num[idx + (a->exp - b->exp)])
	{
		if (add_val)
		{
			result->num[idx - shift] = add_val + 48;
			result->exp += 1;
			return ;
		}
		return ;
	}
	if (!a->num[idx])
		a->num[idx] = '0';
	val = a->num[idx] + b->num[idx + (a->exp - b->exp)] - 48 * 2 + add_val;
	result->num[idx - shift] = val % 10 + 48;
	if (idx - shift == 0 && result->num[idx - shift] == '0')
		shift += 1;
	sum_job_neg(idx + 1, result, a, b, val / 10, shift);
}

void	sum_job_pos(int idx, t_str *result, t_str *a, t_str *b, int add_val)
{
	int val;

	if (!a->num[idx] && !b->num[idx])
	{
		if (add_val)
		{
			result->num[idx] = add_val + 48;
			result->exp += 1;
			return ;
		}
		return ;
	}

	if (!a->num[idx])
		val = b->num[idx] - 48  + add_val;
	else if (!b->num[idx])
		val = a->num[idx] - 48  + add_val;
	else
		val = a->num[idx] + b->num[idx] - 48 * 2 + add_val;
	result->num[idx] = val % 10 + 48;
	sum_job_pos(idx + 1, result, a, b, val / 10);
}

void	sum_t_str(t_str *result, t_str *a, t_str *b)
{
	int exp_a;
	int exp_b;

	init_t_str(result);
	exp_a = a->exp;
	exp_b = b->exp;
	if (a->exp < 0 && b->exp < 0)
	{
		if (a->exp < b->exp)
		{
			result->exp = a->exp;
			sum_job_neg(0, result, a, b, 0, 0);
		}
		else
		{
			result->exp = b->exp;
			sum_job_neg(0, result, b, a, 0, 0);
		}
	}
	else
	{
		if (a->exp < b->exp)
		{
			result->exp = b->exp;
		}
		else
		{
			result->exp = a->exp;
		}
		sum_job_pos(0, result, a, b, 0);
	}
}

int		main(void)
{
	t_str test;
	t_str a;
	t_str b;
	t_str c;

	init_t_str(&test);
	//print_t_str(&test);
	//power2(&test, 0); print_t_str(&test);
	//power2(&test, 1); print_t_str(&test);

	//power2(&test, 308); print_t_str(&test); print_t_str_human(&test);
	ft_putchar('\n');
	//power2(&test, -308); print_t_str(&test); print_t_str_human(&test);
	power2(&a, -3); print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	power2(&b, -4); print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	ft_putstr("\n\n");
	power2(&a, 4); print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	power2(&b, 7); print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	ft_putstr("\n\n");
	init_t_str(&a); a.num[0] = '9'; a.exp = 1;
	init_t_str(&b); b.num[0] = '1'; b.exp = 1;
	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	return (0);
}

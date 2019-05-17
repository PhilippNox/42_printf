/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:33:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/17 21:57:59 by wgorold          ###   ########.fr       */
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
	ft_putstr("idx=");
	ft_putnbr(input->idx_cur);
	ft_putstr(" E");
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
	ft_putstr(" E");
	ft_putnbr(exp_show);
	ft_putstr(" idx=");
	ft_putnbr(input->idx_cur);
	ft_putchar('\n');
}

void	power_job(t_str *input, int idx, int add_val, int base)
{
	int val;

	//print_t_str(input);
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

void	sum_job_neg(int idx, t_str *result, t_str *a, t_str *b, int add_val)
{
	int val;

	//print_t_str(result);
	//printf("exp_a=%d\texp_b=%d\t\tidx=%d\tcheck=%d\n", a->exp, b->exp, idx, idx + (a->exp - b->exp));
	// idx_cur
	if (idx + (a->exp - b->exp) < 0)
	{
		result->num[result->idx_cur++] = a->num[idx];
		sum_job_neg(idx + 1, result, a, b, 0);
		return ;
	}
	if (!a->num[idx] && !b->num[idx + (a->exp - b->exp)])
	{
		if (add_val)
		{
			result->num[result->idx_cur++] = add_val + 48;
			result->exp += 1;
			return ;
		}
		return ;
	}
	if (!a->num[idx])
		a->num[idx] = '0';
	val = a->num[idx] + b->num[idx + (a->exp - b->exp)] - 48 * 2 + add_val;
	result->num[result->idx_cur] = val % 10 + 48;
	if (result->idx_cur != 0 || result->num[0] != '0')
		result->idx_cur += 1;
	sum_job_neg(idx + 1, result, a, b, val / 10);
}

void	sum_job_pos(int idx, t_str *result, t_str *a, t_str *b, int add_val)
{
	int val;

	if (idx >= result->exp - a->exp + a->idx_cur)
	{
		if (add_val)
		{
			printf("END: add_val = %c\n", add_val + 48);
			result->num[result->idx_cur++] = add_val + 48;
			result->exp += 1;
			return ;
		}
		printf("END: just_end\n");
		return ;
	}

	// if (result->exp - a->exp + a->idx_cur - (result->exp - b->exp + b->idx_cur))
	if ( idx < b->exp - a->exp + a->idx_cur - b->idx_cur)
	{
		if (!a->num[idx])
		{
			printf("Only A: a->num[idx] = 0\n");
			result->num[result->idx_cur++] = '0';
		}
		else
		{
			printf("Only A: a->num[idx] = %c\n", a->num[idx]);
			result->num[result->idx_cur++] = a->num[idx];
		}
		sum_job_pos(idx + 1, result, a, b, 0);
		return ;
	}

	if (!a->num[idx])
	{
		printf("Only A+B: a->num[idx] = 0\t b->num= %c\n", b->num[idx - (b->exp - a->exp + a->idx_cur - b->idx_cur)]);
		val = '0' + b->num[idx - (b->exp - a->exp + a->idx_cur - b->idx_cur)] - 48 * 2 + add_val;
	}
	/*
	else if (idx >= b->idx_cur)
	{
		printf("Only A+B: a->num[idx] = %c\t b->num= 0\n", a->num[idx]);
		val = '0' + a->num[idx] - 48 * 2 + add_val;
	}
	*/
	else
	{
		val = a->num[idx] + b->num[idx - (b->exp - a->exp + a->idx_cur - b->idx_cur)] - 48 * 2 + add_val;
		printf("Only A+B: a->num[%d] = %c\t b->num[%d]= %c\n", idx, a->num[idx], idx - (b->exp - a->exp + a->idx_cur - b->idx_cur), b->num[idx - (b->exp - a->exp + a->idx_cur - b->idx_cur)]);
	}
	printf("Result: val = %c\t add_val= %d\n\n", val % 10 + 48, val / 10);
	result->num[result->idx_cur] = val % 10 + 48;
	if (result->idx_cur != 0 || result->num[0] != '0')
		result->idx_cur += 1;
	sum_job_pos(idx + 1, result, a, b, val / 10);
}

void	sum_t_str(t_str *result, t_str *a, t_str *b)
{
	int exp_a;
	int exp_b;
	int exp_max;

	init_t_str(result);
	exp_a = a->exp;
	exp_b = b->exp;

	if (a->exp < 0 && b->exp < 0)
	{
		if (a->exp < b->exp)
		{
			result->exp = a->exp;
			sum_job_neg(0, result, a, b, 0);
		}
		else
		{
			result->exp = b->exp;
			sum_job_neg(0, result, b, a, 0);
		}
	}
	else
	{
		if (a->exp > b->exp)
			exp_max = a->exp;
		else
			exp_max = b->exp;
		result->exp = exp_max;

		if (exp_max - a->exp + a->idx_cur  >  exp_max - b->exp + b->idx_cur)
		{
			printf("As first arg");
			print_t_str(a);
			printf("\n");
			sum_job_pos(0, result, a, b, 0);
		}
		else
		{
			printf("As first arg");
			print_t_str(b);
			printf("\n");
			sum_job_pos(0, result, b, a, 0);
		}
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
	init_t_str(&a); a.num[0] = '9'; a.exp = 0; a.idx_cur = 1;
	init_t_str(&b); b.num[0] = '1'; b.exp = 0; b.idx_cur = 1;

	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	ft_putstr("\n\n");
	init_t_str(&a); a.num[0] = '4'; a.num[1] = '6'; a.idx_cur = 2; a.exp = 4;
	init_t_str(&b); b.num[0] = '5'; b.num[1] = '2'; b.num[2] = '6'; b.num[3] = '0'; b.num[4] = '8'; b.num[5] = '2'; b.num[6] = '1'; b.idx_cur = 7; b.exp = 2;

	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');


	ft_putstr("\n\n");
	init_t_str(&a); a.num[0] = '4'; a.num[1] = '6'; a.idx_cur = 2; a.exp = 3;
	init_t_str(&b); b.num[0] = '5'; b.num[1] = '2'; b.num[2] = '6'; b.num[3] = '0'; b.num[4] = '8'; b.num[5] = '2'; b.num[6] = '1'; b.idx_cur = 7; b.exp = 2;

	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	return (0);
}

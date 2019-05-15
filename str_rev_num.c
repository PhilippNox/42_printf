/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:33:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/15 04:14:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c str_rev_num.c && ./a.out

#include <stdio.h>
#include <string.h>
#define LEN_STR_NUM 400

void	ft_putchar(char c);
void	ft_putnbr(int n);

typedef	struct		s_str
{
	char	num[LEN_STR_NUM];
	int		exp;
}	t_str;

void	init_t_str(t_str *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_NUM)
		input->num[idx] = '\0';
	input->exp = 0;
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
		input->exp = 0;
		return ;
	}
	power2(input, (pwr > 0) ? pwr - 1 : pwr + 1);
	power_job(input, 0, 0, (pwr > 0) ? 2 : 5);
}

int		main(void)
{
	t_str test;

	//init_t_str(&test); print_t_str(&test);
	//power2(&test, 0); print_t_str(&test);
	//power2(&test, 1); print_t_str(&test);

	power2(&test, 308); print_t_str(&test); print_t_str_human(&test);
	ft_putchar('\n');
	power2(&test, -308); print_t_str(&test); print_t_str_human(&test);

	return (0);
}

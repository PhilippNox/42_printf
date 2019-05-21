/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/20 18:03:23 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror ft_put.c str_rev_parts.c && ./a.out

#include <stdio.h>
#include <string.h>
#define LEN_STR_NUM 400

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);

typedef	struct		sum_t_str
{
	char	ent[LEN_STR_NUM];
	char	frc[LEN_STR_NUM];
	int		idx_ent;
	int		idx_frc;
} t_str;

void	init_t_str(t_str *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_NUM)
	{
		input->ent[idx] = '\0';
		input->frc[idx] = '\0';
	}
	input->idx_ent = 0;
	input->idx_frc = 0;
}

void	print_t_str(t_str *input)
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

void	print_t_str_human(t_str *input)
{
	int idx;

	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar(input->ent[idx]);
	idx = input->idx_frc;
	ft_putchar('.');
	while (--idx > -1)
		ft_putchar(input->frc[idx]);
	ft_putstr("\n");
}

void	power_pos(t_str *input)
{
	int idx;
	int val;
	int add_val;

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
}

void	power_neg(t_str * input)
{
	int idx;
	int val;
	int add_val;

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
}

void	power2(t_str *input, int pwr)
{
	if (pwr == 0 || pwr == -1)
	{
		init_t_str(input);
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

void	sum_t_str(t_str *result, t_str *a, t_str *b)
{
	t_str *start;
	t_str *add;
	int idx;
	int add_val;
	int val;

	init_t_str(result);
	start = a;
	add = b;
	if (a->idx_frc < b->idx_frc)
	{
		start = b;
		add = a;
	}

	ft_putstr("start= \n"); 	print_t_str(start);
	ft_putstr("\n  add= \n"); 	print_t_str(add); ft_putstr("\n");

	idx = -1;
	add_val = 0;
	while (++idx < start->idx_frc)
	{
		ft_putstr("idx= "); ft_putnbr(idx);
		ft_putstr("\t idx -start + add = "); ft_putnbr(idx - start->idx_frc + add->idx_frc);
		if (idx < start->idx_frc - add->idx_frc)
		{
			ft_putstr("\t result= "); ft_putchar(start->frc[idx]);
			ft_putstr("\t start= "); ft_putchar(start->frc[idx]);
			ft_putstr("\t end= ");
			result->frc[result->idx_frc++] = start->frc[idx];
		}
		else
		{
			val = start->frc[idx] + add->frc[idx - start->idx_frc + add->idx_frc] - 48 * 2 + add_val ;
			ft_putstr("\t result= "); ft_putchar((val % 10) + 48);
			ft_putstr("\t start= "); ft_putchar(start->frc[idx]);
			ft_putstr("\t end= "); ft_putchar(add->frc[idx - start->idx_frc + add->idx_frc]);
			result->frc[result->idx_frc++] = (val % 10) + 48;
			add_val = val / 10;
		}
		ft_putstr("\t add_val= "); ft_putnbr(add_val); ft_putstr("\n");
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
	//ft_putchar('\n');
	//power2(&test, -308); print_t_str(&test); print_t_str_human(&test);

	ft_putstr("\n\n");
	power2(&a, 4); print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	power2(&b, 7); print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");


	ft_putstr("\n\n");
	power2(&a, -2); print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	power2(&b, -4); print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	power2(&b, -5); print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");


	ft_putstr("\n\n");
	init_t_str(&a); a.frc[0] = '5'; a.frc[1] = '2'; a.frc[2] = '6'; a.frc[3] = '0'; a.idx_frc = 4;
	init_t_str(&b); b.frc[0] = '1'; b.frc[1] = '2'; b.frc[2] = '7'; b.frc[3] = '0'; b.frc[4] = '0'; b.frc[5] = '0'; b.idx_frc = 6;
	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

	ft_putstr("\n\n");
	init_t_str(&a); a.frc[0] = '5'; a.frc[1] = '2'; a.frc[2] = '6'; a.frc[3] = '1'; a.idx_frc = 4;
	init_t_str(&b); b.frc[0] = '1'; b.frc[1] = '2'; b.frc[2] = '7'; b.frc[3] = '0'; b.frc[4] = '0'; b.frc[5] = '9'; b.idx_frc = 6;
	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');


	ft_putstr("\n\n");
	init_t_str(&a); a.frc[0] = '5'; a.frc[1] = '2'; a.frc[2] = '6'; a.frc[3] = '1'; a.idx_frc = 4;
	a.ent[0] = '1'; a.ent[1] = '2'; a.ent[2] = '6'; a.ent[3] = '1'; a.idx_ent = 4;
	init_t_str(&b); b.frc[0] = '1'; b.frc[1] = '2'; b.frc[2] = '7'; b.frc[3] = '0'; b.frc[4] = '0'; b.frc[5] = '9'; b.idx_frc = 6;
	b.ent[0] = '1'; b.ent[1] = '2'; b.ent[2] = '6'; b.ent[3] = '1'; b.idx_ent = 4;
	print_t_str(&a); print_t_str_human(&a); ft_putchar('\n');
	print_t_str(&b); print_t_str_human(&b); ft_putchar('\n');
	ft_putstr("\n====\n");
	sum_t_str(&c, &a, &b); print_t_str(&c); print_t_str_human(&c); ft_putchar('\n');

}

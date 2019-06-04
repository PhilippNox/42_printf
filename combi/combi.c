/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:20:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 13:17:04 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/combi
// clear && gcc -Wall -Wextra combi.c  && ./a.out


#include <stdio.h>
#define SIZE 4 + 1
#define ON  '1'
#define OFF '2'

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		idx++;
	}
	return (idx);
}

int	isOneOf(char target, char *str)
{
	int idx;

	idx = -1;
	while (str[++idx])
		if (str[idx] == target)
			return (1);
	return (0);
}

void	cmparr(char *out, char *target)
{
	int idx;

	idx = -1;
	while (++idx < SIZE)
		out[idx] = target[idx];
}

void	show(char input[SIZE], char used[SIZE])
{
	char mem[SIZE];
	char idx;

	idx = -1;
	while (++idx < SIZE)
	{
		if (used[idx] == ON)
			break;
	}
	//printf("idx = %d\t", idx);
	if (idx == SIZE)
		return ;
	idx = -1;
	while (++idx < SIZE)
	{
		if (used[idx] == ON)
			printf("%c", input[idx]);
	}
	printf("\tused=[%s]", used);
	printf("\n");
	idx = -1;
	while (++idx < SIZE)
	{
		if (used[idx] == ON)
		{
			cmparr(mem, used);
			mem[idx] = OFF;
			//printf("\twhile _used=[%s]", used); printf("\tmem=[%s]\n", mem);
			show(input, mem);
		}
	}
	// printf("\tafter _used=[%s]", used); printf("\tmem=[%s]\n", mem);
}

int main(void)
{
	char input[SIZE] = "1234";
	char used[SIZE] = "1111";

	show(input, used);
}

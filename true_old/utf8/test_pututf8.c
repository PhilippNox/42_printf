/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pututf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 22:39:08 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 02:03:09 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/utf8
// clear && gcc -Wall -Wextra -Werror test_pututf8.c && time ./a.out

# include <unistd.h>
# include <stdio.h>

void show_bytes(unsigned int c)
{
	int idx;
	unsigned int mask;

	mask = 0x80000000;
	idx = -1;
	while (++idx < 32)
	{
		if (idx % 8 == 0)
			write(1, "_", 1);
		if ((mask >> idx) & c)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "_\n", 2);
}

int	ft_pututf8_(char const *s)
{
	int idx;

	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;

	write(1, s, idx);
	return (idx);
}

int	ft_putcharnew(int c)
{
	show_bytes(c);
	return (ft_pututf8_((char *)&c));
}

int	ft_putstrutf8(char const *s)
{
	int idx;
	int printed;

	if (!s)
		return (0);

	printed = 0;
	idx = 0;
	while (*(s + idx))
	{
		idx += ft_pututf8_(s + idx);
		printed++;
	}
	return (printed);
}

int main() {
	char *str;
	int num;

	str = "Зыс👈";
	//str = "Зы";
	//str = "abc";
	num = ft_putstrutf8(str);
	printf("\nnum= %d\n", num);
	num = ft_putcharnew('\n');
	printf("\nnum= %d\n", num);
}

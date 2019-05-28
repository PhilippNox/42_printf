/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 22:39:08 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 02:01:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/utf8
// clear && gcc -Wall -Wextra -Werror test_putchar.c && time ./a.out

# include <unistd.h>

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

void show_utf8(unsigned int c)
{
	unsigned char bytes[4];

	bytes[0] = (c & 0xFF000000) >> 24;
	bytes[1] = (c & 0x00FF0000) >> 16;
	bytes[2] = (c & 0x0000FF00) >> 8;
	bytes[3] = (c & 0x000000FF);

	show_bytes(bytes[0]);
	show_bytes(bytes[1]);
	show_bytes(bytes[2]);
	show_bytes(bytes[3]);

	if (bytes[0])
		write(1, bytes, 1);
	if (bytes[1])
		write(1, bytes + 1, 1);
	if (bytes[2])
		write(1, bytes + 2, 1);
	if (bytes[3])
		write(1, bytes + 3, 1);

}

int main() {
	unsigned int c;

	c = 100;
	c = 53398; //0x0000D096
	c = 0xF09F9188; //👈
	show_bytes(c);
	write(1, ">>>>\n", 5);
	show_utf8(c);

	write(1, "\n", 1);
}

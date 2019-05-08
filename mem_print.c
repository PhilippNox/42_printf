/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:50:20 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 22:47:16 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror mem_print.c && ./a.out

// https://www.h-schmidt.net/FloatConverter/IEEE754.html

#include <stdio.h>
#include <string.h>

union Data {
	int i;
	char str[4];
	float f;
};

int main( ) {

	union Data data;

	data.i = 16448; // ""@@" // 0100'0000 0100'0000
	data.f = -169952862;
	data.i = 1073741824 + 64;

	int idx = -1;
	int byte = -1;
	int mask = 1;
	while(++idx < 32)
	{
		printf("%d", (data.i & mask) / mask);
		printf(" %d\n", mask);
		mask = mask << 1;
	}
	printf("\n");

	printf( "Human view\n");
	idx = -1;
	byte = -1;
	mask = -2147483648;
	while (++byte < 4)
	{
		idx = -1;
		while(++idx < 8)
		{
			printf("%d", (data.i & mask) / mask);
			mask = (mask < 0) ? -(mask >> 1) : mask >> 1;
			if (idx != 7 && (idx + 1) % 4 == 0)
				printf("'");
		}
		printf("  ");
	}
	printf("\n\n");

	printf( "Machine view\n");
	idx = -1;
	byte = -1;
	unsigned char mask_c = 128;
	while (++byte < 4)
	{
		idx = -1;
		mask_c = 128;
		while(++idx < 8)
		{
			printf("%d", (data.str[byte] & mask_c) / mask_c);
			mask_c = mask_c >> 1;
			if (idx != 7 && (idx + 1) % 4 == 0)
				printf("'");
		}
		printf("  ");
	}
	printf("\n\n");

	printf( "Integer view\n%d\n\n", data.i);
	printf( "String view\n%s\n\n", data.str);
	printf( "Float view\n%f\n\n", data.f);

	return (0);
}

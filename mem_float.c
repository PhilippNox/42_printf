/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:50:20 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/20 18:29:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clear && gcc -Wall -Wextra -Werror mem_float.c && ./a.out

// https://www.h-schmidt.net/FloatConverter/IEEE754.html

#include "printf.h"

typedef	struct		s_str_num
{
	char	num[LEN_STR_NUM];
	int		exp;
}	t_str_num;

void	init_str_num(t_str_num input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_NUM)
		input.num[idx] = '\0';
	input.exp = 0;
}

void	test_bin()
{
	int b;
	// 16
	// 0001'0000  0000'0000  0000'0000  0000'0000
	b = 0x00000010;
	printf("%d\n", b);
	// 8
	b = 0x00000008;
	printf("%d\n", b);
}

void	show_mem(union Data data)
{
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
	printf( "Float view\n%.100f\n\n", data.f);
}


//	SRC: https://en.wikipedia.org/wiki/Single-precision_floating-point_format
//	mask for exponent: https://en.wikipedia.org/wiki/Single-precision_floating-point_format#/media/File:Float_example.svg
//	mask for exponent: http://marker.to/K8jIgi
//		01111111100000000000000000000000

//	SRC: https://www.binaryconvert.com/convert_unsigned_int.html
//		0x7F800000

//	right shift logical: so we can use tmp as unsigned int
//		>> 23

//	exp_val: https://wikimedia.org/api/rest_v1/media/math/render/svg/15f92e12d6d0a7c02be4f12c83007940c432ba87
//	exp_val: http://marker.to/7fHwIT
void	show_exp_bits(union Data data)
{
	unsigned int tmp;
	int mask;
	int exp_val;

	mask = 0x7F800000;
	tmp = data.i & mask;
	tmp = tmp >> 23;
	printf("%d\n", tmp);
	exp_val = tmp - 127;
	printf("%d\n", exp_val);
}

int		get_exp_val(union Data data)
{
	unsigned int tmp;
	int mask;

	mask = 0x7F800000;
	tmp = data.i & mask;
	tmp = tmp >> 23;
	return (tmp - 127);
}

//	00000000100000000000000000000000
void	get_degrees(union Data data, int exp_val, short *list, int size)
{
	int idx;
	int idx_list;
	int mask;

	idx = -1;
	while (++idx < size)
	{
		list[idx] = STOP_SHORT;
	}
	list[0] = exp_val; // 1 + fraction
	idx = 0;
	idx_list = 1;
	mask = 0x00800000;
	while (++idx < size)
	{
		mask = mask >> 1;
		if (data.i & mask)
		{
			list[idx_list++] = exp_val - idx;
			//printf("pos=%d\tdeg=%d\n", idx, exp_val - idx);
		}
	}
}

void	print_arr(short *list, int size)
{
	int idx;

	idx = -1;
	printf("[ ");
	while (++idx < size)
		printf("%d, ", list[idx]);
	printf("]");
}

/*
int		main(void)
{
	union Data data;
	short list[24];
	//test_bin();
	//printf("%zu\n",sizeof(float));

	data.f = 11879546;
	data.f = 2.0;
	data.f = 131072.0;
	data.f = 131072.65625;
	//show_exp_bits(data);
	printf("%d\n", get_exp_val(data));
	get_degrees(data, get_exp_val(data), list, 24);
	print_arr(list, 24);

	//data.i = 16;
	//show_mem(data);


	return (0);
}
*/

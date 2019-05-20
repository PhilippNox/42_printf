/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:19:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/20 18:29:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define LEN_STR_NUM 400
# define STOP_SHORT -32768

# include <stdio.h>
# include <string.h>


union Data {
	int i;
	char str[4];
	float f;
};

typedef	struct		sum_t_str
{
	char	ent[LEN_STR_NUM];
	char	frc[LEN_STR_NUM];
	int		idx_ent;
	int		idx_frc;
} t_str;

void	get_degrees(union Data data, int exp_val, short *list, int size);
int		get_exp_val(union Data data);
void	print_arr(short *list, int size);

#endif

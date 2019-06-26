/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost_neg_14336.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 01:54:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

char	*boost_neg_14336_part6(void)
{
	return ("929714074296331987308511003421404604532997823947493210518599504117"
	"744731");
}

void	boost_neg_14336(t_str_f *input)
{
	char	*(*boost_fun[7])(void);

	boost_fun[0] = &boost_neg_14336_part1;
	boost_fun[1] = &boost_neg_14336_part2;
	boost_fun[2] = &boost_neg_14336_part3;
	boost_fun[3] = &boost_neg_14336_part4;
	boost_fun[4] = &boost_neg_14336_part5;
	boost_fun[5] = &boost_neg_14336_part6;
	boost_fun[6] = NULL;
	boost_neg_do(input, boost_fun);
}

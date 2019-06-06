/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 00:31:47 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	make_f(t_task *input, va_list *ap)
{
	t_str_f target;
	int len;
	int len_num;

	get_precision_f(&target, (float)va_arg(*ap, double));
	//print_t_str_f_full(&target);
	print_t_str_f(&target);

	return (1);
}

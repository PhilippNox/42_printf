/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost_pos_4096.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/21 20:21:55 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

char	*boost4096_part1(void)
{
	return ("633091451304043807408342090634330837187029206131115194612376627981"
	"76431420310030958062130184677983375818922540892911487058384147801961662904"
	"42007547130259182194886923736471756481228657080555613349113740709238710529"
	"56554768944817718426477102964997090699597998950352762058322374367564187109"
	"17999874403704465824380762963161920954013608312361845177324617505032891947"
	"65492147006160448498782877865933692212003967895094931609623225607154353234"
	"59287948455197972488272485090431138601172497155116993315097289954531951709"
	"41048742157358207391463612997058459157660087671096131320289679107243820122"
	"68067800835381375280165423195056083207164912944765952684874432140038995220"
	"55521863648294813122157656338190881738528697312510339114963616389967055962"
	"88027923015505833386639057616071480094314098100157469493627811878043769443"
	"44197328136841925889555383961455124177689932795105209503446966203039643282"
	"34354975995049062091036509649587787188679839686600920895387779764411906811"
	"04784048217040730850780970869471668544348643327654721779393881367362264955"
	"81100708244138173834310951630438999073456796595497725631587806323627063975"
	"81834375789738262934417601098043855799439118628848654755179709359382384332"
	"4830873837409424699752834266170172571966052513141888834401");
}

void	boost4096(t_str_f *input)
{
	int		idx;
	char	*boost;

	input->idx_ent = 0;
	boost = boost4096_part1();
	idx = -1;
	while (boost[++idx])
		input->ent[input->idx_ent++] = boost[idx] - 48;
	input->exp_ent = input->idx_ent - 1;
}
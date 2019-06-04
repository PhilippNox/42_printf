/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:20:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 15:51:58 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/combi
// clear && gcc -Wall -Wextra combi.c  && ./a.out
// clear && gcc -Wall -Wextra combi.c  && ./a.out | wc -l


#include <stdio.h>
#include <stdlib.h>
#define TARGET	"#0 -+nm"
#define BEFORE	"_"
#define COUNT 0
#define AFTERCOUNT	"[%"
#define AFTER	"]"

typedef	struct	s_combi
{
	char *input;
	char *glob_mem;

	int stop_hash;
	int size;
	char show_hash;
	char use_glob;
	char *before;
	int count;
	char *after_count;
	char *after;
} t_combi;

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

int power10(int p)
{
	if (p == 0)
		return (1);
	return power10(p - 1) * 10;
}

int valueOfOrder(int num, int order)
{
	if (num < power10(order))
		return (-1);
	return (num % (power10(order + 1)) / power10(order));
}

void	show(t_combi *task, int used)
{
	int mem;
	char idx;

	if (used == task->stop_hash)
		return ;
	idx = -1;
	printf("%s", task->before);
	if (task->count >= 0)
		printf("%d", task->count);
	printf("%s", task->after_count);
	while (++idx < task->size)
	{
		if (valueOfOrder(used, idx) != 1)
			printf("%c", *(task->input + idx));
	}
	printf("%s", task->after);
	if (task->show_hash)
		printf("\tused=[%d]", used);
	printf("\n");
	if (task->count >= 0)
		task->count++;
	idx = -1;
	while (++idx < task->size)
	{
		if (valueOfOrder(used, idx) != 1)
		{
			mem = used;
			mem += power10(idx);
			if (task->glob_mem[mem] == 0)
			{
				show(task, mem);
				if (task->use_glob)
					task->glob_mem[mem] = 1;
			}
		}
	}
}

char	*init_glob_mem(int hash)
{
	int idx;
	char *glob_mem;

	idx = -1;
	glob_mem = (char *)malloc(hash);
	if (!glob_mem)
		return (NULL);
	//printf("task->stop_hash= %d\n", hash);
	while (++idx < hash)
		glob_mem[idx] = 0;
	return (glob_mem);
}

int	init_stop_hash(int order)
{
	int out;
	int idx;

	idx = -1;
	out = 0;
	while (++idx < order)
		out += power10(idx);
	return (out);
}

int	init_combi(t_combi *task)
{
	task->input = TARGET;
	task->before = BEFORE;
	task->count = COUNT;
	task->after_count = AFTERCOUNT;
	task->after = AFTER;

	task->size = ft_strlen(task->input);
	task->stop_hash = init_stop_hash(task->size);
	task->glob_mem = init_glob_mem(task->stop_hash);
	if (!task->glob_mem)
		return (1);
	task->show_hash = 0;
	task->use_glob = 1;
	return (0);
}

void	end_combi(t_combi *task)
{
	free(task->glob_mem);
}

int main(void)
{
	t_combi task;

	if (init_combi(&task))
		return (1);
	show(&task, 0);
	end_combi(&task);
}

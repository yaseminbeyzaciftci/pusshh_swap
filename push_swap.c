/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:43 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 07:50:46 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdlib.h>

void	push_swap(char **av)
{
	t_stack		stack;
	int			size;
	int			i;

	i = -1;
	size = push_swap_strlen(av);
	stack.stack_a = malloc(size * sizeof(int));
	if (!stack.stack_a)
		return ;
	stack.stack_size_a = size;
	stack.stack_b = malloc(size * sizeof(int));
	if (!stack.stack_b)
	{
		free(stack.stack_a);
		return ;
	}
	stack.stack_size_b = 0;
	while (++i < size)
		stack.stack_a[i] = push_swap_atoi(av[i], stack.stack_a);
	check_doubles(stack.stack_a, size);
	sort(&stack, size);
	free(stack.stack_a);
	free(stack.stack_b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		return (0);
	}
	return (0);
}

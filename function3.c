/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:30 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 08:02:28 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	reverse_rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->stack_size_a == 0 || stack->stack_size_a == 1)
		return ;
	i = stack->stack_size_a - 1;
	tmp = stack->stack_a[i];
	while (i)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = tmp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->stack_size_b == 0 || stack->stack_size_b == 1)
		return ;
	i = stack->stack_size_b - 1;
	tmp = stack->stack_b[i];
	while (i)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->stack_size_a == 0 || stack->stack_size_a == 1
		|| (stack->stack_size_b == 0 || stack->stack_size_b == 1))
		return ;
	i = stack->stack_size_a - 1;
	tmp = stack->stack_a[i];
	while (i)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[i] = tmp;
	i = stack->stack_size_b - 1;
	tmp = stack->stack_b[i];
	while (i--)
		stack->stack_b[i] = stack->stack_b[i - 1];
	stack->stack_b[i] = tmp;
	write(1, "rrr\n", 4);
}

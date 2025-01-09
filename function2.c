/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:24 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 08:59:47 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;
	
	if (stack->stack_size_a == 0 || stack->stack_size_a == 1)
		return ;
	i = 0;
	tmp = stack->stack_a[i];
	i++;
	while (i < stack->stack_size_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->stack_size_b == 0 || stack->stack_size_b == 1)
		return ;
	i = 0;
	tmp = stack->stack_b[i];
	i++;
	while (i < stack->stack_size_b)
	{
		stack->stack_b[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->stack_size_a == 0 || stack->stack_size_a == 1
		|| (stack->stack_size_b == 0 || stack->stack_size_b == 1))
		return ;
	i = 0;
	tmp = stack->stack_a[i];
	while (++i < stack->stack_size_a)
		stack->stack_a[i - 1] = stack->stack_a[i];
	stack->stack_a[i - 1] = tmp;
	i = 0;
	tmp = stack->stack_b[i];
	while (++i < stack->stack_size_b)
		stack->stack_a[i - 1] = stack->stack_b[i];
	stack->stack_b[i - 1] = tmp;
	write(1, "rr\n", 3);
}

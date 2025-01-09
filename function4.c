/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:37 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 08:02:38 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->stack_size_a == 0 || stack->stack_size_a == 1)
		return ;
	tmp = 0;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->stack_size_b == 0 || stack->stack_size_b == 1)
		return ;
	tmp = 0;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	write(1, "sb\n", 3);
}

void	swap_s(t_stack *stack)
{
	int	tmp;

	if (stack->stack_size_a == 0 || stack->stack_size_a == 1
		|| (stack->stack_size_b == 0 || stack->stack_size_b == 1))
		return ;
	tmp = 0;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	write(1, "ss\n", 3);
}

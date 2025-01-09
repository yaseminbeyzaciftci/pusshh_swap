/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:15 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 08:26:04 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_b(t_stack *stack)
{
	int	i;

	if (stack->stack_size_a)
	{
		stack->stack_size_b++;
		i = stack->stack_size_b;
		while (--i > 0)
			stack->stack_b[i] = stack->stack_b[i - 1];
		stack->stack_b[0] = stack->stack_a[0];
		i = -1;
		stack->stack_size_a--;
		while (++i < stack->stack_size_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
		}
		write(1, "pb\n", 3);
	}
	else
		return ;
}

void	push_a(t_stack *stack)
{
	int	i;

	if (stack->stack_size_b)
	{
		stack->stack_size_a++;
		i = stack->stack_size_a;
		while (--i > 0)
			stack->stack_a[i] = stack->stack_a[i - 1];
		stack->stack_a[0] = stack->stack_b[0];
		i = -1;
		stack->stack_size_b--;
		while (++i < stack->stack_size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
		}
		write(1, "pa\n", 3);
	}
	else
		return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:04 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 09:29:36 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	temporary_sort(int *stack_temp, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_temp[i] > stack_temp[j])
			{
				temp = stack_temp[i];
				stack_temp[i] = stack_temp[j];
				stack_temp[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_case_stack_a(t_stack *three)
{
	if (three->stack_a[0] > three->stack_a[1] && three->stack_a[0]\
		< three->stack_a[2] && three->stack_a[1] < three->stack_a[2])
		swap_a(three);
	else if (three->stack_a[0] > three->stack_a[1] && three->stack_a[0]\
		> three->stack_a[2] && three->stack_a[1] > three->stack_a[2])
	{
		swap_a(three);
		reverse_rotate_a(three);
	}
	else if (three->stack_a[0] > three->stack_a[1] && three->stack_a[0]\
		> three->stack_a[2] && three->stack_a[1] < three->stack_a[2])
		rotate_a(three);
	else if (three->stack_a[0] < three->stack_a[1] && three->stack_a[0]\
		< three->stack_a[2] && three->stack_a[1] > three->stack_a[2])
	{
		swap_a(three);
		rotate_a(three);
	}
	else if (three->stack_a[0] < three->stack_a[1] && three->stack_a[0]\
		> three->stack_a[2] && three->stack_a[1] > three->stack_a[2])
		reverse_rotate_a(three);
}

int	sort(t_stack *stack, int size)
{
	if (check_sorted(stack->stack_a, stack->stack_size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack);
		else if (size == 3)
			three_numbers_case_stack_a(stack);
		else
			quicksort_stack_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stack	*stack, int len, int push)
{
	if (push == 0)
		push_b(stack);
	else
		push_a(stack);
	len--;
	return (len);
}

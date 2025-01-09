/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:08:58 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 09:34:27 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	quicksort_three_stack_a_and_b(t_stack *stack, int len)
{
	if (len == 3 && stack->stack_size_a == 3)
		three_numbers_case_stack_a(stack);
	else if (len == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->stack_a[0] < stack->stack_a[1]
				&& stack->stack_a[1] < stack->stack_a[2]))
		{
			if (len == 3 && stack->stack_a[0] > stack->stack_a[1]
				&& stack->stack_a[2])
				swap_a(stack);
			else if (len == 3 && !(stack->stack_a[2] > stack->stack_a[0]
					&& stack->stack_a[2] > stack->stack_a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->stack_a[0] > stack->stack_a[1])
				swap_a(stack);
			else if (len++)
				push_a(stack);
		}
	}
}

int	sort_three_b(t_stack *stack, int len)
{
	if (len == 1)
		push_a(stack);
	else if (len == 2)
	{
		if (stack->stack_b[0] < stack->stack_b[1])
			swap_b(stack);
		while (len--)
			push_a(stack);
	}
	else if (len == 3)
	{
		while (len || !(stack->stack_a[0] < stack->stack_a[1]
				&& stack->stack_a[1] < stack->stack_a[2]))
		{
			if (len == 1 && stack->stack_a[0] > stack->stack_a[1])
				swap_a(stack);
			else if (len == 1 || (len >= 2
					&& stack->stack_b[0] > stack->stack_b[1])
				|| (len == 3 && stack->stack_b[0] > stack->stack_b[2]))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack);
		}
	}
	return (0);
}

int	mediane_of_numbers(int *pivot, int *pile, int size)
{
	int		*temporaire_pile;
	int		i;

	temporaire_pile = (int *)malloc(size * sizeof(int));
	if (!temporaire_pile)
		return (0);
	i = 0;
	while (i < size)
	{
		temporaire_pile[i] = pile[i];
		i++;
	}
	temporary_sort(temporaire_pile, size);
	*pivot = temporaire_pile[size / 2];
	free(temporaire_pile);
	return (1);
}

int	quicksort_stack_a(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stack->stack_a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_three_stack_a_and_b(stack, len);
		return (1);
	}
	if (!mediane_of_numbers(&pivot, stack->stack_a, len))
		return (0);
	while (len != (numbers / 2 + numbers % 2))
	{
		if (stack->stack_a[0] < pivot && (len--))
			push_b(stack);
		else if (++count_r)
			rotate_a(stack);
	}
	while (numbers / 2 + numbers % 2 != stack->stack_size_a && count_r--)
		reverse_rotate_a(stack);
	return (quicksort_stack_a(stack, (numbers / 2) + (numbers % 2), 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
	return (1);
}

int	quicksort_stack_b(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stack->stack_b, len, 1) == 1)
		while (len--)
			push_a(stack);
	else if (len <= 3)
	{
		sort_three_b(stack, len);
		return (1);
	}
	numbers = len;
	if (!mediane_of_numbers(&pivot, stack->stack_b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->stack_b[0] >= pivot && len--)
			push_a(stack);
		else if (++count_r)
			rotate_b(stack);
	}
	while (numbers / 2 != stack->stack_size_b && count_r--)
		reverse_rotate_b(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}

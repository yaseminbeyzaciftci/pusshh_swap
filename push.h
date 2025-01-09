/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:18:28 by yaciftci          #+#    #+#             */
/*   Updated: 2025/01/09 08:00:57 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	stack_size_a;
	int	stack_size_b;
}	t_stack;

char	**ft_split(char const *s, char c);

void	push_swap(char **av);
int		push_swap_strlen(char **av);
void	error_detected(int *pile);
int		push_swap_atoi(char *str, int *pile);
void	check_doubles(int *pile, int size);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

int		sort(t_stack *stack, int size);
int		check_sorted(int *pile, int size, int order);
void	three_numbers_case_stack_a(t_stack *three);
void	temporary_sort(int *pile_temporaire, int size);

int		quicksort_stack_a(t_stack *stack, int len, int count_r);
int		quicksort_stack_b(t_stack *stack, int len, int count_r);
void	quicksort_three_stack_a_and_b(t_stack *stack, int len);
int		sort_three_b(t_stack *stack, int len);
int		ft_push(t_stack *stack, int len, int pb);
int		mediane_of_numbers(int *pivot, int *pile, int size);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:51:00 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/20 19:51:05 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (0);
	max = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (0);
	min = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*mid_pos_in_stack_a(t_stack *stack, t_stack *node)
{
	while (!(stack->value > node->value
			&& stack->prev->value < node->value))
		stack = stack->prev;
	return (stack);
}

t_stack	*mid_pos_in_stack_b(t_stack *stack, t_stack *node)
{
	while (!(stack->value < node->value
			&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}

t_stack	*min_step(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (stack->steps->move < min->steps->move)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

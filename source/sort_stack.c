/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:48:42 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/17 18:48:44 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

char	*method_3(t_stack *stack_a, char *op)
{
	t_stack	*max;

	max = ft_max(stack_a);
	if (stack_a->value == max->value)
		op = manager(&stack_a, NULL, op, RA);
	else if (stack_a->next->value == max->value)
		op = manager(&stack_a, NULL, op, RRA);
	if (!is_sorted(stack_a, 3))
		op = manager(&stack_a, NULL, op, SA);
	return (op);
}

char	*push_to_a(t_stack *stack_a, t_stack *stack_b, char *op)
{
	t_stack	*min_a;
	t_stack	*max_a;
	t_stack	*max_b;

	while (stack_b)
	{
		min_a = ft_min(stack_a);
		max_a = ft_max(stack_a);
		if (stack_b->value < min_a->value || stack_b->value > max_a->value)
			op = rotate_direction(stack_a, min_a->value, 'A', op);
		else
		{
			max_b = mid_pos_in_stack_a(stack_a, stack_b);
			op = rotate_direction(stack_a, max_b->value, 'A', op);
		}
		op = manager(&stack_a, &stack_b, op, PA);
	}
	return (op);
}

char	*method_big_number(t_stack *stack_a, t_stack *stack_b, char *op)
{
	t_stack	*min;

	while (ft_lstsize(stack_a) > 3 && !is_ordered(stack_a))
	{
		op = manager(&stack_a, &stack_b, op, PB);
		if (ft_lstsize(stack_a) != 3 && ft_lstsize(stack_b) != 1)
			stack_a = count_steps(stack_a, stack_b);
		if (stack_a->steps && stack_a->steps->move)
			op = push_to_b(stack_a, stack_b, op);
	}
	if (ft_lstsize(stack_a) == 3)
		op = method_3(stack_a, op);
	else
	{
		min = ft_min(stack_a);
		op = rotate_direction(stack_a, min->value, 'A', op);
	}
	if (stack_b)
		op = push_to_a(stack_a, stack_b, op);
	return (op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:02:36 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/29 12:02:39 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

char	*rotation_manager(t_stack *stack_a, t_stack *stack_b,
		int *size_flag, char *op)
{
	int	size;
	int	flag;

	size = size_flag[0];
	flag = size_flag[1];
	while (size--)
		op = manager(&stack_a, &stack_b, op, flag);
	return (op);
}

char	*rrr_rr(t_stack *stack_a, t_stack *stack_b, t_step *steps, char *op)
{
	int	size_flag[2];

	size_flag[1] = -1;
	if (steps->move_a < 0 && steps->move_b < 0)
	{
		size_flag[1] = RRR;
		steps->move_a *= -1;
		steps->move_b *= -1;
	}
	else if (steps->move_a > 0 && steps->move_b > 0)
		size_flag[1] = RR;
	size_flag[0] = line_condition(steps->move_a < steps->move_b,
			steps->move_a, steps->move_b);
	steps->move_a = line_condition(size_flag[1] == RRR,
			-1, 1) * (steps->move_a - size_flag[0]);
	steps->move_b = line_condition(size_flag[1] == RRR,
			-1, 1) * (steps->move_b - size_flag[0]);
	return (rotation_manager(stack_a, stack_b, size_flag, op));
}

char	*ra_rb2(t_stack *stack, t_step *steps, int *size_flag, char *op)
{
	if (steps->move_a != 0 && (size_flag[1] == RA || size_flag[1] == RRA))
	{
		size_flag[0] = steps->move_a;
		op = rotation_manager(stack, NULL, size_flag, op);
	}
	if (steps->move_b != 0 && (size_flag[1] == RB || size_flag[1] == RRB))
	{
		size_flag[0] = steps->move_b;
		op = rotation_manager(NULL, stack, size_flag, op);
	}
	return (op);
}

char	*ra_rb(t_stack *stack_a, t_stack *stack_b, t_step *steps, char *op)
{
	int	size_flag[2];

	size_flag[1] = -1;
	if (steps->move_a < 0)
	{
		size_flag[1] = RRA;
		steps->move_a *= -1;
	}
	else if (steps->move_a > 0)
		size_flag[1] = RA;
	if (steps->move_a != 0)
		op = ra_rb2(stack_a, steps, size_flag, op);
	if (steps->move_b < 0)
	{
		size_flag[1] = RRB;
		steps->move_b *= -1;
	}
	else if (steps->move_b > 0)
		size_flag[1] = RB;
	if (steps->move_b != 0)
		op = ra_rb2(stack_b, steps, size_flag, op);
	return (op);
}

char	*push_to_b(t_stack *stack_a, t_stack *stack_b, char *op)
{
	t_stack	*min;

	min = min_step(stack_a);
	if ((min->steps->move_a < 0 && min->steps->move_b < 0)
		|| (min->steps->move_a > 0 && min->steps->move_b > 0))
		op = rrr_rr(stack_a, stack_b, min->steps, op);
	op = ra_rb(stack_a, stack_b, min->steps, op);
	return (op);
}

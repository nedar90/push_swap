/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:47:28 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/26 13:47:42 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	fill_move(t_step *steps, int move, int move_a, int move_b)
{
	steps->move = move;
	steps->move_a = move_a;
	steps->move_b = move_b;
}

void	min_move(t_step *steps, int *size, int cur_pos_a, int cur_pos_b)
{
	int		diff_a;
	int		diff_b;

	fill_move(steps, line_condition(cur_pos_a > cur_pos_b,
			cur_pos_a, cur_pos_b),
		cur_pos_a, cur_pos_b);
	diff_a = size[0] - cur_pos_a;
	diff_b = size[1] - cur_pos_b;
	if (line_condition((diff_a) > (diff_b), (diff_a), (diff_b)) < steps->move)
		fill_move(steps, line_condition((diff_a) > (diff_b),
				(diff_a), (diff_b)),
			line_condition(!cur_pos_a, 0, -diff_a),
			line_condition(!cur_pos_b, 0, -diff_b));
	if (cur_pos_a + (diff_b) < steps->move)
		fill_move(steps, cur_pos_a + (diff_b), cur_pos_a,
			line_condition(!cur_pos_b, 0, -diff_b));
	if ((diff_a) + cur_pos_b < steps->move)
		fill_move(steps, (diff_a) + cur_pos_b,
			line_condition(!cur_pos_a, 0, -diff_a), cur_pos_b);
}

t_stack	*count_steps(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*b;
	int		cur_pos_a;
	int		size[2];
	int		cur_pos_b;

	size[0] = ft_lstsize(stack_a);
	size[1] = ft_lstsize(stack_b);
	cur_pos_a = 0;
	while (1)
	{
		if (stack_a->value > ft_max(stack_b)->value
			|| stack_a->value < ft_min(stack_b)->value)
			b = ft_max(stack_b);
		else
			b = mid_pos_in_stack_b(stack_b, stack_a);
		cur_pos_b = find_position(stack_b, b->value);
		min_move(stack_a->steps, size, cur_pos_a, cur_pos_b);
		stack_a = stack_a->next;
		if (stack_a->title == 'h')
			break ;
		cur_pos_a++;
	}
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:53:44 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/20 19:53:46 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

char	*oper(int flag)
{
	if (flag == SA)
		return ("sa");
	if (flag == SB)
		return ("sb");
	if (flag == SS)
		return ("ss");
	if (flag == PA)
		return ("pa");
	if (flag == PB)
		return ("pb");
	if (flag == RA)
		return ("ra");
	if (flag == RB)
		return ("rb");
	if (flag == RR)
		return ("rr");
	if (flag == RRA)
		return ("rra");
	if (flag == RRB)
		return ("rrb");
	if (flag == RRR)
		return ("rrr");
	return (0);
}

char	*manager(t_stack **stack_a, t_stack **stack_b, char *op, int flag)
{
	if (flag == SA || flag == SS)
		swap(*stack_a);
	if (flag == SB || flag == SS)
		swap(*stack_b);
	if (flag == PA)
		(*stack_b) = push(stack_b, stack_a);
	if (flag == PB)
		(*stack_a) = push(stack_a, stack_b);
	if (flag == RA || flag == RR)
		rotate(*stack_a);
	if (flag == RB || flag == RR)
		rotate(*stack_b);
	if (flag == RRA || flag == RRR)
		reverse_rotate(*stack_a);
	if (flag == RRB || flag == RRR)
		reverse_rotate(*stack_b);
	return (ft_strjoin(op, oper(flag)));
}

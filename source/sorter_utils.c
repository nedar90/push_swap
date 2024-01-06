/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:19:45 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/25 10:19:47 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	is_sorted(t_stack *stack, int len)
{
	if (!stack)
		return (0);
	while (--len)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_ordered(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	if (!stack)
		return (0);
	len = ft_lstsize(stack);
	tmp = stack;
	while (1)
	{
		if (is_sorted(tmp, len))
			return (1);
		tmp = tmp->next;
		if (tmp->title == 'h')
			break ;
	}
	return (0);
}

int	find_position(t_stack *stack, long num)
{
	int		size;
	t_stack	*lst;

	size = 0;
	lst = stack;
	while (lst->value != num)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char	*rotate_direction(t_stack *stack, int num, int flag, char *op)
{
	int		pos;
	int		len;
	t_stack	**first;
	t_stack	**second;

	first = NULL ;
	second = NULL ;
	if (flag == 'A')
		first = &stack;
	else
		second = &stack;
	pos = find_position(stack, num);
	len = ft_lstsize(stack);
	if (len == 2 && stack->value != num)
		op = manager(first, second, op,
				line_condition(flag == 'A', SA, SB));
	if (len - pos > pos)
		while (stack->value != num)
			op = manager(first, second, op,
					line_condition(flag == 'A', RA, RB));
	else
		while (stack->value != num)
			op = manager(first, second, op,
					line_condition(flag == 'A', RRA, RRB));
	return (op);
}

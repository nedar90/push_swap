/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:48:00 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/11 17:48:04 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	size;

	if (!stack)
		return ;
	tmp = stack->value;
	size = ft_lstsize(stack);
	while (--size)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = tmp;
	stack = stack->next;
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->prev->value;
	stack = stack->prev;
	while (stack->title != 'h')
	{
		stack->value = stack->prev->value;
		stack = stack->prev;
	}
	stack->value = tmp;
}

t_stack	*push(t_stack **head_from, t_stack **head_to)
{
	t_stack	*cpy_next;
	t_stack	*cpy_prev;
	int		flag;

	if (!head_from)
		return (NULL);
	flag = 0;
	if (ft_lstsize(*head_from) == 1)
		flag = 1;
	cpy_next = (*head_from)->next;
	cpy_prev = (*head_from)->prev;
	ft_lstadd_front(head_from, head_to);
	if (flag == 1)
		return (NULL);
	cpy_next->prev = cpy_prev;
	cpy_prev->next = cpy_next;
	cpy_next->title = 'h';
	return (cpy_next);
}

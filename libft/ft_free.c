/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:37:09 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/15 13:37:13 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	(*stack)->prev->next = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		if ((*stack)->steps)
			free ((*stack)->steps);
		free (*stack);
		(*stack) = tmp;
	}
}

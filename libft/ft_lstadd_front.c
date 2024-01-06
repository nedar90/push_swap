/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:03:28 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/26 09:03:31 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **from, t_stack **to)
{
	if (!(*from))
		return ;
	if (!(*to))
	{
		*to = *from;
		(*to)->next = *from;
		(*to)->prev = *from;
	}
	else
	{
		(*to)->title = 0;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*from)->next = *to;
		(*to)->prev = *from;
		*to = *from;
	}
}

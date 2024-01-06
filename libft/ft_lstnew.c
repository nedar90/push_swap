/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:36:02 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/26 10:39:50 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(long content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = content;
	node->title = 0;
	node->steps = malloc(sizeof(t_step));
	if (!node->steps)
		return (NULL);
	node->steps->move = 0;
	node->steps->move_a = 0;
	node->steps->move_b = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

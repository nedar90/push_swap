/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:41:38 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/09 12:41:40 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_stack	*get_stack(int size, char **numbers)
{
	t_stack	*new;
	t_stack	*first;
	t_stack	*prev;
	int		index;

	if (!numbers || !*numbers)
		return (NULL);
	index = 0;
	new = ft_lstnew(ft_atoi(numbers[index]));
	new->title = 'h';
	first = new;
	while (++index < size -1)
	{
		prev = new;
		new = ft_lstnew(ft_atoi(numbers[index]));
		new->prev = prev;
		prev->next = new;
	}
	first->prev = new;
	new->next = first;
	return (first);
}

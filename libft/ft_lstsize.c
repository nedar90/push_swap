/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:44:10 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/26 12:44:40 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	lst = lst->next;
	while (lst->title != 'h')
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

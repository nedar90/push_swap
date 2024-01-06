/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:51:06 by nrajabia          #+#    #+#             */
/*   Updated: 2022/09/07 15:53:13 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s, int size)
{
	char	*ptr;
	int		count;

	if (!s || !*s)
		return (NULL);
	count = -1;
	ptr = malloc(size +2 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (++count <= size)
		ptr[count] = s[count];
	ptr[count] = '\0';
	free(s);
	return (ptr);
}

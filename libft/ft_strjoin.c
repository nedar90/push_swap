/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:25:31 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/16 17:25:48 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		num;

	if (!s2 || !*s2)
		return (NULL);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	num = 0;
	while (s1 && s1[num])
	{
		str[num] = s1[num];
		num++;
	}
	while (*s2 != '\0')
		str[num++] = *s2++;
	str[num++] = '\n';
	str[num] = '\0';
	if (s1)
		free(s1);
	return (str);
}

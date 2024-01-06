/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:35:14 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/02 15:50:27 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	int			sign;
	long		number;

	sign = 1;
	number = 0;
	while (*nptr == ' '
		|| (*nptr >= 10 && *nptr <= 13)
		|| *nptr == '\t')
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + *nptr - 48;
		nptr++;
	}
	return (sign * number);
}

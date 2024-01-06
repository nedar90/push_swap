/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:00:47 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/20 15:03:33 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;

	error_handle_str(ac, av);
	stack_a = get_stack(ac, av +1);
	error_handle_int(stack_a, ac);
	return (stack_a);
}

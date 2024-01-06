/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:46:55 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/20 15:04:27 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

char	*push_swap(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;
	t_stack	*min;

	stack_a = init_stack(ac, av);
	stack_b = NULL ;
	op = malloc(sizeof(*op));
	if (!op)
		return (0);
	op = 0;
	while (!is_sorted(stack_a, ac -1))
	{
		if (ac == 3)
			op = manager(&stack_a, NULL, op, SA);
		else if (is_ordered(stack_a))
		{
			min = ft_min(stack_a);
			op = rotate_direction(stack_a, min->value, 'A', op);
		}
		else
			op = method_big_number(stack_a, stack_b, op);
	}
	ft_free(&stack_a);
	return (op);
}

int	main(int ac, char **av)
{
	char	*op;

	op = push_swap(ac, av);
	if (op)
		ft_printf("%s", op);
	free(op);
}

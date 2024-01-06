/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:19:12 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/20 12:19:18 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libchecker.h"

int	reverse_push_swap(char *op)
{
	if (!op)
		return (-1);
	if (op[0] == 'p' && op[1] == 'a' && op[2] == '\n')
		return (PA);
	if (op[0] == 'p' && op[1] == 'b' && op[2] == '\n')
		return (PB);
	if (op[0] == 's' && op[1] == 's' && op[2] == '\n')
		return (SS);
	if (op[0] == 'r' && op[1] == 'a' && op[2] == '\n')
		return (RA);
	if (op[0] == 'r' && op[1] == 'b' && op[2] == '\n')
		return (RB);
	if (op[0] == 's' && op[1] == 'a' && op[2] == '\n')
		return (SA);
	if (op[0] == 's' && op[1] == 'b' && op[2] == '\n')
		return (SB);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && op[3] == '\n')
		return (RRA);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && op[3] == '\n')
		return (RRB);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && op[3] == '\n')
		return (RRR);
	if (op[0] == 'r' && op[1] == 'r')
		return (RR);
	return (-1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;
	int		i;
	int		flag;

	stack_a = init_stack(ac, av);
	stack_b = NULL;
	i = 0;
	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		flag = reverse_push_swap(op);
		if (flag == -1)
			ft_error();
		manager(&stack_a, &stack_b, NULL, flag);
		free(op);
	}
	if (is_sorted(stack_a, ac -1) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(&stack_a);
}

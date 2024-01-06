/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:40:21 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/08 13:40:24 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit (1);
}

int	is_digit(char **str, int ac)
{
	int	i;
	int	j;

	j = 0;
	while (str[++j] && j < ac)
	{
		i = -1;
		while (str[j][++i])
		{
			if (str[j][i] == '-')
				i++;
			if (str[j][i] < '0' || str[j][i] > '9')
				return (0);
		}
	}
	return (1);
}

void	error_handle_str(int ac, char **av)
{
	if (ac == 1)
		exit (EXIT_SUCCESS);
	if (!is_digit(av, ac))
		ft_error();
}

int	is_duplicate(t_stack *num, t_stack *stack, int len)
{
	t_stack	*cpy;

	cpy = stack;
	while (--len)
	{
		if (cpy->value == num->value && num != cpy)
			return (1);
		cpy = cpy->next;
	}
	return (0);
}

void	error_handle_int(t_stack *stack, int len)
{
	t_stack	*cpy;
	int		cpy_len;

	cpy = stack;
	cpy_len = len;
	while (--len)
	{
		if (cpy->value > INT_MAX)
		{
			ft_free(&stack);
			ft_error();
		}
		if (cpy->value < INT_MIN)
		{
			ft_free(&stack);
			ft_error();
		}
		if (is_duplicate(cpy, stack, cpy_len))
		{
			ft_free(&stack);
			ft_error();
		}
		cpy = cpy->next;
	}
}

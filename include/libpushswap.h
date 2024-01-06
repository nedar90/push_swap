/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:51:20 by nrajabia          #+#    #+#             */
/*   Updated: 2023/05/09 11:51:22 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include <ft_printf.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

int		is_sorted(t_stack *stack, int len);
int		is_ordered(t_stack *stack);
int		find_position(t_stack *stack, long num);
char	*push_to_b(t_stack *stack_a, t_stack *stack_b, char *op);
char	*rotate_direction(t_stack *stack, int num, int flag, char *op);
char	*method_big_number(t_stack *stack_a, t_stack *stack_b, char *op);
char	*method_3(t_stack *stack_a, char *op);
char	*manager(t_stack **stack_a, t_stack **stack_b, char *op, int flag);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
t_stack	*push(t_stack **head_from, t_stack **head_to);
t_stack	*count_steps(t_stack *stack_a, t_stack *stack_b);
t_stack	*init_stack(int ac, char **av);
t_stack	*get_stack(int size, char **numbers);

#endif

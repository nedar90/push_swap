/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <nrajabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:31:01 by nrajabia          #+#    #+#             */
/*   Updated: 2023/10/18 14:26:39 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ft_printf.h>

typedef struct s_step
{
	int	move;
	int	move_a;
	int	move_b;
}		t_step;

typedef struct s_stack
{
	long			value;
	char			title;
	struct s_step	*steps;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

t_stack	*ft_lstnew(long content);
t_stack	*ft_max_num(t_stack *stack, int len);
t_stack	*ft_max(t_stack *stack);
t_stack	*ft_min(t_stack *stack);
t_stack	*mid_pos_in_stack_a(t_stack *stack, t_stack *node);
t_stack	*mid_pos_in_stack_b(t_stack *stack, t_stack *node);
t_stack	*min_step(t_stack *stack);
void	ft_lstadd_front(t_stack **from, t_stack **to);
void	error_handle_int(t_stack *stack, int len);
void	error_handle_str(int ac, char **av);
void	ft_free(t_stack **stack);
void	ft_error(void);
long	ft_atoi(const char *nptr);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s, int size);
int		line_condition(int flag, int true_con, int false_con);
int		find_next_position(t_stack *stack, int position);
int		ft_lstsize(t_stack *lst);

#endif

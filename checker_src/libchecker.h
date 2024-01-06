/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libchecker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:20:01 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/20 12:25:55 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECKER_H
# define LIBCHECKER_H

# include "libpushswap.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define TRUE 1
# define FALSE 0

char	*get_next_line(int fd);
int		shift_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:29:35 by nrajabia          #+#    #+#             */
/*   Updated: 2023/03/13 09:41:18 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libchecker.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE +1];
	char		*line;
	int			num;

	if (BUFFER_SIZE < 1 || fd == -1 || FOPEN_MAX < fd)
		return (NULL);
	line = ft_strjoin_gnl(0, buff);
	if (shift_line(buff))
		return (line);
	num = read(fd, buff, BUFFER_SIZE);
	if (num < 0)
	{
		free(line);
		return (NULL);
	}
	while (num > 0)
	{
		line = ft_strjoin_gnl(line, buff);
		if (shift_line(buff))
			break ;
		num = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

/*int main(void)
{
    int x;
	char *str;
    x = open("accept.txt", O_RDONLY);
	str = get_next_line(x);
    printf("term 1: %s", str);
	free(str);
	str = get_next_line(x);
    printf("term 2: %s", str);
	free(str);
    //printf("term 3: %s", get_next_line(x));
    //printf("term 4: %s", get_next_line(x));
    //printf("term 5: %s", get_next_line(x));
    //printf("term 6: %s", get_next_line(x));
    //printf("term 7: %s", get_next_line(x));

    close(x);
    return (0);
}*/

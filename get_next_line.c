/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:53:34 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/21 17:23:36 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	static char*buff;
	char		*tmp;
	int			n;
	size_t		i;

	if (!(buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	n = 0;
	i = 0;
	while (read(fd, buff, BUFF_SIZE))
	{
		i = 0;
		while (i < BUFF_SIZE && buff[i] != '\n' && buff[i] != 0)
			i++;
		getchar();
		if (*line)
		{
			tmp = ft_strdup(*line);
			free(*line);
		}
		if (!(*line = (char *)malloc((n + i + 1) * sizeof(char))))
			return (-1);
		ft_strcpy(*line, tmp);
		i = 0;
		while (*buff && *buff != '\n' && *buff != 0)
		{
			(*line)[n + i] = *buff;
			buff++;
			i++;
		}
		if (buff[i] == '\n')
			return (1);
		n += i;
		buff -= i;
	}
	return (0);
}

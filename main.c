/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:01:29 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/21 16:59:46 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			ft_putstr(argv[i]);
			ft_putchar('\n');
			while (get_next_line(fd, &line))
			{
				ft_putstr(line);
				ft_putchar('\n');
				free(line);
			}
			i++;
		}
	}
	else
		ft_putstr("usage : gnl source_file1 source_file2\n");
	return (0);
}

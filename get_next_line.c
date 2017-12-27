/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:32:03 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/27 12:30:19 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_it(t_list **file, int fd)
{
	t_list	*node;

	node = *file;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	node = ft_lstnew("\0", fd);
	ft_lstadd(file, node);
	return (*file);
}

static int		line_it(int r, t_list *node, char **line)
{
	int		n;

	if (r < BUFF_SIZE && !ft_strlen(node->content))
		return (0);
	n = 0;
	while (node->content[n] && (node->content)[n] != '\n')
		n++;
	free(*line);
	if (!(*line = ft_strnew(n)))
		return (-1);
	if (!(*line = ft_strncat(*line, node->content, n)))
		return (-1);
	(n < (int)ft_strlen(node->content))
		? ft_strmove(&node->content, n + 1)
		: ft_strclr(node->content);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*file;
	int				r;
	t_list			*node;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	node = get_it(&file, fd);
	if (!(*line = ft_strdup("\0")))
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = 0;
		if (!(node->content = ft_strjoin_free(node->content, buff)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (line_it(r, node, line));
}

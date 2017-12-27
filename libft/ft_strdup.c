/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:29:44 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/27 12:27:27 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc((i + 1) * sizeof(*s2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strmove(char **s1, int n)
{
	char	*tmp;

	*s1 += n;
	tmp = ft_strdup(*s1);
	*s1 -= n;
	free(*s1);
	*s1 = tmp;
	return (*s1);
}

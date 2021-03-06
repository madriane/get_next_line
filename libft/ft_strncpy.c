/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:36:45 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/06 19:15:16 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *d, const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		d[i] = s[i];
		i++;
	}
	while (i < len)
	{
		d[i] = 0;
		i++;
	}
	return (d);
}

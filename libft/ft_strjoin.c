/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:05:54 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/27 12:00:42 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (tr == NULL)
		return (NULL);
	tr = ft_strcpy(tr, s1);
	tr = ft_strcat(tr, s2);
	return (tr);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tr;

	tr = ft_strjoin(s1, s2);
	free(s1);
	return (tr);
}

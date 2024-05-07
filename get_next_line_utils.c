/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:35 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/05/07 17:46:09 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int x)
{
	unsigned int	i;
	char			xc;

	xc = (char) x;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == xc)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == xc)
		return ((char *) &str[i]);
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)str;
	i = 0;
	if (src2 == 0 && dest2 == 0)
		return (0);
	if (src2 > dest2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	while (i < n)
	{
		dest2[n - 1] = src2[n - 1];
		n--;
	}
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 19:08:38 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>


char *get_next_line(int fd);
char	*ft_strchr(const char *str, int x);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dest, const void *str, size_t n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:35 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/05/09 15:35:22 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prepare_the_recall(t_list	**list)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean)
		return ;

	last = look_for_end(*list);
	if (last == NULL)
	{
		free(buf);
		free(clean);
		return;
	}

	i = 0;
	k = 0;
	while (last->buffer_str[i] && last->buffer_str[i] != '\n')
		++i;
	if (last->buffer_str[i] == EOF)
    	return;
	while (last->buffer_str[i] && last->buffer_str[++i])
		buf[k++] = last->buffer_str[i];

	buf[k] = '\0';
	clean->buffer_str = buf;
	clean->next_bs = NULL;
	cancel_mem(list, clean, buf);
}

char	*get_the_line(t_list *list)
{
	int		stringlen;
	char	*next_string;

	stringlen = len_for_endline(list);

	next_string = malloc(sizeof(char) * (stringlen + 1));
	if(next_string == NULL)
		return(NULL);

	str_cpy(list,next_string);

	return(next_string);
}

void	add_string_to_list(t_list	**list, char *buffer)
{
	t_list	*new_element;
	t_list	*last_element;

	last_element = look_for_end(*list);
	new_element = malloc(sizeof(t_list));

	if (new_element == NULL)
		return ;
	if (last_element == NULL)
		*list = new_element;
	else
		last_element->next_bs = new_element;

	new_element -> buffer_str = buffer;
	new_element -> next_bs = NULL;
}

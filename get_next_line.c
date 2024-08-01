/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/06/20 19:48:35 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
La funcion get_next_line debe lee un archivo linea por linea hasta un salto de linea
o hasta el final del archivo.
Debe llamarse recurrentemente para leer todo el archivo. en cada llamada debe devolver
la linea leida.
Debe reservar memoria para la linea leida y liberarla cuando no se necesite.
Debe ser compatible en multiples sistemas operativos
Debe tratar algunos errores:
Archivos vacios, lineas vacias y errores de lectura
*/

/*
 1-No tenemos que abrir el archivo, puesto que el parametro es un descriptor de archivo
 se trabaja con un archivo ya abierto.
 2-Asignar buffer y hacer la comprobación
 3-Leer el archivo hasta \n o 'EOF'.
 4-Devolver la linea leida o NULL si no hay nada que leer o seguir leyendo.????
*/

#include "get_next_line.h"

int	look_for_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buffer_str[i] && i < BUFFER_SIZE)
		{
			if (list->buffer_str[i] == '\n')
				return (1);
			++i;
		}
		list = list->next_bs;
	}
	return (0);
}

void	cancel_mem(t_list **list, t_list *clean, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;

	while (*list)
	{
		tmp = (*list)->next_bs;
		free((*list)->buffer_str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean->buffer_str[0])
		*list = clean;
	else
	{
		free(buf);
		free(clean);
	}
}

t_list	*look_for_end(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next_bs)
		list = list->next_bs;
	return (list);
}

void	str_cpy(t_list *list,char *str)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while(list -> buffer_str[i])
		{
			if(list -> buffer_str[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list -> buffer_str[i++];
		}
		list = list -> next_bs;
	}
	str[j] = '\0';
}

int len_for_endline(t_list *list)
{
	int	i;
	int	l;

	l = 0;
	while (list)
	{
		i = 0;
		while (list -> buffer_str[i])
		{
			if(list -> buffer_str[i] == '\n')
			{
				++l;
				return(l);
			}
			++i;
			++l;
		}
		list = list -> next_bs;
	}
	return (l);
}


void	make_new_list(t_list **list, int fd)
{
	int		c_read;
	char	*buffer;

	while (!look_for_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;

		c_read = read(fd, buffer, BUFFER_SIZE);
		if(!c_read)
		{
			free(buffer);
			return ;
		}
		buffer[c_read] = '\0';
		add_string_to_list(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if( fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	make_new_list(&list, fd);
	if (list == NULL)
		return (NULL);

	next_line = get_the_line(list);

	prepare_the_recall(&list);

	return(next_line);
}

int main()
{
	int fd;
	char *line;
	int lines;

	lines = 1;
	fd = open("lorem.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error al abrir");
		return 1;
	}


	while ( (line = get_next_line(fd)) != NULL)
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);
	return 0;
}

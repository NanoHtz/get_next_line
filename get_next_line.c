/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:42 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
La funcion get_next_line debe lee un archivo linea por linea hasta un salto de linea
o hasta el final del archivo.
Debe llamarse recurrentemente para leer todo el archivo. en cada llamada debe devolver
la linea leida.
Debe reservar memoria para la linea leida y leberarla cuando no se necesite.
Debe ser compatible en multiples sistemas operativos
Debe tratar algunos errores:
Archivos vacios, lineas vacias y errores de lectura
*/
#include "get_next_line.h"
#include <Libft.h>

#define BUFFER_SIZE 1024 //Definimos una macro que guarde el tamaño del buffer.

char *get_next_line(int fd) //Archivo ya abierto, no tenemos que abrirlo nosotros. Lo abrimos desde el main.
{
	static char *buffer; /*Una variable estática, mantiene su valor entre las llamadas
	y que guarda el contenido del archivo,
	esto permite a la función recordar donde estaba.*/
	char *newline; //Variable que guarda la posición del salto de línea.

	if (!buffer)
	{
		buffer = malloc(BUFFER SIZE); //Reservamos memoria para el buffer y comprobamos.
		if (!buffer)
			return (NULL);
	}

	//Leemos el archivo y guardamos el contenido en el Buffer.
	while (newline = ft_strchr(buffer, '\n') == NULL) //Busca un salto de línea en el buffer.
	{
		read(fd, buffer, BUFFER_SIZE);
	}
	return (0);
}


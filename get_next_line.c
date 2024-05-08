/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:08:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/04/26 19:08:30 by fgalvez-         ###   ########.fr       */
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

/*
 1-No tenemos que abrir el archivo, puesto que el parametro es un descriptor de archivi
 se trabaja con un archivo ya abierto.
 2-Asignar buffer y hacer la comprobación
 3-Leer el archivo hasta \n o 'EOF'.
 4-Devolver la linea leida o NULL si no hay nada que leer o seguir leyendo.????
*/
#include "get_next_line.h"

#define BUFFER_SIZE 1024 //Definimos una macro que guarde el tamaño del buffer.

char *get_next_line(int fd) //Archivo ya abierto, no tenemos que abrirlo nosotros.
{
	static char *buffer; /*Una variable estática, mantiene su valor entre las llamadas
	y que guarda el contenido del archivo,
	esto permite a la función recordar donde estaba.*/
	ssize_t b_read; //Esta variable guarda el número de bytes leido, es un tamaño entero con signo.
	char *new_pos; //Guarda la posición de la siguiente línea.
	char *line; //Guarda la línea leida.
	if (!buffer) // Comprueba si el buffer ha sido asignado, es una protección.
	{
		buffer = malloc (BUFFER_SIZE); //Reservamos memoria para el buffer.
		if (!buffer) //Volvemos a realizar la comprobación.
			return NULL;
	}

	b_read = read(fd, buffer, BUFFER_SIZE);//Lee el archivo y lo guarda en b_read
	if (b_read == -1) //Comprobamos si hay un error en la lectura.
	{
		free(buffer); //Liberamos la memoria del buffer.
		return NULL;
	}

	buffer[b_read] = '\0'; //En la última posición del buffer añadimos el carcater del final para poder tratarlo como una cadena de caracteres.
	new_pos = ft_strchr(buffer, '\n');
	if (!new_pos)
		new_pos = ft_strchr(buffer, '\0');

	*new_pos = '\0'; //Añadimos el caracter al final de la línea para poder usar strdup

	line = ft_strdup(buffer); //Guardamos la línea en la variable line.
	if (!line)
		return (NULL);
	ft_memmove(buffer, new_pos + 1, ft_strlen(new_pos + 1) + 1); //Movemos el buffer para que la siguiente llamada a la función pueda leer la siguiente línea.

	return (line);
}



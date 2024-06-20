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

char	*get_next_line(int fd) //Archivo ya abierto, no tenemos que abrirlo nosotros.
{
	static char *buffer; /*Una variable estática, mantiene su valor entre las llamadas
	y que guarda el contenido del archivo,
	esto permite a la función recordar donde estaba.*/
	ssize_t b_read; //Esta variable guarda el número de bytes leido, es un tamaño entero con signo.
	char *new_pos; //Guarda la posición de la siguiente línea.
	char *line; //Guarda la línea leida.
	if (!buffer) // Comprueba si el buffer ha sido asignado, es una protección.
	{
		buffer = malloc (BUFFER_SIZE + 1); //Reservamos memoria para el buffer.
		if (!buffer) //Volvemos a realizar la comprobación.
			return NULL;
	}
	b_read = read(fd, buffer, BUFFER_SIZE - 1);//Lee el archivo y lo guarda en b_read
	if (b_read == -1 || b_read == 0) //Comprobamos si hay un error en la lectura o si se ha llegado al final del archivo con read = 0.
	{
		free(buffer); //Liberamos la memoria del buffer.
		buffer = NULL; //Evitamos un puntero colgante, un puntero que apunta a una memoria ya liberada, si intentamos acceder el comportamiento es indefinido, puede parecer que funciona
		return NULL;
	}
	buffer[b_read] = '\0'; //En la última posición del buffer añadimos el carcater del final para poder tratarlo como una cadena de caracteres.
	new_pos = ft_strchr(buffer, '\n');
	if (!new_pos)
		new_pos = ft_strchr(buffer, '\0');

	*new_pos = '\0'; //Añadimos el caracter al final de la línea para poder usar strdup
	line = ft_strdup(buffer); //Guardamos la línea en la variable line.
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	ft_memmove(buffer, new_pos + 1, ft_strlen(new_pos + 1) + 1); //Movemos el buffer para que la siguiente llamada a la función pueda leer la siguiente línea.
	return (line);
}

//Posible error, se puede hacer static ssize_t b_read ??

int main(){
	int		fd;
	char	*next_line;
	int 	count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n",count,next_line);
		next_line = NULL;
	}
	close(fd);
	return(0);
}
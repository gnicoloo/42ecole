/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:14:59 by gnicolo           #+#    #+#             */
/*   Updated: 2024/12/15 15:59:18 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main() {
    int fd = open("filefd.txt", O_RDONLY);  // Apre il file in modalità lettura
    if (fd == -1) {
        perror("Errore nell'aprire il file");
        return 1;
    }

    char *line;

    // Leggi linee finché non raggiungi la fine
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linea letta: %s", line);
        free(line);  // Libera la memoria allocata per la linea
    }
	get_next_line(fd);
    close(fd);  // Chiude il file descriptor
    return 0;
}

/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf3d
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void free_array(char **line)
{
    if (line != NULL){
        for (int i = 0; line[i] != NULL; i++)
            free(line[i]);
    }
    free(line);
}

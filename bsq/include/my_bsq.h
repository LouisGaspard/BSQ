/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#ifndef __MY_BSQ_H_
#define __MY_BSQ_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct
{
    int x;
    int y;
    int len_l1;
    int lim;
    int size;
} t_mybsq;

int parse_buffer(char *buffer, t_mybsq *bsq);
int len_line1(char *buffer);
int open_file(char *filepath);

#endif

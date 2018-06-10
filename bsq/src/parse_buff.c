/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description
** CPE_BSQ_2017
*/

#include "my.h"
#include "my_bsq.h"

int	open_file(char *filepath)
{
	int fd = 0;

	if ((fd = open(filepath, O_RDONLY)) > 0)
		return (fd);
	return (84);
}

int	len_line1(char *buffer)
{
	int a = 0;

	while (buffer[a] != '\n')
		a++;
	return (a);
}

int	check_squarev2(char *buffer, int pos, int size, t_mybsq *bsq)
{
	int lim_line = (bsq->len_l1 * size) + pos;
	int lim_col = lim_line + size;
	int a = lim_line;

	while (a != lim_col + 1) {
		if (buffer[a] != '.')
			return (-1);
		a++;
	}
	a = pos + size;
	while (a != lim_col) {
		if (buffer[a] != '.')
			return (-1);
		a += bsq->len_l1;
	}
	return (0);
}

void	check_square(char *buffer, int a, t_mybsq *bsq)
{
	int b = 0;

	while ((check_squarev2(buffer, a, b, bsq)) != -1)
		b++;
	if (b > bsq->x) {
		bsq->x = b;
		bsq->y = a;
	}
}

int	parse_buffer(char *buffer, t_mybsq *bsq)
{
	int a = 0;

	while (buffer[a]) {
		if (buffer[a] == '.')
			check_square(buffer, a, bsq);
		if ((buffer[a] != '.') && (buffer[a] != 'o')
				&& (buffer[a] != '\n'))
			return (84);
		a++;
	}
	return (0);
}

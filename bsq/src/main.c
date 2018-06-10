/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description
** CPE_BSQ_2017
*/

#include "my.h"
#include "my_bsq.h"

char	*read_buffer(char *file, int fd, t_mybsq *bsq)
{
	struct stat st;
	char *buffer;

	stat(file, &st);
	if ((buffer = malloc(sizeof(char) * st.st_size)) == NULL)
		return (NULL);
	read(fd, buffer, st.st_size);
	buffer[st.st_size] = '\0';
	bsq->size = st.st_size;
	return (buffer);
}

char	*change_buffer(char *buffer, t_mybsq *bsq)
{
	int a = bsq->y;
	int y = bsq->y;
	int lim = ((bsq->x - 1) * bsq->len_l1) + (bsq->x - 1) + bsq->y;

	while (a <= lim) {
		if ((a >= y) && (a < (y + bsq->x)))
			buffer[a] = 'x';
		if ((buffer[a] == '\n') && (a <= lim))
			y = y + bsq->len_l1;
		a++;
	}
	return (buffer);
}

int	len_buffer(char *buffer)
{
	int a = 0;

	while (buffer[a] != '\n')
		a++;
	a++;
	return (a);
}

int	my_bsq(char *file)
{
	int fd;
	char *buffer;
	int len_nb;
	t_mybsq bsq;

	if ((fd = open_file(file)) == 84)
		return (84);
	if ((buffer = read_buffer(file, fd, &bsq)) == NULL)
		return (84);
	bsq.x = 0;
	bsq.y = 0;
	len_nb = len_buffer(buffer);
	buffer += len_nb;
	bsq.len_l1 = len_line1(buffer) + 1;
	if ((parse_buffer(buffer, &bsq)) == 84)
		return (84);
	buffer = change_buffer(buffer, &bsq);
	write(1, buffer, bsq.size - len_nb);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		if ((my_bsq(av[1])) == 84)
			return (84);
	return (0);
}

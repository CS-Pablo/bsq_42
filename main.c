/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sauron <sauron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:23:16 by onegre            #+#    #+#             */
/*   Updated: 2024/08/31 22:15:43 by sauron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

char	*ft_read_number(char *str, int *nb)
{
	while (*str && (*str >= '0' && *str <= '9'))
		*nb = (*nb * 10) + (*str++ - '0');
	return (str);
}

char	*ft_read_char(char *str, char *grid_char)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		if (!str[i] || !(str[i] >= ' ' && str[i] <= '~'))
			return (NULL);
		j = i + 1;
		while (j < 3)
		{
			if (str[i] == str[j])
				return (NULL);
			j++;
		}
		i++;
	}
	if (str[3] != '\n')
		return (NULL);
	grid_char[0] = str[0];
	grid_char[1] = str[1];
	grid_char[2] = str[2];
	return (str + 4);
}

char	*ft_check_entry(char *entry, int *x_y, char *grid_char)
{
	char	*ptr;

	x_y[1] = 0;
	ptr = ft_read_number(entry, x_y + 1);
	if (!x_y[1])
		return (NULL);
	ptr = ft_read_char(ptr, grid_char);
	printf("%s\n", ptr);
	return (ptr);
}

void find_bsq(int **map, int *x_y, int *max_square)
{
	int i, j;

	for (i = 1; i < x_y[1]; i++)
	{
		for (j = 1; j < x_y[0]; j++)
		{
			if (map[i][j] > 0)
			{
				map[i][j] = min(map[i - 1][j - 1], map[i - 1][j], map[i][j - 1]) + 1;
				if (map[i][j] > max_square[2])
				{
					max_square[0] = i;
					max_square[1] = j;
					max_square[2] = map[i][j];
				}
			}
		}
	}
}

int min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int main(int ac, char **av)
{
	char	*entry;
	int		x_y[2];
	char	grid_char[3];
	int		**grid;

	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		n_read;
	char	*tmp;

	av++;
	while (*av)
	{
		fd = open(*av, O_RDONLY);
		if (fd == -1)
			return (-1);
		entry = NULL;
		n_read = read(fd, buff, BUFF_SIZE);
		buff[n_read] = '\0';
		while (n_read)
		{
			if (!entry)
				entry = ft_strdup(buff);
			else
			{
				tmp = entry;
				entry = ft_strjoin(entry, buff);
				free(tmp);
			}
			n_read = read(fd, buff, BUFF_SIZE);
			buff[n_read] = '\0';
		}
		grid = (int **)malloc(x_y[1] * sizeof(int *));
		for (int i = 0; i < x_y[1]; i++)
			grid[i] = (int *)malloc(x_y[0] * sizeof(int));

		grid = ft_check_entry(entry, x_y, grid_char);

		int max_square[3] = {0, 0, 0};
		find_bsq(grid, x_y, max_square);

		*av = *av + 1;
	}
	return (1);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

char *read_input(int fd)
{
    char buff[BUFF_SIZE + 1];
    char *entry = NULL;
    int n_read;
    char *tmp;

    while ((n_read = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[n_read] = '\0';
        tmp = entry;
        entry = entry ? ft_strjoin(entry, buff) : ft_strdup(buff);
        free(tmp);
    }
    return entry;
}

int **initialize_grid(int width, int height)
{
    int **grid = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        grid[i] = malloc(width * sizeof(int));
    return grid;
}

char *parse_input(char *entry, int *x_y, char *grid_char)
{
    char *ptr = ft_read_number(entry, x_y + 1);
    if (!x_y[1]) return NULL;
    return ft_read_char(ptr, grid_char);
}

void find_bsq(int **map, int *x_y, int *max_square)
{
    for (int i = 1; i < x_y[1]; i++)
        for (int j = 1; j < x_y[0]; j++)
        {
            if (map[i][j] > 0)
            {
                map[i][j] = min(map[i - 1][j - 1], map[i - 1][j], map[i][j - 1]) + 1;
                if (map[i][j] > max_square[2])
                {
                    max_square[0] = i; max_square[1] = j; max_square[2] = map[i][j];
                }
            }
        }
}

int main(int ac, char **av)
{
    int x_y[2] = {0, 0};
    char grid_char[3], *entry;
    int **grid, max_square[3] = {0, 0, 0};
    av++;
    while (*av)
    {
        int fd = open(*av, O_RDONLY);
        if (fd == -1) return -1;
        entry = read_input(fd);
        if (!entry || !parse_input(entry, x_y, grid_char)) return -1;
        grid = initialize_grid(x_y[0], x_y[1]);  
        find_bsq(grid, x_y, max_square);
        free(entry);
        av++;
    }
    return 1;
}

*/
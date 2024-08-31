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
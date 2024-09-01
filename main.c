/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:23:16 by onegre            #+#    #+#             */
/*   Updated: 2024/09/01 16:17:04 by csauron          ###   ########.fr       */
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

int		ft_check_grid(char *str, int *x_y, char* grid_char)
{
	int		i;
	int		j;
	int		k;

	(void)str;
	(void)i;
	(void)j;
	(void)x_y;
	(void)grid_char;

	x_y[0] = 0;
	//printf("\n\n\n\ng1 = %c\n", grid_char[1]);
	
	j = 0;
	k = 0;
	while (str[k] && j < x_y[1])
	{
		printf("hello0\n");
		i = 0;
		while (str[k + i] && str[k + i] != '\n')
		{
			printf("hello1\n");
			if (str[k] != grid_char[0] && str[k] != grid_char[k])
				return (0);
			i++;
		}
		if (str[k + i] == '\n')
		{
			printf("hello2\n");
			if (x_y[0] == 0)
			{
				x_y[0] = i;
				//printf("ICI\n");
			}
			else if (i != x_y[0])
				return (0);
		}
		printf("hello3\n");
		j++; 
	}

	printf("%s", str);
	return (1);
}

char	*ft_read_grid(char *str, char *grid, int *x_y, char *grid_char)
{
	int		ok;

	(void)grid;
	ok = 1;
	(void)ok;
	ok = ft_check_grid(str, x_y, grid_char);
	if(!ok)
		return (NULL);
	return (NULL);
}

char	*ft_check_entry(char *entry, int *x_y, char *grid_char)
{
	(void)entry;
	(void)x_y;
	(void)grid_char;
	char	*ptr;
	char	*grid;

	x_y[1] = 0;
	ptr = ft_read_number(entry, x_y + 1);
	if (!x_y[1])
		return (NULL);
	ptr = ft_read_char(ptr, grid_char);
	if (!ptr)
		return (NULL);
	//printf("%s\n", ptr);
	grid = NULL;
	grid = ft_read_grid(ptr, grid, x_y, grid_char);
	return (NULL);
}
char	*ft_read_file(int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		n_read;
	char	*tmp;
	char	*entry;

	entry = NULL;
	n_read = read(fd, buff, BUFF_SIZE);
	buff[n_read] = '\0';
	while (n_read)
	{
		//printf("%s", buff);
		//printf("\nhere\n");
		if (!entry)
			entry = ft_strdup(buff);
		else
		{
			tmp = entry;
			entry = ft_strjoin(entry, buff);
			free (tmp);
		}
		n_read = read(fd, buff, BUFF_SIZE);
		buff[n_read] = '\0';
	}
	return (entry);
}

int		ft_map_error(char *to_free, char *to_free2)
{
	if (to_free)
		free(to_free);
	if (to_free2)
		free(to_free2);
	write(2, "map error\n", 10);
	return (-1);
}

int		ft_solve(char *entry)
{
	int		x_y[2];
	char	grid_char[3];
	char	*grid;

	grid = ft_check_entry(entry, x_y, grid_char);
	(void)grid;
	return (1);
}

int	main(int ac, char **av)
{
	char	*entry;
	int		i;
	int  	fd;

	i = 1;
	while (i < ac)
	{
		//printf("i = %d\n", i);
		if (i > 1)
			write(1, "\n", 1);
			//printf("Z\n");

		if (ac == 1)
		{
			//write(1, "never here!\n", 12);
			fd = 1;
		}
		else
			fd = open(av[i],  O_RDONLY);
		if (fd == -1)
		{
			//write(1, "hello kitty!\n", 13);
			ft_map_error(0, 0);
		}
		else
		{
			//write(1, "hello miou!\n", 12);
			entry = ft_read_file(fd);
			if (!entry)
				ft_map_error(0, 0);
			else
				ft_solve(entry);
		}
		i++;
	}
	return (1);
}

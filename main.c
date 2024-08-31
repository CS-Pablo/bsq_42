/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onegre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:23:16 by onegre            #+#    #+#             */
/*   Updated: 2024/08/31 00:21:40 by onegre           ###   ########.fr       */
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
	(void)entry;
	(void)x_y;
	(void)grid_char;
	char	*ptr;

	x_y[1] = 0;
	ptr = ft_read_number(entry, x_y + 1);
	if (!x_y[1])
		return (NULL);
	ptr = ft_read_char(ptr, grid_char);
	printf("%s\n", ptr);
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char	*entry;
	int		x_y[2];
	char	grid_char[3];
	char	*grid;

	/********** */
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		n_read;
	char	*tmp;
	/*************** */

	//printf("ac = %d\n", ac);
	av++;
	while (*av)
	{
		/*********************************************** */
		//printf("av[%d]= \"%s\"\n", i, av[i]);
		fd = open(*av,  O_RDONLY);
		if (fd == -1)
			return (-1);
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
		//printf("%s", entry);
		/***************************************************** */
		grid = ft_check_entry(entry, x_y, grid_char);
		(void)grid;
		*av = *av + 1;		
	}
	return (1);
}

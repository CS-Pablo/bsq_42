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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int		i;
	char	*entry;
	int		lign;
	char	grid_char[3];

	/********** */
	int		fd;
	char	buff[BUFF_SIZE + 1];
	int		n_read;
	char	*tmp;
	/*************** */

	//printf("ac = %d\n", ac);
	i = 1;
	while (av[i])
	{
		/*********************************************** */
		//printf("av[%d]= \"%s\"\n", i, av[i]);
		fd = open(av[i],  O_RDONLY);
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
		ft_check_entry();
		i++;
	}
	return (1);
}

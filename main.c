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

	int		i;
	int		fd;
	char	buff[BUFF_SIZE];
	int		n_read;

	//printf("ac = %d\n", ac);
	i = 0;
	while (av[i])
	{
		//printf("av[%d]= \"%s\"\n", i, av[i]);
		fd = open(av[i],  O_RDONLY);
		if (fd == -1)
			return (-1);
		n_read = read(fd, buff, BUFF_SIZE);
		buff[n_read] = '\0';
		printf("%s", buff);
		i++;
	}
	return (1);
}

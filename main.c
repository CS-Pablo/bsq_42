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

#include <unistd.h>
#include <fcntl.h>


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	write(1, "Hello Kitty\n", 11);
	
	int		i;
	int		fd;

	i = 1;
	while (av[i])
	{
		fd = open(av[i]);
	}
	return (1);
}

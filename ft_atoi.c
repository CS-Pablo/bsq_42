/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:28:55 by csauron           #+#    #+#             */
/*   Updated: 2024/08/31 05:48:00 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		++str;
	while (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			sign *= -1;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + (*str++ - '0');
	return (nb * sign);
}
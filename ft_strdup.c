/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:59:20 by csauron           #+#    #+#             */
/*   Updated: 2024/08/31 07:19:45 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*dest;

	ptr = src;
	while (*ptr)
	ptr++;
	dest = (char *)malloc((ptr - src + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ptr = dest;
	while (*src)
	*(ptr++) = *(src++);
	*ptr = '\0';
	return (dest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:59:20 by csauron           #+#    #+#             */
/*   Updated: 2024/08/31 04:09:45 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char    *ft_strdup(char *src)
{
    char    *ptr;
    char    *dest;

    ptr = src;
    while (*ptr)
        ptr++;
    dest = (char *)malloc((ptr - src + 1) * sizeof(char));
    if(!ptr)
        return (NULL);
    ptr = dest;
    while (*src)
        *(ptr++) = *(src++);
    *ptr = '\0';
    return (dest);
}
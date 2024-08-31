/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:10:54 by csauron           #+#    #+#             */
/*   Updated: 2024/08/31 04:54:13 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char    *ft_strjoin(char *s1, char *s2)
{
    char    *dest;
    char    *ptr;

    dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!dest)
        return (NULL);
    ptr = dest;
    while (*s1)
        *(ptr++) = *(s1++);
    while (*s2)
        *(ptr++) = *(s2++);
    *ptr = '\0';
    return (dest);
}
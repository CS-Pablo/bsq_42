/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csauron <csauron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:59:20 by csauron           #+#    #+#             */
/*   Updated: 2024/08/31 04:09:35 by csauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


char    *ft_strdup(char *src);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_atoi(char *str);
#define		BUFF_SIZE	4
#define     BIT_1       0x80
#define     BIT_2       0x40
#define     BIT_3       0x20
#define     BIT_4       0x10

#endif
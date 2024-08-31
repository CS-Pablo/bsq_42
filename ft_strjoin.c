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
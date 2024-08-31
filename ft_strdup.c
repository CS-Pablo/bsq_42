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
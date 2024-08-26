#include "so_long.h"

char    *str_realloc(char *src, size_t size)
{
    char    *new_str;

    new_str = (char *) malloc(size * sizeof(char));
    if (!new_str)
        return (free(src), NULL);
    ft_strlcat(new_str, src, size);
    if (!src)
        new_str[0] = '\0';
    free(src);
    return (new_str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelniko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:50:36 by amelniko          #+#    #+#             */
/*   Updated: 2024/09/29 12:50:37 by amelniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_realloc(char *src, size_t size)
{
	char	*new_str;

	new_str = (char *) malloc(size * sizeof(char));
	if (!new_str)
		return (free(src), NULL);
	new_str[0] = '\0';
	ft_strlcat(new_str, src, size);
	if (!src)
		new_str[0] = '\0';
	free(src);
	return (new_str);
}

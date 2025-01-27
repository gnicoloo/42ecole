/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:05:12 by gnicolo           #+#    #+#             */
/*   Updated: 2024/11/26 22:12:42 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while ((unsigned char)str[i] && (unsigned char) str[i] != (unsigned char)c)
		i++;
	if ((unsigned char)str[i] == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return ((char *)(str + i));
}

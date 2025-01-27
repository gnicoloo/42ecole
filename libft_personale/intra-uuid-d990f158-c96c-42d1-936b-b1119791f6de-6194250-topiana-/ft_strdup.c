/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:09:47 by topiana-          #+#    #+#             */
/*   Updated: 2024/11/22 16:31:07 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*sdup;
	unsigned int	len;

	len = ft_strlen(s);
	sdup = (char *)ft_calloc(len + 1, sizeof(char));
	if (sdup == NULL)
		return (NULL);
	ft_memcpy(sdup, s, len);
	return (sdup);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	//printf("%s\n", strdup(argv[1]));
	printf("%s\n", ft_strdup(argv[1]));
	return (0);
}*/

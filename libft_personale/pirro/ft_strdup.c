/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:38 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:40 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*int	main()
{
	const char s[] = "ciao";
	printf("%s", ft_strdup(s));
}*/

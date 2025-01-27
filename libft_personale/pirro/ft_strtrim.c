/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:32:35 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:01 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fstrncpy(char *str, const char *s1, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!set)
		return (ft_strdup(s1));
	start = 0;
	if (s1)
		end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	if (len > 0)
		str = ft_calloc((len + 1), sizeof(char));
	else
		str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	if (len <= 0)
		return (str);
	fstrncpy(str, (s1 + start), len);
	return (str);
}
/*int main()
{
	char *result;
	result = ft_strtrim("canefde", "cdef");
	printf("%s\n", result);
	free(result);
	return (0);
}*/

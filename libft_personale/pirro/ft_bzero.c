/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:44:33 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/18 16:44:35 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*int main()
{
	char	buffer[10];
	int	i = 0;
	ft_bzero(buffer, 6);
	while(i < 6)
	{
		printf("%d", buffer[i]);
		i++;
	}
}*/

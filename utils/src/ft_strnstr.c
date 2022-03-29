/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:43:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 16:47:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ihay;
	size_t	inee;
	size_t	ista;

	ihay = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[ihay] != '\0' && ihay < len)
	{
		inee = 0;
		if (haystack[ihay] == needle[inee])
		{
			ista = ihay;
			while (haystack[ihay] == needle[inee] && needle[inee] != '\0')
			{
				ihay++;
				inee++;
			}
			if (needle[inee] == '\0' && ihay <= len)
				return ((char *)haystack + ista);
			ihay = ista;
		}
		ihay++;
	}
	return (NULL);
}

/*int	main()
{
	//char haystack[30] = "aaabcabcd";
	char * empty = (char*)"";

	printf("Value Function C = %s\n", strnstr(empty, "", -1));
	printf("Value Function Mano = %s\n", ft_strnstr(empty, "", -1));
}*/

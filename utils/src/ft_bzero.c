/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:30:34 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 11:21:25 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_bzero(void *s, size_t n)
{
	int	is;

	is = 0;
	while (n-- > 0)
		((char *)s)[is++] = '\0';
	return (s);
}

/*int main()
{
	char	s[] = "Ceci est un test";
	unsigned long n;

	n = 15;
	printf("Fonction C = %s\n", bzero(s, n));
	printf("Fonction mano = %s\n", ft_bzero(s, n));
}*/

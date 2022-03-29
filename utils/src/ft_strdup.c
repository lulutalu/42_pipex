/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:19:41 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 19:18:15 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		icopy;
	int		istr;

	if (s1 == NULL)
		return (NULL);
	icopy = 0;
	istr = 0;
	copy = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (! copy)
		return (NULL);
	while (s1[istr] != '\0')
		copy[icopy++] = s1[istr++];
	copy[icopy] = '\0';
	return (copy);
}

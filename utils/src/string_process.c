/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:50:28 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 01:10:39 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	string_process(t_printf *ptr)
{
	ptr->str = ft_strdup(va_arg(ptr->arg, char *));
	ptr->count += ft_putstr_fd_count(ptr->str, 1);
	free(ptr->str);
}

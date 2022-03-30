/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:06:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/30 18:22:10 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "ft_printf.h"
# include "get_next_line.h"
# include "pipex.h"
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct printf_list
{
	int		count;
	int		i;
	va_list	arg;
	char	*str;
	int		nbvar;
	char	*param;
	int		iparam;
}				t_printf;

void	core_process(t_printf *ptr, const char *input);
void	hexa_process(t_printf *ptr, int flag);
void	string_process(t_printf *ptr);
void	pointer_address_process(t_printf *ptr);
void	variable_counter(t_printf *ptr, const char *input);
void	struct_init(t_printf *ptr);
void	if_forest(const char *input, t_printf *ptr);
int		ft_printf(const char *input, ...);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr_fd_count(long n, int fd, int *count);
char	*ft_strdup(const char *s1);
void	*ft_bzero(void *s, size_t n);
void	*ft_itoa_base(char **res, unsigned long n, char const *base);
int		ft_putchar_fd_count(char c, int fd);
int		ft_putstr_fd_count(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif

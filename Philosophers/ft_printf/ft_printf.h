/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:01:47 by Naomi             #+#    #+#             */
/*   Updated: 2024/02/21 16:56:40 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_puthex(unsigned int n, const char format);
int	ft_puthex_uintptr(uintptr_t n);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int n);
int	ft_toupper(int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:13:43 by lpetit            #+#    #+#             */
/*   Updated: 2023/10/29 17:05:20 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_print_str(va_list arg, int len);
int		ft_print_nbr10(int n, int len);
int		ft_print_u10(unsigned int n, int len);
int		ft_print_ptr(va_list arg, int len);
int		ft_print_hexa(va_list arg, int len, int x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:18:37 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/02/28 14:44:00 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convs(va_list args, char convs)
{
	int	rdir;

	rdir = 0;
	if (convs == 'c')
		rdir += ft_print_c(va_arg(args, int));
	else if (convs == 's')
		rdir += ft_print_s(va_arg(args, char *));
	else if (convs == 'd')
		rdir += ft_print_d(va_arg(args, int));
	else if (convs == 'i')
		rdir += ft_print_i(va_arg(args, int));
	else if (convs == 'u')
		rdir += ft_print_u(va_arg(args, unsigned int));
	else if (convs == 'p')
		rdir += ft_print_p(va_arg(args, unsigned long long));
	else if (convs == 'x')
		rdir += ft_print_x(va_arg(args, unsigned int));
	else if (convs == 'X')
		rdir += ft_print_upx(va_arg(args, unsigned int));
	else if (convs == '%')
		rdir += ft_print_percent();
	return (rdir);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_convs(args, str[i + 1]);
			i++;
		}
		else
		{
			write (1, &str[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:27:27 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/02/28 09:25:09 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

void	ft_p(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_p(nb / 16);
		ft_p(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long p)
{
	int	p_len;

	p_len = 0;
	p_len += write (1, "0x", 2);
	if (p == 0)
		p_len += write (1, "0", 1);
	else
	{
		ft_p(p);
		p_len += ft_p_len(p);
	}
	return (p_len);
}

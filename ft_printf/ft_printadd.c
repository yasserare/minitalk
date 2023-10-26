/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <yasserar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:18:30 by yasserar          #+#    #+#             */
/*   Updated: 2023/06/26 01:05:54 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printhex(unsigned long decimal_form, int k)
{
	char	*str;

	str = "0123456789abcdef";
	k = 0;
	if (decimal_form >= 16)
		k += ft_printhex(decimal_form / 16, k);
	k += write(1, &str[decimal_form % 16], 1);
	return (k);
}

int	ft_printadd(unsigned long decimal_form)
{
	int	k;

	k = 0;
	k += ft_putstr("0x");
	k += ft_printhex(decimal_form, k);
	return (k);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_dec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <yasserar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 05:00:34 by yasserar          #+#    #+#             */
/*   Updated: 2023/06/26 05:03:02 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_unsigned_dec(unsigned int number)
{
	int			k;

	k = 0;
	if (number >= 10)
		k += ft_putnbr ((number / 10));
	k += ft_putchar ((number % 10 + '0'));
	return (k);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <yasserar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:22:33 by yasserar          #+#    #+#             */
/*   Updated: 2023/06/26 05:12:41 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	ln;
	int			k;

	ln = n;
	k = 0;
	if (ln < 0)
	{
		k += ft_putchar ('-');
		ln *= -1;
	}
	if (ln >= 10)
		k += ft_putnbr ((ln / 10));
	k += ft_putchar ((ln % 10 + '0'));
	return (k);
}

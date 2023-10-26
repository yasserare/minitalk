/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumhexlow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <yasserar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:22:51 by yasserar          #+#    #+#             */
/*   Updated: 2023/06/26 04:35:26 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumhexlow(unsigned int decimal_form)
{
	char	*str;
	int		k;

	str = "0123456789abcdef";
	k = 0;
	if (decimal_form >= 16)
		k += ft_printnumhexlow(decimal_form / 16);
	k += write(1, &str[decimal_form % 16], 1);
	return (k);
}

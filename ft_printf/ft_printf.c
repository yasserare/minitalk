/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserar <yasserar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:26:34 by yasserar          #+#    #+#             */
/*   Updated: 2023/06/26 04:30:55 by yasserar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"		

static int	check_format_spec(const char *format, int i, va_list ap, int k)
{
	if (format[i] == 's')
		k += ft_putstr(va_arg(ap, char *));
	else if (format[i] == 'c')
		k += ft_putchar(va_arg(ap, int));
	else if (format[i] == 'i' || format[i] == 'd')
		k += ft_putnbr(va_arg(ap, int));
	else if (format[i] == 'p')
		k += ft_printadd((unsigned long)va_arg(ap, void *));
	else if (format[i] == 'u')
		k += ft_unsigned_dec(va_arg(ap, unsigned int));
	else if (format[i] == 'x')
		k += ft_printnumhexlow(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		k += ft_printnumhexupp(va_arg(ap, unsigned int));
	else if (format[i] == '%')
		k += ft_putchar('%');
	return (k);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		k;
	va_list	ap;

	i = 0;
	k = 0;
	va_start (ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			k += ft_putchar(format[i]);
		else
		{
			i++;
			k = check_format_spec(format, i, ap, k);
		}
		i++;
	}
	va_end(ap);
	return (k);
}

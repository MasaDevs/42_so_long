/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:34:35 by marai             #+#    #+#             */
/*   Updated: 2022/12/31 00:14:25 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_ajust(long long nbr, char *base, char c)
{
	ssize_t	sign;
	ssize_t	len;

	sign = 1;
	len = 0;
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		return (ft_putnbr_ptr(nbr, base, sign) + len);
	}
	if (nbr < 0)
	{
		if (c == 'i' || c == 'd')
		{
			len += write(1, "-", 1);
			nbr *= -1;
		}
		else
			sign = -1;
	}
	return (ft_putnbr_base(nbr, base, sign) + len);
}

ssize_t	ft_ajust_str(va_list *ap, char c)
{
	char	*tmp;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		return (1);
	}
	tmp = va_arg(*ap, char *);
	if (tmp == NULL)
		return (write(1, "(null)", 6));
	if (INT_MAX < ft_strlen(tmp))
		return (-1);
	return (write(1, tmp, ft_strlen(tmp)));
}

int	prefix(const char *str, va_list *ap)
{
	if (*str == 'c' || *str == 's')
		return (ft_ajust_str(ap, *str));
	else if (*str == 'i' || *str == 'd')
		return (ft_ajust(va_arg(*ap, int), "0123456789", *str));
	else if (*str == 'u')
		return (ft_ajust(va_arg(*ap, unsigned int), "0123456789", *str));
	else if (*str == 'x')
		return (ft_ajust(va_arg(*ap, unsigned int), "0123456789abcdef", *str));
	else if (*str == 'X')
		return (ft_ajust(va_arg(*ap, unsigned int), "0123456789ABCDEF", *str));
	else if (*str == 'p')
		return (ft_ajust(va_arg(*ap, uintptr_t), "0123456789abcdef", *str));
	else if (*str == '%')
		return (write(1, "%", 1));
	return (write(1, str, 1));
}

int	ft_printf(const char *argv, ...)
{
	va_list	ap;
	ssize_t	len;
	ssize_t	check;

	len = 0;
	va_start(ap, argv);
	while (*argv != '\0')
	{
		if (*argv == '%')
		{
			check = prefix(++argv, &ap);
			if (check < 0)
				return (-1);
			len += check;
		}
		else
		{
			ft_putchar_fd(*argv, 1);
			len++;
		}
		argv++;
	}
	va_end(ap);
	return ((int) len);
}

// int main()
// {
// 	printf("\t%d\n",printf("%X", (unsigned int)LONG_MAX));
// 	printf("\t%d\n",ft_printf("%X", (unsigned int)LONG_MAX));
// 	printf("\t%d\n",printf("%X", (unsigned int)100));
// 	printf("\t%d\n",ft_printf("%X", (unsigned int)100));
// 	printf("\t%d\n",ft_printf("%s", "marai"));
// 	printf("\t%d\n",printf("%s", "marai"));
// 	ft_printf("abc");
// }
// 	int i = 0;
//     char *s = (char *)calloc(1, (size_t)INT_MAX + 10);
//     memset(s, 'a', (size_t)INT_MAX + 5);
//     i = ft_printf("%s\n", s);
//     printf("%d\n", i);
//    // return (0);
// // 	//int len;
// 	char arr[] = "my name is";
// 	printf("%d\n",printf("%c", 'a'));
// 	printf("%d\n",printf("%p", SIZE_MAX));
// 	printf("%d\n",ft_printf("%p", SIZE_MAX));
// 	printf("%d\n",printf("%p", arr));
// 	printf("%d\n",ft_printf("%p", arr));
// 	printf("%d\n",printf("%p", 1));
// 	printf("%d\n",ft_printf("%p", 1));
// 	// printf("%d\n",printf("my name is %p %%%m", "masahito"));
// }

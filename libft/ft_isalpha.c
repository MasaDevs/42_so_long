/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:14:36 by marai             #+#    #+#             */
/*   Updated: 2022/10/09 15:20:19 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

/* 
#include  <stdio.h>
int	main(void)
{
	printf("ft_ : %d\n", ft_isalpha('a' + 1));
	printf("org : %d\n", isalpha('a' + 1));
}
 */
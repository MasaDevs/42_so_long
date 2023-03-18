/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:59:15 by marai             #+#    #+#             */
/*   Updated: 2022/10/17 13:28:02 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	return ;
}

// int main(int argc, char const *argv[])
// {
// 	int	a = 3;
// 	int	b;

// 	b = a;
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// 	b = 0;
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// 	return 0;
// }

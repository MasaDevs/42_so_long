/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:42:16 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 06:48:36 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prelist;

	if (lst == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	prelist = *lst;
	while (prelist->next != NULL)
		prelist = prelist->next;
	prelist->next = new;
}

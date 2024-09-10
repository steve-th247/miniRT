/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:26:09 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 14:06:21 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	ptr = *lst;
	*lst = NULL;
	while (ptr != NULL)
	{
		next = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = next;
	}
}

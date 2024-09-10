/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:18:04 by jyap              #+#    #+#             */
/*   Updated: 2023/10/19 17:22:34 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

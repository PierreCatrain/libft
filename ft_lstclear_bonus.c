/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:13 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/12 10:13:23 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tempo;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tempo = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tempo;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:22 by picatrai          #+#    #+#             */
/*   Updated: 2023/11/12 11:24:50 by picatrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(0);
		if (mem == NULL)
			return (0);
		return (mem);
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (0);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:37:26 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/30 12:58:11 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (struct s_list *)malloc(sizeof(struct s_list));
	if (tmp)
	{
		if (content != NULL)
		{
			tmp->content = malloc(content_size + 1);
			if (!tmp->content)
			{
				free(tmp);
				return (NULL);
			}
			tmp->content = ft_memcpy(tmp->content, content, content_size + 1);
			tmp->content_size = 1 * content_size;
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

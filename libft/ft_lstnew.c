/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:19:46 by rejocic           #+#    #+#             */
/*   Updated: 2018/07/20 14:47:06 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_cont;
	size_t	i;

	i = 0;
	if ((new_cont = ft_memalloc(content_size)) == NULL)
		return (NULL);
	while (i <= content_size && content != NULL)
	{
		((char *)new_cont)[i] = ((char *)content)[i];
		i++;
	}
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = new_cont;
	new->content_size = content_size;
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

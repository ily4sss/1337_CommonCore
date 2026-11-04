/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:45:59 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/10/25 13:51:55 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_node(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new;
	void	*buffer;

	buffer = f(lst->content);
	new = ft_lstnew(buffer);
	if (new == NULL)
		del(buffer);
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*curr;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	copy = create_node(lst, f, del);
	if (copy == NULL)
		return (NULL);
	curr = copy;
	lst = lst->next;
	while (lst)
	{
		new = create_node(lst, f, del);
		if (new == NULL)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		curr->next = new;
		curr = curr->next;
		lst = lst->next;
	}
	return (copy);
}

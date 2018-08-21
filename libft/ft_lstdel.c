/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:41:00 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/11 10:41:00 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *alst;
	while (lst)
	{
		tmp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmp;
	}
	*alst = NULL;
}

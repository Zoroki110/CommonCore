/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:26:00 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/19 20:55:49 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	tmp = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			while (new_list)
			{
				tmp = new_list->next;
				(*del)(new_list->content);
				free(new_list);
				new_list = tmp;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
/*
void    *increment(void *content)
{
    int *new_value = malloc(sizeof(int));
    if (!new_value)
        return (NULL);
    *new_value = *(int *)content + 1;
    return (new_value);
}

void    delete_content(void *content)
{
    free(content);
}
int main()
{
    int a = 1, b = 2, c = 3;
    t_list *lst = ft_lstnew(&a);
    ft_lstadd_back(&lst, ft_lstnew(&b));
    ft_lstadd_back(&lst, ft_lstnew(&c));

    t_list *new_list = ft_lstmap(lst, increment, delete_content);

    t_list *tmp = new_list;
    while (tmp)
    {
        printf("Nouvelle valeur : %d\n", *(int *)tmp->content);
        tmp = tmp->next;
    }
    while (new_list)
    {
        tmp = new_list->next;
        delete_content(new_list->content);
        free(new_list);
        new_list = tmp;
    }
    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
    return 0;
}*/
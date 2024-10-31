/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:21 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/19 20:48:43 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main()
{
    t_list *element = ft_lstnew("Bonjour !");
    if (element)
    {
        printf("Contenu de l'élément : %s\n", (char*)element->content);
    }
    else
    {
        printf("Échec de la création de l'élément.\n");
    }
    free(element);
    return 0;
}*/
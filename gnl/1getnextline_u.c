/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1getnextline_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:16:17 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/05 20:28:45 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Fonction pour trouver le '\n'
int	ft_found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (!stash)
		return (0);
	current = ft_get_list_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//Retourne un pointeur a la derniere node de la stash
t_list	*ft_get_list_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

//Calcule le nombre de charactere dans la line
//avec le '\n' si il y en a 1 et alloue la memoire necessaire
//Check si malloc a bien marche dans l'autre fonction
//car fonction extract line appelle et utilise generate line
void	ft_generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

//Free toutes la stash
//libere la memoire du contenu de la liste chaine
//pointeur next pointe sur le prochain maillon de la liste
//liberer toutes la memoire alloue du maillon actuelle
//passer au maillon suivant et je boucle jusqu'a current vaut NULL donc
//quand j'arrive a la fin de la liste
void	ft_free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

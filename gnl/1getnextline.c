/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1getnextline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:15:31 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/05 20:18:08 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//fonction utilise read pour add character to stash
void	ft_read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (*readed_ptr != 0)
	{
		*readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && *readed_ptr == 0) || *readed_ptr == (-1))
			return (free(buff));
		buff[*readed_ptr] = '\0';
		tmp = buff;
		ft_add_to_stash(stash, buff, *readed_ptr);
		free(buff);
	}
}

//ajouter le contenu buffer a la fin de stash
//Si premier passage pas besoin de mettre a la fin de stash
//juste ajouter new_node au premier maillon de stash
void	ft_add_to_stash(t_list **stash, char *buff, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (free(new_node));
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		stash = &new_node;
		return ;
	}
	last = ft_get_list_last(*stash);
	last->next = new_node;
}

//Take tous les characteres de stash et mettre dans line.
//STOP quand rencontre first '\n'
void	ft_extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (!stash)
		return ;
	ft_generate_line(line, stash);
	if (!*line)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	*line[j] = '\0';
	printf("line : %s\n", line[0]);
}

//Clear la Stash pour qu'il ne reste que les characters qui
//n'ont pas etait utilise avant dans la static stash
void	ft_clean_stash(t_list *stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!stash || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_get_list_last(stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char)
			* ((ft_strlen(last->content) - i) + 1));
	if (!clean_node->content)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_free_stash(stash);
	stash = clean_node;
}

//La fonction principale GNL
//utiliser read pour lire fd et ajouter a la liste chaine
//extraire de la liste chaine stash pour mettre dans line
//Nettoyer tous ce beau bordel
/*si line[0] vaut '\0' signife fin du fichier donc on clean le dernier
	maillon de la liste chaine et on clean line*/
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	ft_read_and_stash(fd, &stash, &readed);
	if (!stash)
		return (NULL);
	ft_extract_line(stash, &line);
	ft_clean_stash(stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int main()
{
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	system("leaks a.out");
}

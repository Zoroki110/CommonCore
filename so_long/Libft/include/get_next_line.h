/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:33:42 by trouilla          #+#    #+#             */
/*   Updated: 2024/11/26 11:43:01 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7 
# endif

char		*get_next_line(int fd);
int			ft_strchr_gnl(const char *s, char c);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif

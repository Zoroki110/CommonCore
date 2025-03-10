/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:57:06 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/07 15:57:08 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    int lower = ft_tolower(ch);
    printf("Uppercase character: %c\n", lower);

    return 0;
}
*/

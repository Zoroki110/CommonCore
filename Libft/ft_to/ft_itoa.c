/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:56:36 by trouilla          #+#    #+#             */
/*   Updated: 2024/10/17 16:45:45 by trouilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= (-1);
		len++;
	}
	if (n == 0)
		return (len + 1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nb;

	nb = n;
	len = count_len(nb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= (-1);
	}
	while (nb > 0)
	{
		res[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}

/* int main()
{
	int test1 = -1942;
	int test2 = 0;
	int test3 = 1942;
	int test4 = 2147483647;
	int test5 = ;

	printf("resultat : %s\n", ft_itoa(test1));
	printf("resultat : %s\n", ft_itoa(test2));
	printf("resultat : %s\n", ft_itoa(test3));
	printf("resultat : %s\n", ft_itoa(test4));
	printf("resultat : %s\n", ft_itoa(test5));
	printf("resultat : %s\n", ft_itoa(0));
	return (0);
} */
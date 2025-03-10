/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:50:23 by sinawara          #+#    #+#             */
/*   Updated: 2024/10/14 14:36:52 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n > 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	len = ft_size(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	while (len-- > 0)
	{
		num[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (is_negative)
		num[0] = '-';
	return (num);
}
/*
int main()
{
	int test_numbers[] = {2147483647, -2147483648, 0, 6, 100000, -987654};
    int i;
    char *result;

    printf("Testing :\n");
    for (i = 0; i < 6; i++) // Loop through test numbers
    {
        result = ft_itoa(test_numbers[i]);
        if (result)
        {
            printf("Number: %d -> String: %s\n", test_numbers[i], result);
            free(result); // Remember to free the dynamically allocated memory
        }
        else
        {
            printf("Memory allocation failed for number: %d\n", test_numbers[i]);
        }
    }
    return 0;
}
*/
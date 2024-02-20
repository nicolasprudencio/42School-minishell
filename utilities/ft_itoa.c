/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:23:31 by nicolas           #+#    #+#             */
/*   Updated: 2024/02/20 19:26:51 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libseas.h"

static int	get_digits_amount(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		while (n)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			n_size;
	long int	nb;

	n_size = get_digits_amount(n);
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		n_size++;
	}
	str = mem_calloc((n_size + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = '0' + nb % 10;
		nb /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}

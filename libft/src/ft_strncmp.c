/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:20:47 by ttrave            #+#    #+#             */
/*   Updated: 2023/10/31 15:21:56 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	lim;

	i = 0;
	lim = n / sizeof(size_t);
	while (i + 1 < lim && ((size_t *)s1)[i] == ((size_t *)s2)[i])
		i++;
	i *= sizeof(size_t);
	while (i + 1 < n && ((unsigned char *)s1)[i]
		&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]);
}

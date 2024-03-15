/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:39 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/17 19:13:47 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlclear(t_gnl **lst)
{
	t_gnl	*ptr1;
	t_gnl	*ptr2;

	ptr1 = *lst;
	*lst = NULL;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		free(ptr1->content);
		free(ptr1);
		ptr1 = ptr2;
	}
	return (NULL);
}

char	ft_lstnew_back_gnl(t_gnl **fd_arr, int fd, char *content, size_t len)
{
	t_gnl	*new;
	t_gnl	*lst;

	new = malloc(sizeof(t_gnl));
	if (!new)
	{
		free(content);
		ft_gnlclear(&fd_arr[fd]);
		return (1);
	}
	new->content = content;
	new->len = len;
	new->i = 0;
	new->next = NULL;
	if (!fd_arr[fd])
		fd_arr[fd] = new;
	else
	{
		lst = fd_arr[fd];
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	return (0);
}

char	ft_in_gnl(char *s, size_t i_start, size_t len)
{
	if (!s || i_start >= len)
		return (0);
	while (i_start < len)
	{
		if (s[i_start] == '\n')
			return (1);
		i_start++;
	}
	return (0);
}

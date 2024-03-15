/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:05:28 by ttrave            #+#    #+#             */
/*   Updated: 2023/11/19 21:31:15 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reinit_lst(t_gnl **fd_arr, int fd)
{
	t_gnl	*ptr1;
	t_gnl	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = fd_arr[fd];
	while (ptr1->next)
	{
		ptr2 = ptr1->next;
		free(ptr1->content);
		free(ptr1);
		ptr1 = ptr2;
	}
	fd_arr[fd] = ptr1;
	i = fd_arr[fd]->i;
	while (i < fd_arr[fd]->len && fd_arr[fd]->content[i] != '\n')
		i++;
	i += (i < fd_arr[fd]->len && fd_arr[fd]->content[i] == '\n');
	fd_arr[fd]->i = i;
	if (fd_arr[fd]->i >= fd_arr[fd]->len)
	{
		free(fd_arr[fd]->content);
		free(fd_arr[fd]);
		fd_arr[fd] = NULL;
	}
}

static char	ft_parse_next_line(t_gnl **fd_arr, int fd, size_t size)
{
	int		len_read;
	char	*buffer;

	len_read = size;
	buffer = NULL;
	while ((size_t)len_read == size && !ft_in_gnl(buffer, 0, size))
	{
		buffer = malloc(size * sizeof(char));
		if (!buffer)
		{
			ft_gnlclear(&fd_arr[fd]);
			return (1);
		}
		len_read = read(fd, buffer, size);
		if (len_read == -1)
		{
			free(buffer);
			return (!ft_gnlclear(&fd_arr[fd]));
		}
		if (!len_read)
			free (buffer);
		else if (ft_lstnew_back_gnl(fd_arr, fd, buffer, len_read))
			return (1);
	}
	return (0);
}

static char	*ft_alloc_next_line(t_gnl **fd_arr, int fd, char *next_line,
	size_t size)
{
	t_gnl	*ptr;
	size_t	len;
	size_t	i;

	len = 0;
	ptr = fd_arr[fd];
	i = ptr->i;
	while (ptr && !(i >= ptr->len && ptr->len < size))
	{
		len++;
		if (ptr->content[i] == '\n')
			break ;
		if (i + 1 >= ptr->len)
		{
			ptr = ptr->next;
			i = 0;
		}
		else
			i++;
	}
	next_line = malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	next_line[len] = '\0';
	return (next_line);
}

static char	*ft_join_lst(t_gnl **fd_arr, int fd, t_gnl *ptr, size_t size)
{
	size_t	i;
	size_t	j;
	char	*next_line;

	i = 0;
	ptr = fd_arr[fd];
	j = ptr->i;
	next_line = ft_alloc_next_line(fd_arr, fd, NULL, size);
	if (!next_line)
		return (NULL);
	while (ptr && !(j >= ptr->len && ptr->len < size))
	{
		next_line[i++] = ptr->content[j];
		if (ptr->content[j] == '\n')
			break ;
		if (j + 1 >= ptr->len)
		{
			ptr = ptr->next;
			j = 0;
		}
		else
			j++;
	}
	ft_reinit_lst(fd_arr, fd);
	return (next_line);
}

char	*get_next_line(int fd, size_t size, char *error)
{
	char			*next_line;
	static t_gnl	*fd_arr[1024] = {NULL};

	next_line = NULL;
	if (fd < 0 || fd > 1023 || size <= 0)
		return (NULL);
	if (!fd_arr[fd] || (fd_arr[fd]->len == size
			&& !ft_in_gnl(fd_arr[fd]->content, fd_arr[fd]->i, fd_arr[fd]->len)))
	{
		if (ft_parse_next_line(fd_arr, fd, size))
		{
			*error = 1;
			return (NULL);
		}
	}
	if (!fd_arr[fd])
		return (NULL);
	next_line = ft_join_lst(fd_arr, fd, NULL, size);
	if (!next_line)
	{
		*error = 1;
		return (ft_gnlclear(&fd_arr[fd]));
	}
	return (next_line);
}

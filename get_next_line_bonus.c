/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:08:12 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/21 13:08:14 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

void	read_file(int fd, char **remainder, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, remainder, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*remainder);
		ft_free_strs(remainder, 0, 0);
		*remainder = join_strs(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*remainder))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
}

char	*extract_line_from_buffer(char **remainder, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*remainder);
	ft_free_strs(remainder, 0, 0);
	*remainder = after_newline(*tmp);
	line = before_newline(*tmp);
	ft_free_strs(tmp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	read_file(fd, &remainder[fd], &tmp);
	if (remainder[fd] != NULL && *remainder[fd] != '\0')
		line = extract_line_from_buffer(&remainder[fd], &tmp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&remainder[fd], &line, &tmp);
		return (NULL);
	}
	return (line);
}

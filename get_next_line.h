/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:08:34 by adeboose          #+#    #+#             */
/*   Updated: 2024/10/23 11:44:41 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* ---------- GNL ------------ */
char	*get_next_line(int fd);
void	read_file(int fd, char **remainder, char **tmp);
char	*parse_buffer(char **remainder, char **tmp);
char	*before_newline(const char *s);
char	*after_newline(const char *s);

/* ---------- UTILS ---------- */
int		contains_newline(const char *s);
char	*ft_strdup(const char *s1);
char	*join_strs(const char *s1, const char *s2);
void	*ft_malloc_zero(size_t count, size_t size);
void	ft_free_strs(char **str, char **str2, char **str3);

#endif

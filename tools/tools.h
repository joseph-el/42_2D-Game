/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:30:56 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/21 10:51:00 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t __count, size_t __size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t __size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *stash, char *buffer);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*found(char *str);
char	*ft_subline(char *stash);
char	*cleaning_stash(char *stash);
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:55:45 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/21 18:09:08 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int nb);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(const char *str);
void		ft_putstr_fd(char const *s, int fd);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *src);
int			ft_strequ(const char *s1, const char *s2);
void		ft_striter(char *s, void (*f)(char *c));
void		ft_striteri(char *s, void (*f)(unsigned int n, char *c));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		*ft_strmap(const char *s, char (*f)(char c));
char		*ft_strmapi(const char *s, char (*f)(unsigned int n, char c));
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnew(size_t size);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strtrim(const char *s);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_swap(int *a, int *b);
int			ft_is_whitespace(char c);
const char	*ft_find_next_str(const char *str, char c, int skip);
int			ft_count_splits_str(const char *str, char seps);
void		*ft_tabledel(char **array, int i);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

#endif

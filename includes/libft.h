/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:09:01 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/25 14:41:00 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_format
{
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
	char			length;
	char			type;
	struct s_format	*first;
	struct s_format	*next;
}				t_format;

int				ft_atoi(char *str);
int				ft_atoin(char *str, int n);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(intmax_t nbr);
char			*ft_itoa_base(uintmax_t value, int base);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
	size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
	size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_mod(int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnstr(char const *s, int n);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr_in_upper(char const *s);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
	size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char			*ft_strncat(char *restrict s1, const char *restrict s2,
	size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strndup(const char *s1, int n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_numbercount (char *str);
int				ft_notnumbercount (char *str);
char			*ft_onlytext (char *str);
char			*ft_onlynumber (char *str);
int				ft_arrsize(char const *s, char c);
char			*ft_unicode(wchar_t wch);
int				ft_sizeof_unicode(wchar_t wch);
int				ft_counter(int num);
char			pf_find_flags(char *s, int start, char c);
int				pf_find_width(char *s, int start, int end);
int				pf_find_precision(char *s, int start, int end);
char			pf_find_length(char *s, int start, int end, int i);
char			pf_find_type(char *s, int end);
int				pf_is_type(char c);
int				pf_to_struct(char *s, int start, int i, t_format **format);
char			*pf_add_0x(char *str, int len);
char			*pf_add_to_start(char *str, char c, int num);
char			*pf_add_to_end_char(char *str, char c, int num);
char			*pf_add_to_end(char *str, char c, int num);
char			*pf_set_wight (char *s, t_format *format);
char			*pf_set_precision_num(char *s, int precision);
char			*pf_set_precision_str(char *s, int precision);
void			pf_read_s(va_list *args, t_format *format);
void			pf_read_p(va_list *args, t_format *format);
void			pf_read_c(va_list *args, t_format *format);
void			pf_read_di(va_list *args, t_format *format);
void			pf_read_uox(va_list *args, t_format *format);
void			pf_read_percent(t_format *format, char c);
char			pf_next_type(char *s, int start);
void			pf_del_struct(t_format *format);
int				pf_next_type_pos(char *s, int start);
int				ft_printf(char *s, ...);
int				get_next_line(const int fd, char **line);

#endif

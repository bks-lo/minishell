/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:57:28 by dscriabi          #+#    #+#             */
/*   Updated: 2022/03/05 20:43:40 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 32
# endif
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_flags
{
	int			type;
	int			width;
	int			dash;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

char			*ft_itoa(int n);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(const char *str, int c);
char			*ft_strnstr(const char *big, const char *little, int len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
int				ft_strlen(const char *str);
int				ft_isalpha(int argument);
int				ft_isdigit(int arg);
int				ft_isalnum(int arg);
int				ft_isascii(int arg);
int				ft_isprint(int arg);
int				ft_toupper(int arg);
int				ft_tolower(int arg);
int				ft_isoutofintrange(char *number);
int				ft_atoi(const char *str);
int				ft_memcmp(const void *str1, const void *str2, int n);
int		ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, int n);
int				ft_lstsize(t_list *lst);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_calloc(int nitems, int size);
void			*ft_realloc(void *ptr, size_t size);
void			ft_bzero(void *s, int n);
void			*ft_memset(void *str, int c, int n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memccpy(void *dest, const void *src, int c, int n);
void			*ft_memchr(const void *str, int c, int n);
void			*ft_memmove(void *str1, const void *str2, int n);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
int				ft_printf(const char *format, ...);
void			ft_putchar(char c);
int				ft_istype(int kar);
int				ft_isflag(int kar);
int				ft_interpret_dot(const char *str, t_flags *flags, va_list args);
t_flags			ft_interpret_dash(t_flags flags);
t_flags			ft_interpret_star(va_list list, t_flags flags);
t_flags			ft_interpret_digit(char c, t_flags flags);
int				ft_print_width(int width, int minus, int zero);
int				ft_print_char(char c, t_flags flags);
int				ft_flag_filter(t_flags flags, va_list list);
int				ft_print_percent(t_flags flags);
int				ft_print_str_precision(char *str, int precision);
int				ft_print_string(char *str, t_flags flags);
int				ft_print_pointer(unsigned long long ull_ptr, t_flags flags);
char			*ft_ptoa(unsigned long long dec);
char			*ft_utoa(unsigned int n);
int				ft_print_int(int integer_input, t_flags flags);
int				ft_print_uint(unsigned int uint_input, t_flags flags);
int				ft_print_hexa(unsigned int hexa_input, t_flags flags);
char			*get_next_line(int fd);
int			ft_get_next_line(int fd, char **out_str, int *len);
char			*ft_gnl_strjoin(char const *s1, char const *s2);
size_t			ft_gnl_strlen(char *s);
void			*ft_free_split(char **split_str, int word_count);
int				ft_stringcomp(const char *str1, const char *str2);
int				ft_strisnum(const char *str);
int				ft_free_all_split(char **split);
double			ft_atof(const char *str);

#endif

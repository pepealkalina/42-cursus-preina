/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:58:34 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/30 13:32:11 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define NEGRO_T    "\x1b[30m"
# define NEGRO_F    "\x1b[40m"
# define ROJO_T     "\x1b[31m"
# define ROJO_F     "\x1b[41m"
# define VERDE_T    "\x1b[32m"
# define VERDE_F    "\x1b[42m"
# define AMARILLO_T "\x1b[33m"
# define AMARILLO_F "\x1b[43m"
# define AZUL_T     "\x1b[34m"
# define AZUL_F     "\x1b[44m"
# define MAGENTA_T  "\x1b[35m"
# define MAGENTA_F  "\x1b[45m"
# define CYAN_T     "\x1b[36m"
# define CYAN_F     "\x1b[46m"
# define BLANCO_T   "\x1b[37m"
# define BLANCO_F   "\x1b[47m"
# define RESET_COLOR "\x1b[0m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str);
void		*ft_bzero(void *s, size_t n);
int			ft_isalpha(int argument);
int			ft_isalnum(int argument);
int			ft_isascii(int argument);
int			ft_isprint(int argument);
int			ft_isdigit(char *argument);
size_t		ft_strlen(const char *str);
int			ft_toupper(int chara);
int			ft_tolower(int chara);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memcpy(void *to, const void *from, size_t num);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		*ft_memmove(void *str1, const void *str2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
void		*ft_memccpy(void *dest, const void *orig, int c, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strrchr(const char *str, int c);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_printf

int			ft_printf(char const *str, ...);
int			ft_printchar(int c);
int			ft_printstr(char *s);
int			ft_printnbr(long nb);
int			ft_print_ptr(unsigned long long ptr);
int			ft_printu(unsigned int nb);
int			ft_print_hex(unsigned int nbr);
int			ft_printp(unsigned long long ptr);

#endif
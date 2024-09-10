/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:17:42 by jyap              #+#    #+#             */
/*   Updated: 2024/03/23 14:10:23 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

int			ft_isalpha(int i);
int			ft_isdigit(int i);
int			ft_isalnum(int i);
int			ft_isascii(int i);
int			ft_isprint(int i);
int			ft_strlen(const char *str);
void		*ft_memset(void *s, int i, size_t size);
void		ft_bzero(void *s, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int i);
int			ft_tolower(int i);
char		*ft_strchr(const char *str, int i);
char		*ft_strrchr(const char *str, int i);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
void		*ft_memchr(const void *s, int i, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t size);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *str);
char		*ft_substr(const char *str, unsigned int start, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *str, char c);
char		*ft_itoa(int i);
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int i, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		pcs;
	int		neg_pcs;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}	t_format;

# define SPECIFIERS "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			print_dupe_fd(char c, int n, int fd);
t_format	ft_newformat(void);
int			ft_print_format(t_format f, va_list ap);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_d_i(t_format f, va_list ap, int *count);
int			ft_print_u(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list ap);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*ft_strcomb(char *dst, char *src);
int			checkend(char c);
int			check_nl(char *str);
char		*get_next_nl(int fd, char *output);
char		*get_read(char *input);
char		*savepoint(char *input);
char		*get_next_line(int fd);

#endif

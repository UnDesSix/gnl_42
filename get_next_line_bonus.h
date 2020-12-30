/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarboul <mlarboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:23 by mlarboul          #+#    #+#             */
/*   Updated: 2020/11/20 23:36:02 by mlarboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_BONUS_H
# define FT_GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# if (BUFFER_SIZE > 8192000)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8192000
# endif

typedef	unsigned int	t_size;

typedef struct	s_list
{
	int				fd;
	int				flag_eof;
	t_size			buff_size;
	t_size			line_size;
	t_size			buff_indx;
	char			*buffer;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_read_fd(t_list *elm, char **line);
int				ft_fill_line(t_list *elm, char **line);
void			ft_clear_elm(t_list **begin_list, t_list *elm_to_del);
t_list			*ft_create_elmem(int fd);
t_list			*ft_push_front(t_list **begin_list, int fd);
char			*ft_strncpy(char *dst, char *src, size_t len);
char			*ft_realloc_spe(char *src, size_t init_len, size_t add_len);
char			*ft_strncat(char *dst, char *src,
										size_t line_offset, size_t add_len);

#endif

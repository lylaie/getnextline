/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:41:25 by audumont          #+#    #+#             */
/*   Updated: 2020/01/21 00:30:53 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX _POSIX_OPEN_MAX
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef GNL_ERROR
#  define GNL_ERROR -1
# endif

# ifndef GNL_SUCCESS
#  define GNL_SUCCESS 1
# endif

# ifndef GNL_END
#  define GNL_END 0
# endif

int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *str);
int						ft_free(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:31:24 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/01 13:00:57 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# define C_BLUE	"\033[34m"
# define C_RED	"\033[31m"
# define C_NONE	"\033[0m"
# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_lem_in
{
	struct s_lem_in		*next;
	struct s_lem_in		*prev;
	char				*room_name;
	char				**room_link;
	char				**save;
	int					open;
	int					tab;
	int					nb_ants;
}						t_lem_in;

typedef struct			s_lem_out
{
	struct s_lem_out	*next;
	struct s_lem_out	*prev;
	struct s_lem_out	*first;
	struct s_lem_out	*last;
	char				*room_name;
	int					nb_ants;
}						t_lem_out;

int						g_nbr_ants;
char					*g_start;
char					*g_end;
int						main(int ac, char **av);
void					check_link(t_lem_in **list, char *line);
void					end(char *line);
void					start(char *line);
int						alloc_tab(int *len, t_lem_in *list);
void					free_all(t_lem_in *list);
void					free_all_2(t_lem_out *list);
void					check_road(t_lem_in *list);
void					send_ants(t_lem_in *list, t_lem_in *start);
void					check_room(void);
int						short_road(t_lem_in *list, t_lem_in *s, t_lem_in *end);
void					init_save(t_lem_in *list);
void					save_tab(char *str, t_lem_in *list);
void					print_link(t_lem_in *list);
void					error(char *s1);
void					check_nbr(char *line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:25:53 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/16 15:54:05 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# define BUFFSIZE		20
# define STDIN			0
# define NO_FAULT		0
# define EASY_ROTATE	1
# define HARD_ROTATE	2
# define _FAULT_		0x00
# define _ERROR_		0x00
# define _SUCCESS_		0x01
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_pushswap
{
	int				*a;
	int				*b;
	int				tmpa;
	int				tmpb;
	int				len;
	int				count;
	int				arg;
	t_bool			count_rules;
	t_bool			print_rules;
	t_bool			final_display;
	t_bool			print_display;
}					t_pushswap;

typedef struct		s_env
{
	int				value;
	struct s_env	*first_b;
	struct s_env	*last_b;
	struct s_env	*first_a;
	struct s_env	*last_a;
	struct s_env	*ptr;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef struct		s_lst
{
	char			*param;
	struct s_lst	*next;
}					t_lst;

/*
**		checker functions
*/

int					check_arg(int ac, char **av);
t_lst				*create_new_clist(char *line);
t_lst				*add_back_clist(t_lst *list, char *line);
void				put_in_dblist(int ac, char **av, t_env **tmp2);
void				check_param(char *param);
void				sort_param(t_lst *list_par, t_env **tmp2);
void				rotate_a(t_env **tmp2, t_lst *list_par);
void				rotate_b(t_env **tmp2, t_lst *list_par);
void				rev_rotate_a(t_env **tmp2, t_lst *list_par);
void				rev_rotate_b(t_env **tmp2, t_lst *list_par);
void				swap_s(t_env **tmp2, char c, t_lst *list_par);
void				check_sort(t_env *tmp2);
int					check_arg(int ac, char **av);
int					check_double(int ac, char **av);

/*
**		push_swap functions
*/

int					get_arg(t_pushswap *ps, int ac, char **av, int arg);
int					algo_reverse(t_pushswap *ps);
int					easy_begin(t_pushswap *ps);
void				push_swap(t_pushswap *ps);
void				sort_sample_list(int *list, int beg, int end);
int					get_fault(int *p, int len);
int					get_max(int *p, int len);
int					get_min(int *p, int len);
int					get_index(int *p, int len, int present);
void				rule_sa(t_pushswap *ps);
void				rule_sb(t_pushswap *ps);
void				rule_pa(t_pushswap *ps);
void				rule_pb(t_pushswap *ps);
void				rule_ra(t_pushswap *ps);
void				rule_rb(t_pushswap *ps);
void				rule_rra(t_pushswap *ps);
void				rule_rrb(t_pushswap *ps);
void				rule_ss(t_pushswap *ps);
void				rule_rr(t_pushswap *ps);
void				rule_rrr(t_pushswap *ps);
void				push_up_sort(int *t, int len);
void				push_back_sort(int *t, int len);
int					rotate_basic_a(t_pushswap *ps);
int					rotate_hard_a(t_pushswap *ps);
void				display(t_pushswap *ps);

/*
**		global_functions
*/

void				push_a(t_env **tmp2);
void				push_b(t_env **tmp2);

/*
**		other functions
*/

void				print(t_env *tmp2);
void				print_list(t_env *tmp2);
void				print_list_a(t_env *tmp2);
void				print_list_b(t_env *tmp2);

#endif

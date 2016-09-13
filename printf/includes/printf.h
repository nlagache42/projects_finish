/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 11:46:39 by nlagache          #+#    #+#             */
/*   Updated: 2016/09/03 00:54:18 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
int				is_valid(const char *format, int i);
long			check_flags(va_list ap, const char *format, int *i, char **tmp, int *j);
char			what_attribut(const char *format, int i);
char			*flag_space(int arg, const char *format, int **i, char *tmp, int **r);
long long		check_arg_int(va_list ap, const char *format, int i);
char			*check_arg_char(va_list ap, const char *format, int i);
char			*check_attribut(long arg, char **arg_char, const char *format, int i, int **r);
char			*flag_nbr(int arg, const char *format, int **i,char *tmp);
char			*flag_nbr_char(char *arg_char, const char *format, int **i, char *tmp);
char			*flag_zero(long *arg, const char *format, int **i, char *tmp);
char			*flag_zero_char(char *arg_char, const char *format, int **i, char *tmp, int *ext);
char			*flag_negative(int arg, const char *format, int **i,char *tmp, int **r);
char			*flag_negative_char(char *arg_char, const char *format, int **i, char *tmp);
char			*flag_positive(int arg, const char *format, int **i, char **tmp, int **r);
char			*flag_wildcard(va_list ap, int arg, const char *format, int **i, char *tmp);
char			*flag_wildcard_negative(int arg, int arg2, char *tmp);
char			*flag_wildcard_positive(int arg, int arg2, char *tmp, char att);
char			*flag_wildcard_nbr(int arg2, char *tmp, int nbr_space);
int				*flag_wildcard_nbr_space(int arg2, const char *format, int ***i, int *nbr_space);
char			*flag_point(long *arg, const char *format, int **i, char *tmp, int **r);
char			*flag_point_char(char *arg_char, const char *format, int **i, char *tmp);
char			*save_char(int arg);
char			*convert_upper(char *arg_char);
char			*flag_l(long arg, char *tmp);
char			*flag_diez(char*arg_char, const char *format, int **i,char *tmp);
char			*save_value_int(char *tmp2, char **tmp, int x);
long			ft_convert_byte(char *str);
char			*save_val_base(char *mask, char *val_base);
long			ft_atoi_long(const char *str);
long			ft_long(long value);
char			*ft_maxi(void);
char			*ft_itoa_long(long n);
char			*ft_otoa(unsigned long long n);
char			*ft_otoa_spec(unsigned long long n);
char			*ft_btoa(unsigned long n);
long			ft_convert_byte(char *str);
char			*save_val_base(char *mask, char *val_base);
char			*ft_utoa(unsigned long long n);
char			*ft_htoa_void(unsigned long n);
int				ft_strcmp(const char *s1,const char *s2);//akrgjkjgklj
long long		hexa_value(long long x);
char			*ft_htoa(unsigned long long n);
int				ft_nbrlen_long(int n);
int				print_str(char *tmp, long arg, char att);
char			*save_false(char *tmp, char c);

#endif

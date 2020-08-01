/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:34:05 by cyuriko           #+#    #+#             */
/*   Updated: 2019/09/10 14:34:08 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define COLOR_RED     "RED"
# define COLOR_GREEN   "GREEN"
# define COLOR_YELLOW  "YELLOW"
# define COLOR_BLUE    "BLUE"
# define COLOR_MAGENTA "MAGENTA"
# define COLOR_CYAN    "CYAN"
# define COLOR_RESET   "RESET"
# define COLOR_BLINK	"BLINK"
# define UNDERLINE_TEXT	"UNDERLINE"

typedef struct	s_struct
{
	int			i;
	int			fd;
	size_t		len;
	int			start;
	char		cplus;
	char		cspase;
	char		*chash;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			init_l;
	int			init_h;
	int			width;
	int			precision;
	int			no_presicion;
	int			int_bl;
	int			was_presicion;
	int 		star;
}				t_struct;

int				ft_printf(const char *str, ...);
t_struct		*create_struct(t_struct *f);
t_struct		*zeroing(t_struct *f);
void			search_details(const char *str, t_struct *f, va_list ap);
t_struct		flags(t_struct *f, char c);
void			specifier(char c, t_struct *f, va_list ap);
void			bonus_specifier(char c, t_struct *f, va_list ap);
void			long_allocation(t_struct *f, char c, va_list ap);
void			short_allocation(t_struct *f, char c, va_list ap);
void			ft_print_s(t_struct *f, va_list ap);
void			ft_print_c(t_struct *f, va_list ap);
void			ft_print_d(t_struct *f, va_list ap);
void			ft_print_u(t_struct *f, va_list ap);
void			ft_print_p(t_struct *f, va_list ap);
void			ft_print_o(t_struct *f, va_list ap);
void			ft_print_x(t_struct *f, va_list ap, char c);
void			ft_print_b(t_struct *f, va_list ap);
void			ft_print_r(t_struct *f, va_list ap);
void			ft_print_bc(va_list ap);
void			print_nonprintable(int c, t_struct *f);
void			print_nonprintable2(int c, t_struct *f);
void			print_nonprintable3(int c, t_struct *f);
void			ft_print_ld(t_struct *f, va_list ap);
void			ft_print_lld(t_struct *f, va_list ap);
void			ft_print_lu(t_struct *f, va_list ap);
void			ft_print_llu(t_struct *f, va_list ap);
void			ft_print_lo(t_struct *f, va_list ap);
void			ft_print_llo(t_struct *f, va_list ap);
void			ft_print_lx(t_struct *f, va_list ap, char c);
void			ft_print_llx(t_struct *f, va_list ap, char c);
void			ft_print_hd(t_struct *f, va_list ap);
void			ft_print_hhd(t_struct *f, va_list ap);
void			ft_print_hu(t_struct *f, va_list ap);
void			ft_print_hhu(t_struct *f, va_list ap);
void			ft_print_ho(t_struct *f, va_list ap);
void			ft_print_hho(t_struct *f, va_list ap);
void			ft_print_f(t_struct *f, va_list ap);
void			ft_print_hx(t_struct *f, va_list ap, char c);
void			ft_print_hhx(t_struct *f, va_list ap, char c);
void			print_width_before(int avail_wid, int len_param, t_struct *f);
void			print_width_after(int avail_wid, int len_param, t_struct *f);
void			print_unsigned_width_before(int avail_wid, int len_param,
		t_struct *f);
void			print_unsigned_width_after(int avail_wid, int len_param,
		t_struct *f);
void			print_text_width_before(int avail_wid, int len_param,
		t_struct *f);
void			print_text_width_after(int avail_wid, t_struct *f);
void			print_nondec_width_before(int avail_wid, int len_p, t_struct *f,
		char c);
void			extra_nondec_before(int av_width, int g, t_struct *f, char c);
void			print_nondec_width_after(int avail_wid, int len_p, t_struct *f,
		char c);
void			extra_case(t_struct *f, int len_param, char c);
void			extra_case_2(t_struct *f, int len_param);
void			extra_case_3(t_struct *f, int len_param);
void			extra_case_4(t_struct *f, int len_param);
void			rezeroing(t_struct *f);
char			*ft_itoa_base(u_int64_t value, int base, char c);
int				len_value(u_int64_t value, int base);
int				space_or_plus(t_struct *f, long long int d);
void			alternative_output(t_struct *f, char c);
void			determine_width(const char *str, t_struct *f);
void			determine_presicion(const char *str, t_struct *f);
void			expanded_specifier(char c, t_struct *f);
void			print_space_plus(t_struct *f);
void			print_width(t_struct *f);
void			alternative_long(char c, t_struct *f, va_list ap);
char			*ft_itoa2(unsigned long long int n);
long double		ft_pow(double x, int y);
void			search_else_details(const char *s, t_struct *f, va_list ap);
void			specifier2(char c, t_struct *f, va_list ap);
int				chek_oct_hex(t_struct *f, unsigned int nb, int flag);
int				check_nums(t_struct *f, int nb);
void			ft_print_bf(t_struct *f, va_list ap);
int				write_denormal_b(long double flat, t_struct *f);
int				write_denormal(double flat, t_struct *f);

#endif

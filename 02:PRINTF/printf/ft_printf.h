
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int precision;
	int star;
}	t_flags;

int		ft_printf(const char *format, ...);
size_t	ft_parse_input(va_list arguments, const char *format);
void	ft_init_flags(t_flags *flags);
size_t	ft_parse_flag(const char *format, size_t i, t_flags *flags, va_list
						arguments);
size_t	ft_is_digit(char symb);
size_t	ft_is_type(char symb);
void	ft_flag_dot(const char *format,size_t *i, t_flags *flags, va_list
						arguments);
void	ft_flag_width(t_flags *flags, va_list arguments);
void	ft_flag_minus(t_flags *flags);
void	ft_flag_digit(t_flags *flags, char dig);
size_t	ft_processor(char type, t_flags *flags, va_list arguments);
size_t	ft_add_width(int width, int printed_elements, int flag_null);
size_t	process_char(char symb, t_flags flags);
size_t	process_percent(t_flags flags);
size_t	process_string(char *string, t_flags flags);
int		ft_strlen(const char *s);
size_t	ft_proc_str_with_precision(char *string, int precision);
size_t	ft_proc_minus(char  *string, t_flags flags);
size_t	process_integer(int num, t_flags flags);
char	*ft_itoa(int n);
size_t	process_unsigned_int(unsigned int num, t_flags flags);
char 	*ft_itoa_unsigned_int(unsigned int num);
size_t	process_pointer(unsigned long pointer, t_flags *flags);
size_t	process_hex(unsigned int hex, int cap, t_flags flags);

#endif

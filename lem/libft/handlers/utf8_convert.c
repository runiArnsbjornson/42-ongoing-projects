/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:46:48 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 15:13:05 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		numberbits(unsigned int code)
{
	int				ret;
	unsigned int	mask;

	ret = 0;
	mask = 1;
	if (code < 2)
		return (1);
	while (code >= mask)
	{
		++ret;
		mask <<= 1;
		if (mask == 0)
			return (8 * sizeof(code));
	}
	return (ret);
}

void	push_char(char *buf, size_t *index, char eob)
{
	if (*index == 0 || buf == NULL || index == NULL)
		return ;
	--*index;
	buf[*index] = eob;
}

void	push_uchar(char *buf, size_t *index, unsigned char eohex)
{
	push_char(buf, index, (char)eohex);
}

char	*utf8_convert(char *buf, size_t index, int code)
{
	const int			usablebits[4] = {7, 5, 4, 3};
	const unsigned char	mask[4] = {0x7F, 0x1F, 0x0F, 0x07};
	const unsigned char prefix[4] = {0x00, 0xC0, 0xE0, 0xF0};
	int					bits_left;
	size_t				i;

	i = 0;
	bits_left = numberbits((unsigned int)code);
	if (buf == NULL || index < 5 || code < 0 || bits_left > 21 || buf == 0)
		return (NULL);
	push_char(buf, &index, '\0');
	while (bits_left > usablebits[i])
	{
		push_uchar(buf, &index, (unsigned char)(code & 0x0000003F) | 0x80);
		++i;
		code >>= 6;
		bits_left -= 6;
		if (i > 4)
			return (NULL);
	}
	push_uchar(buf, &index, (unsigned char)(code & mask[i]) | prefix[i]);
	return (buf + index);
}

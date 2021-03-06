/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:09:44 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/14 04:06:47 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		rgb_to_hexa(int r, int g, int b)
{
	if (r > 255)
		r = 55;
	if (g > 255)
		g = 55;
	if (b > 255)
		b = 55;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

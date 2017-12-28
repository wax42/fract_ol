/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:59:47 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:37:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	mouse_hook1(int x, int y, t_p *p)
{
	if (x < (WIN_X) && y < (WIN_Y))
	{
		p->fract.c_r = (x < p->mouse_x) ? (p->fract.c_r + 0.01) : \
		(p->fract.c_r - 0.01);
		p->fract.c_i = (y < p->mouse_y) ? (p->fract.c_i + 0.01) : \
		(p->fract.c_i - 0.01);
	}
}

int			mouse_hook(int x, int y, t_p *p)
{
	if (x >= 0 && x <= WIN_X && y >= 0 && y <= WIN_Y)
	{
		if (p->var_mouse == 1)
		{
			mouse_hook1(x, y, p);
			ft_which_fractal(p);
		}
		p->mouse_x = x;
		p->mouse_y = y;
	}
	return (0);
}

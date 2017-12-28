/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rool_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:37:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:42:35 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	roll_hook1(int button, int x, int y, t_p *p)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		if (button == 1 || button == 4)
		{
			p->fract.zoom *= 1.1;
			p->fract.x1 = p->fract.x1 + ((double)x - ((double)WIN_X / 2)) \
			/ p->fract.zoom;
			p->fract.y1 = p->fract.y1 + ((double)y - ((double)WIN_Y / 2)) \
			/ p->fract.zoom;
		}
		if (button == 2 || button == 5)
		{
			p->fract.zoom *= 0.9;
			p->fract.x1 = p->fract.x1 + ((double)x - ((double)WIN_X / 2)) \
			/ p->fract.zoom;
			p->fract.y1 = p->fract.y1 + ((double)y - ((double)WIN_Y / 2)) \
			/ p->fract.zoom;
		}
	}
}

int			roll_hook(int button, int x, int y, t_p *p)
{
	roll_hook1(button, x, y, p);
	ft_which_fractal(p);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur_fibonacci.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:05:02 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 00:38:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	ft_recur_fibonacci_1(t_p *p, t_fract *l)
{
	if (l->val == 1)
	{
		l->y -= l->size;
		ft_draw_carre_fibonnaci(p, *l);
		l->x += l->size;
	}
	else if (l->val == 2)
	{
		l->x -= l->size;
		l->y -= l->size;
		ft_draw_carre_fibonnaci(p, *l);
	}
	else if (l->val == 3)
	{
		l->x -= l->size;
		ft_draw_carre_fibonnaci(p, *l);
		l->y += l->size;
	}
}

void		ft_recur_fibonacci(t_p *p, t_fract l)
{
	l.i = l.iteration_max;
	while (--l.i > 0)
	{
		l.size = ft_fibonacci(l.i);
		if (l.val == 0 || l.val == 4)
		{
			ft_draw_carre_fibonnaci(p, l);
			l.x += l.size;
			l.y += l.size;
			l.val = 0;
		}
		ft_recur_fibonacci_1(p, &l);
		l.val++;
	}
}

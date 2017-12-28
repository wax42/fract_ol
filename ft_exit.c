/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 23:35:09 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/21 15:39:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	ft_aff_error(int code)
{
	if (code == -1)
		ft_putendl("ESC");
	else if (code == 0)
		ft_putstr("Usage : ./fractol <filename> [ ex :./fractol Mandelbrot ] \
		\n\n filename valid: { Mandelbrot, Mandelbrot_Conjugate}\n\t\t { Julia,\
Fibonacci, Fibonacci_normal}\n");
}

int			ft_exit(int i)
{
	ft_aff_error(i);
	exit(0);
}

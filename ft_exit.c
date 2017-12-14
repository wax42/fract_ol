/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 23:35:09 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/11 23:35:16 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	ft_aff_error(int code)
{
	if (code == -1)
		ft_putendl("ESC");
	else if (code == 0)
		ft_putendl("Fd invalide");
	else if (code == 1)
		ft_putendl("Maps invalides");
	else if (code == 2)
		ft_putendl("Error Malloc");
}

int			ft_exit(int i)
{
	ft_aff_error(i);
	exit(0);
}

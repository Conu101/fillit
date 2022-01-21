/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_listorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:31:45 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 11:39:45 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//for example if we want to pass the first piece to second position, next to 
// first will be the third and next to second will be first
t_piecelist	*switch_listorder(t_piecelist *piecelist, int i)
{
	piecelist->list[i + 1]->next = piecelist->list[i];
	piecelist->list[i]->next = piecelist->list[i + 2];
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern_matching/substr.h"

char		*substr_sharp(t_substr *this, char *str, char *pattern)
{
	char	*ret;

	this->patss = pattern_substr_new(pattern); 
	this->match = twl_strnew(twl_strlen(str));
	this->str = str;
	this->ind_m = 0;
	this->ind_p = 0;
	substr_sharp_supervisor(this);
	ret = twl_strdup(this->str + twl_strlen(this->match));
	free(this->match);
	pattern_substr_del(this->patss);
	this->patss = NULL;
	return (ret);
}

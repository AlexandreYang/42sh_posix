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

#ifndef PATMATCH_H
# define PATMATCH_H

# include "basics.h"
# include "twl_dict.h"
# include "twl_ctype.h"
# include "pattern.h"
# include <dirent.h>
# include <sys/stat.h>

typedef struct		s_match__
{
	t_lst			*pattern;
	char			*name;
	int				ind_p;
	int				ind_n;
	int				len;
}					t_match__;

typedef struct		s_matching_
{
	DIR				*fd_dir;
	char			*building;
	t_lst			*pattern;
	int				depth;
}					t_matching_;

typedef struct		s_class_expr__
{
	char			*name;
	char			expr[128];
	int				ind_n;
	int				ind_e;
	int				reverse;
}					t_class_expr__;

typedef struct		s_patmatch
{
	t_pattern		*pattern;
	t_lst			*match;
	t_dict			*class_expr;
}					t_patmatch;

t_patmatch			*patmatch_new(void);
void				patmatch_del(t_patmatch *this);

void				patmatch_add_class_expr_(t_patmatch *this, char *content);
void				patmatch_ce_open_bracket__(t_patmatch *this,
															t_class_expr__ *ce);
void				patmatch_ce_hyphen__(t_class_expr__ *ce);
															

t_lst				*patmatch_match(t_patmatch *this, char *pattern);
void				patmatch_recurs__(t_patmatch *this, t_matching_ *match);

int					patmatch_supervisor__(t_patmatch *this, t_match__ *m);
int					patmatch_question_mark__(t_patmatch *this, t_match__ *m);
int					patmatch_fixed__(t_patmatch *this, t_match__ *m,
													t_pattern_data *data);
int					patmatch_asterisk__(t_patmatch *this, t_match__ *m);
int					patmatch_bracket__(t_patmatch *this, t_match__ *m,
													t_pattern_data *data);

#endif

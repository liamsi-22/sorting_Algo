/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushwap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:59:17 by iel-fagh          #+#    #+#             */
/*   Updated: 2024/05/12 16:08:56 by iel-fagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct lst
{
	int			x;
	int			up;
	int			position;
	int			push_cost;
	struct lst	*target_node;
	struct lst	*next;
}				t_list;

// utils functions ...
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char *s, char c);
long long		ft_atoi(char *str);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// chwck error functions ...
int				checknumbers(char *str);
int				checkminmax(char *str);
int				checkdouble(char *str);
int				checkdgts(char *str);

// linked_list functions ...
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstbfrlast(t_list *lst);
void			free_arrayy(char **array);
t_list			*ft_lstlast(t_list *lst);
t_list			*lst_min(t_list *lst);
char			*ft_strneww(size_t n);
int				ft_lstsize(t_list *lst);
int				lst_max(t_list *lst);

// turk_algo functions ...
t_list			*stackinit(t_list *stack_a, char *str);
void			push_except3(t_list **a, t_list **b);
void			push_to_a(t_list **a, t_list **b);
void			fill_stacks(t_list *b, t_list *a);
void			turk_algo(t_list **a, t_list **b);
int				find_bigsmaller(int y, t_list *a);
t_list			*find_target(int y, t_list *a);
void			fill_swap_cost(t_list *b);
t_list			*find_cheapest(t_list *b);
void			fill_positiona(t_list *a);
int				check_order(t_list *stack);
void			sort_3(t_list **lst);

// instruction functions ...
void			pb(t_list **a, t_list **b);
void			pa(t_list **b, t_list **a);
void			rrr(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);
void			ss(t_list *a, t_list *b);
void			rrb(t_list **stack_b);
void			rra(t_list **stack_a);
void			rb(t_list **stack_b);
void			ra(t_list **stack_a);
void			sa(t_list *stack_a);
void			sb(t_list *stack_b);

#endif

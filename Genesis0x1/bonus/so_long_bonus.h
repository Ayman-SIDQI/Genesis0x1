/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:52:58 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/25 11:12:09 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include<stdio.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>
# include<time.h>
# include"get_next_line_bonus.h"
# include"mlx.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_var
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		count;
	int		len;
	int		aard;
	char	*filename;
	int		width;
	int		height;

}t_var;

typedef struct s_check
{
	int		i;
	int		j;
	short	p;
	short	e;
	short	c;
	short	y;
}t_check;

typedef struct s_map
{
	t_check		checks;
	t_var		vars;
	void		*tiles;
	void		*free;
	void		*coin;
	void		*exit;
	void		*portal2;
	void		*portal3;
	void		*portal4;
	void		*limn;
	void		*sup;
	void		*lisr;
	void		*standing;
	void		*enemy;
	int			playerx;
	int			playery;
	int			duplayerx;
	int			duplayery;
	int			exitx;
	int			exity;
	int			enemyx;
	int			enemyy;
	char		*full;
	char		*tmp;
	char		**splitted;
	char		**dupspl;
	int			c;
	int			e;
	int			p;
	void		*mlx_ptr;
	void		*mlx_win;
	int			o;
	int			z;
	int			y;
	int			cc;
	int			fd;
	int			i;

}t_map;

int		ft_strlen(char *s);
int		ft_strchr(char *s, int c);
void	checkerrors(char *av, t_map	*all);
void	ftnlast(char *s1, char *s2, t_map *all);
char	*ft_strjoin(char *s1, char *s2);
char	*mon_strdup(char *s1);
void	jm3str(char *av, t_map *all);
void	allocatedabitch(t_map *all);
char	**ft_split(char *so, char dm);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
void	checkdup(char *full, t_map *all);
void	bitwix(t_map *all);
void	putblk(t_map *all, int i, int j, void *img);
void	stock_blays(t_map *all);
int		checksafe(t_map *all, int y, int x);
void	existance_check(char **str, t_map *all);
void	backtrack(t_map *all, int duplayerx, int duplayery);
char	*ft_itoa(int n);
void	free_2d(char **str, short num);
void	exit_perror(void);
void	var_free(char *full, char *tmp, char**splitted, char **dupspl);
void	exit_close_ciao(int fd);
void	destroy_win_innit(t_map *all);
int		animation_jutsu(t_map *all);
void	fd_mlx_fp_bonus(char *full, char *tmp, char**splitted, t_map *all);
int		search_enemy(t_map *all);
void	var_free_exit_perror(t_map *all);
int		mickeymous(t_map *all);
void	sprite_dance(short exity, short exitx, t_map *all);
void	portal(t_map *all);
void	incrementor(t_map *all, int n);
void	size_and_width(t_map *all);
void	standing_death(t_map *all);
void	lisr_death(t_map *all);
void	enemy_death(t_map *all);
void	limn_death(t_map *all);
void	free_death(t_map *all);
void	coin_death(t_map *all);
void	exit_death(t_map *all);
void	sup_death(t_map *all);
void	last_newline(t_map *all);

#endif
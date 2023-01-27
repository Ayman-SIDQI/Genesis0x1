NAME=so_long

BNAME=so_long_bonus

CC=cc

SRC= ft_split.c \
	shadowrealm2.c \
	bitwix.c \
	get_next_line.c \
	so_long.c \
	checkerrors.c \
	get_next_line_utils.c \
	stock_blays.c \
	checksafe.c \
	freedom.c \
	patch_up.c \
	var_free_exit_perror.c \
	ft_calloc.c \
	readerallocator.c \
	ft_putnbr_fd.c \
	shadow_realm.c

BONUS_SRC= 	bonus/anim_bonus.c 					\
			bonus/get_next_line_utils_bonus.c	\
			bonus/var_free_exit_perror_bonus.c	\
			bonus/get_next_line_bonus.c 			\
			bonus/animation_jutsu_bonus.c		\
			bonus/patch_up_bonus.c				\
			bonus/bitwix_bonus.c				\
			bonus/readerallocator_bonus.c		\
			bonus/checkerrors_bonus.c			\
			bonus/search_enemy_bonus.c			\
			bonus/checksafe_bonus.c				\
			bonus/shadowrealm_2_bonus.c			\
			bonus/freedom_bonus.c				\
			bonus/shadowrealm_bonus.c			\
			bonus/ft_calloc_bonus.c				\
			bonus/so_long_bonus.c				\
			bonus/ft_itoa_bonus.c				\
			bonus/stock_blays_bonus.c			\
			bonus/ft_split_bonus.c				\
			bonus/utils_bonus.c					\
			bonus/fv_mlxd_fp_bonus.c

CFLAGS=-Wall -Wextra -Werror

MLXFLAGS=-lmlx -framework OpenGL -framework AppKit

OBJ=${SRC:.c=.o}

OBJBONUS=${BONUS_SRC:.c=.o}

%.o: %.c so_long.h
	${CC} ${CFLAGS} -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

bonus: ${BNAME}

${BNAME}: ${OBJBONUS}
	${CC} ${CFLAGS} $^ ${MLXFLAGS} -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} $^ ${MLXFLAGS} -o $@

clean:
	rm -f ${OBJ} ${OBJBONUS}

fclean:
	rm -fr ${OBJ} ${OBJBONUS} ${NAME} ${BNAME}

re: fclean all

.PHONY:all fclean clean bonus
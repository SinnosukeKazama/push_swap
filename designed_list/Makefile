CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= push_swap
OBJ_DIR := object
SRC_DIR	:= source_code
GLD_DIR := $(SRC_DIR)/generaling_list_doublelink
GS_DIR  := $(SRC_DIR)/generaling_stack
OS_DIR  := $(SRC_DIR)/operate_stack
ROS_DIR := $(SRC_DIR)/rap_operate_stack
GL_DIR  := $(SRC_DIR)/grewout_libft
PA_DIR  := $(SRC_DIR)/parse_arg
S_DIR   := $(SRC_DIR)/sort

SRCS 	:= $(GLD_DIR)/free_dllist.c\
	   $(GLD_DIR)/ft_dllstadd_front.c\
	   $(GLD_DIR)/ft_dllstnew.c\
	   $(GLD_DIR)/gen_dllist_loop.c\
	   $(GS_DIR)/free_stack.c\
	   $(GS_DIR)/gen_stack.c\
	   $(OS_DIR)/pop.c\
	   $(OS_DIR)/push.c\
	   $(OS_DIR)/rotate.c\
	   $(OS_DIR)/rotate_rav.c\
	   $(OS_DIR)/swap.c\
	   $(ROS_DIR)/pa.c\
	   $(ROS_DIR)/pb.c\
	   $(ROS_DIR)/ra.c\
	   $(ROS_DIR)/rb.c\
	   $(ROS_DIR)/rr.c\
	   $(ROS_DIR)/rra.c\
	   $(ROS_DIR)/rrb.c\
	   $(ROS_DIR)/rrr.c\
	   $(ROS_DIR)/sa.c\
	   $(ROS_DIR)/sb.c\
	   $(ROS_DIR)/ss.c\
	   $(GL_DIR)/atol_strict.c\
	   $(GL_DIR)/ft_calloc.c\
	   $(GL_DIR)/ft_isdigit.c\
	   $(GL_DIR)/ft_memset.c\
	   $(GL_DIR)/ft_split.c\
	   $(GL_DIR)/ft_strdup.c\
	   $(GL_DIR)/ft_strlcpy.c\
	   $(GL_DIR)/ft_strlen.c\
	   $(GL_DIR)/ft_substr.c\
	   $(PA_DIR)/free_wp.c\
	   $(PA_DIR)/parse_chr_array.c\
	   $(PA_DIR)/parse_int_array.c\
	   $(S_DIR)/assign_index.c\
	   $(S_DIR)/radix_sort_ary.c\
	   $(S_DIR)/radix_sort_stk.c\
	   $(SRC_DIR)/main.c


all: $(NAME)

OBJS    := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(FPA):
	$(MAKE) -C $(FP_DIR)

$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

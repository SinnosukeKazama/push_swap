CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= libftprintf.a
ROOT_DIR := ..
OBJ_DIR := object
SRC_DIR	:= source_code
FUNCBTM_DIR := $(SRC_DIR)/function_btm
FUNCMID_DIR := $(SRC_DIR)/function_mid
FUNCTOP_DIR := $(SRC_DIR)/function_top

SRCS	:= $(FUNCBTM_DIR)/count_digit.c\
$(FUNCBTM_DIR)/count_digit_unsigned.c\
$(FUNCBTM_DIR)/ft_abs.c\
$(FUNCMID_DIR)/ft_put_char.c\
$(FUNCMID_DIR)/ft_put_nbr.c\
$(FUNCMID_DIR)/ft_put_str.c\
$(FUNCMID_DIR)/ft_put_hexadecimal.c\
$(FUNCMID_DIR)/ft_put_ptr.c\
$(FUNCMID_DIR)/ft_put_unsignednbr.c\
$(FUNCTOP_DIR)/ft_printf.c

OBJS	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)
	
$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

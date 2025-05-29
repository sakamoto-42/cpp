NAME = my_first_class_in_orthodox_canonical_form
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_FILES = \
			Fixed.cpp \
			main.cpp \

OBJS = $(SRCS_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
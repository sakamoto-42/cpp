NAME =  abstract_class
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_FILES = \
			AAnimal.cpp \
			Brain.cpp \
			Cat.cpp \
			Dog.cpp \
			main.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \

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
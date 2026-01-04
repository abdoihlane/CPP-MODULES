NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

CC = g++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
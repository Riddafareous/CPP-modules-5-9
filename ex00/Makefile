NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=%.o)

FLAGS = -Wall -Wextra -Werror -std=c++11

CC = g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
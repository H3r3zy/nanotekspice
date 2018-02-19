
##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	= Src/Parsing/Main.cpp		\
	  Src/Parsing/Parsing.cpp	\
	  Src/Parsing/ErrorParsing.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./Include
CPPFLAGS += -std=c++11 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

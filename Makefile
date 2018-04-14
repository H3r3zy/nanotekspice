##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	= 	Src/Main.cpp		\
	  	Src/Parsing/Parsing2.cpp	\
	  	Src/Parsing/ErrorParsing.cpp	\
		Src/Component/AbstractComponent.cpp	\
		Src/Component/Chipset/CD4008BMS.cpp	\
		Src/Component/Chipset/CD4011B.cpp	\
		Src/Component/Chipset/CD4030C.cpp	\
		Src/Component/Chipset/CD4069UBC.cpp	\
		Src/Component/Chipset/CD4512B.cpp	\
		Src/Component/Chipset/CD4514BC.cpp	\
		Src/Component/Chipset/HCF4081B.cpp	\
		Src/Component/Chipset/HEF4001B.cpp	\
		Src/Component/Chipset/HEF4071B.cpp	\
		Src/Component/Component/AndGate.cpp	\
		Src/Component/Component/Clock.cpp	\
		Src/Component/Component/FullAdderComponent.cpp	\
		Src/Component/Component/Input.cpp	\
		Src/Component/Component/NandGate.cpp	\
		Src/Component/Component/NorGate.cpp	\
		Src/Component/Component/NotGate.cpp	\
		Src/Component/Component/OrGate.cpp	\
		Src/Component/Component/RSNorLatchComponent.cpp	\
		Src/Component/Component/XorGate.cpp	\
		Src/Component/Component/Output.cpp	\
		Src/Factory.cpp	\
		Src/Interpretor.cpp \
		Src/Executor.cpp	\
		Src/Component/Chipset/MC14040B.cpp	\
		Src/Component/Chipset/HC4017.cpp	\
		Src/Component/Chipset/CD4013BC.cpp	\
		Src/Component/Chipset/CD4094BC.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./Include -I ./Include/Chipset -I ./Include/Component -I ./Include/Parsing
CPPFLAGS += -std=c++11 -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -ggdb3

debug: re

tests_run:
		make -C tests re
		./tests/test

coverage:	tests_run
	make -C tests coverage

.PHONY: all clean fclean re debug

##
## EPITECH PROJECT, 2018
## cpp_rush2
## File description:
## Created by martin.januario@epitech.eu
##

SRC             =       $(shell find ../Src/ -type f -name "*.cpp")

SRC_OBJECT      =       test_and.cpp	\
			test_or.cpp	\
			test_nor.cpp	\
			test_nand.cpp	\
			test_not.cpp	\
			test_xor.cpp	\
			test_hef4001b.cpp	\
			test_fulladder.cpp	\
			test_cd4008bms.cpp	\
			test_cd4011b.cpp	\
			test_cd4030c.cpp	\
			test_cd4069ubc.cpp	\
			test_hef4071b.cpp	\
			test_hcf4081b.cpp	\
			test_rsnorlatch.cpp	\
			test_cd4512b.cpp	\
			ReportHook.cpp		\
			test_cd4514bc.cpp	\
			test_clock.cpp


CPPFLAGS        =       -lcriterion -std=c++11 --coverage

COVERAGEFLAGS   =       -lcriterion -std=c++11 -lgcov --coverage

IFLAGS		=	-I ../Include/ -I ../Include/Chipset -I ../Include/Component

NAME    	=       test

all:                    $(NAME)

$(NAME):
			g++ -o $(NAME) $(SRC_OBJECT) $(SRC) $(CPPFLAGS) $(IFLAGS)

coverage:
			@g++ $(SRC_OBJECT) $(SRC) $(COVERAGEFLAGS) -o $(NAME) $(IFLAGS)
			@./$(NAME)
			@gcov *.gcno
			@echo "--"
			@gcov *.gcno | tail -n 1

clean:
			rm -f $(NAME)
			rm -f *.gcda
			rm -f *.gcno
			rm -f *.gcov

re:                     clean all

.PHONY:                 all clean re coverage

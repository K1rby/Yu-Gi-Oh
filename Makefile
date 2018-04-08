##
## Makefile for service in /home/quentin/Documents/C++/exercice/tp-resto
##
## Made by fontenay
## Login   <quentin@epitech.net>
##
## Started on  Mon Dec 18 16:21:33 2017 fontenay
## Last update Sun Apr  8 15:20:11 2018 fontenay
##

CC      =       g++

RM      =       rm -f

NAME    =       Yu-Gi-Oh

LIB	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC     =       main.cpp	\
		menu.cpp

OBJ     =       $(SRC:.cpp=.o)


all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LIB)

clean   :
		$(RM) $(OBJ)

fclean  :       clean
		$(RM) $(NAME)

re      :       fclean all

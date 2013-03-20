##
## Makefile for raytracer in /home/teisse_l//Documents/projet/raytracer
## 
## Made by lambert teisserenc-bonesteve
## Login   <teisse_l@epitech.net>
## 
## Started on  Wed Jan 25 01:05:57 2012 lambert teisserenc-bonesteve
## Last update Wed Mar 20 21:09:06 2013 lambert teisserenc-bonesteve
##

NAME		=	learn

CXXFLAGS	=	-I include/ -Wextra -Wall -lsfml-window -lsfml-graphics -lm

LDFLAGS		=	

CC		=	g++
RM		=	rm -fv

SRC		=	src/main.cpp	\
			src/Learn.cpp	\
			src/Voc.cpp	\

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

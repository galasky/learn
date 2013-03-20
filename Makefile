NAME		=	learn

CXXFLAGS	=	-I include/ -Wextra -Wall

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 10:02:50 by aperrein          #+#    #+#              #
#    Updated: 2023/10/25 10:02:52 by aperrein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex02

OBJ_DIR		=	OBJ/

SRC			=	Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

all			:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o:  $(SRC_DIR)%.cpp
				c++ $(CFLAGS) -c $< -o $@

$(OBJ_DIR)	:	
				mkdir $(OBJ_DIR)

$(NAME)		:	$(OBJ)
				c++	$(CFLAGS) -o $(NAME) $(OBJ)

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

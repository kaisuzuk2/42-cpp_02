NAME	=	fixed
CXX		=	c++
FLAG	=	-Wall -Werror -Wextra -std=c++98

RM 		=	rm -rf

SRCS	=	Fixed.cpp \
			main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAG) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAG) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
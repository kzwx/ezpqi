
SRC = src/hunter/Hunter.cpp \
      src/widgets/Widget.cpp \
      src/widgets/Window.cpp \
      src/main.cpp

OBJS = $(SRC:.cpp=.o)

NAME = my_hunter

CXXFLAGS += -Wall -Wextra -Werror
CXXFLAGS += -std=c++17
CXXFLAGS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

CXX = g++

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean

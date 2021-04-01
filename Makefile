
SRC = src/constraints/CenterConstraint.cpp \
      src/constraints/Constraints.cpp \
      src/constraints/PixelConstraint.cpp \
      src/constraints/RelativeConstraint.cpp \
      src/hunter/Hunter.cpp \
      src/scenes/LaunchScene.cpp \
      src/scenes/SceneManager.cpp \
      src/widgets/Button.cpp \
      src/widgets/Composite.cpp \
      src/widgets/Image.cpp \
      src/widgets/Text.cpp \
      src/widgets/Texture.cpp \
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

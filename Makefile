INCLUDE = -I/usr/local/include
LIB = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -g $(INCLUDE)
CXX = clang++
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: 
	$(CXX) $(SRC) -o $(EXEC) $(CXXFLAGS) $(INCLUDE) $(LIB)
	
clean:
	rm -f $(OBJ) $(EXEC)
fclean: clean
	rm -f $(EXEC)
re: fclean all
SRC = \
	src/main.cpp \
	src/Circuit.cpp \
	src/Component.cpp \
	src/Parser.cpp \
	src/Gates.cpp \
	src/Help.cpp \
	src/Pin.cpp \
	src/PinManager.cpp \
	src/InputPin.cpp \
	src/OutputPin.cpp \
	src/Chipsets/2716_rom.cpp \
	src/Chipsets/4001_nor.cpp \
	src/Chipsets/4004_microprocessor.cpp \
	src/Chipsets/4008_adder.cpp \
	src/Chipsets/4011_nand.cpp \
	src/Chipsets/4013_flipflop.cpp \
	src/Chipsets/4017_johnson.cpp \
	src/Chipsets/4030_xor.cpp \
	src/Chipsets/4040_counter.cpp \
	src/Chipsets/4069_not.cpp \
	src/Chipsets/4071_or.cpp \
	src/Chipsets/4081_and.cpp \
	src/Chipsets/4094_shift.cpp \
	src/Chipsets/4512_selector.cpp \
	src/Chipsets/4514_decoder.cpp \
	src/Chipsets/4801_ram.cpp \
	src/Input.cpp \
	src/Output.cpp \
	src/Factory.cpp \
	src/MyShell.cpp \
	src/True.cpp \
	src/False.cpp \
	src/Clock.cpp

CXX = g++
CXXFLAGS = -W -Wall -Wextra -g -Wno-unused-parameter
VALGRIND = -g
NAME = nanotekspice

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(SFMLFLAGS) $(NCURSESFLAGS) $(VALGRIND)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

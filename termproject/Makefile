.SUFFIXES: .cpp .o

OBJECTS = Block.o Block_controller.o Piece.o Fold.o Tree.o Cross.o Piece_maker.o Map.o App_controller.o
MAIN = main.o $(OBJECTS)

CXX = g++
TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)


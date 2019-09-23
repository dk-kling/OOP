.SUFFIXES: .cpp .o

OBJECTS = main.o student_id.o print.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	      $(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

main.o : main.cpp
student_id.o : student_id.cpp
print.o : print.cpp

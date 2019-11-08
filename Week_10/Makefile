.SUFFIXES: .cpp .o

OBJECTS = vehicle.o car.o bike.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)	

clean :
	rm -rf $(OBJECTS) $(TARGET)

vehicle.o : vehicle.cpp
car.o : car.cpp
bike.o : bike.cpp
main.o : main.cpp

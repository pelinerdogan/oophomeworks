


all: clean compile run

compile: hw2_210104004266.h hw2_210104004266.cpp  driver1.cpp driverr2.cpp 
	@echo "Compiling..."
	@g++ -std=c++11 -c hw2_210104004266.cpp 
	@g++ -std=c++11 -c driver1.cpp 
	@g++ -std=c++11 -c driverr2.cpp 
	@g++ -std=c++11 -c hw1_lib.cpp 
	@g++ -std=c++11 hw2_210104004266.o driverr2.o  hw1_lib.o -o hw2d2
	@g++ -std=c++11 hw2_210104004266.o driver1.o  hw1_lib.o -o hw2d1
	
	@echo "Compiled..."

run:
	
	
   
	@echo "running driver 1..."
	./hw2d1
	@echo "running driver 2..."
	./hw2d2

driver1: hw2_210104004266.h hw2_210104004266.cpp  driver1.cpp
	@g++ -std=c++11 -c hw2_210104004266.cpp 
	@g++ -std=c++11 -c driver1.cpp
	@g++ -std=c++11 hw2_210104004266.o driver1.o  hw1_lib.o -o hw2d1
		
	@echo "running driver 1..."
	./hw2d1
driver2:hw2_210104004266.h hw2_210104004266.cpp driverr2.cpp 
	@echo "running and Compiling driver 2..."
	@g++ -std=c++11 -c hw2_210104004266.cpp 
	@g++ -std=c++11 -c driverr2.cpp
	@g++ -std=c++11 hw2_210104004266.o driverr2.o  hw1_lib.o -o hw2d2
		
	./hw2d2

clean:
	
	@rm -f *.o
	@rm -f hw2



all: clean compile run

compile: hw3head.h hw3lib.cpp  driver1hw3.cpp 
	@echo "Compiling..."
	@g++ -std=c++11 -c hw3lib.cpp 
	@g++ -std=c++11 -c driver1hw3.cpp 
	@g++ -std=c++11 -c driver2hw3.cpp 
	@g++ -std=c++11 -c hw1againlib.cpp 

	@g++ -std=c++11 hw3lib.o driver1hw3.o  hw1againlib.o -o hw3d1
	@g++ -std=c++11 hw3lib.o driver2hw3.o  hw1againlib.o -o hw3d2
	
	@echo "Compiled..."

run:
	
	
   
	@echo "running driver 1..."
	./hw3d1
	@echo "running driver 2..."
	./hw3d2
	

driver1: hw3head.h hw3lib.cpp  driver1hw3.cpp
	@g++ -std=c++11 -c hw3lib.cpp 
	@g++ -std=c++11 -c hw1againlib.cpp 
	@g++ -std=c++11 -c driver1hw3.cpp
	@g++ -std=c++11 hw3lib.o driver1hw3.o  hw1againlib.o -o hw3d1
		
	@echo "running driver 1..."
	./hw3d1

driver2: hw3head.h hw3lib.cpp  driver2hw3.cpp
	@g++ -std=c++11 -c hw3lib.cpp 
	@g++ -std=c++11 -c hw1againlib.cpp 
	@g++ -std=c++11 -c driver2hw3.cpp
	@g++ -std=c++11 hw3lib.o driver2hw3.o  hw1againlib.o -o hw3d1
		
	@echo "running driver 1..."
	./hw3d1	

clean:
	
	@rm -f *.o
	@rm -f hw3d1
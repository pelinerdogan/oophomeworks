


all: clean compile run

compile: hw5head.h hw5lib.cpp driver1hw5.cpp driver2hw5.cpp hw1againlib.cpp 
	@echo "Compiling..."
	@g++ -std=c++11 -c hw5lib.cpp 
	@g++ -std=c++11 -c hw1againlib.cpp 
	@g++ -std=c++11 -c driver1hw5.cpp 
	@g++ -std=c++11 -c driver2hw5.cpp 
	@g++ -std=c++11  hw1againlib.o  hw5lib.o driver1hw5.o -o hw5d1
	@g++ -std=c++11  hw1againlib.o  hw5lib.o driver2hw5.o -o hw5d2
	


	
	@echo "Compiled..."

run:
	./hw5d1
	./hw5d2
	



clean:
	
	@rm -f *.o
	@rm -f hw5
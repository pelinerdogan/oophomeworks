


all: clean compile run

compile: hw4Lib.h hw4Lib.cpp  hw4Main.cpp 
	@echo "Compiling..."
	@g++ -std=c++11 -c hw4Lib.cpp 
	@g++ -std=c++11 -c hw4Main.cpp 
	@g++ -std=c++11 hw4Lib.o hw4Main.o  -o hw4

	
	@echo "Compiled..."

run:
	
	
   
	@echo "running "
	./hw4
	

clean:
	
	@rm -f *.o
	@rm -f hw4
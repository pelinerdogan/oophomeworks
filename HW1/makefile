


all: clean compile run

compile: hw1_lib.h hw1_lib.cpp  hw1_main.cpp
	
	@echo "Compiling..."
	@g++ -std=c++11 -c hw1_lib.cpp 
	@g++ -std=c++11 -c hw1_main.cpp 
	@g++ -std=c++11 hw1_lib.o hw1_main.cpp -o hw1 

run:
	
	

	./hw1
	
clean:
	
	@rm -f *.o
	@rm -f hw1
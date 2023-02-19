#include <iostream>
#include <vector>
#include "hw1again.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <string>
#include <cmath>
#include <chrono>


namespace hw3{

class tetris;


}

 


class hw3::tetris{
    
public:
    tetris();
    tetris(int width, int length);
    void draw();
    void drawbool();//bool table draw function that i used to debug
    void put(int i1,int i2,const tetromino t);
    void clean(int i1,int i2,const tetromino t);
    void play(tetromino &t);
    tetris operator+=(const tetromino &t);
    char** board;
    bool** boardbool;
private:
    int width;
    int length;
};
#include <iostream>
#include <vector>
#include "hw1_lib.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <string>
#include <cmath>
#include <chrono>
using namespace std;

class tetris
{
public:
    tetris();
    tetris(int width, int length);
    void tetrominoadd(tetromino x);
    void fitTetris(tetromino &tet);
    void draw();
    void drawbool();


private:
    int width;
    int length;
    vector<vector<char>> board;
    vector<vector<bool>> boardbool;
    vector<tetromino> tetrominovec;
};
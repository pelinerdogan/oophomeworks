#include "hw3head.h"


int main(){
 
 hw3::tetris tet(10,10);
 hw3::tetris tet1(10,10);

   tetromino tetmino2(tetrominos:: I);
   tetromino tetmino1(tetrominos:: L);
   tetromino tetmino3(tetrominos:: J);
   cout<<"drawing board"<<endl;
   tet.draw();
    cout<<"testing += operator with J tetromino"<<endl;
    tet += tetmino3;
    tet.draw();
   cout<<"playing with L tetromino"<<endl;
   cout<<"put and clean functions are used inside this function"<<endl;
   cout<<"you can test rotate and move"<<endl;
   
   tet1.play(tetmino1);
  
   
   
    return 0;
}
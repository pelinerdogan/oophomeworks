#include "hw2_210104004266.h"


int main(){
 tetris x(10,10);
 tetromino tet,tet1;

   cout<< "setting tetris shape function working"<<endl;
    tet.setShape(tetrominos:: I);
   cout<<"printing tetromino to see setshape works"<<endl;
   tet.print();
    
   cout<< "adding tetromino animation this function calls fittetris function which adds tetromino to board this is test of both of them and draw function" <<endl;
   x.tetrominoadd(tet);

  cout<< "just testing fit tetris with adding I" <<endl;
   x.fitTetris(tet);

    cout<< "just testing draw " <<endl;
    x.draw();
   cout<< "just testing drawbool that I used while im coding to see bool table " <<endl;
    x.drawbool();
    return 0;
}
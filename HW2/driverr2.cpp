#include "hw2_210104004266.h"


int main(){

   int width=0,height=0;
   srand( (unsigned)time( NULL ) ) ;//for different randoms
   int randy;
   bool quitted = false;
   
  cout<< "please enter a width and height for the board" <<endl;
  while(width<3){
    cout<<" width: ";
  cin >> width;

  }
  while(height<3){
  cout<<" height: ";
  cin >> height;
}
  tetris a(width,height);
  
  char x;
  cout<< "please enter tetromino type you want to add or you can enter 'R' for random or 'Q' for quitting" <<endl;
while(quitted == false){
   cout<<"enter \n";
   cin >> x;
   tetromino tet;
    switch (x)   
    {
    case 'i':
    case 'I':
    tet.setShape(tetrominos:: I);
    a.tetrominoadd(tet);
      break;
    case 'j':
    case 'J':

    
    tet.setShape(tetrominos:: J);
    a.tetrominoadd(tet);
   
      break;
    case 'l':
    case 'L':
    
    tet.setShape(tetrominos:: L);
    a.tetrominoadd(tet);
      break;
    case 'T':
    case 't':
  
    tet.setShape(tetrominos:: T);
    a.tetrominoadd(tet);
      break;
    case 'o':
    case 'O':
   
    tet.setShape(tetrominos:: O);
    a.tetrominoadd(tet);
      break;
    case 's':
    case 'S':
      
    tet.setShape(tetrominos:: S);
    a.tetrominoadd(tet);
      break;

    case 'z':
    case 'Z':

    tet.setShape(tetrominos:: Z);
    a.tetrominoadd(tet);
    
      break;

    case 'r':
    case 'R':
    
      randy=  (rand()% 7 ) ;
      if(randy == 0){
       
    tet.setShape(tetrominos:: I);
    a.tetrominoadd(tet);
      }
      if(randy == 1){

    tet.setShape(tetrominos:: J);
    a.tetrominoadd(tet);
      }
      if(randy == 2){

    tet.setShape(tetrominos:: L);
    a.tetrominoadd(tet);
      }
      if(randy == 3){

    tet.setShape(tetrominos:: T);
    a.tetrominoadd(tet);
      }
      if(randy == 4){

    tet.setShape(tetrominos:: O);
    a.tetrominoadd(tet);
      }
      if(randy == 5){

    tet.setShape(tetrominos:: S);
    a.tetrominoadd(tet);
      }
      if(randy == 6){

    tet.setShape(tetrominos:: Z);
    a.tetrominoadd(tet);
      }

      break;
    case 'q':
    case 'Q':
    
      quitted = true;
      break;
      default:

      cout<<"try again wrong input"<<endl;
      
    }

  a.draw();



}



    return 0;
}
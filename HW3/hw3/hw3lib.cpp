#include "hw3head.h"




hw3::tetris::tetris(int width, int length){

 this->length = length;
 this->width = width;
 board = new char*[length+5];
 boardbool = new bool*[length];

for (int i = 0; i < length+5; i++)   //creating the board
{
    board[i] = new char[width];
    boardbool[i] = new bool[width];
}

for (int i = 0; i < length+5; i++)
{
    board[i] = new char[width];
    boardbool[i] = new bool[width];
}

for (int i = 0; i < 4; i++)
{


  
for (int m = 0; m < width-1; m++)
{
  
  board[i][m] = ' ';

  
}



}



for (int i = 3; i < length+3; i++)
{
  
  board[i][0] = '+';
  boardbool[i][0] = true;
  
for (int m = 1; m < width-1; m++)
{
  
  board[i][m] = ' ';

  
}

   board[i][width-1] = '+';
  
   boardbool[i][width-1] = true;

}



for (int m = 0; m < width; m++)
{
  
  board[length+3][m] = '+';
  boardbool[length+3][m]= true;
  
}

  

   



}



hw3::tetris hw3::tetris:: operator+=( const tetromino &t){
 int mid = width/2 -(t.getcolumn()/2);
  put(0,mid,t);  //ads tetromino on board


return *this;

}

void hw3::tetris::draw(){



  cout << "\x1B[2K"; //for animation 

  for (int i = 0; i < length+4; ++i)
  {

    this_thread::sleep_for(chrono::milliseconds(90));
    for (int m = 0; m < width ; ++m)
    {

      cout << board[i][m];
    }
    cout << endl;
  }



}
void hw3::tetris::drawbool(){ //bool table draw function that i used to debug



  for (int i = 0; i < length+4; ++i)
  {

    this_thread::sleep_for(chrono::milliseconds(90));
    for (int m = 0; m < width ; ++m)
    {

      cout << boardbool[i][m];
    }
    cout << endl;
  }



}

void hw3::tetris::play(tetromino &t){

int moven , rotaten; 
char rotatew,movew;
bool doner= false; //controls rotate
bool donem= false; //controls move
int mid = width/2 -(t.getcolumn()/2);//calculating mid point to put tetromino
bool rockbottom = false;
int count = 1;
bool godown = false;

*this += t; //adding tetromino

draw(); //drawing
 
 

clean(0,mid,t);//cleans added tetromino to start animate



while (doner== false) //checks if it done rotating
{ string rot;
  cout<<"How many times you like to rotate?"<<endl;
  cin>> rot;
  rotaten=stoi(rot);  //takes input as string and turns to int to avoid misinputs to create infinite loop
  if(rotaten>0){

  
  cout<<"which way would you like to rotate? \n (enter r for right or l for left)" <<endl ;
  cin>>rotatew;

switch (rotatew)//rotate way
{
case 'R': //to right
case 'r':
for(int i=0; i<rotaten;++i)
 t.rotate(direction::right);
mid= width/2 -(t.getcolumn()/2);  //recalculating mid point
put(0,mid,t);

draw();

clean(0,mid,t);

doner=true;



  break;

case 'L':
case 'l': //to left

for(int i=0; i<rotaten;++i)
 t.rotate(direction::left);
mid= width/2 -(t.getcolumn()/2); //takes input as string and turns to int to avoid misinputs to create infinite loop
put(0,mid,t);

draw();

clean(0,mid,t);
doner=true;

  break;

default:
cout<<"Not valid choice ! " <<endl ;

  break;
}
 
  }
  else if(rotaten== 0){
   doner=true;
  }
  else
  {
    cout<<"Not valid choice !" <<endl ;
  }
  
}

 

if(width-2>t.getcolumn() && length >t.getrow()){ // checks if it can fit

   
while (donem == false)
{ 
  
  string mov;
  cout<<"How many times you like to move?"<<endl;
  cin>> mov;
  moven = stoi(mov); //to avoid 

  if(moven>0){
  cout<<"which way would you like to move? \n (enter r for right or l for left)" <<endl ;
  cin>>movew;
  int allr=9,alll=1;
  if(movew =='r' ||movew =='R' ){
    allr= moven+mid+t.getcolumn();
  }
   if(movew =='l' ||movew =='L' ){
     alll= mid-moven;
  }

if(alll>0 && allr<width){ //checks if it fits
switch (movew)
{
case 'R':
case 'r':


put(0,moven+mid,t);
 
 rockbottom = false;
 count = 1;
 godown = false;
while (false==rockbottom)
{

 

for (int i = 0 ; i < t.getrow() ; i++)
{
    
for (int m = 0; m < t.getcolumn() ; m++)
{

    
  if( boardbool[i+count][mid+m+moven] == true && t.shape[i][m] != ' ') //checks if its full if so stops goin down
  godown = true;

}

}
 
 if( godown == false){



clean(count-1,mid+moven,t); //keeps going down


put(count,moven+mid,t);


 }else{
  rockbottom=true;

 for (int i = 0 ; i < t.getrow()  ; i++)
{
    
for (int m = 0; m < t.getcolumn() ; m++)
{

  if(board[i+count-1][mid+m+moven] != ' '){
   boardbool[i+count-1][mid+m+moven]=true;
   
 
  }  
  


}

}
 }
  

  count++;
  draw();
;
}





donem=true;



  break;

case 'L':
case 'l':



put(0,mid-moven,t);

 
 rockbottom = false;
 count = 1;
 godown = false;
while (false==rockbottom)
{

  

for (int i = 0 ; i < t.getrow()  ; i++)
{
    
for (int m = 0; m <  t.getcolumn()  ; m++)
{

    
  if( boardbool[i+count][mid+m-moven] ==true && t.shape[i][m] != ' ')//checks if theres a tetromino or it hitted bottom
  godown = true;

}

}
 
 if( godown == false){


clean(count-1,mid-moven,t);  // keeps going down


put(count,mid-moven,t);


 }else{
  rockbottom=true; //it founds its place so i add to bool table

 for (int i = 0 ; i <t.getrow() ; i++)
{
    
for (int m = 0; m <  t.getcolumn() ; m++)
{

  if(board[i+count-1][mid+m-moven] != ' ')    
  boardbool[i+count-1][mid+m-moven]=true;


}

}


 }
  

  count++;
  draw();
 
}




donem=true;

  break;

default:
cout<<"Not valid choice !" <<endl ;

  break;
}
  }
}
  else if(moven == 0){ //if not move goes straightly down
  
  
 rockbottom = false;
count = 1;            
 godown = false;

while (false==rockbottom)
{
  

for (int i = 0 ; i <t.getrow()  ; i++)
{
    
for (int m = 0; m < t.getcolumn()  ; m++)
{

    
  if( boardbool[i+count][mid+m] == true && t.shape[i][m] != ' ')  //checks if there a tetromino underneath
  godown = true;

}

}
 
 if( godown == false){

                       //keeps going down
clean(count-1,mid,t);

  
put(count,mid,t);


 }else{
  rockbottom=true;

 for (int i = 0 ; i < t.getrow() ; i++)
{
    
for (int m = 0; m < t.getcolumn()  ; m++)
{

   if(board[i+count-1][mid+m+moven] != ' ')   //if it is done moving adds tetromninno to bool table
  boardbool[i+count-1][mid+m]=true;
 
 


}

}
 }
  

  count++;
  draw();
 

}
  
  
   donem=true;



  }
  else
  {
    cout<<"Not valid choice !" <<endl ;

  }
  
}

}
else
{
  cout<<"adding tetromino failed" <<endl ;
}


}


 void hw3::tetris::put(int i1,int i2, tetromino t){
  
    
      for (int i = 0 ; i < t.getrow()  ; i++)
    {
        
    for (int m = 0; m < t.getcolumn() ; m++)
    {

        
      if(t.shape[i][m] != ' '){
  
      board[i+i1][m+i2] = t.shape[i][m];

      }
     
    }

    }
  

 }
    
    void hw3::tetris::clean(int i1,int i2, tetromino t){
     
      for (int i = 0 ; i < t.getrow()  ; i++)
    {
        
    for (int m = 0; m < t.getcolumn() ; m++)
    {

        
      switch (t.gettype())
      {
      case tetrominos::I  :
        if(board[i+i1][m+i2] == 'I')
         board[i+i1][m+i2] = ' ';

        break;
      case tetrominos::J  :
         if(board[i+i1][m+i2] == 'J')
         board[i+i1][m+i2] = ' ';

        break;
      
      case tetrominos::L  :
        if(board[i+i1][m+i2] == 'L')
         board[i+i1][m+i2] = ' ';

        break;
      
      case tetrominos::O :
        if(board[i+i1][m+i2] == 'O')
         board[i+i1][m+i2] = ' ';

        break;
      
      case tetrominos::S :
         if(board[i+i1][m+i2] == 'S')
         board[i+i1][m+i2] = ' ';

        break;
        
      case tetrominos::T :
         if(board[i+i1][m+i2] == 'T')
         board[i+i1][m+i2] = ' ';

        break;
      
      case tetrominos::Z :
        if(board[i+i1][m+i2] == 'Z')
         board[i+i1][m+i2] = ' ';

        break;
      }
     
    }

    }

 }
     
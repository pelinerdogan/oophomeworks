#include "hw1_lib.h"

int main()
{

  cout << "welcome to TETRİS  made by Pelin Erdoğan\n how many tetrominos do you want?" << endl;
  int tetrominocount;
  cin >> tetrominocount;
  vector<tetromino> tetrominovector;

  tetrominovector.reserve(tetrominocount);// to be more efficient

  char x;
  cout << "what are the types?" << endl;
  for (int i = 0; i < tetrominocount; ++i) //taking tetromino choice
  {
    cin >> x;

    switch (x)   
    {
    case 'i':
    case 'I':
      tetrominovector.push_back(tetromino(tetrominos::I));
      break;
    case 'j':
    case 'J':
      tetrominovector.push_back(tetromino(tetrominos::J));
      break;
    case 'l':
    case 'L':
      tetrominovector.push_back(tetromino(tetrominos::L));
      break;
    case 'T':
    case 't':
      tetrominovector.push_back(tetromino(tetrominos::T));
      break;
    case 'o':
    case 'O':
      tetrominovector.push_back(tetromino(tetrominos::O));
      break;
    case 's':
    case 'S':
      tetrominovector.push_back(tetromino(tetrominos::S));
      break;

    case 'z':
    case 'Z':

      tetrominovector.push_back(tetromino(tetrominos::Z));
      break;

      default:

      cout<<"try again wrong input"<<endl;
      --i;
    }
  }
  cout<<"Your tetrominos"<<endl;
  for (int k = 0; k < tetrominocount; ++k)
  {

    tetrominovector[k].print();
    
  }
  
  vector<vector<char>>  fit = {{},{},{},{}};
  fit.reserve(4);
  
  
  tetromino::tetrominofit( fit, tetrominovector);
  cout<< "Best fit of your tetrominos"<<endl;
  tetromino:: printfullfit(fit);
  cout << endl;

  return 0;
}

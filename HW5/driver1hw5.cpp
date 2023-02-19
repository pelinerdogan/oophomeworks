#include "hw5head.h"

int main()
{

   tetromino tetmino2(tetrominos::I);
   tetromino tetmino4(tetrominos::I);
   tetromino tetmino1(tetrominos::S);
   tetromino tetmino3(tetrominos::J);

   tetromino tetmino5(tetrominos::O);
   tetromino tetmino6(tetrominos::Z);

   cout << "creating with the integer parameter vector class constructor" << endl;
   hw5::TetrisVector tet(10, 10);
   hw5::TetrisVector tet2(10, 10);
   cout << "creating withthe no parameter vector class constructor" << endl;
   hw5::TetrisVector tet4;
   cout << "drawing board of integer parameter vector class" << endl;
   tet.draw();
   cout << "testing += operator with J tetromino to vector class" << endl;
   tet += tetmino3;
   tet.draw();

   cout << endl<<"Testing animate of vector class\n Put and clean functions are used inside this function" << endl;
   cout << "you can test rotate and move" << endl;

   tet2.animate(tetmino2);

   cout << "testing number of moves" << endl;
   cout << "number of moves " << tet2.numberOfMoves() << endl;

   cout << "writing this board to file outputvector.txt" << endl<<endl;

   tet2.writeToFile("outputvector.txt");
   cout << "reading  board in file inputvector.txt and drawing the read board" << endl;

   tet4.readFromFile("inputvector.txt");

   tet4.draw();

   cout <<endl<< "Trying exeption handling I'll call last move on two different tetris objects one will throw exeption" << endl;
   try
   {

      cout << tet2.lastMove() << endl;
      cout << tet.lastMove() << endl;
   }
   catch (const char *)
   {

      cout << "there is no last move on this tetris" << endl;
   }

   cout << "creating with the integer parameter 1d array class constructor" << endl;

   hw5::TetrisArray1D tet3(10, 10);
   hw5::TetrisArray1D tet1(10, 10);
   cout << "creating with the no parameter 1d array class constructor" << endl;
   hw5::TetrisArray1D tet5;

   cout << "drawing board of integer parameter 1d array class" << endl;
   tet1.draw();

   cout << "testing += operator with J tetromino to 1d array class" << endl;
   tet1 += tetmino3;
   tet1.draw();

   cout << "Testing animate of 1d array class\n Put and clean functions are used inside this function" << endl;
   cout << "you can test rotate and move" << endl;

   tet3.animate(tetmino1);

   cout << "testing number of moves" << endl;
   cout << "number of moves " << tet3.numberOfMoves() << endl;

   cout << "writing this board to file output.txt" << endl;

   tet3.writeToFile("output.txt");

   cout << "reading  board in file input.txt and drawing the read board" << endl;
   tet5.readFromFile("input.txt");
   tet5.draw();

   cout << "Trying exeption handling I'll call last move on two different tetris objects one will throw exeption" << endl;

   try
   {

      cout << tet3.lastMove() << endl;
      cout << tet1.lastMove() << endl;
   }
   catch (const char *)
   {

      cout << "there is no last move on this tetris" << endl;
   }

   tet3.endofall();
   tet5.endofall();
   tet1.endofall();

   cout << "creating with the adaptor  class constructor with vector" << endl;
   hw5::TetrisAdapter<vector<char>> tet6(10, 10);

   hw5::TetrisAdapter<vector<char>> tet7(10, 10);

   cout << "creating with the no parameter adaptor class constructor with vector" << endl;

   hw5::TetrisAdapter<vector<char>> tet8;

   cout << "drawing board of adaptor  class  with vector " << endl;
   tet6.draw();
   cout << "testing += operator with J tetromino to adaptor  class  with vector" << endl;
   tet6 += tetmino3;
   tet6.draw();

   cout << "Testing animate of adaptor  class  with vector\n Put and clean functions are used inside this function" << endl;
   cout << "you can test rotate and move" << endl;

   tet7.animate(tetmino4);

   cout << "testing number of moves" << endl;
   cout << "number of moves " << tet7.numberOfMoves() << endl;

   cout << "writing this board to file outputadaptor.txt" << endl;

   tet7.writeToFile("outputadaptor.txt");
   cout << "reading  board in file inputadaptor.txt and drawing the read board" << endl;
   tet8.readFromFile("inputadaptor.txt");
   tet8.draw();

   cout << "Trying exeption handling I'll call last move on two different tetris objects one will throw exeption" << endl;
   try
   {

      cout << tet7.lastMove() << endl;
      cout << tet6.lastMove() << endl;
   }
   catch (const char *)
   {

      cout << "there is no last move on this tetris" << endl;
   }

   cout << "creating with the adaptor  class constructor with deque" << endl;
   hw5::TetrisAdapter<deque<char>> tet9(10, 10);

   hw5::TetrisAdapter<deque<char>> tet10(10, 10);

   cout << "creating with the no parameter adaptor class constructor with deque" << endl;

   hw5::TetrisAdapter<deque<char>> tet11;

   cout << "drawing board of adaptor  class  with deque " << endl;
   tet9.draw();
   cout << "testing += operator with J tetromino to adaptor  class  with deque" << endl;
   tet9 += tetmino3;
   tet9.draw();

   cout << "Testing animate of adaptor  class  with deque\n Put and clean functions are used inside this function" << endl;
   cout << "you can test rotate and move" << endl;

   tet10.animate(tetmino5);

   cout << "testing number of moves" << endl;
   cout << "number of moves " << tet10.numberOfMoves() << endl;

   cout << "writing this board to file outputadaptor2.txt" << endl;

   tet10.writeToFile("outputadaptor2.txt");
   cout << "reading  board in file inputadaptor.txt and drawing the read board" << endl;
   tet11.readFromFile("inputadaptor.txt");
   tet11.draw();

   cout << "Trying exeption handling I'll call last move on two different tetris objects one will throw exeption" << endl;
   try
   {

      cout << tet10.lastMove() << endl;
      cout << tet9.lastMove() << endl;
   }
   catch (const char *)
   {

      cout << "there is no last move on this tetris" << endl;
   }

   return 0;
}
#include "hw2_210104004266.h"

tetris::tetris()
{ // constructor that does nothing
}

tetris ::tetris(int width, int length)
{
  this->length = length; // making the board
  this->width = width;

  board.reserve(length + 2);
  boardbool.reserve(length + 2);

  for (int i = 0; i < length - 1; ++i)
  {
    board[i].push_back('+');
    boardbool[i].push_back(true);
    for (int m = 0; m < width - 2; ++m)
    {
      board[i].push_back(' ');
      boardbool[i].push_back(false);
    }

    board[i].push_back('+');
    boardbool[i].push_back(true);
  }

  for (int i = 0; i < width; ++i)
  {
    board[length - 1].push_back('+');
    boardbool[length - 1].push_back(true);
  }
}

void tetris::draw() 
{

  cout << "\x1B[2K"; //for aniamation 

  for (int i = 0; i < length; ++i)
  {

    this_thread::sleep_for(chrono::milliseconds(90));
    for (int m = 0; m < width + 1; ++m)
    {

      cout << board[i][m];
    }
    cout << endl;
  }
}


void tetris::drawbool()  //helps to debug
{



  for (int i = 0; i < length; ++i)
  {

    for (int m = 0; m < width + 1; ++m)
    {

      cout << boardbool[i][m];
    }
    cout << endl;
  }
}

void tetris::tetrominoadd(tetromino x)
{
  cout << "\x1B[2J";  //clears the terminal
  tetrominovec.push_back(x);
  int blank;

  if (width - 2 > x.shape[0].size())
  {

    for (int k = 0; k < x.shape.size(); ++k)
    {
      blank = x.shape[k].size();
      for (int i = 0; i < blank; i++)
      {

        board[k][i + (width - blank) / 2] = x.shape[k][i];
      }
    }

    int blockdown = 1;
    bool cross = true;  

    while (x.shape.size() * blockdown < length - 1 && cross == true) 
    {

      for (int k = 0; k < x.shape.size(); ++k)
      {
        blank = x.shape[k].size();
        for (int i = 0; i < blank; i++)
        {

          if (board[k + (x.shape.size() * blockdown)][i + (width - blank) / 2] != ' ')
          {
            cross = false;  //checks if animation cross with another element
            for (int k = 0; k < x.shape.size(); ++k)
            {

              for (int i = 0; i < blank; i++)
              {

                board[k + (x.shape.size() * (blockdown - 1))][i + (width - blank) / 2] = ' ';
              }
            }
          }
        }
      }
      for (int k = 0; k < x.shape.size(); ++k)
      {
        if (cross == true)
        {

          for (int i = 0; i < blank; i++)
          {
            board[k + (x.shape.size() * blockdown) - x.shape.size()][i + (width - blank) / 2] = ' ';
            board[k + (x.shape.size() * blockdown)][i + (width - blank) / 2] = x.shape[k][i];
          }
        }
      }

      draw();  //draws the board 

      if (cross == true)
      {
        for (int k = 0; k < x.shape.size(); ++k)
        {

          for (int i = 0; i < blank; i++)
          {

            board[k + (x.shape.size() * blockdown)][i + (width - blank) / 2] = ' ';
          }
        }
      }

      blockdown++;
    }
  }

  fitTetris(x);
}

void tetris::fitTetris(tetromino &tet)
{

  // control bottom if it fits put

  // if not then rotate
  // fits put no then check 1 up

  // check for empty squares if u can

  int lr = length - 2;
  int lc = 1;

  bool r1 = false, c1 = false;
  

  bool printed = false;
  switch (tet.gettype()) // putting according to type
  {
  case tetrominos::I:  

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() != 1)
        {

          if (width - 6 >= 0 && lr >= 0)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              for (int i = 0; i < 4; ++i)
              {

                if (boardbool[lr][lc + k + i] == true)
                {

                  r1 = true;   // //checks if its crossing with another element
                  i = 5; //ends for for efficiency
                }
              }

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 4; ++i)
                {

                  board[lr][lc + k + i] = tet.shape[0][i];   //prints tetromino to board
                  boardbool[lr][lc + k + i] = true;

                  printed = true;
                }
                k = width;
              }
              if (k == width - 2 && r1 == true && printed == false)
              {

                tet.rotate(direction::right);  //if not fits rotate
              }

              r1 = false;
            }
          }
          else
          {

            tet.rotate(direction::right); //if not fits rotate
          }
        }
        else
        {

          if (length >= 5 && width >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {
              if (lr >= 4)
              {
                for (int i = 0; i < 4; ++i)
                {

                  if (boardbool[lr - i][lc + k] == true)    //checks crossing
                  {

                    c1 = true;
                  }
                }
              }

              if (lr >= 4)
              {
                if (c1 == false)
                {

                  for (int i = 0; i < 4; ++i)
                  {

                    board[lr - i][lc + k] = tet.shape[i][0];   //prints tetromino to board
                    boardbool[lr - i][lc + k] = true;

                    printed = true;
                  }
                  k = width;
                }
              }
              if (k == width - 2 && printed == false && lr > 0 && (c1 == true || lr < 4))
              {

                tet.rotate(direction::right);  //if not fits rotate

                lr--;
                if (lr == 1)
                  printed = true;
              }

              c1 = false;
            }
          }
          else
          {
            cout << "Sorry not enough place for this " << endl;

            printed = true;
          }
        }
      }
    }
    break;

  case tetrominos::J:

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() == 1)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k] == true ||
                  (boardbool[lr][lc + k + 1] == true) ||  //check crossing
                  (boardbool[lr][lc + k + 2] == true) ||
                  (boardbool[lr - 1][lc + k] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr][lc + k + i] = tet.shape[1][i];

                  boardbool[lr][lc + k + i] = true;

                  if (i == 0)
                  {
                    board[lr - 1][lc + k + i] = tet.shape[0][i];
                    boardbool[lr - 1][lc + k + i] = true;   //prints tetromino to board
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);// if not fit rotate
            }
          }
        }

        if (tet.getturnr() == 2)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k] == true ||   //check crossing
                  (boardbool[lr - 1][lc + k] == true) ||
                  (boardbool[lr - 2][lc + k] == true) ||
                  (boardbool[lr - 2][lc + k + 1] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - i][lc + k] = tet.shape[i][0];
                  boardbool[lr - i][lc + k] = true;

                  if (i == 2)
                  {

                    board[lr - i][lc + k + 1] = tet.shape[0][1];   //prints tetromino to board
                    boardbool[lr - i][lc + k + 1] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);//if not fits rotate
            }
          }
        }

        if (tet.getturnr() == 3)
        { // checks if it rotated

          if (width - 2 >= 0 && lr >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr - 1][lc + k] == true ||
                  (boardbool[lr - 1][lc + k + 1] == true) ||  //check crossing
                  (boardbool[lr - 1][lc + k + 2] == true) ||
                  (boardbool[lr][lc + k + 2] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; i++)
                {

                  board[lr - 1][lc + k + i] = tet.shape[0][i];

                  boardbool[lr - 1][lc + k + i] = true;

                  if (i == 2)
                  {
                    board[lr][lc + k + i] = tet.shape[1][i];
                    boardbool[lr][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }
          }

          if (printed == false)
            lr--;
        }

        if (tet.getturnr() == 0)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr - 2][lc + k + 1] == true ||  //check crossing
                  (boardbool[lr - 1][lc + k + 1] == true) ||
                  (boardbool[lr][lc + k + 1] == true) ||
                  (boardbool[lr][lc + k] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - i][lc + k + 1] = tet.shape[i][1]; //prints tetromino to board
                  boardbool[lr - i][lc + k + 1] = true;   //turns fulled parts to true in bool table

                  if (i == 1)
                  {

                    board[lr][lc + k] = tet.shape[2][0];
                    boardbool[lr][lc + k] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {

              tet.rotate(direction::right);
            }
          }
        }
      }
    }
    break;

  case tetrominos::L:

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() == 1)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k + 1] == true ||
                  (boardbool[lr - 1][lc + k + 1] == true) ||  //check crossing
                  (boardbool[lr - 1][lc + k + 2] == true) ||
                  (boardbool[lr - 1][lc + k] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - 1][lc + k + i] = tet.shape[0][i];

                  boardbool[lr - 1][lc + k + i] = true;

                  if (i == 0)
                  {
                    board[lr][lc + k + i] = tet.shape[1][i];   //prints tetromino to board
                    boardbool[lr][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);
            }
          }
        }

        if (tet.getturnr() == 2)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k] == true ||
                  (boardbool[lr - 1][lc + k] == true) ||  //check crossing
                  (boardbool[lr - 2][lc + k - 1] == true) ||
                  (boardbool[lr - 2][lc + k] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - i][lc + k] = tet.shape[i][1];
                  boardbool[lr - i][lc + k] = true;

                  if (i == 2)
                  {

                    board[lr - i][lc + k - 1] = tet.shape[0][0];  //prints tetromino to board
                    boardbool[lr - i][lc + k - 1] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);
            }
          }
        }

        if (tet.getturnr() == 3)
        { // checks if it rotated

          if (width - 2 >= 0 && lr >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k] == true ||
                  (boardbool[lr][lc + k + 1] == true) ||  //check crossing
                  (boardbool[lr][lc + k + 2] == true) ||
                  (boardbool[lr - 1][lc + k + 2] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; i++)
                {

                  board[lr][lc + k + i] = tet.shape[1][i];

                  boardbool[lr][lc + k + i] = true;

                  if (i == 2)
                  {
                    board[lr - 1][lc + k + i] = tet.shape[0][i];  //prints tetromino to board
                    boardbool[lr - 1][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }
          }

          if (printed == false)
            lr--;
        }

        if (tet.getturnr() == 0)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr - 2][lc + k] == true ||
                  (boardbool[lr - 1][lc + k] == true) ||
                  (boardbool[lr][lc + k] == true) ||
                  (boardbool[lr][lc + k + 1] == true))   //check crossing
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - i][lc + k] = tet.shape[i][0]; //prints tetromino to board
                  boardbool[lr - i][lc + k] = true;  

                  if (i == 1)
                  {

                    board[lr][lc + k + i] = tet.shape[2][1];  //prints tetromino to board
                    boardbool[lr][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {

              tet.rotate(direction::right);
            }
          }
        }
      }
    }

    break;

  case tetrominos::Z:

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() != 1)
        { // checks if it rotated

          if (width - 4 >= 0 && lr >= 0)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              for (int i = 0; i < 3; ++i)
              {

                int j = 0;
                if (i == 0)
                  j = 1;

                if (boardbool[lr][lc + k + i + j] == true)
                {

                  r1 = true;
                }
                else
                {

                  if (i == 2)
                  {

                    if (boardbool[lr - 1][lc + k + i - 1] == true)
                      r1 = true; //checks crossing
                  }
                  else
                  {

                    if (boardbool[lr - 1][lc + k + i] == true)
                      r1 = true;
                  }
                }
              }

              int j = 0;

              if (r1 == false && printed == false)
              {
                if (lc + k > 0)
                {
                  if (boardbool[lr][lc + k - 1] == true)
                    j = 1;
                }

                for (int i = 0; i < 3 - j; ++i)
                {

                  board[lr][lc + k + i + j] = tet.shape[1][i + j];   //prints tetromino to board

                  boardbool[lr][lc + k + i + j] = true;

                  printed = true;
                }

                for (int i = 0; i < 2; ++i)
                {

                  board[lr - 1][lc + k + i] = tet.shape[0][i];
                  boardbool[lr - 1][lc + k + i] = true;

                  printed = true;
                }
                k = width;
              }
              if (k == width - 2 && r1 == true && printed == false)
              {

                tet.rotate(direction::right);
              }

              r1 = false;
            }
          }
          else
          {

            tet.rotate(direction::right);
          }
        }
        else
        {

          if (length >= 4 && width >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {
              if (lr >= 3)
              {
                for (int i = 0; i < 3; ++i)
                {

                  if (i == 0)
                  {

                    if (boardbool[lr][lc + k] == true)  //checks crossing
                    {

                      c1 = true;
                    }
                  }

                  if (i == 1)
                  {

                    if (boardbool[lr - i][lc + k + 1] == true || boardbool[lr - i][lc + k] == true)
                    {

                      c1 = true;
                    }
                  }

                  if (i == 2)
                  {

                    if (boardbool[lr - i][lc + k + 1] == true)
                    {

                      c1 = true;
                    }
                  }
                }
              }

              if (lr >= 3)
              {
                if (c1 == false)
                {
                  int j = 0;

                  for (int i = 0; i < 1; ++i)
                  {
                    board[lr][lc + k + i] = tet.shape[2][i];  //prints tetromino to board
                    boardbool[lr - 1][lc + k + i] = true;

                    for (int i = 0; i < 2; ++i)
                    {
                      board[lr - 1][lc + k + i] = tet.shape[1][i];
                      boardbool[lr - 1][lc + k + i] = true;
                    }

                    if (lr - 2 >= 0)
                    {

                      if (board[lr - 2][lc + k] == false)
                        j = 0;
                      else
                        j = 0;
                    }
                    for (int i = j; i < 2; ++i)
                    {
                      board[lr - 2][lc + k + i] = tet.shape[0][i];
                      boardbool[lr - 2][lc + k + i] = true;
                    }

                    printed = true;
                  }
                  k = width;
                }
              }
              if (k == width - 2 && printed == false && lr > 0 && (c1 == true || lr < 3))
              {

                tet.rotate(direction::right);

                lr--;
                if (lr == 1)
                  printed = true;
              }

              c1 = false;
            }
          }
          else
          {
            cout << "Sorry not enough place for this " << endl;

            printed = true;
          }
        }
      }
    }
    break;

  case tetrominos::S:

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() != 1)
        {

          if (width - 4 >= 0 && lr >= 0)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              for (int i = 0; i < 3; ++i)
              {

                int j = 0;
                if (i == 2)
                  j = 1;

                if (boardbool[lr][lc + k + i - j] == true)
                {

                  r1 = true;
                }
                else
                {

                  if (i == 0)
                  {

                    if (boardbool[lr - 1][lc + k + i + 1] == true)// checks if its crossing
                      r1 = true;
                  }
                  else
                  {

                    if (boardbool[lr - 1][lc + k + i] == true)
                      r1 = true;
                  }
                }
              }

              int j = 0;

              if (r1 == false && printed == false)
              {
                if (lc + k > 0)
                {
                  if (boardbool[lr - 1][lc + k] == true)
                    j = 1;
                }

                for (int i = 0; i < 2; ++i)
                {

                  board[lr][lc + k + i] = tet.shape[1][i];   //prints tetromino to board

                  boardbool[lr][lc + k + i] = true;

                  printed = true;
                }

                for (int i = 1; i < 3; ++i)
                {

                  board[lr - 1][lc + k + i] = tet.shape[0][i];
                  if (i != 0)
                    boardbool[lr - 1][lc + k + i] = true;

                  printed = true;
                }
                k = width;
              }
              if (k == width - 2 && r1 == true && printed == false)
              {

                tet.rotate(direction::right);
              }

              r1 = false;
            }
          }
          else
          {

            tet.rotate(direction::right);
          }
        }
        else
        {

          if (length >= 4 && width >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {
              if (lr >= 3)
              {
                for (int i = 0; i < 3; ++i)
                {

                  if (i == 0)
                  {

                    if (boardbool[lr][lc + k + 1] == true)
                    {

                      c1 = true;
                    }
                  }

                  if (i == 1)
                  {

                    if (boardbool[lr - i][lc + k + 1] == true || boardbool[lr - i][lc + k] == true)
                    {

                      c1 = true;
                    }
                  }

                  if (i == 2)
                  {

                    if (boardbool[lr - i][lc + k] == true)
                    {

                      c1 = true;
                    }
                  }
                }
              }

              if (lr >= 3)
              {
                if (c1 == false)
                {
                  int j = 0;

                  if (lc + k + 1 < width - 1)
                  {
                    if (boardbool[lr][lc + k] == true)
                      j = 1;
                  }

                  for (int i = 0; i < 2 - j; ++i)
                  {
                    cout << lc + k + i << endl
                         << j << endl;
                    board[lr][lc + k + i + j] = tet.shape[2][i + j];
                    boardbool[lr][lc + k + i + j] = true;

                    for (int i = 0; i < 2; ++i)
                    {  
                      board[lr - 1][lc + k + i] = tet.shape[1][i];  //printing
                      boardbool[lr - 1][lc + k + i] = true;
                    }

                    for (int i = 0; i < 1; ++i)
                    {
                      board[lr - 2][lc + k + i] = tet.shape[0][i];
                      boardbool[lr - 2][lc + k + i] = true;
                    }

                    printed = true;
                  }
                  k = width;
                }
              }
              if (k == width - 2 && printed == false && lr > 0 && (c1 == true || lr < 3))
              {

                tet.rotate(direction::right);

                lr--;
                if (lr == 1)
                  printed = true;
              }

              c1 = false;
            }
          }
          else
          {
            cout << "Sorry not enough place for this " << endl;

            printed = true;
          }
        }
      }
    }

    break;

  case tetrominos::O:
    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this 1" << endl;
        printed = true;
      }
      else
      {

        if (width - 2 >= 0 && lr >= 0)
        {

          for (int k = 0; k < width - 1; ++k)
          {

            for (int i = 0; i < 2; ++i)
            {

              if (boardbool[lr][lc + k + i] == true || boardbool[lr - 1][lc + k + i] == true)
              {

                r1 = true;
                i = 3;
              }
            }

            if (r1 == false && printed == false)
            {

              for (int i = 0; i < 2; ++i)
              {

                board[lr][lc + k + i] = tet.shape[1][i];
                board[lr - 1][lc + k + i] = tet.shape[0][i];
                boardbool[lr][lc + k + i] = true;     //printing
                boardbool[lr - 1][lc + k + i] = true;

                printed = true;
              }
              k = width;
            }

            r1 = false;
          }

          if (printed == false && lr > 0)
          {
            lr--;
          }
        }
      }
    }
    break;

  case tetrominos::T:

    while (printed == false)
    {

      if (lr == 0)
      {
        cout << "Sorry not enough place for this " << endl;
        printed = true;
      }
      else
      {

        if (tet.getturnr() == 1)
        { // checks if it rotated

          if (width - 2 >= 0 && lr >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k + 1] == true ||
                  (boardbool[lr - 2][lc + k + 1] == true) ||  //check crossing
                  (boardbool[lr - 1][lc + k + 1] == true) ||
                  (boardbool[lr - 1][lc + k] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 2; ++i)
                {

                  if (i == 1)
                  {
                    board[lr - 2][lc + k + i] = tet.shape[0][i];
                    board[lr - 1][lc + k + i] = tet.shape[1][i];
                    board[lr][lc + k + i] = tet.shape[2][i];//printing
                    boardbool[lr][lc + k + i] = true;
                    boardbool[lr - 1][lc + k + i] = true;
                    boardbool[lr - 2][lc + k + i] = true;
                  }
                  if (i == 0)
                  {
                    board[lr - 1][lc + k + i] = tet.shape[1][i];
                    boardbool[lr - 1][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);
            }
          }
        }

        if (tet.getturnr() == 2)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k + 1] == true ||
                  (boardbool[lr][lc + k + 2] == true) ||
                  (boardbool[lr][lc + k] == true) ||  //check crossing
                  (boardbool[lr - 1][lc + k + 1] == true))
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr][lc + k + i] = tet.shape[1][i];//printing
                  boardbool[lr][lc + k + i] = true;    

                  if (i == 1)
                  {

                    board[lr - 1][lc + k + i] = tet.shape[0][i];
                    boardbool[lr - 1][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {
              tet.rotate(direction::right);
            }
          }
        }

        if (tet.getturnr() == 3)
        { // checks if it rotated

          if (width - 2 >= 0 && lr >= 3)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr][lc + k] == true ||
                  (boardbool[lr - 2][lc + k] == true) ||
                  (boardbool[lr - 1][lc + k + 1] == true) ||
                  (boardbool[lr - 1][lc + k] == true))  //check crossing
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 2; i++)
                {

                  if (i == 0)
                  {

                    board[lr - 2][lc + k + i] = tet.shape[0][i];
                    board[lr - 1][lc + k + i] = tet.shape[1][i];
                    board[lr][lc + k + i] = tet.shape[2][i];
                    boardbool[lr][lc + k + i] = true;  //printing
                    boardbool[lr - 1][lc + k + i] = true;
                    boardbool[lr - 2][lc + k + i] = true;
                  }
                  if (i == 1)
                  {
                    board[lr - 1][lc + k + i] = tet.shape[1][i];
                    boardbool[lr - 1][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }
          }

          if (printed == false)
            lr--;
        }

        if (tet.getturnr() == 0)
        { // checks if it rotated

          if (width - 3 >= 0 && lr >= 2)
          {

            for (int k = 0; k < width - 1; ++k)
            {

              if (boardbool[lr - 1][lc + k + 1] == true ||
                  (boardbool[lr - 1][lc + k + 2] == true) ||
                  (boardbool[lr - 1][lc + k] == true) ||
                  (boardbool[lr][lc + k + 1] == true))  //check crossing
                r1 = true;

              if (r1 == false && printed == false)
              {

                for (int i = 0; i < 3; ++i)
                {

                  board[lr - 1][lc + k + i] = tet.shape[0][i];
                  boardbool[lr - 1][lc + k + i] = true;

                  if (i == 1)
                  {

                    board[lr][lc + k + i] = tet.shape[1][i];
                    boardbool[lr][lc + k + i] = true;
                  }

                  printed = true;
                }
                k = width;
              }

              r1 = false;
            }

            if (printed == false)
            {

              tet.rotate(direction::right);
            }
          }
        }
      }
    }
    break;
  }
}

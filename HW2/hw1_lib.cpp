#include "hw1_lib.h"
#include <cstdlib>

tetromino ::tetromino(tetrominos tetrominochoice)
{

   setShape(tetrominochoice);
    
} // Constructor with parameter
tetromino ::tetromino() {}

void tetromino ::setShape(tetrominos tetrominochoice)
{ // setting shapes by creating vectors

   switch (tetrominochoice)
   {
   case tetrominos::I:

      shape.push_back({'I', 'I', 'I', 'I'});
      type = tetrominos::I;
      break;

   case tetrominos::J:
      shape.push_back({' ', 'J'});
      shape.push_back({' ', 'J'});
      shape.push_back({'J', 'J'});
      type = tetrominos::J;
      break;

   case tetrominos::O:
      shape.push_back({'O', 'O'});
      shape.push_back({'O', 'O'});
      type = tetrominos::O;
      break;

   case tetrominos::L:

      shape.push_back({'L', ' '});
      shape.push_back({'L', ' '});
      shape.push_back({'L', 'L'});
      type = tetrominos::L;

      break;

   case tetrominos::T:
      shape.push_back({'T', 'T', 'T'});
      shape.push_back({' ', 'T', ' '});
      type = tetrominos::T;
      break;

   case tetrominos::S:

      shape.push_back({' ', 'S', 'S'});
      shape.push_back({'S', 'S', ' '});
      type = tetrominos::S;
      break;

   case tetrominos::Z:
      shape.push_back({'Z', 'Z', ' '});
      shape.push_back({' ', 'Z', 'Z'});
      type = tetrominos::Z;
      break;
   }
}

int  tetromino :: getturnr(){


   return rturnnum;
}

int  tetromino :: getturnl(){


   return lturnnum;
}
  tetrominos tetromino::  gettype(){



   return type;
  }
void tetromino ::rotate(direction turnWay)
{ // rotates the shape by changing the object

   if (turnWay == direction::right) // I control the shape by counting turn numbers
      ++rturnnum;

      


   if (turnWay == direction::left)
      ++lturnnum;

   switch (type)
   {
   case tetrominos::I:
      switch (abs(rturnnum - lturnnum)) // I check this way turn numbers because "I" only has 2 options
      {
      case 2:
         shape.clear();
         shape.push_back({'I', 'I', 'I', 'I'});
          rturnnum = 0;
         lturnnum = 0;
         break;
      case 1:
         shape.clear();
         shape.push_back({'I'});
         shape.push_back({'I'});
         shape.push_back({'I'});
         shape.push_back({'I'});
       

         break;
      }

      break;

   case tetrominos::J:
      if (rturnnum > lturnnum)
      {
         switch (rturnnum - lturnnum)
         { // since "j" has 4 options I check them separetly

         case 1:
            shape.clear();
            shape.push_back({'J'});
            shape.push_back({'J', 'J', 'J'});

            break;

         case 4:
            shape.clear();
            shape.push_back({' ', 'J'});
            shape.push_back({' ', 'J'});
            shape.push_back({'J', 'J'});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 3:
            shape.clear();
            shape.push_back({'J', 'J', 'J'});
            shape.push_back({' ', ' ', 'J'});

            break;
         case 2:
            shape.clear();

            shape.push_back({'J', 'J'});
            shape.push_back({'J'});
            shape.push_back({'J'});

            break;
         }
      }

      if (rturnnum <= lturnnum)
      {
         switch (lturnnum - rturnnum)
         { // since "j" has 4 options I check them separetly

         case 3:
            shape.clear();
            shape.push_back({'J'});
            shape.push_back({'J', 'J', 'J'});

            break;

         case 0:
            shape.clear();
            shape.push_back({' ', 'J'});
            shape.push_back({' ', 'J'});
            shape.push_back({'J', 'J'});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 4:
            shape.clear();
            shape.push_back({' ', 'J'});
            shape.push_back({' ', 'J'});
            shape.push_back({'J', 'J'});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 1:
            shape.clear();
            shape.push_back({'J', 'J', 'J'});
            shape.push_back({' ', ' ', 'J'});

            break;
         case 2:
            shape.clear();

            shape.push_back({'J', 'J'});
            shape.push_back({'J'});
            shape.push_back({'J'});

            break;
         }
      }

      break;

   case tetrominos::O:
      // o doesn't change with rotation
      break;

   case tetrominos::L:

      if (rturnnum > lturnnum)
      {

         switch (rturnnum - lturnnum) // since "L" has 4 options I check them separetly
         {

         case 1:
            shape.clear();
            shape.push_back({'L', 'L', 'L'});
            shape.push_back({'L'});
            break;

         case 4:
            shape.clear();
            shape.push_back({'L', ' '});
            shape.push_back({'L', ' '});
            shape.push_back({'L', 'L'});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 3:
            shape.clear();
            shape.push_back({' ', ' ', 'L'});
            shape.push_back({'L', 'L', 'L'});

            break;

         case 2:
            shape.clear();

            shape.push_back({'L', 'L'});
            shape.push_back({' ', 'L'});
            shape.push_back({' ', 'L'});

            break;
         }
      }
      if (rturnnum <= lturnnum)
      {

         switch (lturnnum - rturnnum) // since "L" has 4 options I check them separetly
         {

         case 3:
            shape.clear();
            shape.push_back({'L', 'L', 'L'});
            shape.push_back({'L'});

            break;

         case 4:
            shape.clear();
            shape.push_back({'L', ' '});
            shape.push_back({'L', ' '});
            shape.push_back({'L', 'L'});
            rturnnum = 0;
            lturnnum = 0;
            break;

         case 0:
            shape.clear();
            shape.push_back({'L', ' '});
            shape.push_back({'L', ' '});
            shape.push_back({'L', 'L'});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 1:

            shape.clear();
            shape.push_back({' ', ' ', 'L'});
            shape.push_back({'L', 'L', 'L'});

            break;

         case 2:
            shape.clear();

            shape.push_back({'L', 'L'});
            shape.push_back({' ', 'L'});
            shape.push_back({' ', 'L'});

            break;
         }
      }

      break;

   case tetrominos::T:

      if (rturnnum > lturnnum)
      {

         switch (rturnnum - lturnnum) // since "T" has 4 options I check them separetly
         {

         case 1:
            shape.clear();
            shape.push_back({' ', 'T'});
            shape.push_back({'T', 'T'});
            shape.push_back({' ', 'T'});

            break;

         case 4:
            shape.clear();
            shape.push_back({'T', 'T', 'T'});
            shape.push_back({' ', 'T', ' '});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 3:
            shape.clear();
            shape.push_back({'T', ' '});
            shape.push_back({'T', 'T'});
            shape.push_back({'T', ' '});

            break;
         case 2:
            shape.clear();

            shape.push_back({' ', 'T', ' '});
            shape.push_back({'T', 'T', 'T'});

            break;
         }
      }

      if (rturnnum <= lturnnum)
      {

         switch (lturnnum - rturnnum) // since "T" has 4 options I check them separetly
         {

         case 3:
            shape.clear();
            shape.push_back({' ', 'T'});
            shape.push_back({'T', 'T'});
            shape.push_back({' ', 'T'});

            break;

         case 4:
            shape.clear();
            shape.push_back({'T', 'T', 'T'});
            shape.push_back({' ', 'T', ' '});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 0:
            shape.clear();
            shape.push_back({'T', 'T', 'T'});
            shape.push_back({' ', 'T', ' '});
            rturnnum = 0;
            lturnnum = 0;
            break;
         case 1:
            shape.clear();
            shape.push_back({'T', ' '});
            shape.push_back({'T', 'T'});
            shape.push_back({'T', ' '});

            break;
         case 2:
            shape.clear();

            shape.push_back({' ', 'T', ' '});
            shape.push_back({'T', 'T', 'T'});

            break;
         }
      }
      break;

   case tetrominos::S:
      switch (abs(rturnnum - lturnnum))
      { // I check this way turn numbers because "S" only has 2 options
      case 2:
         shape.clear();
         shape.push_back({' ', 'S', 'S'});
         shape.push_back({'S', 'S', ' '});
         rturnnum = 0;
         lturnnum = 0;
         break;
      case 1:
         shape.clear();
         shape.push_back({'S'});
         shape.push_back({'S', 'S'});
         shape.push_back({' ', 'S'});

         break;
      }
      break;

   case tetrominos::Z:

      switch (abs(rturnnum - lturnnum))
      { // I check this way turn numbers because "Z" only has 2 options
      case 2:
         shape.clear();
         shape.push_back({'Z', 'Z', ' '});
         shape.push_back({' ', 'Z', 'Z'});
         rturnnum = 0;
         lturnnum = 0;
         break;
      case 1:
         shape.clear();
         shape.push_back({' ', 'Z'});
         shape.push_back({'Z', 'Z'});
         shape.push_back({'Z', ' '});

         break;
      }

      break;
   }
}

    void tetromino:: setturnr(int a){
     rturnnum = a;
    }
    void tetromino::setturnl(int a){
     lturnnum = a;
    }

   
bool tetromino::canFit(tetromino &other)
{

   bool allchecked = false;

   bool rightoffirstemptyLR;  // row right side of tetromino emptiness check
   bool leftofsecondemptyLR;  // last row left side of tetromino emptiness check
   bool rightoffirstempty2LR; // second last  row right side of tetromino emptiness check
   bool leftofsecondempty2LR; // second last row left side of tetromino emptiness check
   bool rightoffirstempty3LR; // third last  row right side of tetromino emptiness check
   bool leftofsecondempty3LR; // third last row left side of tetromino emptiness check
   bool rightoffirstempty4LR; // fourth last  row right side of tetromino emptiness check
   bool leftofsecondempty4LR; // fourt last row left side of tetromino emptiness check

   // tetrominos have 4 rows max
   int count = 0;
   while (count < 4)
   {

      if (shape.size() == 1 || other.shape.size() == 1)
      { /*checking size of the shape so i dont try to check
a row that doesnt exists*/

         // checking emtiness of rows

         if (shape[shape.size() - 1].back() == ' ') // checks object on left's last rows right empty or not
            rightoffirstemptyLR = true;

         else
            rightoffirstemptyLR = false;

         if (other.shape[other.shape.size() - 1].front() != ' ') // checks object on right's last rows left empty or not
            leftofsecondemptyLR = false;
         else
            leftofsecondemptyLR = true;

         if ((rightoffirstemptyLR == true && leftofsecondemptyLR == false) || // being fitted condition
             (rightoffirstemptyLR == false && leftofsecondemptyLR == true) ||
             (rightoffirstemptyLR == false && leftofsecondemptyLR == false))
         {

            allchecked = true;
         }
      }

      else if (shape.size() == 2 || other.shape.size() == 2)
      { /*checking size of the shape so i dont try to check
a row that doesnt exists*/

         if (shape[shape.size() - 1].back() == ' ') // checks object on left's last row's right empty or not
            rightoffirstemptyLR = true;

         else
            rightoffirstemptyLR = false;

         if (other.shape[other.shape.size() - 1].front() != ' ') // checks object on right's last rows left empty or not
            leftofsecondemptyLR = false;
         else
            leftofsecondemptyLR = true;

         if (shape[shape.size() - 2].back() == ' ') // checks object on left's 2nd last row's right empty or not
            rightoffirstempty2LR = true;
         else
            rightoffirstempty2LR = false;

         if (other.shape[other.shape.size() - 2].front() != ' ') // checks object on right's 2nd last rows left empty or not
            leftofsecondempty2LR = false;
         else
            leftofsecondempty2LR = true;

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == false)
         {

            allchecked = true;
         }

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == true)
         {

            if (leftofsecondempty2LR == false)
            { // checks if the second last row of tertrominos intersect
               if (rightoffirstempty2LR == true)
                  allchecked = true;

               if (rightoffirstempty2LR == false)
                  allchecked = false;
            }
            if (leftofsecondempty2LR == true)
            { // checks if the second last row of tertrominos intersect

               if (rightoffirstempty2LR == true)
                  allchecked = true;
               if (rightoffirstempty2LR == false)
                  allchecked = true;
            }
         }

         if (rightoffirstemptyLR == true && leftofsecondemptyLR == false)
         {

            if (leftofsecondempty2LR == false)
            {
               if (rightoffirstempty2LR == true)
                  allchecked = true;
               if (rightoffirstempty2LR == false) // checks if the second last row of tertrominos intersect
                  allchecked = false;
            }
            if (leftofsecondempty2LR == true)
            {
               if (rightoffirstempty2LR == true)
                  allchecked = true;
               if (rightoffirstempty2LR == false)
                  allchecked = true;
            }
         }
      }

      else if (shape.size() == 3 || other.shape.size() == 3)
      {

         if (shape[shape.size() - 1].back() == ' ') // checks object on left's last row's right empty or not
            rightoffirstemptyLR = true;

         else
            rightoffirstemptyLR = false;

         if (other.shape[other.shape.size() - 1].front() != ' ') // checks object on right's last rows left empty or not
            leftofsecondemptyLR = false;
         else
            leftofsecondemptyLR = true;

         if (shape[shape.size() - 2].back() == ' ') // checks object on left's  2nd last row's right empty or not
            rightoffirstempty2LR = true;
         else
            rightoffirstempty2LR = false;

         if (other.shape[other.shape.size() - 2].front() != ' ') // checks object on right's 2nd last rows left empty or not
            leftofsecondempty2LR = false;
         else
            leftofsecondempty2LR = true;

         if (shape[shape.size() - 3].back() == ' ') // checks object on left's 3d last row's right empty or not
            rightoffirstempty3LR = true;
         else
            rightoffirstempty3LR = false;

         if (other.shape[other.shape.size() - 3].front() != ' ') // checks object on right's 3d last rows left empty or not
            leftofsecondempty3LR = false;
         else
            leftofsecondempty3LR = true;

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == false)
         { // if both can stand next to them without interacting

            allchecked = true;
         }

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == true)
         { // if they are interacting

            if (leftofsecondempty2LR == false)
            { // checks if the second last row of tertrominos intersect
               if (rightoffirstempty2LR == true)
               { // if they don't it checks third row

                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }
               if (rightoffirstempty2LR == false)
                  allchecked = false;
            }

            if (leftofsecondempty2LR == true)
            { // checks if the second last row of tertrominos intersect

               if (rightoffirstempty2LR == true)
               { // if they don't it checks third row
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }

               if (rightoffirstempty2LR == false)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }
            }
         }

         if (rightoffirstemptyLR == true && leftofsecondemptyLR == false)
         { // checks condition where first tetromino has a empty space and second dont

            if (leftofsecondempty2LR == false)
            { // checks if the second last row of tertrominos intersect
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }
               if (rightoffirstempty2LR == false)
                  allchecked = false;
            }
            if (leftofsecondempty2LR == true)
            {
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }

               if (rightoffirstempty2LR == false)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                     allchecked = true;
               }
            }
         }
      }

      else if (shape.size() == 4 || other.shape.size() == 4)
      {

         if (shape[shape.size() - 1].back() == ' ') // checks object on left's last row's right empty or not
            rightoffirstemptyLR = true;

         else
            rightoffirstemptyLR = false;

         if (other.shape[other.shape.size() - 1].front() != ' ') // checks object on right's last rows left empty or not
            leftofsecondemptyLR = false;
         else
            leftofsecondemptyLR = true;

         if (shape[shape.size() - 2].back() == ' ') // checks object on left's 2nd last row's right empty or not
            rightoffirstempty2LR = true;
         else
            rightoffirstempty2LR = false;

         if (other.shape[other.shape.size() - 2].front() != ' ') // checks object on right's 2nd last rows left empty or not
            leftofsecondempty2LR = false;
         else
            leftofsecondempty2LR = true;

         if (shape[shape.size() - 3].back() == ' ') // checks object on left's 3rd last row's right empty or not
            rightoffirstempty3LR = true;
         else
            rightoffirstempty3LR = false;

         if (other.shape[other.shape.size() - 3].front() != ' ') // checks object on right's 3d last rows left empty or not
            leftofsecondempty3LR = false;
         else
            leftofsecondempty3LR = true;

         if (shape[shape.size() - 4].back() == ' ') // checks object on left's 4th last row's right empty or not
            rightoffirstempty4LR = true;

         else
            rightoffirstempty4LR = false;

         if (other.shape[other.shape.size() - 4].front() != ' ') // checks object on right's 4th last rows left empty or not
            leftofsecondempty4LR = false;
         else
            leftofsecondempty4LR = true;

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == false)
         { // checks contion first tetromino and second tetromino doesnt have space

            allchecked = true;
         }

         if (rightoffirstemptyLR == false && leftofsecondemptyLR == true)
         { // checks contion first tetromino doesnt and second tetromino does have space

            if (leftofsecondempty2LR == false)
            {
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
               if (rightoffirstempty2LR == false)
                  allchecked = false;
            }
            if (leftofsecondempty2LR == true)
            {
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
               if (rightoffirstempty2LR == false)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
            }
         }

         if (rightoffirstemptyLR == true && leftofsecondemptyLR == false)
         { // checks contion first tetromino does and second tetromino doesnt have space

            if (leftofsecondempty2LR == false)
            { // checks if second last row is intersecting
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
               if (rightoffirstempty2LR == false)
                  allchecked = false;
            }
            if (leftofsecondempty2LR == true)
            {
               if (rightoffirstempty2LR == true)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
               if (rightoffirstempty2LR == false)
               {
                  if (rightoffirstempty3LR == true && leftofsecondempty3LR == false ||
                      rightoffirstempty3LR == true && leftofsecondempty3LR == true ||
                      rightoffirstempty3LR == false && leftofsecondempty3LR == true)
                  {

                     if (rightoffirstempty4LR == true && leftofsecondempty4LR == false ||
                         rightoffirstempty4LR == true && leftofsecondempty4LR == true ||
                         rightoffirstempty4LR == false && leftofsecondempty4LR == true)
                        allchecked = true;
                  }
               }
            }
         }
      }

      if (allchecked == false)
      {
         count++;
         other.rotate(direction::right);
      }
      else
      {

         count = 4;
      }
   }

   return allchecked;
}

void tetromino ::print() const
{

   for (auto row : shape)
   {

      for (char x : row)
      {
         cout << x;
      }

      cout << endl;
   }

   cout << endl;
}

void tetromino ::printfullfit(const vector<vector<char>> &vect)
{
   for (auto row : vect)
   {

      for (char x : row)
      {
         cout << x;
      }
      cout << endl;
   }

   cout << endl;
}

void tetromino ::tetrominofit(vector<vector<char>> &vec, vector<tetromino> &vectetromino)
{
   vector<bool> used;
   for (int i = 0; i < vectetromino.size(); ++i)
   {
      used.push_back(false);
   }
   int length, length1, length2;

   for (int i = 0; i < vectetromino.size() - 2; ++i)
   {

      if (vectetromino[i].canFit(vectetromino[i + 1]) == false && vectetromino[i].canFit(vectetromino[i + 2]) == true)
      {
         tetromino temp;
         temp = vectetromino[i + 1];
         vectetromino[i + 1] = vectetromino[i + 2];
         vectetromino[i + 2] = temp;
         --i;
      }
   }

   for (int i = 0; i < vectetromino.size() - 1; ++i)
   {

      if (vectetromino[i].canFit(vectetromino[i + 1]) == true)
      {

         used.at(i) = true;
      }
   }
   used.at(vectetromino.size() - 1) = true;

   int r0 = 0, r1 = 0, r2 = 0, r3 = 0; // keeps the number of elements in rows

   for (int i = 0; i < vectetromino.size(); ++i)
   {

      switch (vectetromino[i].shape.size())
      {
      case 1:
         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[3].push_back(vectetromino[i].shape[0][k]);
            vec[2].push_back(' '); // to not cause problems I push tabs to rows ı didnt use
            vec[1].push_back(' ');
            vec[0].push_back(' ');
            ++r0;
            ++r1;
            ++r2;
            ++r3;
         }
         break;

      case 3:

         for (int k = 0; k < vectetromino[i].shape[2].size(); ++k)
         {
            vec[3].push_back(vectetromino[i].shape[2][k]); // row 4 push
            ++r3;
         }
         for (int k = 0; k < vectetromino[i].shape[1].size(); ++k)
         {
            vec[2].push_back(vectetromino[i].shape[1][k]); // row 3 push
            ++r2;
         }

         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[1].push_back(vectetromino[i].shape[0][k]); // row 2 push
            ++r1;
         }
         if (vectetromino[i].shape[0].size() > vectetromino[i].shape[1].size() && vectetromino[i].shape[0].size() > vectetromino[i].shape[2].size())
         {
            for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
            {
               vec[0].push_back(' '); // row 1 push
               ++r0;
            }

            for (int k = 0; k < vectetromino[i].shape[0].size() - vectetromino[i].shape[1].size(); ++k)
            {
               vec[2].push_back(' '); // completes the pattern with tabs
               ++r2;
            }

            for (int k = 0; k < vectetromino[i].shape[0].size() - vectetromino[i].shape[2].size(); ++k)
            {
               vec[3].push_back(' '); // completes the pattern with tabs
               ++r3;
            }
         }

         else if (vectetromino[i].shape[1].size() > vectetromino[i].shape[0].size() && vectetromino[i].shape[1].size() > vectetromino[i].shape[2].size())
         {

            for (int k = 0; k < vectetromino[i].shape[1].size(); ++k)
            {
               vec[0].push_back(' '); // completes the pattern with tabs
               ++r0;
            }
            for (int k = 0; k < vectetromino[i].shape[1].size() - vectetromino[i].shape[0].size(); ++k)
            {
               vec[1].push_back(' '); // completes the pattern with tabs
               ++r1;
            }
            for (int k = 0; k < vectetromino[i].shape[1].size() - vectetromino[i].shape[2].size(); ++k)
            {
               vec[3].push_back(' '); // completes the pattern with tabs
               ++r3;
            }
         }
         else if (vectetromino[i].shape[2].size() > vectetromino[i].shape[0].size() && vectetromino[i].shape[2].size() > vectetromino[i].shape[3].size())
         {
            for (int k = 0; k < vectetromino[i].shape[2].size(); ++k)
            {
               vec[0].push_back(' ');
               ++r0;
            }

            for (int k = 0; k < vectetromino[i].shape[2].size() - vectetromino[i].shape[0].size(); ++k)
            {
               vec[1].push_back(' ');
               ++r1;
            }

            for (int k = 0; k < vectetromino[i].shape[2].size() - vectetromino[i].shape[1].size(); ++k)
            {
               vec[2].push_back(' ');
               ++r2;
            }
         }
         break;
      case 2:

         for (int k = 0; k < vectetromino[i].shape[1].size(); ++k)
         {
            vec[3].push_back(vectetromino[i].shape[1][k]);
            ++r3;
         }

         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[2].push_back(vectetromino[i].shape[0][k]);
            ++r2;
         }

         if (vectetromino[i].shape[0].size() > vectetromino[i].shape[1].size())
         {
            for (int k = 0; k < vectetromino[i].shape[0].size() - vectetromino[i].shape[1].size(); ++k)
            {
               vec[0].push_back(' ');
               ++r0;
            }

            for (int k = 0; k < vectetromino[i].shape[0].size() - (vectetromino[i].shape[1].size() - 1); ++k)
            {
               vec[1].push_back(' ');
               ++r1;
            }
         }
         else
         {
            for (int k = 0; k < vectetromino[i].shape[1].size() - vectetromino[i].shape[0].size(); ++k)
            {
               vec[2].push_back(' ');
               ++r2;
            }

            for (int k = 0; k < vectetromino[i].shape[1].size(); ++k)
            {
               vec[0].push_back(' ');
               ++r0;
            }

            for (int k = 0; k < vectetromino[i].shape[1].size(); ++k)
            {
               vec[1].push_back(' ');
               ++r1;
            }
         }

         if (vectetromino[i].shape[1][vectetromino[i].shape[1].size() - 1] == ' ' && vectetromino[i].shape[0][vectetromino[i].shape[0].size() - 1] != ' ')
         {
         }

         if (vectetromino[i].shape[1][vectetromino[i].shape[1].size() - 1] != ' ' && vectetromino[i].shape[0][vectetromino[i].shape[0].size() - 1] == ' ')
         {
         }
         break;
      case 4:

         // only rotated ı can be 4 so ı dont need to check

         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[3].push_back(vectetromino[i].shape[0][k]);
            ++r3;
         }
         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[2].push_back(vectetromino[i].shape[1][k]);
            ++r2;
         }
         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[1].push_back(vectetromino[i].shape[2][k]);
            ++r1;
         }
         for (int k = 0; k < vectetromino[i].shape[0].size(); ++k)
         {
            vec[0].push_back(vectetromino[i].shape[3][k]);
            ++r0;
         }

         break;
      }

      if (used.at(i) == true)
      {

         if (i >= 1)
         { // this part arranges tetreminos that fit eachothers tabs
            if (vectetromino[i].shape[vectetromino[i].shape.size() - 1][0] == ' ' && vectetromino[i - 1].shape[vectetromino[i - 1].shape.size() - 1].back() != ' ')
            {

               vec[3].erase(vec[3].begin() + r3 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
               vec[2].erase(vec[2].begin() + r2 - 1 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
               vec[1].erase(vec[1].begin() + r1 - 1 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
            }
         }

         if (i >= 1)
         {
            if (vectetromino[i].shape[vectetromino[i].shape.size() - 1][0] != ' ' && vectetromino[i - 1].shape[vectetromino[i - 1].shape.size() - 1].back() == ' ')
            {

               vec[2].erase(vec[2].begin() + r2 - 1 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
               if (vectetromino[i - 1].shape[vectetromino[i - 1].shape.size() - 1].front() == ' ')
                  vec[3].erase(vec[3].begin() + r3 - 2 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
               if (vectetromino[i - 1].shape[vectetromino[i - 1].shape.size() - 1].front() != ' ')
                  vec[3].erase(vec[3].begin() + r3 - 1 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
               vec[1].erase(vec[1].begin() + r1 - 1 - (vectetromino[i].shape[vectetromino[i].shape.size() - 1].size()));
            }
         }
      }
   }
}
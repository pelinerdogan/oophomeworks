#include "hw1again.h"
#include <cstdlib>

tetromino ::tetromino(tetrominos tetrominochoice)
{

    setShape(tetrominochoice);

} // Constructor with parameter
tetromino ::tetromino() {}

void tetromino ::setShape(tetrominos tetrominochoice)
{

    switch (tetrominochoice)
    {
    case tetrominos::I:
        rownum = 1;
        columnnum= 4;
        shape = new char *[1];

        for (int i = 0; i < 1; i++)
        {
            shape[i] = new char[4];
        }

        for (int i = 0; i < 4; i++)
        {
            shape[0][i] = 'I';
        }

        type = tetrominos::I;
        break;

    case tetrominos::J:
         rownum = 3;
        columnnum= 2;
        shape = new char *[3];

        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
        }

        for (int i = 0; i < 3; i++)
        {
            shape[i][1] = 'J';
        }

        for (int i = 0; i < 2; i++)
        {
            shape[i][0] = ' ';
        }
        shape[2][0] = 'J';

        type = tetrominos::J;
        break;

    case tetrominos::O:
         rownum = 2;
        columnnum= 2;
        shape = new char *[2];

        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[2];
        }

        for (int i = 0; i < 2; i++)
        {
            shape[i][0] = 'O';
            shape[i][1] = 'O';
        }

        type = tetrominos::O;
        break;

    case tetrominos::L:
         rownum = 3;
        columnnum= 2;
        shape = new char *[3];

        for (int i = 0; i < 3; i++)
        {
            shape[i] = new char[2];
        }

        for (int i = 0; i < 2; i++)
        {
            shape[i][1] = ' ';
        }

        for (int i = 0; i < 3; i++)
        {
            shape[i][0] = 'L';
        }
        shape[2][1] = 'L';

        type = tetrominos::L;

        break;

    case tetrominos::T:
        rownum = 2;
        columnnum= 3;
        shape = new char *[2];

        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
        }

        for (int i = 0; i < 3; i++)
        {
            shape[0][i] = 'T';
        }

        shape[1][0] = ' ';
        shape[1][1] = 'T';
        shape[1][2] = ' ';

        type = tetrominos::T;
        break;

    case tetrominos::S:
        rownum = 2;
        columnnum= 3;
        shape = new char *[2];

        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
        }

        shape[0][0] = ' ';
        shape[0][1] = 'S';
        shape[0][2] = 'S';

        shape[1][0] = 'S';
        shape[1][1] = 'S';
        shape[1][2] = ' ';

        type = tetrominos::S;
        break;

    case tetrominos::Z:
         rownum = 2;
        columnnum= 3;
        shape = new char *[2];

        for (int i = 0; i < 2; i++)
        {
            shape[i] = new char[3];
        }

        shape[0][0] = 'Z';
        shape[0][1] = 'Z';
        shape[0][2] = ' ';

        shape[1][0] = ' ';
        shape[1][1] = 'Z';
        shape[1][2] = 'Z';

        type = tetrominos::Z;
        break;
    }
}

int tetromino ::getturnr()
{

    return rturnnum;
}

int tetromino ::getturnl()
{

    return lturnnum;
}
tetrominos tetromino::gettype()
{

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
        case 2:{
              rownum = 1;
              columnnum= 4;
            for (int i = 0; i < 4; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
        
            char ** shape1 = new char *[1];

            for (int i = 0; i < 1; i++)
            {
                shape1[i] = new char[4];
            }

            for (int i = 0; i < 4; i++)
            {
                shape1[0][i] = 'I';
            }

            rturnnum = 0;
            lturnnum = 0;
            shape = shape1;
            break;
        }
        
        case 1:
        {
            for (int i = 0; i < 1; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
           
             rownum = 4;
             columnnum= 1;
            char** shape2 = new char *[4];
            for (int i = 0; i < 4; i++)
            {
                shape2[i] = new char[1];
            }

            for (int i = 0; i < 4; i++)
            {
                shape2[i][0] = 'I';
            }
            
           shape= shape2;
            break;
        }
        }
          
        break;

    case tetrominos::J:
       if(rturnnum>lturnnum){
        switch (rturnnum - lturnnum)
        { // since "j" has 4 options I check them separetly

        case 1:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
            rownum = 2;
           columnnum= 3;
           char** shape3 = new char *[2];

            shape3[0] = new char[3];
            shape3[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape3[1][i] = 'J';
            }
            shape3[0][0] = 'J';
            shape3[0][1] = ' ';
            shape3[0][2] = ' ';
            shape=shape3;
            break;
        }
        case 4:
          {
            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
              rownum = 3;
              columnnum= 2;
            char** shape4 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape4[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape4[i][1] = 'J';
            }

            for (int i = 0; i < 2; i++)
            {
                shape4[i][0] = ' ';
            }
            shape4[2][0] = 'J';

            // shape.clear();
            // shape.push_back({' ', 'J'});
            // shape.push_back({' ', 'J'});
            // shape.push_back({'J', 'J'});
            rturnnum = 0;
            lturnnum = 0;
            shape =shape4;
            break;

          }
        case 3:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

           char** shape5 = new char *[2];

            shape5[0] = new char[3];
            shape5[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape5[0][i] = 'J';
            }
            shape5[1][2] = 'J';
            shape5[1][0] = ' ';
            shape5[1][1] = ' ';
            
              rownum = 2;
             columnnum= 3;
            // shape.clear();
            // shape.push_back({'J', 'J', 'J'});
            // shape.push_back({' ', ' ', 'J'});
            shape =shape5;
            break;
        }
        case 2:

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

           char** shape6 = new char *[3];

            shape6[0] = new char[2];
            shape6[1] = new char[2];
            shape6[2] = new char[2];

            for (int i = 0; i < 3; i++)
            {
                shape6[i][0] = 'J';
            }

            shape6[0][1] = 'J';
            shape6[1][1] = ' ';
            shape6[2][1] = ' ';

            //  shape.clear();

            /*shape.push_back({'J', 'J'});
             shape.push_back({'J'});
             shape.push_back({'J'});
           */
            rownum = 3;
           columnnum= 2;
           shape=shape6;
            break;
        }
    }
    else{

        switch (abs(lturnnum - rturnnum))
        { // since "j" has 4 options I check them separetly

        case 3:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
            rownum = 2;
           columnnum= 3;
           char** shape3 = new char *[2];

            shape3[0] = new char[3];
            shape3[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape3[1][i] = 'J';
            }
            shape3[0][0] = 'J';
            shape3[0][1] = ' ';
            shape3[0][2] = ' ';
            shape=shape3;
            break;
        }
        case 4:
          {
            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;
              rownum = 3;
              columnnum= 2;
            char** shape4 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape4[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape4[i][1] = 'J';
            }

            for (int i = 0; i < 2; i++)
            {
                shape4[i][0] = ' ';
            }
            shape4[2][0] = 'J';

       
            rturnnum = 0;
            lturnnum = 0;
            shape =shape4;
            break;

          }
        case 1:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

           char** shape5 = new char *[2];

            shape5[0] = new char[3];
            shape5[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape5[0][i] = 'J';
            }
            shape5[1][2] = 'J';
            shape5[1][0] = ' ';
            shape5[1][1] = ' ';
            
              rownum = 2;
             columnnum= 3;
          
            shape =shape5;
            break;
        }
        case 2:

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

           char** shape6 = new char *[3];

            shape6[0] = new char[2];
            shape6[1] = new char[2];
            shape6[2] = new char[2];

            for (int i = 0; i < 3; i++)
            {
                shape6[i][0] = 'J';
            }

            shape6[0][1] = 'J';
            shape6[1][1] = ' ';
            shape6[2][1] = ' ';

          
            rownum = 3;
           columnnum= 2;
           shape=shape6;
            break;
        }

    }
        break;

    case tetrominos::O:
        // o doesn't change with rotation
        break;

    case tetrominos::L:
        if (rturnnum>lturnnum)
        {
    
        switch (rturnnum - lturnnum) // since "L" has 4 options I check them separetly
        {

        case 1:{
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape7 = new char *[2];

            shape7[0] = new char[3];
            shape7[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape7[0][i] = 'L';
            }
            shape7[1][0] = 'L';
            shape7[1][1] = ' ';
            shape7[1][2] = ' ';
            
            shape=shape7;
             rownum = 2;
             columnnum= 3;
            break;
        }
        case 4:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape8 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape8[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape8[i][0] = 'L';
            }

            for (int i = 0; i < 2; i++)
            {
                shape8[i][1] = ' ';
            }
            shape8[2][1] = 'L';

           
             rownum = 3;
             columnnum= 2;
            rturnnum = 0;
            lturnnum = 0;
            shape = shape8;
            break;
        }
        case 3:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape9 = new char *[2];

            shape[0] = new char[3];
            shape[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape[1][i] = 'L';
            }
            shape[0][2] = 'L';
            shape[0][0] = ' ';
            shape[0][1] = ' ';
              rownum = 2;
             columnnum= 3;
          
            shape = shape9;
            break;
        }
        case 2:{

        

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape10 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape10[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape10[i][1] = 'L';
            }

            for (int i = 1; i < 3; i++)
            {
                shape10[i][0] = ' ';
            }
            shape10[0][0] = 'L';
              rownum = 3;
             columnnum= 2;

           shape=shape10;
            break;
        }
        break;
        }
    }
    else{
             
        switch (lturnnum - rturnnum) // since "L" has 4 options I check them separetly
        {

        case 3:{
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape7 = new char *[2];

            shape7[0] = new char[3];
            shape7[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape7[0][i] = 'L';
            }
            shape7[1][0] = 'L';
            shape7[1][1] = ' ';
            shape7[1][2] = ' ';
           
            shape=shape7;
             rownum = 2;
             columnnum= 3;
            break;
        }
        case 4:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape8 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape8[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape8[i][0] = 'L';
            }

            for (int i = 0; i < 2; i++)
            {
                shape8[i][1] = ' ';
            }
            shape8[2][1] = 'L';

           
             rownum = 3;
             columnnum= 2;
            rturnnum = 0;
            lturnnum = 0;
            shape = shape8;
            break;
        }
        case 1:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape9 = new char *[2];

            shape[0] = new char[3];
            shape[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape[1][i] = 'L';
            }
            shape[0][2] = 'L';
            shape[0][0] = ' ';
            shape[0][1] = ' ';
              rownum = 2;
             columnnum= 3;
            
            shape = shape9;
            break;
        }
        case 2:{

        

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape10 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape10[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape10[i][1] = 'L';
            }

            for (int i = 1; i < 3; i++)
            {
                shape10[i][0] = ' ';
            }
            shape10[0][0] = 'L';
              rownum = 3;
             columnnum= 2;

            shape=shape10;
            break;
        }
        break;
        }


    }
        break;
    case tetrominos::T:
       if (lturnnum>rturnnum)
       {
       
       
        switch (abs(lturnnum - rturnnum)) // since "T" has 4 options I check them separetly
        {

        case 3:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape11 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape11[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape11[i][1] = 'T';
            }

            shape11[0][0] = ' ';
            shape11[1][0] = 'T';
            shape11[2][0] = ' ';
            
              rownum = 3;
             columnnum= 2;
          
          shape = shape11;
            break;
        }
        case 4:
        {
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char ** shape12 = new char *[2];

            shape12[0] = new char[3];
            shape12[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape12[0][i] = 'T';
            }
            shape12[1][0] = ' ';
            shape12[1][1] = 'T';
            shape12[1][2] = ' ';
              rownum = 2;
              columnnum= 3;
           
            shape = shape12;
            rturnnum = 0;
            lturnnum = 0;
            break;

        }
        case 0:{
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char ** shape13 = new char *[2];

            shape13[0] = new char[3];
            shape13[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape13[0][i] = 'T';
            }
            shape13[1][0] = ' ';
            shape13[1][1] = 'T';
            shape13[1][2] = ' ';

            rturnnum = 0;
            lturnnum = 0;

              rownum = 2;
             columnnum= 3;
             shape = shape13;
            break;
        }
        case 1:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape14 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape14[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape14[i][0] = 'T';
            }

            shape14[0][1] = ' ';
            shape14[1][1] = 'T';
            shape14[2][1] = ' ';
              rownum = 3;
              columnnum= 2;
          shape= shape14;
            break;
        }
        case 2:
         {
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape15 = new char *[2];

            shape15[0] = new char[3];
            shape15[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape15[1][i] = 'T';
            }
            shape15[0][0] = ' ';
            shape15[0][1] = 'T';
            shape15[0][2] = ' ';
              rownum = 2;
              columnnum= 3;
             shape = shape15;
            break;
         }
        }
    }else{
        
       
        switch (rturnnum - lturnnum) // since "T" has 4 options I check them separetly
        {

        case 1:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape11 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape11[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape11[i][1] = 'T';
            }

            shape11[0][0] = ' ';
            shape11[1][0] = 'T';
            shape11[2][0] = ' ';
            
              rownum = 3;
             columnnum= 2;
        
          shape = shape11;
            break;
        }
        case 4:
        {
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char ** shape12 = new char *[2];

            shape12[0] = new char[3];
            shape12[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape12[0][i] = 'T';
            }
            shape12[1][0] = ' ';
            shape12[1][1] = 'T';
            shape12[1][2] = ' ';
              rownum = 2;
              columnnum= 3;
     
            shape = shape12;
            rturnnum = 0;
            lturnnum = 0;
            break;

        }
        case 0:{
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char ** shape13 = new char *[2];

            shape13[0] = new char[3];
            shape13[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape13[0][i] = 'T';
            }
            shape13[1][0] = ' ';
            shape13[1][1] = 'T';
            shape13[1][2] = ' ';

            rturnnum = 0;
            lturnnum = 0;

              rownum = 2;
             columnnum= 3;
             shape = shape13;
            break;
        }
        case 3:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape14 = new char *[3];

            for (int i = 0; i < 3; i++)
            {
                shape14[i] = new char[2];
            }

            for (int i = 0; i < 3; i++)
            {
                shape14[i][0] = 'T';
            }

            shape14[0][1] = ' ';
            shape14[1][1] = 'T';
            shape14[2][1] = ' ';
              rownum = 3;
              columnnum= 2;
             shape= shape14;
            break;
        }
        case 2:
         {
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape15 = new char *[2];

            shape15[0] = new char[3];
            shape15[1] = new char[3];

            for (int i = 0; i < 3; i++)
            {
                shape15[1][i] = 'T';
            }
            shape15[0][0] = ' ';
            shape15[0][1] = 'T';
            shape15[0][2] = ' ';
              rownum = 2;
              columnnum= 3;
          shape = shape15;
            break;
         }
        }
    }

        break;

    case tetrominos::S:
        switch (abs(rturnnum - lturnnum))
        { // I check this way turn numbers because "S" only has 2 options
        case 2:
        {
            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape16 = new char *[2];

            shape16[0] = new char[3];
            shape16[1] = new char[3];

            shape16[0][0] = ' ';
            shape16[0][1] = 'S';
            shape16[0][2] = 'S';

            shape16[1][0] = 'S';
            shape16[1][1] = 'S';
            shape16[1][2] = ' ';
              rownum = 2;
             columnnum= 3;
           
            rturnnum = 0;
            lturnnum = 0;
            shape=shape16;
            break;
        }
        case 1:
             {
            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

           char**  shape17 = new char *[3];

            shape17[0] = new char[2];
            shape17[1] = new char[2];
            shape17[2] = new char[2];

            shape17[0][0] = 'S';
            shape17[0][1] = ' ';

            shape17[1][0] = 'S';
            shape17[1][1] = 'S';

            shape17[2][0] = ' ';
            shape17[2][1] = 'S';
              rownum = 3;
             columnnum= 2;
             shape=shape17;
          
            break;
        }
        }
        break;

    case tetrominos::Z:

        switch (abs(rturnnum - lturnnum))
        { // I check this way turn numbers because "Z" only has 2 options
        case 2:{

            for (int i = 0; i < 3; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape18 = new char *[2];

            shape18[0] = new char[3];
            shape18[1] = new char[3];

            shape18[0][0] = 'Z';
            shape18[0][1] = 'Z';
            shape18[0][2] = ' ';

            shape18[1][0] = ' ';
            shape18[1][1] = 'Z';
            shape18[1][2] = 'Z';
              rownum = 2;
              columnnum= 3;
            /*  shape.clear();
              shape.push_back({'Z', 'Z', ' '});
              shape.push_back({' ', 'Z', 'Z'});
            */

            shape= shape18;
            rturnnum = 0;
            lturnnum = 0;
            break;
        }
        case 1:{

            for (int i = 0; i < 2; i++)
            {
                delete[] shape[i];
            }

            delete[] shape;

            char** shape19 = new char *[3];

            shape19[0] = new char[2];
            shape19[1] = new char[2];
            shape19[2] = new char[2];

            shape19[0][1] = 'Z';
            shape19[0][0] = ' ';

            shape19[1][0] = 'Z';
            shape19[1][1] = 'Z';

            shape19[2][0] = 'Z';
            shape19[2][1] = ' ';
            
              rownum = 3;
              columnnum= 2;
              shape=shape19;
            /*  shape.clear();
              shape.push_back({' ', 'Z'});
              shape.push_back({'Z', 'Z'});
              shape.push_back({'Z', ' '});
  */
            break;
        }
        }

        break;
    }
}

void tetromino::setturnr(int a)
{
    rturnnum = a;
}
void tetromino::setturnl(int a)
{
    lturnnum = a;
}
int tetromino::getrow ()const
{
    return rownum;
}
int tetromino::getcolumn() const
{
    return columnnum;
}

void tetromino::print()
{
    for (int i = 0; i < rownum; i++)
    {
       for (int m = 0; m < columnnum; m++)
       {
       cout<<shape[i][m];
       }
       cout<<endl;
    }
      cout<<endl;
}

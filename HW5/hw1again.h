#include <iostream>
#include <vector>

using namespace std;

enum class tetrominos {I,O,T,J,L,S,Z};   // Enum type for tetrominos

enum class direction {right,left};   // Enum type for direction to use as a parameter




class tetromino   
    {
        public:
            tetromino( tetrominos tetrominochoice); // Constructor with paramter
            tetromino();                                             // Default constructor
            void rotate(direction turnWay);//rotates tetrominos
            void setShape(tetrominos tetrominochoice); //sets shape
            char** shape;  
            
            int getturnr() ;
            int getturnl() ;
             int getrow() const;
             int getcolumn() const;
            
            tetrominos gettype();
            void setturnr(int a);
            void setturnl(int a);
            void print();
           
        private:
          
         int rownum= 0 ;
         int columnnum =0 ;
         int rturnnum = 0;
         int lturnnum = 0;  
         tetrominos type; 
    };
    
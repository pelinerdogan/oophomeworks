#include <iostream>
#include <vector>

using namespace std;

enum class tetrominos {I,O,T,J,L,S,Z};   // Enum type for tetrominos

enum class direction {right,left};   // Enum type for direction to use as a parameter




class tetromino   // Inner Class
    {
        public:
            tetromino( tetrominos tetrominochoice); // Constructor with paramter
            tetromino();                                             // Default constructor
            void rotate(direction turnWay);//rotates tetrominos
            void setShape(tetrominos tetrominochoice); //sets shape
            void print() const;
            static void printfullfit(const vector<vector<char>> &vect) ;
            bool canFit(tetromino &other) ;
            static void tetrominofit(vector<vector<char>> &vec, vector<tetromino> &vectetromino);// modifies a vector that shows fitted version of tetrominos
            

        private:
         vector<vector<char>> shape;   
    
         int rturnnum = 0;
         int lturnnum = 0;  
         tetrominos type; 
    };
    
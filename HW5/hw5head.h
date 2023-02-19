#include <iostream>
#include <fstream>
#include <vector>
#include "hw1again.h"
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <string.h>
#include <cmath>
#include <deque>
#include <array>
#include <chrono>

/*

this header is long because I implemented template class in here

*/

using namespace std;

namespace hw5
{

    template <class T> // Since I don't know the return type of the operator overload I used a template
    class abstractTetris
    { // abstract class I used pure virtual functions

    public:
        virtual void draw() = 0;
        virtual void readFromFile(string fname) = 0;
        virtual void writeToFile(string fname) = 0;
        virtual T operator+=(const tetromino &t) = 0;

        virtual void animate(tetromino &t) = 0;
        virtual string lastMove() = 0;
        virtual int numberOfMoves() = 0;

    protected:
        int width = 0;
        int length = 0;
    };

    class TetrisVector : public abstractTetris<TetrisVector>
    {
    public:
        TetrisVector();
        TetrisVector(int width, int height);

        void draw();
        void readFromFile(string fname);
        void writeToFile(string fname);
        TetrisVector operator+=(const tetromino &t);
        void put(int i1, int i2, tetromino t);
        void clean(int i1, int i2, const tetromino t);
        void animate(tetromino &t);
        string lastMove();
        int numberOfMoves() { return numofmoves; };
        vector<vector<bool>> boardbool;

    private:
        string moves = " ";
        int numofmoves = 0;
        vector<vector<char>> board;
    };

    class TetrisArray1D : public abstractTetris<TetrisArray1D>
    {
    public:
        TetrisArray1D();
        TetrisArray1D(int width, int height);
        void draw();
        void readFromFile(string fname);
        void writeToFile(string fname);
        TetrisArray1D operator+=(const tetromino &t);
        void animate(tetromino &t);
        void put(int i1, int i2, tetromino t);
        void clean(int i1, int i2, const tetromino t);
        string lastMove();
        int numberOfMoves() { return numofmoves; };
        void capacityUp(int tsize);
        void endofall()
        {

            free(board);
            free(boardbool);
        };
        bool *boardbool;

    private:
        string moves = " ";
        int numofmoves = 0;
        char *board;
        int size = 1;
    };
    /*
    TetrisAdapter: This class takes a template parameter and behaves like an adaptor class
    just like the stack or queue class of the STL. The parameter classes can be any STL class with
    a random access iterator
    */
    template <class T1>
    class TetrisAdapter : public abstractTetris<TetrisAdapter<T1>>
    {
    public:
        TetrisAdapter(int width, int height);
        TetrisAdapter(){};
        void draw();
        void readFromFile(string fname);
        void writeToFile(string fname);
        TetrisAdapter operator+=(const tetromino &t);
        void animate(tetromino &t);
        string lastMove();
        int numberOfMoves() { return numofmoves; };
        void put(int i1, int i2, tetromino t);
        void clean(int i1, int i2, const tetromino t);
        vector<bool> boardbool;

    private:
        string moves = " ";
        int numofmoves = 0;
        T1 board;
        int width = 0;
        int length = 0;
        typename T1::iterator iter = board.begin();
    };
    /*
     */
    template <class T1>
    void TetrisAdapter<T1>::draw()
    {

        cout << "\x1B[2K"; // for animation
        iter = board.begin();
        for (int i = 0; i < board.size() / width; ++i)
        {

            this_thread::sleep_for(chrono::milliseconds(50));

            for (int m = 0; m < width; ++m)
            {

                cout << *(iter + (width * i) + m); // I USED ITERATOR TO REACH EVERY MEMBER
            }
            cout << endl;
        }
    }

    template <class T1>
    void TetrisAdapter<T1>::writeToFile(string fname)
    {

        iter = board.begin();
        ofstream ofile(fname);

        for (int i = 0; i < (length + 4) * width; i++)
        {

            char ch = *(iter + i); // I used iterator to reach member
            ofile << ch;

            if (i % width == width - 1)
                ofile << "\n";
        }

        ofile.close();
    }

    template <class T1>
    void TetrisAdapter<T1>::readFromFile(string fname)
    {

        char text;

        ifstream in(fname);
        int count = 0;
        int cwidth;
        int clength;
        bool foundfirstplus = false;
        int firstplus;
        int lastplus;
        bool foundwidth = false;

        if (in.is_open())
        {
            while (in.good())
            {

                in.get(text); // reads only game characters

                if (text == '+' || text == ' ' || text == 'L' || text == 'T' || text == 'I' || text == 'J' || text == 'O' || text == 'S' || text == 'Z')
                {

                    board.push_back(text); // both vector and deque class has this function

                    if (text != ' ')
                    {
                        boardbool.push_back(true);
                    }
                    else
                    {
                        boardbool.push_back(false);
                    }

                    count++;
                }
            }

            in.close();
        }

        int k = 0;

        iter = board.begin();
        while (foundfirstplus == false)
        {

            if (*(iter + k) == '+') // usage of random access iterator to calculate width and length
            {

                foundfirstplus = true;
                firstplus = k;
            }
            k++;
        }

        while (foundwidth == false)
        {

            if (*(iter + k) == '+')
            {
                foundwidth = true;
                cwidth = k - firstplus;
            }
            k++;
        }
        width = cwidth + 1;

        for (int i = 0; i < board.size(); ++i)
        {

            if (*(iter + i) == '+')
            {
                clength++;
            }
        }
        length = (clength - (width - 2)) / 2;
    }
    template <class T1>
    TetrisAdapter<T1> TetrisAdapter<T1>::operator+=(const tetromino &t)
    {

        int mid = width / 2 - (t.getcolumn() / 2);
        put(0, mid, t); // ads tetromino on board

        return *this;
    }

    template <class T1>
    void TetrisAdapter<T1>::animate(tetromino &t)
    {

        int moven, rotaten;
        char rotatew, movew;
        bool doner = false;                        // controls rotate
        bool donem = false;                        // controls move
        int mid = width / 2 - (t.getcolumn() / 2); // calculating mid point to put tetromino
        bool rockbottom = false;
        int count = 1;
        bool godown = false;
        *this += t; // adding tetromino

        draw(); // drawing

        clean(0, mid, t); // cleans added tetromino to start animate

        while (doner == false) // checks if it done rotating
        {
            string rot;
            cout << "How many times you like to rotate?" << endl;
            cin >> rot;
            rotaten = stoi(rot); // takes input as string and turns to int to avoid misinputs to create infinite loop
            if (rotaten > 0)
            {

                cout << "which way would you like to rotate? \n (enter r for right or l for left)" << endl;
                cin >> rotatew;

                switch (rotatew) // rotate way
                {
                case 'R': // to right
                case 'r':
                    moves = "rotated right " + rot + " times moved ";
                    for (int i = 0; i < rotaten; ++i)
                        t.rotate(direction::right);
                    mid = width / 2 - (t.getcolumn() / 2); // recalculating mid point
                    put(0, mid, t);

                    draw();

                    clean(0, mid, t);

                    doner = true;

                    break;

                case 'L':
                case 'l': // to left
                    moves = "rotated left " + rot + " times moved ";
                    for (int i = 0; i < rotaten; ++i)
                        t.rotate(direction::left);
                    mid = width / 2 - (t.getcolumn() / 2); // takes input as string and turns to int to avoid misinputs to create infinite loop
                    put(0, mid, t);

                    draw();

                    clean(0, mid, t);
                    doner = true;

                    break;

                default:
                    cout << "Not valid choice ! " << endl;

                    break;
                }
            }
            else if (rotaten == 0)
            {
                moves = "not rotated  moved ";
                doner = true;
            }
            else
            {
                cout << "Not valid choice !" << endl;
            }
        }

        if (width - 2 > t.getcolumn() && length > t.getrow())
        { // checks if it can fit
            int wronginput = 0;
            while (donem == false)
            {

                string mov;
                if (wronginput == 0)
                    cout << "How many times you like to move?" << endl;
                if (wronginput != 0)
                    cout << "Move not possible asking again. How many times you like to move?" << endl;
                cin >> mov;
                wronginput++;
                moven = stoi(mov); // to avoid wrong input to cause infinite loop

                if (moven > 0)
                {
                    cout << "which way would you like to move? \n (enter r for right or l for left)" << endl;
                    cin >> movew;
                    int allr = 9, alll = 1;
                    if (movew == 'r' || movew == 'R')
                    {
                        allr = moven + mid + t.getcolumn();
                    }
                    if (movew == 'l' || movew == 'L')
                    {
                        alll = mid - moven;
                    }

                    if (alll > 0 && allr < width)
                    { // checks if it fits

                        numofmoves += moven;
                        switch (movew)
                        {
                        case 'R':
                        case 'r':
                            moves = moves + mov + " times to right \n";
                            put(0, moven + mid, t);

                            rockbottom = false;
                            count = 1;
                            godown = false;
                            while (false == rockbottom)
                            {

                                for (int i = 0; i < t.getrow(); i++)
                                {

                                    for (int m = 0; m < t.getcolumn(); m++)
                                    {

                                        if (boardbool[((i + count) * width) + mid + m + moven] == true && t.shape[i][m] != ' ') // checks if its full if so stops goin down
                                            godown = true;
                                    }
                                }

                                if (godown == false)
                                {

                                    clean(count - 1, mid + moven, t); // keeps going down

                                    put(count, moven + mid, t);
                                }
                                else
                                {
                                    rockbottom = true;

                                    for (int i = 0; i < t.getrow(); i++)
                                    {

                                        for (int m = 0; m < t.getcolumn(); m++)
                                        {

                                            if (*(iter + ((i + count - 1) * width) + mid + m + moven) != ' ')
                                            {
                                                boardbool[((i + count - 1) * width) + mid + m + moven] = true;
                                            }
                                        }
                                    }
                                }

                                count++;
                                draw();
                                ;
                            }

                            donem = true;

                            break;

                        case 'L':
                        case 'l':
                            moves = moves + mov + " times to left\n";
                            put(0, mid - moven, t);

                            rockbottom = false;
                            count = 1;
                            godown = false;
                            while (false == rockbottom)
                            {

                                for (int i = 0; i < t.getrow(); i++)
                                {

                                    for (int m = 0; m < t.getcolumn(); m++)
                                    {

                                        if (boardbool[((i + count) * width) + mid + m - moven] == true && t.shape[i][m] != ' ') // checks if theres a tetromino or it hitted bottom
                                            godown = true;
                                    }
                                }

                                if (godown == false)
                                {

                                    clean(count - 1, mid - moven, t); // keeps going down

                                    put(count, mid - moven, t);
                                }
                                else
                                {
                                    rockbottom = true; // it founds its place so i add to bool table

                                    for (int i = 0; i < t.getrow(); i++)
                                    {

                                        for (int m = 0; m < t.getcolumn(); m++)
                                        {

                                            if (*(iter + ((i + count - 1) * width) + mid + m - moven) != ' ')
                                                boardbool[((i + count - 1) * width) + mid + m - moven] = true;
                                        }
                                    }
                                }

                                count++;
                                draw();
                            }

                            donem = true;

                            break;

                        default:
                            cout << "Not valid choice !" << endl;

                            break;
                        }
                    }
                }
                else if (moven == 0)
                { // if not move goes straightly down
                    moves = moves + mov + " times \n";
                    rockbottom = false;
                    count = 1;
                    godown = false;

                    while (false == rockbottom)
                    {

                        for (int i = 0; i < t.getrow(); i++)
                        {

                            for (int m = 0; m < t.getcolumn(); m++)
                            {

                                if (boardbool[((i + count) * width) + mid + m] == true && t.shape[i][m] != ' ') // checks if there a tetromino underneath
                                    godown = true;
                            }
                        }

                        if (godown == false)
                        {

                            // keeps going down
                            clean(count - 1, mid, t);

                            put(count, mid, t);
                        }
                        else
                        {
                            rockbottom = true;

                            for (int i = 0; i < t.getrow(); i++)
                            {

                                for (int m = 0; m < t.getcolumn(); m++)
                                {

                                    if (*(iter + ((i + count - 1) * width) + mid + m + moven) != ' ') // if it is done moving adds tetromninno to bool table
                                        boardbool[((i + count - 1) * width) + mid + m] = true;
                                }
                            }
                        }

                        count++;
                        draw();
                    }

                    donem = true;
                }
                else
                {
                    cout << "Not valid choice !" << endl;
                }
            }
        }
        else
        {
            cout << "adding tetromino failed" << endl;
        }
    }

    /*
     */

    template <class T1>
    string TetrisAdapter<T1>::lastMove()
    {

        if (moves.compare(" ") == 0)
        {
            throw "no moves";
        } // exeption handleing without exiting
        else
            return moves;
    }

    template <class T1>
    void TetrisAdapter<T1>::put(int i1, int i2, tetromino t)
    {
        iter = board.begin();
        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                if (t.shape[i][m] != ' ')
                {

                    *(iter + (((i + i1) * width)) + m + i2) = t.shape[i][m];
                }
            }
        }
    }

    template <class T1>
    void hw5::TetrisAdapter<T1>::clean(int i1, int i2, tetromino t)
    { // cleans the tetromino in a given space
        iter = board.begin();

        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                switch (t.gettype())
                {
                case tetrominos::I:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'I')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;
                case tetrominos::J:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'J')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;

                case tetrominos::L:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'L')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;

                case tetrominos::O:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'O')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;

                case tetrominos::S:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'S')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;

                case tetrominos::T:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'T')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;

                case tetrominos::Z:
                    if (*(iter + (((i + i1) * width)) + m + i2) == 'Z')
                        *(iter + (((i + i1) * width)) + m + i2) = ' ';

                    break;
                }
            }
        }
    }

    /*
     */
    template <class T1>
    TetrisAdapter<T1>::TetrisAdapter(int width, int height)
    {

        this->width = width;
        this->length = height;

        for (int i = 0; i < 4; ++i)
        {

            for (int m = 0; m < width; ++m)
            {

                board.push_back(' ');
                boardbool.push_back(false);
            };
        }

        for (int i = 4; i < length + 3; ++i)
        {
            board.push_back('+');
            boardbool.push_back(true);
            for (int m = 0; m < width - 2; ++m)
            {
                board.push_back(' ');
                boardbool.push_back(false);
            }

            board.push_back('+');
            boardbool.push_back(true);
        }

        for (int i = 0; i < width; ++i)
        {
            board.push_back('+');
            boardbool.push_back(true);
        }
    }
}

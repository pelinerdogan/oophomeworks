
#include "hw5head.h"

namespace hw5
{

    TetrisVector::TetrisVector()
    {
    }

    TetrisVector::TetrisVector(int width, int length)
    {
        vector<char> row;
        vector<bool> rowb;
        this->length = length; // making the board
        this->width = width;

        board.reserve(length + 6);
        boardbool.reserve(length + 6);

        for (int i = 0; i < 4; ++i)
        {

            for (int m = 0; m < width; ++m)
            {

                row.push_back(' ');
                rowb.push_back(false);
            }

            board.push_back(row);
            boardbool.push_back(rowb);
            row.clear();
            rowb.clear();
        }

        for (int i = 4; i < length + 3; ++i)
        {
            row.push_back('+');
            rowb.push_back(true);
            for (int m = 0; m < width - 2; ++m)
            {
                row.push_back(' ');
                rowb.push_back(false);
            }

            row.push_back('+');
            rowb.push_back(true);
            board.push_back(row);
            boardbool.push_back(rowb);
            row.clear();
            rowb.clear();
        }

        for (int i = 0; i < width; ++i)
        {
            row.push_back('+');
            rowb.push_back(true);
        }
        board.push_back(row);
        boardbool.push_back(rowb);
        row.clear();
        rowb.clear();
    }

    string TetrisVector::lastMove()
    {

        if (moves.compare(" ") == 0)
        {
            throw "no moves"; // exeption handleing without exit
        }
        else
            return moves;
    }

    void TetrisVector::draw()
    {
        cout << endl
             << endl;

        cout << "\x1B[2K"; // for animation

        for (int i = 0; i < board.size(); ++i)
        {

            this_thread::sleep_for(chrono::milliseconds(50));

            for (int m = 0; m < width; ++m)
            {

                cout << board[i][m];
            }
            cout << endl;
        }
    }

    void TetrisVector::readFromFile(string fname)
    {

        char text;

        ifstream in(fname);
        ifstream in2(fname);

        int count = 0, count2 = 0, count1 = 0;
        int cwidth;
        int clength;
        bool foundfirstplus;
        int firstplus = 0;
        int secondplus;
        bool foundwidth;

        int l = 0, p = 0;
        if (in.is_open())
        {
            while (in.good())
            {

                in.get(text);

                if (text == '+' || text == ' ' || text == 'L' || text == 'T' || text == 'I' || text == 'J' || text == 'O' || text == 'S' || text == 'Z')
                {

                    p++;
                    if (text == '+' && count1 == 1)
                    {

                        count2++;
                    }
                    if (text == '+' && count1 == 0)
                    {

                        count1 = 1;
                        count2 = 0;
                    }

                    if (text != '+' && count1 == 1)
                    {

                        count1 = 0;
                    }
                }
            }

            in.close();
        }

        if (in2.is_open())

        {
            int k = 0, m = 0;
            board.push_back({' ', ' ', ' '});
            board[0].clear();

            while (in2.good())
            {

                in2.get(text);

                if (text == '+' || text == ' ' || text == 'L' || text == 'T' || text == 'I' || text == 'J' || text == 'O' || text == 'S' || text == 'Z')
                {

                    board[k][m] = text;

                    l++;
                    m++;

                    if (l % (count2) == 0 && l != p)
                    {

                        k++;
                        m = 0;

                        board.push_back({' ', ' ', ' '});
                        board[k].clear();
                    }
                }
            }

            length = board.size();
            width = count2;

            in2.close();
        }
    }

    void TetrisVector::writeToFile(string fname)
    {

        ofstream ofile(fname);

        for (int i = 0; i < board.size(); i++)
        {

            for (int j = 0; j < width; j++)
            {
                char ch = board[i][j];
                ofile << ch;
            }

            ofile << "\n";
        }

        ofile.close();
    }

    TetrisVector TetrisVector::operator+=(const tetromino &t)
    {

        int mid = width / 2 - (t.getcolumn() / 2);
        put(0, mid, t); // ads tetromino on board

        return *this;
    }

    void hw5::TetrisVector::put(int i1, int i2, tetromino t) // ads tetromino to given space
    {

        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                if (t.shape[i][m] != ' ')
                {

                    board[i + i1][m + i2] = t.shape[i][m];
                }
            }
        }
    }

    void TetrisVector::animate(tetromino &t)
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
                moves = "not rotated moved ";
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
                            moves = moves + mov + " times to right";
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

                                        if (boardbool[i + count][mid + m + moven] == true && t.shape[i][m] != ' ') // checks if its full if so stops goin down
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

                                            if (board[i + count - 1][mid + m + moven] != ' ')
                                            {
                                                boardbool[i + count - 1][mid + m + moven] = true;
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

                                        if (boardbool[i + count][mid + m - moven] == true && t.shape[i][m] != ' ') // checks if theres a tetromino or it hitted bottom
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

                                            if (board[i + count - 1][mid + m - moven] != ' ')
                                                boardbool[i + count - 1][mid + m - moven] = true;
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

                                if (boardbool[i + count][mid + m] == true && t.shape[i][m] != ' ') // checks if there a tetromino underneath
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

                                    if (board[i + count - 1][mid + m + moven] != ' ') // if it is done moving adds tetromninno to bool table
                                        boardbool[i + count - 1][mid + m] = true;
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

    void hw5::TetrisVector::clean(int i1, int i2, tetromino t)
    {

        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                switch (t.gettype())
                {
                case tetrominos::I:
                    if (board[i + i1][m + i2] == 'I')
                        board[i + i1][m + i2] = ' ';

                    break;
                case tetrominos::J:
                    if (board[i + i1][m + i2] == 'J')
                        board[i + i1][m + i2] = ' ';

                    break;

                case tetrominos::L:
                    if (board[i + i1][m + i2] == 'L')
                        board[i + i1][m + i2] = ' ';

                    break;

                case tetrominos::O:
                    if (board[i + i1][m + i2] == 'O')
                        board[i + i1][m + i2] = ' ';

                    break;

                case tetrominos::S:
                    if (board[i + i1][m + i2] == 'S')
                        board[i + i1][m + i2] = ' ';

                    break;

                case tetrominos::T:
                    if (board[i + i1][m + i2] == 'T')
                        board[i + i1][m + i2] = ' ';

                    break;

                case tetrominos::Z:
                    if (board[i + i1][m + i2] == 'Z')
                        board[i + i1][m + i2] = ' ';

                    break;
                }
            }
        }
    }

    //********************************************************************************

    TetrisArray1D::TetrisArray1D()
    {
    }

    TetrisArray1D::TetrisArray1D(int width, int length)
    {
        size = width * (length + 4);
        this->width = width;
        this->length = length;
        board = (char *)malloc(size * sizeof(char));
        boardbool = (bool *)malloc(size * sizeof(bool));

        for (int i = 0; i < 4 * width; i++)
        {

            board[i] = ' ';
            boardbool[i] = false;
        }

        for (int i = 4 * width; i < size - width; i++)
        {
            if (i % width == 0 || i % width == width - 1)
            {

                board[i] = '+';
                boardbool[i] = true;
            }
            else
            {

                board[i] = ' ';

                boardbool[i] = false;
            }
        }

        for (int i = size - width; i < size; i++)
        {

            board[i] = '+';
            boardbool[i] = true;
        }
    }

    void TetrisArray1D::draw()
    {

        cout << "\x1B[2K"; // for animation

        for (int i = 0; i < size; ++i)
        {
            cout << board[i];

            if (i % width == width - 1)
            {

                this_thread::sleep_for(chrono::milliseconds(50));
                cout << endl;
            }
        }
    }

    void TetrisArray1D::readFromFile(string fname)
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

                    capacityUp(1);

                    board[count] = text;

                    if (text != ' ')
                    {
                        boardbool[count] = true;
                    }
                    else
                    {
                        boardbool[count] = false;
                    }

                    count++;
                }
            }

            in.close();
        }
        size = count;

        int k = 0;

        while (foundfirstplus == false)
        {
            if (board[k] == '+')
            {

                foundfirstplus = true;
                firstplus = k;
            }
            k++;
        }

        while (foundwidth == false)
        {

            if (board[k] == '+')
            {
                foundwidth = true;
                cwidth = k - firstplus;
            }
            k++;
        }
        width = cwidth + 1;

        for (int i = 0; i < size; ++i)
        {

            if (board[i] == '+')
            {
                clength++;
            }
        }
        length = (clength - (width - 2)) / 2;
    }

    void TetrisArray1D::writeToFile(string fname)
    {

        ofstream ofile(fname);

        for (int i = 0; i < (length + 4) * width; i++)
        {

            char ch = board[i];
            ofile << ch;

            if (i % width == width - 1)
                ofile << "\n";
        }

        ofile.close();
    }

    void TetrisArray1D::capacityUp(int tsize) // dynamic memmory capacity increase function
    {

        char *board1 = (char *)malloc(size * sizeof(char));

        bool *boardbool1 = (bool *)malloc(size * sizeof(bool));
        if (size > 1)
        {

            for (int i = 0; i < size; i++)
            {

                board1[i] = board[i];
                boardbool1[i] = boardbool[i];
            }
        }

        size += tsize;

        board = (char *)malloc(size * sizeof(char));
        boardbool = (bool *)malloc(size * sizeof(bool));

        for (int i = 0; i < size; i++)
        {
            board[i] = board1[i];
            boardbool[i] = boardbool1[i];
        }
    }

    void hw5::TetrisArray1D::put(int i1, int i2, tetromino t) // ads tetromino to given space
    {

        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                if (t.shape[i][m] != ' ')
                {

                    board[(((i + i1) * width)) + m + i2] = t.shape[i][m];
                }
            }
        }
    }

    void hw5::TetrisArray1D::clean(int i1, int i2, tetromino t) // deletes tetromino from given space
    {

        for (int i = 0; i < t.getrow(); i++)
        {

            for (int m = 0; m < t.getcolumn(); m++)
            {

                switch (t.gettype())
                {
                case tetrominos::I:
                    if (board[(((i + i1) * width)) + m + i2] == 'I')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;
                case tetrominos::J:
                    if (board[(((i + i1) * width)) + m + i2] == 'J')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;

                case tetrominos::L:
                    if (board[(((i + i1) * width)) + m + i2] == 'L')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;

                case tetrominos::O:
                    if (board[(((i + i1) * width)) + m + i2] == 'O')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;

                case tetrominos::S:
                    if (board[(((i + i1) * width)) + m + i2] == 'S')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;

                case tetrominos::T:
                    if (board[(((i + i1) * width)) + m + i2] == 'T')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;

                case tetrominos::Z:
                    if (board[(((i + i1) * width)) + m + i2] == 'Z')
                        board[(((i + i1) * width)) + m + i2] = ' ';

                    break;
                }
            }
        }
    }

    string TetrisArray1D::lastMove()
    {

        if (moves.compare(" ") == 0)
        {
            throw "no moves"; // exeption handleing without exit
        }

        else
            return moves;
    }

    void TetrisArray1D::animate(tetromino &t)
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
                    moves = "rotated right " + rot + " times, moved ";
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
                    moves = "rotated left " + rot + " times , moved ";
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
                moves = "not rotated moved ";
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

                                            if (board[((i + count - 1) * width) + mid + m + moven] != ' ')
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
                            moves = moves + mov + " times to left \n";
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

                                            if (board[((i + count - 1) * width) + mid + m - moven] != ' ')
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

                                    if (board[((i + count - 1) * width) + mid + m + moven] != ' ') // if it is done moving adds tetromninno to bool table
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

    TetrisArray1D TetrisArray1D::operator+=(const tetromino &t)
    {

        int mid = width / 2 - (t.getcolumn() / 2);
        put(0, mid, t); // ads tetromino on board

        return *this;
    }

    //**********************************

}
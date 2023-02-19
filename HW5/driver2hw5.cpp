#include "hw5head.h"

int main()
{

    char boardchoice;
    cout << "Please enter board choice V for vector 1 for 1D array \nA for adaptor class with vector, D for adaptor class with deque  " << endl;
    cin >> boardchoice;

    switch (boardchoice)
    {
    case 'V':
    case 'v':
    {

        int width = 0, height = 0;
        string w, h;
        srand((unsigned)time(NULL)); // for different randoms
        int randy;
        bool quitted = false;

        cout << "please enter a width and height for the board" << endl;
        while (width < 3)
        {
            cout << " width: ";
            cin >> w;
            width = stoi(w);
        }
        while (height < 3)
        {
            cout << " height: ";
            cin >> h;
            height = stoi(h);
        }
        hw5::TetrisVector a(width, height);

        char x;
        cout << "please enter tetromino type you want to add or you can enter 'R' for random or 'Q' for quitting" << endl;
        while (quitted == false)
        {
            cout << "enter \n";
            cin >> x;
            cout << endl;
            tetromino tet;
            switch (x)
            {
            case 'i':
            case 'I':
                tet.setShape(tetrominos::I);
                a.animate(tet);
                break;
            case 'j':
            case 'J':

                tet.setShape(tetrominos::J);
                a.animate(tet);

                break;
            case 'l':
            case 'L':

                tet.setShape(tetrominos::L);
                a.animate(tet);

                break;
            case 'T':
            case 't':

                tet.setShape(tetrominos::T);
                a.animate(tet);

                break;
            case 'o':
            case 'O':

                tet.setShape(tetrominos::O);
                a.animate(tet);

                break;
            case 's':
            case 'S':

                tet.setShape(tetrominos::S);
                a.animate(tet);

                break;

            case 'z':
            case 'Z':

                tet.setShape(tetrominos::Z);
                a.animate(tet);

                break;

            case 'r':
            case 'R':
                cout << "heye";
                randy = (rand() % 7);
                if (randy == 0)
                {

                    tet.setShape(tetrominos::I);
                    a.animate(tet);
                }
                if (randy == 1)
                {

                    tet.setShape(tetrominos::J);
                    a.animate(tet);
                }
                if (randy == 2)
                {

                    tet.setShape(tetrominos::L);
                    a.animate(tet);
                }
                if (randy == 3)
                {

                    tet.setShape(tetrominos::T);
                    a.animate(tet);
                }
                if (randy == 4)
                {

                    tet.setShape(tetrominos::O);
                    a.animate(tet);
                }
                if (randy == 5)
                {

                    tet.setShape(tetrominos::S);
                    a.animate(tet);
                }
                if (randy == 6)
                {

                    tet.setShape(tetrominos::Z);
                    a.animate(tet);
                }

                break;
            case 'q':
            case 'Q':

                quitted = true;
                break;
            default:

                cout << "try again wrong input" << endl;
                break;
            }

            a.draw();
            bool q = true;
            for (int i = 0; i < width; i++)
            {
                if (a.boardbool[4][i] == false)
                { // ends the game
                    q = false;
                }
            }
            if (q == false)
            {
                for (int i = 0; i < width; i++)
                {
                    if (a.boardbool[3][i] == true)
                    { // ends the game
                        q = true;
                    }
                }
            }

            quitted = q;
        }

        cout << "GAME OVER!" << endl;
    }

    break;

    case '1':

    { /*
       */
        int width = 0, height = 0;
        string w, h;
        srand((unsigned)time(NULL)); // for different randoms
        int randy;
        bool quitted = false;

        cout << "please enter a width and height for the board" << endl;
        while (width < 3)
        {
            cout << " width: ";
            cin >> w;
            width = stoi(w);
        }
        while (height < 3)
        {
            cout << " height: ";
            cin >> h;
            height = stoi(h);
        }
        hw5::TetrisArray1D a(width, height);

        char x;
        cout << "please enter tetromino type you want to add or you can enter 'R' for random or 'Q' for quitting" << endl;
        while (quitted == false)
        {
            cout << "enter \n";
            cin >> x;
            tetromino tet;
            switch (x)
            {
            case 'i':
            case 'I':
                tet.setShape(tetrominos::I);
                a.animate(tet);
                break;
            case 'j':
            case 'J':

                tet.setShape(tetrominos::J);
                a.animate(tet);

                break;
            case 'l':
            case 'L':

                tet.setShape(tetrominos::L);
                a.animate(tet);

                break;
            case 'T':
            case 't':

                tet.setShape(tetrominos::T);
                a.animate(tet);

                break;
            case 'o':
            case 'O':

                tet.setShape(tetrominos::O);
                a.animate(tet);

                break;
            case 's':
            case 'S':

                tet.setShape(tetrominos::S);
                a.animate(tet);

                break;

            case 'z':
            case 'Z':

                tet.setShape(tetrominos::Z);
                a.animate(tet);

                break;

            case 'r':
            case 'R':

                randy = (rand() % 7);
                if (randy == 0)
                {

                    tet.setShape(tetrominos::I);
                    a.animate(tet);
                }
                if (randy == 1)
                {

                    tet.setShape(tetrominos::J);
                    a.animate(tet);
                }
                if (randy == 2)
                {

                    tet.setShape(tetrominos::L);
                    a.animate(tet);
                }
                if (randy == 3)
                {

                    tet.setShape(tetrominos::T);
                    a.animate(tet);
                }
                if (randy == 4)
                {

                    tet.setShape(tetrominos::O);
                    a.animate(tet);
                }
                if (randy == 5)
                {

                    tet.setShape(tetrominos::S);
                    a.animate(tet);
                }
                if (randy == 6)
                {

                    tet.setShape(tetrominos::Z);
                    a.animate(tet);
                }

                break;
            case 'q':
            case 'Q':

                quitted = true;
                break;
            default:

                cout << "try again wrong input" << endl;
            }

            a.draw();
            bool q = true;
            for (int i = 0; i < width; i++)
            {
                if (a.boardbool[(4 * width) + i] == false)
                { // ends the game
                    q = false;
                }
            }
            if (q == false)
            {
                for (int i = 0; i < width; i++)
                {
                    if (a.boardbool[(3 * width) + i] == true)
                    { // ends the game
                        q = true;
                    }
                }
            }

            quitted = q;
        }

        cout << "GAME OVER!" << endl;
        a.endofall();
    }
    break;
    case 'A':
    case 'a':
    {

        int width = 0, height = 0;
        string w, h;
        srand((unsigned)time(NULL)); // for different randoms
        int randy;
        bool quitted = false;

        cout << "please enter a width and height for the board" << endl;
        while (width < 3)
        {
            cout << " width: ";
            cin >> w;
            width = stoi(w);
        }
        while (height < 3)
        {
            cout << " height: ";
            cin >> h;
            height = stoi(h);
        }
        hw5::TetrisAdapter<vector<char>> a(width, height);

        char x;
        cout << "please enter tetromino type you want to add or you can enter 'R' for random or 'Q' for quitting" << endl;
        while (quitted == false)
        {
            cout << "enter \n";
            cin >> x;
            tetromino tet;
            switch (x)
            {
            case 'i':
            case 'I':
                tet.setShape(tetrominos::I);
                a.animate(tet);
                break;
            case 'j':
            case 'J':

                tet.setShape(tetrominos::J);
                a.animate(tet);

                break;
            case 'l':
            case 'L':

                tet.setShape(tetrominos::L);
                a.animate(tet);

                break;
            case 'T':
            case 't':

                tet.setShape(tetrominos::T);
                a.animate(tet);

                break;
            case 'o':
            case 'O':

                tet.setShape(tetrominos::O);
                a.animate(tet);

                break;
            case 's':
            case 'S':

                tet.setShape(tetrominos::S);
                a.animate(tet);

                break;

            case 'z':
            case 'Z':

                tet.setShape(tetrominos::Z);
                a.animate(tet);

                break;

            case 'r':
            case 'R':

                randy = (rand() % 7);
                if (randy == 0)
                {

                    tet.setShape(tetrominos::I);
                    a.animate(tet);
                }
                if (randy == 1)
                {

                    tet.setShape(tetrominos::J);
                    a.animate(tet);
                }
                if (randy == 2)
                {

                    tet.setShape(tetrominos::L);
                    a.animate(tet);
                }
                if (randy == 3)
                {

                    tet.setShape(tetrominos::T);
                    a.animate(tet);
                }
                if (randy == 4)
                {

                    tet.setShape(tetrominos::O);
                    a.animate(tet);
                }
                if (randy == 5)
                {

                    tet.setShape(tetrominos::S);
                    a.animate(tet);
                }
                if (randy == 6)
                {

                    tet.setShape(tetrominos::Z);
                    a.animate(tet);
                }

                break;
            case 'q':
            case 'Q':

                quitted = true;
                break;
            default:

                cout << "try again wrong input" << endl;
            }

            a.draw();
            bool q = true;
            for (int i = 0; i < width; i++)
            {
                if (a.boardbool[(4 * width) + i] == false)
                { // ends the game
                    q = false;
                }
            }
            if (q == false)
            {
                for (int i = 0; i < width; i++)
                {
                    if (a.boardbool[(3 * width) + i] == true)
                    { // ends the game
                        q = true;
                    }
                }
            }

            quitted = q;
        }

        cout << "GAME OVER!" << endl;
    }
    break;
    case 'D':
    case 'd':

    {

        int width = 0, height = 0;
        string w, h;
        srand((unsigned)time(NULL)); // for different randoms
        int randy;
        bool quitted = false;

        cout << "please enter a width and height for the board" << endl;
        while (width < 3)
        {
            cout << " width: ";
            cin >> w;
            width = stoi(w);
        }
        while (height < 3)
        {
            cout << " height: ";
            cin >> h;
            height = stoi(h);
        }
        hw5::TetrisAdapter<vector<char>> a(width, height);

        char x;
        cout << "please enter tetromino type you want to add or you can enter 'R' for random or 'Q' for quitting" << endl;
        while (quitted == false)
        {
            cout << "enter \n";
            cin >> x;
            tetromino tet;
            switch (x)
            {
            case 'i':
            case 'I':
                tet.setShape(tetrominos::I);
                a.animate(tet);
                break;
            case 'j':
            case 'J':

                tet.setShape(tetrominos::J);
                a.animate(tet);

                break;
            case 'l':
            case 'L':

                tet.setShape(tetrominos::L);
                a.animate(tet);

                break;
            case 'T':
            case 't':

                tet.setShape(tetrominos::T);
                a.animate(tet);

                break;
            case 'o':
            case 'O':

                tet.setShape(tetrominos::O);
                a.animate(tet);

                break;
            case 's':
            case 'S':

                tet.setShape(tetrominos::S);
                a.animate(tet);

                break;

            case 'z':
            case 'Z':

                tet.setShape(tetrominos::Z);
                a.animate(tet);

                break;

            case 'r':
            case 'R':

                randy = (rand() % 7);
                if (randy == 0)
                {

                    tet.setShape(tetrominos::I);
                    a.animate(tet);
                }
                if (randy == 1)
                {

                    tet.setShape(tetrominos::J);
                    a.animate(tet);
                }
                if (randy == 2)
                {

                    tet.setShape(tetrominos::L);
                    a.animate(tet);
                }
                if (randy == 3)
                {

                    tet.setShape(tetrominos::T);
                    a.animate(tet);
                }
                if (randy == 4)
                {

                    tet.setShape(tetrominos::O);
                    a.animate(tet);
                }
                if (randy == 5)
                {

                    tet.setShape(tetrominos::S);
                    a.animate(tet);
                }
                if (randy == 6)
                {

                    tet.setShape(tetrominos::Z);
                    a.animate(tet);
                }

                break;
            case 'q':
            case 'Q':

                quitted = true;
                break;
            default:

                cout << "try again wrong input" << endl;
            }

            a.draw();
            bool q = true;
            for (int i = 0; i < width; i++)
            {
                if (a.boardbool[(4 * width) + i] == false)
                { // ends the game
                    q = false;
                }
            }
            if (q == false)
            {
                for (int i = 0; i < width; i++)
                {
                    if (a.boardbool[(3 * width) + i] == true)
                    { // ends the game
                        q = true;
                    }
                }
            }

            quitted = q;
        }

        cout << "GAME OVER!" << endl;
    }
    break;

    default:
        cout << "not a valid choice exiting..." << endl;
    }

    return 0;
}
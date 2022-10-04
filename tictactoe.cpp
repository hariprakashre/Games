#include <iostream>
#include <stdlib.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
using namespace std;
void color_text(char s)
{
    if (s == 'X')
    {
        cout << BLUE << "X" << RESET;
    }
    else if (s == 'O')
    {
        cout << GREEN << "O" << RESET;
    }
    else
        cout << s;
}
class tictactoe
{
    string s = "000000000";
    char p1 = 'X';
    char p2 = 'O';
    int player;
    string name;
    string name2;

public:
    tictactoe(int r, char A, string a, string b = "Computer")
    {
        player = r;
        name = a;
        name2 = b;
        if (A == 'O')
        {
            p1 = 'O';
            p2 = 'X';
        }
    }
    bool player1(int r)
    {
        while (true)
        {
            if (s[r - 1] == '0')
            {
                s[r - 1] = p1;
                return true;
            }
            cout << RED << "Already filled try other" << endl;
            int x;
            cout << GREEN << "Where to fill" << endl;
            cin >> x;
            player1(x);
        }
    }
    bool player2(int r)
    {
        while (true)
        {
            if (s[r - 1] == '0')
            {
                s[r - 1] = p2;
                return true;
            }
            cout << RED << "Already filled try other" << endl;
            int x;
            cout << GREEN << "Where to fill" << endl;
            cin >> x;
            player2(x);
        }
    }
    void print()
    {
        cout << "\n\n\tTic Tac Toe\n\n";

        cout << BLUE << name << " (X)  &  " << name2 << " (O)" << RESET << endl
             << endl;
        cout << endl;

        cout << BLUE << "     |     |     " << RESET << endl;
        cout << "  ";
        color_text(s[0]);
        cout << BLUE << "  |  " << RESET;
        color_text(s[1]);
        cout << BLUE << "  |  " << RESET;
        color_text(s[2]);
        cout << endl;

        cout << BLUE << "_____|_____|_____" << RESET << endl;
        cout << BLUE << "     |     |     " << RESET << endl;

        cout << "  ";
        color_text(s[3]);
        cout << BLUE << "  |  " << RESET;
        color_text(s[4]);
        cout << BLUE << "  |  " << RESET;
        color_text(s[5]);
        cout << endl;

        cout << BLUE << "_____|_____|_____" << RESET << endl;
        cout << BLUE << "     |     |     " << RESET << endl;

        cout << "  ";
        color_text(s[6]);
        cout << BLUE << "  |  " << RESET;
        color_text(s[7]);
        cout << BLUE "  |  " << RESET;
        color_text(s[8]);
        cout << endl;

        cout << BLUE << "     |     |     " << RESET << endl
             << endl;
    }
    int playersbestmove(int r)
    {
        char p;
        if (r == 1)
        {
            char p = p1;
        }
        if (r == 2)
        {
            char p = p2;
        }
        if ((s[0] == p && s[4] == p) || (s[7] == p && s[6] == p) || (s[2] == p && s[5] == p))
        {
            if (s[8] == '0')
                return 9;
        }
        if ((s[2] == p && s[4] == p) || (s[0] == p && s[3] == p) || (s[7] == p && s[8] == p))
        {
            if (s[6] == '0')
                return 7;
        }
        if ((s[0] == p && s[8] == p) || (s[7] == p && s[6] == p) || (s[3] == p && s[5] == p))
        {
            if (s[4] == '0')
                return 5;
        }
        if ((s[4] == p && s[8] == p) || (s[1] == p && s[2] == p) || (s[3] == p && s[6] == p))
        {
            if (s[0] == '0')
                return 1;
        }
        if ((s[0] == p && s[1] == p) || (s[5] == p && s[8] == p) || (s[4] == p && s[6] == p))
        {
            if (s[2] == '0')
                return 3;
        }
        if ((s[0] == p && s[2] == p) || (s[4] == p && s[7] == p))
        {
            if (s[1] == '0')
                return 2;
        }
        if ((s[2] == p && s[8] == p) || (s[3] == p && s[4] == p))
        {
            if (s[5] == '0')
                return 6;
        }
        if ((s[0] == p && s[6] == p) || (s[4] == p && s[5] == p))
        {
            if (s[3] == '0')
                return 4;
        }
        if ((s[6] == p && s[8] == p) || (s[1] == p && s[4] == p))
        {
            if (s[7] == '0')
                return 8;
        }
        while (true)
        {
            srand(time(0));
            int x = rand() % 9;
            if (s[x] == '0')
            {
                return x + 1;
            }
        }
    }
    bool win(int r)
    {
        if (r == 1)
        {
            if ((s[0] == p1 && s[1] == p1 && s[2] == p1) || (s[3] == p1 && s[4] == p1 && s[5] == p1) || (s[6] == p1 && s[7] == p1 && s[8] == p1) || (s[0] == p1 && s[4] == p1 && s[8] == p1) || (s[2] == p1 && s[4] == p1 && s[6] == p1) || (s[0] == p1 && s[3] == p1 && s[6] == p1) || (s[1] == p1 && s[4] == p1 && s[7] == p1) || (s[2] == p1 && s[5] == p1 && s[8] == p1))
            {
                return true;
            }
            return false;
        }
        if (r == 2)
        {
            if ((s[0] == p2 && s[1] == p2 && s[2] == p2) || (s[3] == p2 && s[4] == p2 && s[5] == p2) || (s[6] == p2 && s[7] == p2 && s[8] == p2) || (s[0] == p2 && s[4] == p2 && s[8] == p2) || (s[2] == p2 && s[4] == p2 && s[6] == p2) || (s[0] == p2 && s[3] == p2 && s[6] == p2) || (s[1] == p2 && s[4] == p2 && s[7] == p2) || (s[2] == p2 && s[5] == p2 && s[8] == p2))
            {
                return true;
            }
            return false;
        }
        return false;
    }
    bool full()
    {
        if (s[0] == '0' || s[1] == '0' || s[2] == '0' && s[3] == '0' || s[4] == '0' || s[5] == '0' || s[6] == '0' || s[7] == '0' || s[8] == '0')
        {
            return false;
        }
        return true;
    }
};
int main()
{
    char a;
    int r;
    bool choice;
    cout << BLUE << "MULTIPLAYER/SOLOPLAYER" << endl;
    cout << BLUE << "Type 0 For SOLO, For anything else computer :)" << endl;
    cin >> choice;
    if (!choice)
    {
        cout << "Name of player1" << endl;
        string k;
        cin >> k;
        cout << "Name of player2" << endl;
        string k2;
        cin >> k2;
        cout << "player1 choose your letter(X,O)" << endl;
        char X;
        cin >> X;
        tictactoe t = tictactoe(1, X, k, k2);
        while (true)
        {
            cout << BLUE << "choose position for player one:" << RESET;
            cin >> r;
            t.player1(r);
            t.print();
            if (t.win(1))
            {
                cout << BLUE << "Player 1 won" << RESET << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << RESET << endl;
                return 0;
            }
            cout << "choose position for player two";
            cin >> r;
            t.player2(r);
            t.print();
            if (t.win(1))
            {
                cout << BLUE << "Player 2 won" << RESET << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << RESET << endl;
                return 0;
            }
        }
    }
    cout << "Name of player1" << endl;
    string k;
    cin >> k;
    cout << BLUE << "Select the character you need(X OR 0):" << endl;
    cin >> a;
    cout << BLUE << "Select the position to be played(1 or 2):" << endl;
    cin >> r;
    tictactoe t = tictactoe(r, a, k);
    t.print();
    if (r == 1)
    {
        int x;
        while (true)
        {
            int r;
            cout << GREEN << "Where to fill" << endl;
            cin >> x;
            t.player1(x);
            t.print();
            if (t.win(1))
            {
                cout << GREEN << "you won" << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << endl;
                return 0;
            }
            r = t.playersbestmove(2);
            t.player2(r);
            t.print();
            if (t.win(2))
            {
                cout << RED << "You lost" << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << endl;
                return 0;
            }
        }
    }
    if (r == 2)
    {
        int x;
        while (true)
        {
            int r;
            r = t.playersbestmove(1);
            t.player2(r);
            t.print();
            if (t.win(2))
            {
                cout << RED << "You lost" << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << endl;
                return 0;
            }
            cout << GREEN << "Where to fill" << endl;
            cin >> x;
            t.player1(x);
            t.print();
            if (t.win(1))
            {
                cout << GREEN << "you won" << endl;
                return 0;
            }
            if (t.full())
            {
                cout << RED << "Its full" << endl;
                return 0;
            }
        }
    }
}
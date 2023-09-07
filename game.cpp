/*This game is developed by the greatest developers of all time namely
Utsav Vasoya and Mrudul Dhaduk on the auspicious date of 20/08/23 within 90 minutes */

#include <iostream>
using namespace std;

class game
{
    char gameboard[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};

public:
    friend void playGame();
    void displaygameboard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << gameboard[i][j] << " ";
            }
            cout << endl;
        }
    }
    void input(char x)
    {
        int i, j;
        if (x == 'O')
        {
            while (true)
            {
                cout << "Player O's turn. Enter the position where you want to mark: ";
                cin >> i >> j;
                if (gameboard[i][j] == '_')
                {
                    gameboard[i][j] = 'O';
                    break;
                }
                else
                {
                    cout << "The position is already occupied. Enter again!" << endl;
                }
            }
        }
        else
        {
            while (true)
            {
                cout << "Player X's turn. Enter the position where you want to mark: ";
                cin >> i >> j;
                if (gameboard[i][j] == '_')
                {
                    gameboard[i][j] = 'X';
                    break;
                }
                else
                {
                    cout << "The position is already occupied. Enter again!" << endl;
                }
            }
        }
    }
    bool winCheck()
    {
        for (int i = 0; i < 3; i++)
        {
            if ((gameboard[i][0] == gameboard[i][1]) && (gameboard[i][1] == gameboard[i][2]) && (gameboard[i][2] == 'X'))
            {
                cout << "Hurray! " << gameboard[i][0] << " Won" << endl;
                return true;
            }
            if ((gameboard[0][i] == gameboard[1][i]) && (gameboard[1][i] == gameboard[2][i]) && (gameboard[2][i] == 'O'))
            {
                cout << "Hurray! " << gameboard[0][i] << " Won" << endl;
                return true;
            }
            if ((gameboard[i][0] == gameboard[i][1]) && (gameboard[i][1] == gameboard[i][2]) && (gameboard[i][2] == 'O'))
            {
                cout << "Hurray! " << gameboard[i][0] << " Won" << endl;
                return true;
            }
            if ((gameboard[0][i] == gameboard[1][i]) && (gameboard[1][i] == gameboard[2][i]) && (gameboard[2][i] == 'X'))
            {
                cout << "Hurray! " << gameboard[0][i] << " Won" << endl;
                return true;
            }
        }
        if ((gameboard[0][0] == gameboard[1][1]) && (gameboard[1][1] == gameboard[2][2]) && (gameboard[2][2] == 'X'))
        {
            cout << "Hurray! " << gameboard[0][0] << " Won" << endl;
            return true;
        }
        if ((gameboard[0][2] == gameboard[1][1]) && (gameboard[1][1] == gameboard[2][0]) && (gameboard[2][0] == 'X'))
        {
            cout << "Hurray! " << gameboard[2][0] << " Won" << endl;
            return true;
        }
        if ((gameboard[0][0] == gameboard[1][1]) && (gameboard[1][1] == gameboard[2][2]) && (gameboard[2][2] == 'O'))
        {
            cout << "Hurray! " << gameboard[0][0] << " Won" << endl;
            return true;
        }
        if ((gameboard[0][2] == gameboard[1][1]) && (gameboard[1][1] == gameboard[2][0]) && (gameboard[2][0] == 'O'))
        {
            cout << "Hurray! " << gameboard[2][0] << " Won" << endl;
            return true;
        }
        return false;
    }
};
void playGame()
{   game o;
    cout << "Who wants to start first ? X or O" << endl;
    char y, player;
    while (true)
    {
        cin >> y;

        if (y == 'X')
        {
            player = 'X';
            break;
        }
        else if (y == 'O')
        {
            player = 'O';
            break;
        }
        else
        {
            cout << "Enter valid character as suggested in the instruction" << endl;
        }
    }
    bool x;
    for (int k = 0; k < 9; k++)
    {
        o.input(player);
        o.displaygameboard();
        x = o.winCheck();
        if (x == true)
        {
            return;
        }
        if (player == 'O')
        {
            player = 'X';
        }
        else
        {
            player = 'O';
        }
    }
    x = o.winCheck();
    if (x == false)
    {
        cout << "The game is drawn" << endl;
    }
}
int main()
{
    playGame();
    cout << "Do you want to play again? if Yes enter Y or enter N if No" << endl;
    char x;
    cin >> x;
    if (x == 'Y' || x == 'y')
    {
        main();
    }
    return 0;
}
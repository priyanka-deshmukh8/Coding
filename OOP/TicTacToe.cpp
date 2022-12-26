//Program by Priyanka

#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class TicTacToe
{
private:
    int arr[3][3];  //2d array of 3 by 3
    int playerTurn; // it will be either 1 or 2

    void drawarr();     // to generate arr layout
    int checkWin();     //to check winner
    void playerMove();  //funtion to make player move
    bool checkDraw();   //if result is true match will draw
    bool checkResult(); //to  check result
    //these 4 function are declared as private for data hiding
public:
    TicTacToe();     //constructor
    void playGame(); // it will take return checkresult function if any player won(true return value) then player move function stop
};
TicTacToe ::TicTacToe() //to initialize all element as 0
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            arr[i][j] =0 ;
    }
    srand(time(0));
    playerTurn = rand() % 2 + 1; // rand will generate either 1 or 2 for player turn
    
}
void TicTacToe::playGame()
{
    while (1)
    {
        system("cls");
        drawarr();         // arr layoot
        playerMove();      // player move
        if (checkResult()) //if check result function return return true(if any player won) then loop will break
            break;         //to break loop
    }
    cout << endl; //awe hi de diya
}
void TicTacToe::drawarr()
{
    int i;
    cout << "  _____________________________________________________________" << endl //to print message
         << endl;
    cout << "  \n  Player 1(1)           Vs           Player 2(2)" << endl //to print message
         << endl;

    for (i = 0; i < 3; i++)
    {
        cout << " "; //just for giving space
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
            if (j == 2)
                continue;
            cout << "  |   ";
        }
        if (i == 2)
            continue;
        cout << endl
             << "____|______|_____" << endl
             << "    |      |    " << endl;
    }
    if(checkWin() == -1)
    {cout << endl
         << "\n\n******Turn Player" << playerTurn <<"******"<< endl
         << endl;}
}
void TicTacToe ::playerMove()
{
    int row, col;
    bool correctMove = false; //initialise correct move with false
    cout << endl
         << endl
         << "Make your Move" << endl;
    while (!correctMove) //while true
    {
        cout << "Enter row(0-2):";
        cin >> row;
        cout << "Enter col (0-2):";
        cin >> col;

        if ((row <= 2 && row >= 0) && (col >= 0 && col <= 2))
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (arr[row][col] == 0)         //to check if the place is filled with 0
                    arr[row][col] = playerTurn; //fill that place with playerturn value 
                    correctMove = true;           //correct move will assigned to true

                    playerTurn++;       // player turn value will increment by one
                    if (playerTurn > 2) //if value after increment become 3
                        playerTurn = 1; //then value will become 1
                }
            }
        }
        if(correctMove)
        cout<<"Wrong Input,please enter again"<<endl;

    }
      /*  if (row == 0 && col == 0)
        {
            arr[0][0] = playerTurn;
        }
        else if (row == 0 && col == 1)
        {
            arr[0][1] = playerTurn;
        }
        else if (row == 0 && col == 2)
        {
            arr[0][2] = playerTurn;
        }
        else if (row == 1 && col == 0)
        {
            arr[1][0] = playerTurn;
        }
        else if (row == 0 && col == 0)
        {
            arr[1][1] = playerTurn;
        }
        else if (row == 1 && col == 2)
        {
            arr[1][2] = playerTurn;
        }
        else if (row == 2 && col == 0)
        {
            arr[2][0] = playerTurn;
        }
        else if (row == 2 && col == 1)
        {
            arr[2][1] = playerTurn;
        }
        else if (row == 2 && col == 2)
        {
            arr[2][2] = playerTurn;
        }
        correctMove=true;
         
    }
    playerTurn++;       // player turn value will increment by one
    if (playerTurn > 2) //if value after increment become 3
    playerTurn = 1; //then value will become 1
*/
}
bool TicTacToe ::checkResult() //this function will return either true or false
{
    int check = checkWin(); //variable check  store the value of player (1 or 2 or -1) return by checkWin() function
    switch (check)
    {
    case 1:

        drawarr();
        cout << endl
             << "\n\nPlayer 1 Won!"; //if return was player 1
        return true; 
        break;            //value will return to playGame function
    case 2:

        drawarr();
        cout << endl
             << "\n\nPlayer 2 Won!"; //if return was player 2
        return true;
        break;
    case -1:
        if (checkDraw()) //if checkDraw() is returning true
        {

            drawarr();
            cout << endl
                 << endl
                 << "\n\n__________Match Drawn____________";
            return true;
        }
        break;
    }
    return false; // returning false to playGame() function
}

int TicTacToe::checkWin() //to check player is won or not
{
    for (int player = 1; player < 3; player++)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((arr[i][0] == player) && (arr[i][1] = player) && (arr[i][2] == player))
                return player;
            if ((arr[0][i] == player) && (arr[1][i] = player) && (arr[2][i] == player))
                return player;
        }
        if ((arr[0][0] == player) && (arr[1][1] = player) && (arr[2][2] == player))
            return player;
        if ((arr[0][2] == player) && (arr[1][1] = player) && (arr[2][0] == player))
            return player;
    }
    return -1; //it will return -1 to checkResult function
}
bool TicTacToe::checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
                return false; //value will return to case -1 in checkresult() function
        }
    }
    return true;
}
int main(void)
{
    cout<<"\t\t\t Welcome\n\t         ********* Tic--Tac--Toe ********\n";
    
    TicTacToe t;  //to generate object t of class TicTacToe
    t.playGame(); //this function is managing all other task performing functions
    exit(0);      //stop the working
}
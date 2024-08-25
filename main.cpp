#include <iostream>
#include <unistd.h>

static int player_turn = 1;

using namespace std;

void Loading()
{
    int i = 0;
    cout << "\n Loading";
    while (i++ < 3)
    {
        cout << "." << flush;
        usleep(300 * 1000);
    }
    system("clear");
}

class tictactoe
{
private:
    char box[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string P1;
    string P2;

public:
    void playboard();
    void mainmenu();
    bool rules();
    int playerinput(char);
    void position(char);
};

void tictactoe::playboard()
{
    cout << "     ||     ||     \n";
    cout << "  " << box[0][0] << "  " << "||" << "  " << box[0][1] << "  " << "||"<< "  " << box[0][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[1][0] << "  "<< "||" << "  " << box[1][1] << "  " << "||" << "  " << box[1][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[2][0] << "  " << "||" << "  " << box[2][1] << "  " << "||" << "  " << box[2][2] << "  \n";
    cout << "     ||     ||     \n";
}

void tictactoe::mainmenu()
{
    playboard();
    cout << "\n\nPress Enter to start the game!" << flush;
    
    system("read");
    system("clear");
    Loading();
    cout << "\t---------------------\n";
    cout << "\t---------------------\n";
    cout << "\t     PLAYER INFO\n";
    cout << "\t---------------------\n";
    cout << "\t---------------------\n\n\n";
    
    cout <<"Name of Player 1: ";
    getline(cin >> ws, P1);
    cout << "Name of Player 2: ";
    getline(cin >> ws, P2);
    cout << "\nLet's Start!" << flush;
    system("read");
    system("clear");
    Loading();
    
    playboard();
    cout << "\n'O' is assigned to " << P1 << "\n";
    cout << "'X' is assigned to " << P2 << "\n\n";
    cout << P1 << " will start first!" << endl;
    system("read");
    system("clear");
}

bool tictactoe::rules()
{
    for (int i = 0; i < 3; i++)
    {
        if((box[i][0] == 'O' && box[i][1] == 'O' && box[i][2] == 'O') ||
           (box[0][i] == 'O' && box[1][i] == 'O' && box[2][i] == 'O'))
        {
            system("clear");
            playboard();
            cout << "Hurray! " << P1 << " Won!" << endl;
            return true;
        }
        
        else if((box[i][0] == 'X' && box[i][1] == 'X' && box[i][2] == 'X') ||
                (box[0][i] == 'X' && box[1][i] == 'X' && box[2][i] == 'X'))
        {
            system("clear");
            playboard();
            cout << "Hurray! " << P2 << " Won!" << endl;
            return true;
        }
    }
    
    if(box[0][0] == 'O' && box[1][1] == 'O' && box[2][2] == 'O')
    {
        system("clear");
        playboard();
        cout << "Hurray! " << P1 << " Won!" << endl;
        return true;
    }

    else if(box[0][0] == 'X' && box[1][1] == 'X' && box[2][2] == 'X')
    {
        system("clear");
        playboard();
        cout << "Hurray! " << P1 << " Won!" << endl;
        return true;
    }
    return false;
}

int tictactoe::playerinput(char OX)
{
    playboard();
    int T;
    
    if(OX == 'O')
        cout << "\nIt's your turn " << P1 << "\n"; 

    else if(OX == 'X')
        cout << "\nIt's your turn " << P2 << "\n";
    
    cout << "Enter the desired '" << OX << "' position: ";
    cin >> T;
    return T;
}

void tictactoe::position(char OX)
{
loop:
    switch(playerinput(OX))
    {
        case 1:
            box[0][0] = OX;
            return;
        
        case 2:
            box[0][1] = OX;
            return;
        
        case 3:
            box[0][2] = OX;
            return;

        case 4:
            box[1][0] = OX;
            return;
        
        case 5:
            box[1][1] = OX;
            return;
        
        case 6:
            box[1][2] = OX;
            return;
        
        case 7:
            box[2][0] = OX;
            return;
        
        case 8:
            box[2][1] = OX;
            return;
        
        case 9:
            box[2][2] = OX;
            return;
    }

    system("clear");
    cout << "Enter available number from the board!" << endl;
    system("read");
    goto loop;
    return;
}


int main()
{
    system("clear");

    tictactoe game;
    game.mainmenu();
    int i;
    char OX;
    for(i = 0; i < 9; i++)
    {
        if(player_turn % 2 == 1)
            OX = 'O';
        else if(player_turn % 2 == 0)
            OX = 'X';
        game.position(OX);
        cout << flush;
        player_turn++;
        if(game.rules())
            break;
        system("clear");
    } 
    if(i == 9)
    {
        system("clear");
        game.playboard();
        cout << "\nGame is Draw!" << endl;
    }
    system("read");
    system("clear");
}

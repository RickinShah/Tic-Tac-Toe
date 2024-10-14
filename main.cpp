#include <iostream>
#include <unistd.h>

using namespace std;

static int playerTurn = 0;

void Loading() {
    int i = 0;
    cout << "\n Loading";
    while (i++ < 3) {
        cout << "." << flush;
        usleep(300 * 600);
    }
    system("clear");
}

class TicTacToe {
private:
    char box[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string P[2];

public:
    void playboard();
    void mainMenu();
    bool rules();
    int playerInput(char);
    void position(char);
};

void TicTacToe::playboard() {
    cout << "     ||     ||     \n";
    cout << "  " << box[0][0] << "  " << "||" << "  " << box[0][1] << "  "
         << "||" << "  " << box[0][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[1][0] << "  " << "||" << "  " << box[1][1] << "  "
         << "||" << "  " << box[1][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[2][0] << "  " << "||" << "  " << box[2][1] << "  "
         << "||" << "  " << box[2][2] << "  \n";
    cout << "     ||     ||     " << endl;
}

void TicTacToe::mainMenu() {
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

    for (int i = 0; i < 2; i++) {
        cout << "Name of Player " << i + 1 << ": ";
        getline(cin >> ws, P[i]);
    }
    cout << "\nLet's Start!" << flush;
    system("read");
    system("clear");
    Loading();

    playboard();
    cout << "\n'O' is assigned to " << P[0] << "\n";
    cout << "'X' is assigned to " << P[1] << "\n\n";
    cout << P[0] << " will start first!" << endl;
    system("read");
    system("clear");
}

bool TicTacToe::rules() {
    for (int i = 0; i < 3; i++) {
        if ((box[i][0] == 'O' && box[i][1] == 'O' && box[i][2] == 'O') ||
            (box[0][i] == 'O' && box[1][i] == 'O' && box[2][i] == 'O')) {
            system("clear");
            playboard();
            cout << "Hurray! " << P[0] << " Won!" << endl;
            return true;
        }

        else if ((box[i][0] == 'X' && box[i][1] == 'X' && box[i][2] == 'X') ||
                 (box[0][i] == 'X' && box[1][i] == 'X' && box[2][i] == 'X')) {
            system("clear");
            playboard();
            cout << "Hurray! " << P[1] << " Won!" << endl;
            return true;
        }
    }

    if ((box[0][0] == 'O' && box[1][1] == 'O' && box[2][2] == 'O') ||
        (box[0][2] == 'O' && box[1][1] == 'O' && box[2][0] == 'O')) {
        system("clear");
        playboard();
        cout << "Hurray! " << P[0] << " Won!" << endl;
        return true;
    }

    else if ((box[0][0] == 'X' && box[1][1] == 'X' && box[2][2] == 'X') ||
             (box[0][2] == 'X' && box[1][1] == 'X' && box[2][0] == 'X')) {
        system("clear");
        playboard();
        cout << "Hurray! " << P[1] << " Won!" << endl;
        return true;
    }
    return false;
}

int TicTacToe::playerInput(char OX) {
    playboard();
    int pos;

    if (OX == 'O')
        cout << "\nIt's your turn " << P[0] << "\n";

    else
        cout << "\nIt's your turn " << P[1] << "\n";

    cout << "Enter the desired '" << OX << "' position: ";
    cin >> pos;
    return pos;
}

void TicTacToe::position(char OX) {
    int isValidPos = false;
    do {
        int pos = playerInput(OX);
        int cols = (pos - 1) % 3;
        int row = (pos - 1) / 3;

        if ((pos > 0 && pos < 10) &&
            (box[row][cols] != 'X' && box[row][cols] != 'O')) {
            box[row][cols] = OX;
            isValidPos = true;
        } else {
            cout << "\nEnter available number from the board!" << endl;
            system("read");
            system("clear");
        }
    } while (!isValidPos);
}

int main() {
    system("clear");

    char OX = 'O';
    bool isWinner = false;
    TicTacToe tictactoe;

    tictactoe.mainMenu();

    for (int i = 0; i < 9; i++) {
        OX = playerTurn % 2 ? 'X' : 'O';
        tictactoe.position(OX);

        if (playerTurn > 3) {
            isWinner = tictactoe.rules();
            if (isWinner)
                break;
        }

        playerTurn++;
        system("clear");
    }

    if (!isWinner) {
        system("clear");
        tictactoe.playboard();
        cout << "\nGame is Draw!" << endl;
    }

    system("read");
    system("clear");
}

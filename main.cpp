#include <unistd.h>
#include <iostream>
#include <limits>

using std::string, std::cout, std::endl, std::cin, std::flush, std::ws;


class TicTacToe {
   private:
    string P[2];
    char   box[3][3]  = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int    playerTurn = 0;
    char   OX         = 'O';
    void   Loading();

   public:
    int  getPlayerTurn() { return playerTurn; }
    void setPlayerTurn(int playerTurn) { this->playerTurn = playerTurn; }
    char getOX() { return OX; }
    void setOX(char OX) { this->OX = OX; }
    void playboard();
    void mainMenu();
    bool rules(const char);
    int  playerInput(const char);
    void position(const char);
    bool restartGame();
    void clearBoard();
};

void TicTacToe::Loading() {
    constexpr int loadingDelay = 180000;
    cout << "\n Loading";
    for (int i = 0; i < 3; ++i) {
        cout << "." << flush;
        usleep(loadingDelay);
    }
    system("clear");
}

void TicTacToe::playboard() {
    cout << "     ||     ||     \n";
    cout << "  " << box[0][0] << "  " << "||" << "  " << box[0][1] << "  " << "||" << "  "
         << box[0][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[1][0] << "  " << "||" << "  " << box[1][1] << "  " << "||" << "  "
         << box[1][2] << "  \n";
    cout << "     ||     ||     \n";
    cout << "-----||-----||-----\n";
    cout << "     ||     ||     \n";
    cout << "  " << box[2][0] << "  " << "||" << "  " << box[2][1] << "  " << "||" << "  "
         << box[2][2] << "  \n";
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

bool TicTacToe::rules(const char player) {
    string playerName = player == 'O' ? P[0] : P[1];
    for (int i = 0; i < 3; i++) {
        if ((box[i][0] == player && box[i][1] == player && box[i][2] == player) ||
            (box[0][i] == player && box[1][i] == player && box[2][i] == player)) {
            system("clear");
            playboard();
            cout << "\nHurray! " << playerName << " Won!" << endl;
            return true;
        }
    }

    if ((box[0][0] == player && box[1][1] == player && box[2][2] == player) ||
        (box[0][2] == player && box[1][1] == player && box[2][0] == player)) {
        system("clear");
        playboard();
        cout << "\nHurray! " << playerName << " Won!" << endl;
        return true;
    }

    return false;
}

int TicTacToe::playerInput(const char OX) {
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

void TicTacToe::position(const char OX) {
    int isValidPos = false;
    do {
        int pos  = playerInput(OX);
        int cols = (pos - 1) % 3;
        int row  = (pos - 1) / 3;

        if ((pos > 0 && pos < 10) && (box[row][cols] != 'X' && box[row][cols] != 'O')) {
            box[row][cols] = OX;
            isValidPos     = true;
        } else {
            cout << "\nEnter available number from the board!" << endl;
            system("read");
            system("clear");
        }
    } while (!isValidPos);
}

bool TicTacToe::restartGame() {
    int restart = 0;
    playboard();

    cout << "\nRestart Game? \n"
         << "1. Restart\n"
         << "2. Exit\n\n"
         << "Enter your choice: ";
    while (!(cin >> restart) || (restart < 1 || restart > 2)) {
        cout << "Invalid input. Enter 1 to restart or 2 to exit: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    clearBoard();
    return restart == 1 ? true : false;
}

void TicTacToe::clearBoard() {
    char num = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            box[i][j] = num++;
        }
    }
}

int main() {
    system("clear");

    constexpr size_t maxTurns = 9;
    TicTacToe        ticTacToe;
    bool             start = true;

    while (start) {
        ticTacToe.mainMenu();
        ticTacToe.setOX('O');
        ticTacToe.setPlayerTurn(0);
        bool isWinner = false;

        for (size_t i = 0; i < maxTurns; i++) {
            ticTacToe.setOX(ticTacToe.getPlayerTurn() % 2 ? 'X' : 'O');
            ticTacToe.position(ticTacToe.getOX());

            const size_t minimumTurnsForRules = 3;
            if (ticTacToe.getPlayerTurn() > minimumTurnsForRules) {
                isWinner = ticTacToe.rules(ticTacToe.getOX());
                if (isWinner)
                    break;
            }

            ticTacToe.setPlayerTurn(ticTacToe.getPlayerTurn() + 1);
            system("clear");
        }

        if (!isWinner) {
            system("clear");
            ticTacToe.playboard();
            cout << "\nGame is Draw!" << endl;
        }
        system("read");
        system("clear");
        start = ticTacToe.restartGame();
        system("clear");
    }
}

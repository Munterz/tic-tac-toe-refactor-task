#include <iostream>
using namespace std;

class Board {
private:
    char grid[3][3];

public:
    Board() {
        char cell = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                grid[i][j] = cell++;
    }

    void display() const {
        cout << "Player - 1 [X]  Player - 2 [O]\n";
        cout << "     |     |     \n";
        for (int i = 0; i < 3; i++) {
            cout << "  ";
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j];
                if (j < 2) cout << "  | ";
            }
            cout << "\n";
            if (i < 2) cout << "_____|_____|_____\n     |     |     \n";
        }
        cout << "     |     |     \n";
    }

    bool isGameOver(bool &draw) const {
        for (int i = 0; i < 3; i++)
            if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
                return true;

        for (int i = 0; i < 3; i++)
            if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
                return true;

        if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
            return true;

        if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
            return true;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i][j] != 'X' && grid[i][j] != 'O') {
                    draw = false;
                    return false;
                }

        draw = true;
        return true;
    }

    char& at(int row, int col) {
        return grid[row][col];
    }

    const char& at(int row, int col) const {
        return grid[row][col];
    }
};

Board board;
char turn = 'X';
bool draw = false;

int getMoveChoice(char currentPlayer) {
    if (currentPlayer == 'X') {
        cout << "Player - 1 [X] turn: ";
    } else {
        cout << "Player - 2 [O] turn: ";
    }

    int input;
    cin >> input;
    return input;
}

bool convertChoiceToCoords(int choice, int &row, int &column) {
    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default: return false;
    }
    return true;
}

bool makeMove(int row, int column, char &currentPlayer) {
    if (board.at(row, column) != 'X' && board.at(row, column) != 'O') {
        board.at(row, column) = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    } else {
        cout << "Box already filled! Please choose another!\n";
        return false;
    }
}

void player_turn() {
    int choice = getMoveChoice(turn);

    int row, column;
    if (!convertChoiceToCoords(choice, row, column)) {
        cout << "Invalid Move\n";
        return;
    }

    if (!makeMove(row, column, turn)) {
        player_turn();
    }
}

int main() {
    cout << "Tic Tac Toe Game!\n";
    cout << "For 2 players.\n";

    while (true) {
        board.display();
        player_turn();
        if (board.isGameOver(draw)) break;
    }

    if (turn == 'X' && !draw) {
        cout << "Congratulations! Player 'O' has won the game\n";
    } else if (turn == 'O' && !draw) {
        cout << "Congratulations! Player 'X' has won the game\n";
    } else {
        cout << "Game Draw!!!\n";
    }
}
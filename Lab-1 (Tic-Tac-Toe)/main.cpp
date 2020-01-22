#include <iostream>

using namespace std;

bool REPEAT = false;

class TicTacToe {
private:
    char PLAYER1_SYMBOL = 'X';
    char PLAYER2_SYMBOL = '0';
    char PLACE_SYMBOL = ' ';
    int WINNER = 0;

    int currentPlayer = 1;
    char defaultEmptySymbol = '.';
    char board[3][3];
    int playerColumn = 0;
    int playerRow = 0;

public:
    // Expose game-state MACRO for main();
    bool WIN = false;
    bool DRAW = false;

    TicTacToe() {

        // Constructor will Initialize/Populate the board with the defaultEmptySymbol.
        for (int i = 0; i < sizeof(board[i]) / sizeof(char); ++i) {
            for (int j = 0; j < sizeof(board[j]) / sizeof(char); ++j)
                board[i][j] = defaultEmptySymbol;
        }

    }

    void displayInstructions() {
        cout << "Welcome to Tic Tac Toe.\n"
             << "To begin, please enter a column and row number.\n"
             << "Player 1 goes first." << endl;

        showBoard();
    }

    void showBoard() {

        // Iterate through Columns (Y)
        for (int i = 0; i < sizeof(board[i]) / sizeof(char); ++i) {
            // Iterate through Rows (X)
            for (int j = 0; j < sizeof(board[j]) / sizeof(char); ++j) {
                // Display board[column][row] value
                cout << board[i][j];
            }

            // Add a carriage return after each Row is displayed.
            cout << endl;
        }
    }

    void getMove() {

        // Switch the Filler to be used on the input coordinate
        switch (currentPlayer) {
            case 1:
                PLACE_SYMBOL = 'X';
                break;
            case 2:
                PLACE_SYMBOL = '0';
                break;
        }

        // Restart move if position on board is already occupied.
        do {
            // Prompt the player for input (X).
            cout << "Player " << currentPlayer << ", enter the desired Column number (1-3)" << endl;

            // Validate the input.
            do {
                cin >> playerColumn;

                // Check to see if valid integer was entered
                if (cin.fail()) {
                    cout << "Please enter a valid integer number between 1 and 3" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (playerColumn < 1 || playerColumn > 3)
                    cout << "Please enter a valid integer number between 1 and 3" << endl;

            } while (playerColumn < 1 || playerColumn > 3);     // Check to see if between number of rows and columns.

            // After validation, -1 from player answer so it translates to the 0 indexed array.
            playerColumn--;

            // Prompt the player for input (Y).
            cout << "Player " << currentPlayer << ", enter the desired Row number (1-3)" << endl;
            // Validate the input.
            do {
                cin >> playerRow;

                // Check to see if valid integer was entered
                if (cin.fail()) {
                    cout << "Please enter a valid integer number between 1 and 3" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (playerRow < 1 || playerRow > 3)
                    cout << "Please enter a valid integer number between 1 and 3" << endl;

                // Check to see if between number of rows and columns.
            } while (playerRow < 1 ||
                     playerRow > 3);

            // After validation, -1 from player answer so it translates to the 0 indexed array.
            playerRow--;

            if (board[playerRow][playerColumn] == 'X' || board[playerRow][playerColumn] == '0')
                cout << "That position has already been used. Please restart your move." << endl;

        } while (board[playerRow][playerColumn] == 'X' || board[playerRow][playerColumn] == '0');

        // Finally, store the player's move on the board. (x, y)
        board[playerRow][playerColumn] = PLACE_SYMBOL;

        cout << endl;
    }

    void checkWin() {

        // var used to check if 3 in a row.
        int validationCounter = 0;

        // Validate Method: Horizontal
        for (int i = 0; i < sizeof(board[i]) / sizeof(char); ++i) // Iterate through Y position
        {
            // Iterate through X position
            for (int j = 0; j < sizeof(board[j]) / sizeof(char); ++j)
                if (board[0][i] == board[j][i] &&
                    board[0][i] != defaultEmptySymbol)
                    validationCounter++;    // Ignore if cell is empty.

            // If 3 in a row, player wins.
            if (validationCounter == 3) {
                WIN = true;
                WINNER = currentPlayer;
            } else
                validationCounter = 0;
        }

        // Validation Method: Vertical.
        validationCounter = 0;  // Reset validationCounter.
        for (int i = 0; i < sizeof(board[i]) / sizeof(char); ++i) // Iterate through X position.
        {
            // Iterate through Y position.
            for (int j = 0; j < sizeof(board[j]) / sizeof(char); ++j)
                if (board[i][0] == board[i][j] &&
                    board[i][0] != defaultEmptySymbol)  // Ignore empty cells.
                    validationCounter++;

            // If 3 in a row, player wins.
            if (validationCounter == 3) {
                WIN = true;
                WINNER = currentPlayer;
            } else
                // Reset validation counter.
                validationCounter = 0;
        }

        // Validation Method: Diagonal.
        validationCounter = 0;  // Reset validationCounter.

        // Check to make sure we are not validating empty spaces in a row.
        if (board[0][0] != defaultEmptySymbol) {
            // DIRECTION: TOP LEFT TO BOTTOM RIGHT.
            // 0,0 increment by (+) 1 down -> (+) 1 right
            for (int i = 0; i < 3; ++i)
                if (board[0][0] == board[i][i] &&
                    board[i][i] != defaultEmptySymbol)
                    validationCounter++;

            // If 3 in a row, player wins.
            if (validationCounter == 3) {
                WIN = true;
                WINNER = currentPlayer;
            } else
                validationCounter = 0;
        }

        // DIRECTION: BOTTOM LEFT TO top RIGHT
        // two variables need for the second diagonal pattern.
        int x = 0;
        int y = 2;

        // Check to make sure we are not validating empty spaces in a row.
        if (board[0][2] != defaultEmptySymbol) {
            // 0, 2 increment by (-) 1 up -> (+1) right
            for (int i = 0; i < 3; ++i)
                if (board[0][2] == board[x++][y--])
                    validationCounter++;

            // Check if 3 in a row AND last value validated was player 1 symbol
            if (validationCounter == 3) {
                WIN = true;
                WINNER = currentPlayer;
            } else
                validationCounter = 0;
        }

        if (WIN)
            cout << "Congratulations Player " << WINNER << ", you win!" << endl;
    }

    void checkDraw() {

        // var used to check how many cells have been used.
        int validated = 0;

        // Iterate through X
        for (int i = 0; i < sizeof(board[i]) / sizeof(char); ++i) {
            // Iterate through Y
            for (int j = 0; j < sizeof(board[j]) / sizeof(char); ++j)
                if (board[i][j] != defaultEmptySymbol)
                    validated++;
        }

        // If all cells are used, we know the players have hit a draw.
        if (validated == 9) {
            cout << "The game ended in a draw." << endl;
            DRAW = true;
        } else
            DRAW = false;

    }

    void changePlayer() {
        if (currentPlayer == 1)
            currentPlayer = 2;
        else if (currentPlayer == 2)
            currentPlayer = 1;
    }

    void static promptNewGame() {
        char userInput = ' ';

        cout << "Would you like to start a new game? (y/n)" << endl;

        do {
            cin >> userInput;
            userInput = toupper(userInput);

            if (userInput != 'Y' && userInput != 'N')
                cout << "Please enter 'y' or 'n' to restart or quit." << endl;

        } while (userInput != 'Y' && userInput != 'N');

        if (userInput == 'Y')
            REPEAT = true;
        else if (userInput == 'N')
            REPEAT = false;
    }
};

int main() {

    // outer Repeat loop.
    do {
        TicTacToe Game;

        // display instruction
        Game.displayInstructions();

        // inner game loop
        do {
            // get next move.
            Game.getMove();
            // update board.
            Game.showBoard();
            // check for win.
            Game.checkWin();
            // check for tie
            Game.checkDraw();
            // if game not over, swap player
            Game.changePlayer();
        } while (!Game.WIN && !Game.DRAW);

        TicTacToe::promptNewGame();

        // display final board and congratulate winner
    } while (REPEAT);

    return 0;
}
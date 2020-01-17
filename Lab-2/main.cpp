#include <iostream>
#include <iostream>
#include <cstdlib> // for random
#include <ctime> // for time
#include <Windows.h>
#include <cstring>
#include <thread>

using namespace std;

//int num = 4;
//int num2 = 6;
//
//char myArray[num][num2];

class DungeonSlayer {
private:
    // global constants
    const static int MAX_ROW = 10;
    const static int MAX_COL = 10;
    int SIZE = MAX_ROW * MAX_COL;
    const char EMPTY_SPACE = '.';
    const char TRAP = 'T';
    const char TREASURE = '$';
    const char PLAYER = '@';
    // Array to hold X && Y coordinates of player.
    int PLAYER_PREV_POS[2];
    int PLAYER_POS[2];
    int SCORE = 0;
    char prevFrame[MAX_ROW][MAX_COL];

    char dungeonBoard[MAX_ROW][MAX_COL];

    int userInput = 0;


    // VARIABLES
    bool WIN = false;
    bool LOSE = false;

public:

    DungeonSlayer() {
        // initialize seed Random Number Generator.
        srand(static_cast<int>(time(NULL)));
    }

    // Function that returns a random number between 0-9;
    int getRandomNumber() {
        return rand() % 9;
    }

    // Show the Instructions for the Gamme.
    void displayInstructions() {
        cout << "Displaying Instructions" << endl;
    }

    void drawBoard() {
        // Draw Y coordinate.
        for (int y = 0; y < MAX_COL; ++y) {
            // Draw X coordinate.
            for (int x = 0; x < MAX_ROW; ++x)
                cout << dungeonBoard[x][y];
            /// Newline between rows.
            cout << "\n";
        }
        // Flush buffer to Console.
        cout.flush();
    }

    // x is the column, y is the row. The origin (0,0) is top-left.
    void setCursorPosition(int x, int y) {
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout.flush();
        COORD coord = {(SHORT) x, (SHORT) y};
        SetConsoleCursorPosition(hOut, coord);
    }

    void setMove(char &input) {

        // Copy the Players Previous location (so we can later fill it with empty space).
        for (int i=0; i < 2; ++i)
            PLAYER_PREV_POS[i] = PLAYER_POS[i];

        // Move the player up/down/left/right depending on key press.
        switch (input){
            case 'W':
                PLAYER_POS[1] -= 1;
                break;
            case 'A':
                PLAYER_POS[0] -= 1;
                break;
            case 'S':
                PLAYER_POS[1] += 1;
                break;
            case 'D':
                PLAYER_POS[0] += 1;
        }

        if (dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] == TRAP)
            gameOver();
        else if (dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] == TREASURE)
            ++ SCORE;
        else {
            // Move the player.
            dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] = PLAYER;
            // Replace previous position to be empty.
            dungeonBoard[PLAYER_PREV_POS[0]][PLAYER_PREV_POS[1]] = EMPTY_SPACE;
        }
    }

    void gameOver(){
        cout << "You stepped on a bear trap and starved to death. GAME OVER" << endl;

    }

    void getMove() {
        char userInput = ' ';
        bool VALID = false;

        do {
            cout << "Move your character (@) using (W,A,S,D)" << endl;
            cin >> userInput;

            userInput = toupper(userInput);

            if (cin.fail()) {
                cout << "That is not a valid entry!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (userInput == 'W' ||
                       userInput == 'A' ||
                       userInput == 'S' ||
                       userInput == 'D') {
                VALID = true;
                setMove(userInput);
            }


//            // Validate the inputs.
//            switch(userInput){
//                case 'w': setMove(userInput); VALID=true; break;
//                case 'a': setMove(userInput); VALID=true; break;
//                case 's': setMove(userInput); VALID=true; break;
//                case 'd': setMove(userInput); VALID=true; break;
//            }
        } while (!VALID);
    }

    void drawFrame() {
        // Display the first frame, then update any following frames.
    }

    void cls() {
        // Get the Win32 handle representing standard output.
        // This generally only has to be done once, so we make it static.
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        // Type-def Get Console Buffer Info
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        // Type-def Get/SET a Coordinate Position
        COORD topLeft = {0, 0};

        // std::cout uses a buffer to batch writes to the underlying console.
        // We need to flush that to the console because we're circumventing
        // std::cout entirely; after we clear the console, we don't want
        // stale buffered text to randomly be written out.
        cout.flush();

//        // Fof the consigure out the current width and height ole window
//        if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
//            // TODO: Handle failure!
//            abort();
//        }
        DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

        DWORD written;

        // Flood-fill the console with spaces to clear it
        FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

        // Reset the attributes of every character to the default.
        // This clears all background colour formatting, if any.
        FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

        // Move the cursor back to the top left for the next sequence of writes
        SetConsoleCursorPosition(hOut, topLeft);
    }

    void updateFrame() {
//        std::memset((char*)prevFrame, 0, MAX_ROW * MAX_COL);

        // Display the Board state if frame has changed.
        for (int y = 0; y != MAX_COL; ++y) {
            for (int x = 0; x != MAX_ROW; ++x) {
                if (dungeonBoard[x][y] == prevFrame[x][y]) {
                    continue;
                }
                // Move Cursor to position to update
                setCursorPosition(x, y);
                // Push updated character to position.
                cout << dungeonBoard[x][y];
            }
        }

        // Flush to display updated output.
        cout.flush();
//        std::memcpy((char *) prevFrame, (char const *) dungeonBoard, MAX_ROW * MAX_COL);
    }

    void saveFrame(){
        // Copy the Board.
        for (int y = 0; y < MAX_COL; ++y) {
            for (int x = 0; x < MAX_ROW; ++x)
                prevFrame[x][y] = dungeonBoard[x][y];
        }
    }


    // Set up the dungeon board with traps and treasure
    void initDungeon() {
        // Prompt the user (for debugging).
        cout << "Initializing the dungeon" << endl;
        // Fill the Board with empty spaces.
        for (int i = 0; i < MAX_ROW; ++i)
            for (int j = 0; j < MAX_COL; ++j)
                dungeonBoard[i][j] = EMPTY_SPACE;
        // Place the PLAYER at a random location at the start of the game:
        PLAYER_POS[0] = getRandomNumber();  // Store the random X coordinate of the player.
        PLAYER_POS[1] = getRandomNumber();  // Store the random Y coordinate of the player.
        dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] = PLAYER;    // Place the player at the X/Y POS coordinates.
        // Place a Random Quantity of Traps && Treasure (0-9) on the board.
        for (int i = 0; i < getRandomNumber(); ++i) {
            // Get Random Locations on the board
            int x = getRandomNumber();
            int y = getRandomNumber();
            // Check if Location is already occupied by the Player.
            if (dungeonBoard[x][y] != PLAYER) {
                // Generate a Random Item.
                int itemIndex = getRandomNumber() % 2;
                // Check if itemIndex is odd or even (TRAP OR TREASURE).
                if (itemIndex == 0) dungeonBoard[x][y] = TRAP;
                else dungeonBoard[x][y] = TREASURE;
            }
        }
    }

//    char getDungeonSize() {
//        char dungeonBoard[MAX_ROW][MAX_COL];
//
//        for (int i = 0; i<2; ++i) {
//            // Display prompt for either X or Y scale.
//            if (i == 0) cout << "Please enter the scale of the dungeon (X amount of rows): " << endl;
//            else cout << "Please enter the scale of the dungeon (Y amount of rows): " << endl;
//            // Get User Input.
//            cin >> userInput;
//            // Check for input failures.
//            while (cin.fail()) {
//                cout << "That is not a valid number. Please enter an integer." << endl;
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cin >> userInput;
//            }
//            if (i==0) MAX_ROW = userInput;
//            else MAX_COL = userInput;
//        }
//
//        return dungeonBoard[MAX_ROW][MAX_COL];
//    }

    // display current dungeon state
    void displayDungeon() {
        cout << "Displaying the dungeon" << endl;
    }

    // sees if move is onto checkCode object
    bool checkMove() {
        cout << "Checking move for stepping on " << "checkCode" << endl;
        cout << " Return true for debug purposes" << endl;
        return true;
    }

    // update the dungeon for next move
    void updateDungeon() {
        cout << "Updating Dungeon for next move" << endl;
    }

    // do you want to play again?
    void restartGame() {
        cout << "Checking for play again, returning false for debug" << endl;
//        return false;
    }

};

int main() {

    DungeonSlayer Game;
    bool PLAYING = true;

    Game.displayInstructions();
    Game.initDungeon();

    Game.drawBoard();
    Game.cls();

    while (PLAYING) {
        /// https://stackoverflow.com/questions/34842526/update-console-without-flickering-c

        // Save the Frame State.
        Game.saveFrame();

        // Get the player's move. (also SETS player MOVE).
        Game.getMove();

        // Draw the board (deprecated).
//        Game.drawBoard();

        // Clear output Buffer.
        Game.cls();

        cout << endl;

        Game.drawBoard();

        // update the displayed frame.
        Game.updateFrame();

    }







//    // play again loop
//    do {
//        // initialize dungeon
//        // display instructions
//        // game loop
//        do {
//            // display dungeon
//            // get move
//            // move monsters if you have any
//            win = checkMove(dungeon, cash);
//            if (not win)
//                lose = checkMove(dungeon, trap);
//            // check for monster kill if monsters exist
//            if (not win and not lose)
//                lose = checkMove(dungeon, monster);
//            if (not win and not lose)
//            // update dungeon
//        } while (not win and not lose);
//    } while ();
//}

    return 0;
}

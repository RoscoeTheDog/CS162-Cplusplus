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
    const char SPACE = '.';
    const char TRAP = 'T';
    const char PLAYER = '@';
    const char TREASURE = '$';

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
        // Draw X coordinate.
        for (int i = 0; i < MAX_ROW; ++i)
            // Draw Y coordinate.
            for (int j = 0; j < MAX_COL; ++j)
                cout << dungeonBoard[i][j];
            /// Newline between rows.
            cout << "\n";
        cout << endl;
    }

    // x is the column, y is the row. The origin (0,0) is top-left.
    void setCursorPosition(int x, int y)
    {
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout.flush();
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hOut, coord);
    }

    void updateFrame(){
        char prevFrame[MAX_ROW][MAX_COL];
        std::memset((char*)prevFrame, 0, MAX_ROW * MAX_COL);

// ...

        for (int y = 0; y != MAX_COL; ++y)
        {
            for (int x = 0; x != MAX_ROW; ++x)
            {
                if (dungeonBoard[x][y] == prevFrame[x][y]) {
                    continue;
                }
                setCursorPosition(x, y);
                std::cout << dungeonBoard[x][y];
            }
            cout << "\n";
        }
        cout << "\n";
        std::cout.flush();
        std::memcpy((char*)prevFrame, (char const*)dungeonBoard, MAX_ROW * MAX_COL);
    }


    // Set up the dungeon board with traps and treasure
    void initDungeon() {
        // Prompt the user (for debugging).
        cout << "Initializing the dungeon" << endl;
        // Fill the Board with empty spaces.
        for (int i = 0; i < MAX_ROW; ++i)
            for (int j = 0; j < MAX_COL; ++j)
                dungeonBoard[i][j] = SPACE;
        // Place the PLAYER at a random location at the start of the game.
        dungeonBoard[getRandomNumber()][getRandomNumber()] = PLAYER;
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

    // get a valid move (L,R,U,D)
    char getMove() {
        cout << "Getting a move, returning UP for debug" << endl;
        return ' ';
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


    // Step through with a debugger, or insert sleeps, to see the effect.
//    Game.setCursorPosition(10, 5);
//    cout << "CHEESE";
//    Game.setCursorPosition(10, 5);
//    std::cout << 'W';
//    Game.setCursorPosition(10, 9);
//    std::cout << 'Z';
//    Game.setCursorPosition(10, 5);
//    std::cout << "     ";  // Overwrite characters with spaces to "erase" them
//    std::cout.flush();

    while (PLAYING) {
        /// https://stackoverflow.com/questions/34842526/update-console-without-flickering-c
        

        // Draw the board.
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

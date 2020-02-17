#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <limits>

using namespace std;

class DungeonSlayer {
private:
    // private class constants
    const static int MAX_ROW = 10;
    const static int MAX_COL = 10;
    const char PLAYER = 'P';
    const char EMPTY_SPACE = '.';
    const char TRAP = 'T';
    const char TREASURE = '$';
    const char ESCAPE = '0';

    // The dungeon board/map.
    char dungeonBoard[MAX_ROW][MAX_COL];
    // The X && Y coordinates of players current and previous positions.
    int PLAYER_POS[2];
    int PLAYER_PREV_POS[2];
    char prevFrame[MAX_ROW][MAX_COL];  // Intended to be used to update frames in realtime, but did not have time to troubleshoot console-specific issues.

    // Player score and some other fun stuff.
    int SCORE = 0;
    int MIN_OBJ_THRESHOLD = 7;

    // Input Handling.
    char userInput = 0;

public:
    bool PLAYING = true;
    bool NEW_GAME = true;

    DungeonSlayer() {
        // seed Random Number Generator.
        srand(static_cast<int>(time(NULL)));
    }

    // Method that returns a random number between 0-9;
    int getRandomNumber() {
        return rand() % 9;
    }

    // Method that displays the Instructions for the Game.
    void displayInstructions() {
        cout << "Welcome to DungeonSlayer!\n\n"
             << "HOW TO PLAY:\n"
             << "1) Move your player (P) with WASD.\n"
             << "2) Collect $ to gain additional points.\n"
             << "3) Don't step on Traps(T) or you will bleed out!\n"
             << "4) Reach the end of the level by finding the exit (0)!"
             << "Good luck!\n"
             << endl;
    }

    // Method that draws the map board.
    void drawBoard() {
        // Show the player's score in the upper portion of screen.
        cout << "Score: " << SCORE << endl;
        // Draw Y coordinate.
        for(int y = 0 ; y < MAX_COL ; ++y) {
            // Draw X coordinate.
            for(int x = 0 ; x < MAX_ROW ; ++x)
                cout << dungeonBoard[x][y];
            // Newline between rows.
            cout << "\n";
        }
        // Flush buffer to Console.
        cout.flush();
    }

    // method that uses 'userInput' member to change the player's position in the dungeon map.
    void setMove() {

        // Copy the Players Previous location (so we can later fill it with empty space).
        for(int i = 0 ; i < 2 ; ++i)
            PLAYER_PREV_POS[i] = PLAYER_POS[i];

        // Move the player up/down/left/right depending on key press.
        switch(userInput) {
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

        // Check for score/win/lose conditions.
        if (dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] == TREASURE)
            ++SCORE;
        else if (dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] == ESCAPE)
            gameVictory();
        else if (dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] == TRAP)
            gameOver();

        // Move the player.
        dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] = PLAYER;
        // Set previous position to be an empty character.
        dungeonBoard[PLAYER_PREV_POS[0]][PLAYER_PREV_POS[1]] = EMPTY_SPACE;
    }

    // Method that prompts game over and  user lost and exits the application.
    void gameOver() {
        cout << "You stepped on a bear trap and died! GAME OVER." << endl;
        PLAYING = false;
    }

    void gameVictory(){
        cout << "Congratulations, you escaped the dungeon alive!\n"
             << "Final score: " << SCORE << "\n"
             << endl;
        PLAYING = false;
    }

    void mainMenu() {
        cout << "Would you like to start a new game...? (y/n)" << endl;

        cin >> userInput;
        userInput = toupper(userInput);

        while (userInput != 'Y' && userInput != 'N') {
            cout << "Please enter (y)es or (n)o" << endl;
            cin >> userInput;
            userInput = toupper(userInput);
        }

        if (userInput == 'Y')
            NEW_GAME = true;
        else
            NEW_GAME = false;
    }

    // This method assigns 'userInput' member until it is considered valid input.
    void getMove() {
        bool VALID = false;

        do {
            cin >> userInput;

            userInput = toupper(userInput);

            if (cin.fail()) {
                cout << "That is not a valid entry!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (userInput == 'W' ||
                     userInput == 'A' ||
                     userInput == 'S' ||
                     userInput == 'D') {
                VALID = true;
            }
        } while (!VALID);

    }

    // Set up the dungeon board with traps and treasure
    void initDungeon() {
        // x, y hold two random coordinates.
        int x = getRandomNumber();
        int y = getRandomNumber();
        // numItems holds the amount of total miscellaneous objects generated on the map.
        int numItems = getRandomNumber();
        // itemIndex is to determine what item is used on the item table.
        int itemIndex = getRandomNumber() % 2;

        // Fill the Board with empty spaces.
        for(int i = 0 ; i < MAX_ROW ; ++i)
            for(int j = 0 ; j < MAX_COL ; ++j)
                dungeonBoard[i][j] = EMPTY_SPACE;

        // Place the PLAYER at a random location at the start of the game:
        PLAYER_POS[0] = x;   // Store the random X coordinate of the player.
        PLAYER_POS[1] = y;   // Store the random Y coordinate of the player.
        dungeonBoard[PLAYER_POS[0]][PLAYER_POS[1]] = PLAYER;     // Set the player at the X/Y coordinates.

        // Keep generating new positions if new coordinates are where the player is at.
        do {
            x = getRandomNumber();
            y = getRandomNumber();
        }while (dungeonBoard[x][y] == PLAYER) ;

        // Place an escape/win-condition for the player.
        dungeonBoard[x][y] = ESCAPE;

        // Keep generating a new quantity of items if below the declared object threshold.
        while(numItems < MIN_OBJ_THRESHOLD)
            numItems = getRandomNumber();

        // Place a Random Quantity of Traps && Treasure between MIN_OBJ_THRESHOLD:10 on the board.
        for(int i = 0 ; i < numItems ; ++i) {
            // Get new Random Locations on the board
            x = getRandomNumber();
            y = getRandomNumber();
            // Check if Location is already occupied by the Player or Escape.
            if(dungeonBoard[x][y] != PLAYER &&
               dungeonBoard[x][y] != ESCAPE) {
                // Check if itemIndex is odd or even (TRAP OR TREASURE).
                if(itemIndex == 0)
                    dungeonBoard[x][y] = TRAP;
                else
                    dungeonBoard[x][y] = TREASURE;
            }
        }
    }

    // DEPRECATED METHOD: ask the user for size of dungeon at start of game. Can't do yet-- requires pointers and dynamic arrays.
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


    // DEPRECATED METHOD:
    // different ways to communicate to output buffer for real-time drawing and signaling of input.
    // However-- being console and platform specific, ran into many issues with this.
    // I did not have enough time fully finish adding this into the game.

    //    void setCursorPosition(int x, int y) {
    //        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //        std::cout.flush();
    //        COORD coord = {(SHORT) x, (SHORT) y};
    //        SetConsoleCursorPosition(hOut, coord);
    //    }
    //
    //    void cls() {
    //        // Get the Win32 handle representing standard output.
    //        // This generally only has to be done once, so we make it static.
    //        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //
    //        // Type-def Get Console Buffer Info
    //        CONSOLE_SCREEN_BUFFER_INFO csbi;
    //
    //        // Type-def Get/SET a Coordinate Position
    //        COORD topLeft = {0, 0};
    //
    //        // std::cout uses a buffer to batch writes to the underlying console.
    //        // We need to flush that to the console because we're circumventing
    //        // std::cout entirely; after we clear the console, we don't want
    //        // stale buffered text to randomly be written out.
    //        cout.flush();
    //
    ////        // Fof the consigure out the current width and height ole window
    ////        if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
    ////            // TODO: Handle failure!
    ////            abort();
    ////        }
    //        DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
    //
    //        DWORD written;
    //
    //        // Flood-fill the console with spaces to clear it
    //        FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);
    //
    //        // Reset the attributes of every character to the default.
    //        // This clears all background colour formatting, if any.
    //        FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);
    //
    //        // Move the cursor back to the top left for the next sequence of writes
    //        SetConsoleCursorPosition(hOut, topLeft);
    //    }
    //
    //    void updateFrame() {
    ////        std::memset((char*)prevFrame, 0, MAX_ROW * MAX_COL);
    //
    //        // Display the Board state if frame has changed.
    //        for (int y = 0; y != MAX_COL; ++y) {
    //            for (int x = 0; x != MAX_ROW; ++x) {
    //                if (dungeonBoard[x][y] == prevFrame[x][y]) {
    //                    continue;
    //                }
    //                // Move Cursor to position to update
    //                setCursorPosition(x, y);
    //                // Push updated character to position.
    //                cout << dungeonBoard[x][y];
    //            }
    //        }
    //
    //        // Flush to display updated output.
    //        cout.flush();
    ////        std::memcpy((char *) prevFrame, (char const *) dungeonBoard, MAX_ROW * MAX_COL);
    //    }
    //
    //    void saveFrame(){
    //        // Copy the Board.
    //        for (int y = 0; y < MAX_COL; ++y) {
    //            for (int x = 0; x < MAX_ROW; ++x)
    //                prevFrame[x][y] = dungeonBoard[x][y];
    //        }
    //    }
    void checkMove() {

        // This is my hacky way to get around negative number checking without changing all of my program's variables. :lol:
        int PLAYER_X = PLAYER_POS[0];
        int PLAYER_Y = PLAYER_POS[1];

        // Move the player up/down/left/right depending on key press.
        switch(userInput) {
            case 'W':
                PLAYER_Y -= 1;
                break;
            case 'A':
                PLAYER_X -= 1;
                break;
            case 'S':
                PLAYER_Y += 1;
                break;
            case 'D':
                PLAYER_X += 1;
        }

        // Check if player stepped outside of bounds.
        if(PLAYER_X > (MAX_ROW - 1)    ||   // '0' index checks for x.
           PLAYER_X < 0                ||
           PLAYER_Y > (MAX_COL - 1)    ||   // '1' index checks for y.
           PLAYER_Y < 0) {
            // Move the player back to previous position.
            PLAYER_POS[0] = PLAYER_PREV_POS[0];
            PLAYER_POS[1] = PLAYER_PREV_POS[1];
        }
    }
};

int main() {

    DungeonSlayer Game;

    do
    {
        new(&Game) DungeonSlayer;   // run the constructor using already allocated memory (to reset instance variables) (https://stackoverflow.com/questions/2494471/c-is-it-possible-to-call-a-constructor-directly-without-new)
        Game.displayInstructions();
        Game.initDungeon();

        do
        {
            Game.drawBoard();
            Game.getMove();
            Game.checkMove();
            Game.setMove();
        } while (Game.PLAYING);

        Game.mainMenu();

    } while (Game.NEW_GAME);

    // Helps keeps Visual Studio 2019 debugger from auto-closing when no breakpoints being used.
    if (_WIN32)
    {
        system("pause");
        exit(0);
    }
    else
        return 0;
}

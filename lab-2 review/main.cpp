#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <cstdlib>

using namespace std;

//dungeon constants
const int MAX_DUNGEON_SIZE = 12;
const int MAX_TRAP_COUNT = MAX_DUNGEON_SIZE/2;
//validation constants
const long BUFF_SIZE = numeric_limits<streamsize>::max();
const char END_LINE = '\n';

//function prototypes, useful stuff
void createDungeon(int DungeonBluePrints[][MAX_DUNGEON_SIZE],int& player_x_pos,int& player_y_pos);
int getRandNumber();
void displayDungeon(int DungeonBluePrints[][MAX_DUNGEON_SIZE]);
int getMove(int& player_x_coord,int& player_y_coord,int DungeonBluePrints[][MAX_DUNGEON_SIZE]);
int checkMove(int moved_to_tile, bool& game_completed_flag, bool& game_fail_flag,int DungeonBluePrints[][MAX_DUNGEON_SIZE]);

//main game loop, but you probably knew that
int main(){
    //srand(static_cast<unsigned>(time(0)));
    int dungeonmap [MAX_DUNGEON_SIZE] [MAX_DUNGEON_SIZE] = {};
    srand(time(NULL));
    int current_player_x_coord = 0;
    int current_player_y_coord = 0;
    int previous_tile = 0;
    bool loot_get = false;
    bool trap_hit = false;

    createDungeon(dungeonmap,current_player_x_coord,current_player_y_coord);
    while (trap_hit == false && loot_get == false)
        {
        displayDungeon(dungeonmap);
        cout << current_player_x_coord << "," << current_player_y_coord << endl;
        previous_tile = getMove(current_player_x_coord,current_player_y_coord,dungeonmap);
        checkMove(previous_tile,loot_get,trap_hit,dungeonmap);
        }
    return 0;
}
//Dungeon creation algorithms, also contains the ascii reference chart for future and current tiles
void createDungeon(int DungeonBluePrints[][MAX_DUNGEON_SIZE],int& player_x_pos,int& player_y_pos){
//Number 2 ASCII Chart
// 0 - Empty Spaces
// 1 - 4 Four Corners
// 5 - Lengthwise Wall
// 6 - Hight wise Wall
// 7 - Wall Junction T Vertical Right Side
// 8 - Wall Junction T Vertical Left Side
// 9 - Wall Junction T Horizontal
// 10 - Wall Junction T Horizontal upside down
// 11 - Wall Junction 4-Way
// 12 - Player
// 13 - Trap
// 14 - Treasure
//Generating Exterior Walls and corners
    for (int  y_placement = 0; y_placement < MAX_DUNGEON_SIZE; y_placement++){
        for (int x_placement = 0; x_placement < MAX_DUNGEON_SIZE; x_placement++){
        //Placing the corners of the maze
          if (y_placement == 0 && x_placement == 0){
              DungeonBluePrints [x_placement][y_placement] = 1;
            }
           else if (y_placement == 0 && x_placement == MAX_DUNGEON_SIZE-1){
              DungeonBluePrints [x_placement][y_placement] = 2;
            }
           else if (y_placement == MAX_DUNGEON_SIZE-1 && x_placement == 0){
              DungeonBluePrints [x_placement][y_placement] = 3;
            }
           else if (y_placement == MAX_DUNGEON_SIZE-1 && x_placement == MAX_DUNGEON_SIZE-1){
              DungeonBluePrints [x_placement][y_placement] = 4;
            }
        //Placing the Vertical and Horizontal Exterior walls
            else if (y_placement == 0 || y_placement == MAX_DUNGEON_SIZE-1)
              {
                    DungeonBluePrints[x_placement][y_placement] = 5;
              }
            else if (x_placement == 0 || x_placement == MAX_DUNGEON_SIZE-1)
              {
                DungeonBluePrints [x_placement][y_placement] = 6;
              }
        }
    }
    //Placing items (Like Treasure), player start location, and traps
    //also counts if treasure, player, the trap placed, and the processes completion.
    bool item_gen_completed = false;
    int player_placed = 0;
    int traps_placed = 0;
    int treasure_placed = 0;
    while (item_gen_completed == false)
        {
        //picks a random unoccupied point and places a randomly selected item
        int x_place_rand = getRandNumber();
        int y_place_rand = getRandNumber();
        if (DungeonBluePrints [x_place_rand][y_place_rand] != 0)
            {
            continue;
            }
        else
            {
            //uses the validated random coordinates to place different items in random spots not occupied
             if (player_placed < 1)
             {
                 player_y_pos = y_place_rand;
                 player_x_pos = x_place_rand;
                 DungeonBluePrints[x_place_rand][y_place_rand] = 12;
                 player_placed++;
             }
             else if (traps_placed < MAX_TRAP_COUNT)
             {
                DungeonBluePrints[x_place_rand][y_place_rand] = 13;
                traps_placed++;
             }
             else if (treasure_placed < 1)
             {
                 DungeonBluePrints[x_place_rand][y_place_rand] = 14;
                 treasure_placed++;
             }
             else
             {
                 item_gen_completed = true;
             }
            }
        }
}
//draws the dungeon each game loop cycle
void displayDungeon(int DungeonBluePrints[][MAX_DUNGEON_SIZE]){
   //icon chart
   char top_left = 'T'+'u';
   char top_right = 'T'+'g';
   char bottom_left = 'T'+'t';
   char bottom_right = 'T'+'h';
   char long_wall = 'T'+'y';
   char tall_wall = 'T'+'f';
   char player = 'u' + 'u';
   char trap = 'v' + ':';
   char treasure = 'w' + 'v';
   for (int  y_print = 0; y_print < MAX_DUNGEON_SIZE; y_print++){
         for (int x_print = 0; x_print < MAX_DUNGEON_SIZE; x_print++){
         switch(DungeonBluePrints[x_print][y_print])
            {
         case 0:
            cout << " ";
            break;
         case 1:
            cout << top_left;
            break;
         case 2:
            cout << top_right << endl;
            break;
         case 3:
            cout << bottom_left;
            break;
         case 4:
            cout << bottom_right << endl;
            break;
         case 5:
            cout << long_wall;
            break;
         case 6:
            if (x_print == MAX_DUNGEON_SIZE-1)
                {
                cout << tall_wall << endl;
                }
            else
                {
                cout << tall_wall;
                }
            break;
         case 12:
            cout << player;
            break;
         case 13:
            cout << trap;
            break;
         case 14:
            cout << treasure;
            break;
            }
        }
    }
}
//generates a random number
int getRandNumber(){
int generated_int = rand() %MAX_DUNGEON_SIZE +1;
return generated_int;
}
//validates user input, and moves the icon and updates the board
int getMove(int& player_x_coord,int& player_y_coord,int DungeonBluePrints[][MAX_DUNGEON_SIZE]){
    string player_input = "";
    int usr_in_str_len = 0;
    bool valdate_input_complete = false;
    int moved_to_tile = 0;
    cout << "Enter your movement for this turn.L for left, R for right, U for up, and D for down\n";
    while (valdate_input_complete == false)
    {
        //prompt user
        cin >> player_input;
        //input lowering and validation
        usr_in_str_len = player_input.length();
        for (int i = 0; i != usr_in_str_len; i++)
            {
            player_input[i] = tolower(player_input[i]);
            }
        if (player_input == "l")
        {
            if(DungeonBluePrints[player_x_coord-1][player_y_coord] > 0 && DungeonBluePrints[player_x_coord-1][player_y_coord] < 7)
            {
                cout << "You find the way blocked, and decide to choose another way\n";
                continue;
            }
            else
            {
                DungeonBluePrints[player_x_coord][player_y_coord] = 0;
                player_x_coord--;
                moved_to_tile = DungeonBluePrints[player_x_coord][player_y_coord];
                DungeonBluePrints[player_x_coord][player_y_coord] = 12;
                valdate_input_complete = true;
                return moved_to_tile;
            }
        }
        else if (player_input == "r")
        {
            if(DungeonBluePrints[player_x_coord+1][player_y_coord] > 0 && DungeonBluePrints[player_x_coord+1][player_y_coord] < 7)
            {
                cout << "You find the way blocked, and decide to choose another way\n";
                continue;
            }
            else
            {
                DungeonBluePrints[player_x_coord][player_y_coord] = 0;
                player_x_coord++;
                moved_to_tile = DungeonBluePrints[player_x_coord][player_y_coord];
                DungeonBluePrints[player_x_coord][player_y_coord] = 12;
                valdate_input_complete = true;
                return moved_to_tile;
            }
        }
        else if (player_input == "u")
        {
            if(DungeonBluePrints[player_x_coord][player_y_coord-1] > 0 && DungeonBluePrints[player_x_coord][player_y_coord-1] < 7)
            {
                cout << "You find the way blocked, and decide to choose another way\n";
                continue;
            }
            else
            {
                DungeonBluePrints[player_x_coord][player_y_coord] = 0;
                player_y_coord--;
                moved_to_tile = DungeonBluePrints[player_x_coord][player_y_coord];
                DungeonBluePrints[player_x_coord][player_y_coord] = 12;
                valdate_input_complete = true;
                return moved_to_tile;
            }
        }
        else if (player_input == "d")
        {
            if(DungeonBluePrints[player_x_coord][player_y_coord+1] > 0 && DungeonBluePrints[player_x_coord+1][player_y_coord] < 7)
            {
                cout << "You find the way blocked, and decide to choose another way\n";
                continue;
            }
            else
            {
                DungeonBluePrints[player_x_coord][player_y_coord] = 0;
                player_y_coord++;
                moved_to_tile = DungeonBluePrints[player_x_coord][player_y_coord];
                DungeonBluePrints[player_x_coord][player_y_coord] = 12;
                valdate_input_complete = true;
                return moved_to_tile;
            }
        }
        else
        {
            cout << "That isn't a legal move, please enter another\n";
        }
    }
}
//checks for import tile interactions (such as hitting a trap or collecting treasure)
int checkMove(int moved_to_tile, bool& game_completed_flag, bool& game_fail_flag, int DungeonBluePrints[][MAX_DUNGEON_SIZE]){
if (moved_to_tile == 13)
    {
    cout << "You fell into a pit of pointy spikes. That may sting in the morning. GAME OVER\n";
    game_fail_flag = true;
    }
else if (moved_to_tile == 14)
    {
    cout << "You find a chest full of glittering gems. This will surely come in handy when you return. YOU WIN\n";
    game_completed_flag = true;
    }
else
    {
    cout<< "You venture on through the damp catacombs\n";
    }
}

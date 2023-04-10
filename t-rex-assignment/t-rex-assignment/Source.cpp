#include <iostream> 
#include <conio.h> 
#include <time.h>
#include <windows.h>

#define dinoPos 2   //defining dinosaur x-axis position
#define hurdlePos 90  // definning hurdle y-axis position 

using namespace std;


int dinoY = 0;  // dino y-axis position
int speed = 30; // speeed of dino
bool gameover = false;  //boolean value to stop the game

//function to define the coordinate of console windows 
void gotoxy(int x, int y) {
    COORD coord;    // defining coordinate variable 
    coord.X = x;    // defining x-axis     
    coord.Y = y;    // defining y-axis 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
    //to set console position and to define standard output  
    //handle is a pointer that point to GC heap 
}

class trexMap {
public:
//function to draw the map( includes celling and ground )
    static void map() {
        system("cls");
        gameover = false;   //when game is running 
        gotoxy(10, 4); cout << "SCORE : ";  //prints score in cordinate (10,4)
        for (int i = 0; i < 100; i++) {     // for-loop to print the map
        gotoxy(1 + i, 1); cout << "\33[96m#\33[0m";
        gotoxy(1 + i, 25); cout << "\33[92m#\33[0m";
        }
    }



    //function to draw the  dino and to move it
    static void reactTrex(int jump = 0) {
        static int foot = 0;    // static variable foot
        if (jump == 0)          //setting the y-cordinate of dinosaur according to the input made
            dinoY = 0;
        else if (jump == 2) {
            dinoY--;
        }
        else dinoY++;

        // printing the dino
        gotoxy(dinoPos, 21 - dinoY); cout << "     \33[33mhhh\33[0m";
        gotoxy(dinoPos, 22 - dinoY); cout << "\33[33mt  bbb\33[0m  ";
        gotoxy(dinoPos, 23 - dinoY); cout << " \33[33mt bbb\33[0m";
        // printing foot accorindg to the input made
        if (jump == 1) {
            gotoxy(2, 24 - dinoY);
            cout << " \33[33mff ff\33[0m ";
        }
        else if (foot == 0) {
            gotoxy(2, 24 - dinoY); {cout << " \33[33mff\33[0m   "; }
            foot = !foot;
        }
        else if (foot == 1) {
            gotoxy(2, 24 - dinoY); {cout << "    \33[33mff\33[0m"; }
            foot = !foot;
        }

        gotoxy(5, 20 - dinoY);  //hiding the printed head above the dino
        if (jump == 2) { cout << "      "; }

        gotoxy(2, 25 - dinoY);  //prints the surface where dino is standing or running 
        if (jump == 0) {
            cout << "\33[92m############\33[0m";
        }
        else {
            cout << "            ";
        }
        Sleep(speed);

    }
};

class hurdles {
public:
    //drwas the hurdles(cactus looking object)
    static void drawHurdle() {
        static int plantX = 0;  // static variable for x-coordinate of the plant
        static int score = 0;   // score counter
        char ch;                // character variable to store user input 
        if (plantX == 82 && dinoY < 2) {  // if statement to check if plant's coordinate collide with dino coordinates
            PlaySound(TEXT("game over"), NULL, SND_ASYNC);
            score = 0;
            plantX = 0;
            speed = 40;
            gotoxy(36, 8); cout << "Game Over";
            gotoxy(36, 9); cout << "Press any key to continue";
            ch = _getch();             // get character from keyboard
            gameover = true;
        }
        //draw hurdle 
        gotoxy(hurdlePos - plantX, 22); cout << "\33[32m| |\33[0m ";
        gotoxy(hurdlePos - plantX, 23); cout << "\33[32m| |\33[0m ";
        gotoxy(hurdlePos - plantX, 24); cout << " \33[32m|\33[0m  ";
        plantX++;   // to shift x-cordinate for plant

        if (plantX == 89) { //if it goes to left side of the screen, it resets to zero 
            plantX = 0;
            score++;
            gotoxy(11, 2); cout << "     ";
            gotoxy(18, 4); cout << score;
            if (speed == 0) {}
            else { speed = speed - 2; }

        }
    }
};


class setupGame {
public:
    //basic setup of game 
    static void setup() {
        PlaySound(TEXT("main theme.wav"), NULL, SND_ASYNC);
        //playing the sound in asynchroniously and returns immediately after beginning of the sound  
        system("cls");
        char ch;
        int i;
        trexMap::map();
        while (true) {
            while (!_kbhit()) {
                if (gameover == true) {
                    return;
                }
                trexMap::reactTrex();
                hurdles::drawHurdle();
            }
            ch = _getch();
            if (ch == 32) {
                i = 0;
                while (i < 6) {
                    trexMap::reactTrex(1);
                    hurdles::drawHurdle();
                    i++;
                }
                while (i > 0) {
                    trexMap::reactTrex(2);
                    hurdles::drawHurdle();
                    i--;
                }
            }
            else if (ch == 'p')
                break;
        }
    }



    // function for instruction
    static void instruction() {
        string text = "INSTRUCTIONS";
        do
        {

            system("cls");
            gotoxy(42, 5); {cout << "\33[92m#############################\33[0m"; }
            gotoxy(42, 6); {cout << "\33[92m#                           #\33[0m"; }
            gotoxy(42, 7); {cout << "\33[92m#\33[0m        INSTRUCTIONS       \33[92m#\33[0m"; }
            gotoxy(42, 8); {cout << "\33[92m#                           #\33[0m"; }
            gotoxy(42, 9); {cout << "\33[92m#############################\33[0m"; }
            gotoxy(40, 12); {cout << "\33[93m1. Press Space Bar to Jump\33[0m"; }
            gotoxy(40, 13); {cout << "\33[93m2. Press 'p' key to return to main menu page\33[0m"; }
            gotoxy(40, 14); {cout << "\33[93m3. Press any key to go back\33[0m"; }
            char ch = _getch();
            if (ch = '10') { break; }
        } while (1);
    }
};


//functiofor the main page
int main() {
    do {
        system("cls");
        PlaySound(TEXT("intro.wav"), NULL, SND_ASYNC);
        gotoxy(40, 5); {cout << "\33[92m#############################\33[0m"; }
        gotoxy(40, 6); {cout << "\33[92m#                           #\33[0m"; }
        gotoxy(40, 7); {cout << "\33[92m#\33[0m          Mini-dino        \33[92m#\33[0m"; }
        gotoxy(40, 8); {cout << "\33[92m#\33[0m                           \33[92m#\33[0m"; }
        gotoxy(40, 9); {cout << "\33[92m#############################\33[0m"; }
        gotoxy(40, 12); {cout << "\33[93m1. Press '1' to Start Game\33[0m"; }
        gotoxy(40, 13); {cout << "\33[93m2. Press '2' to see Instructions\33[0m"; }
        gotoxy(40, 14); {cout << "\33[93m3. Press '3' to Quit\33[0m"; }
        gotoxy(38, 16); {cout << "\33[93mSelect Option: \33[0m"; }
        char op = _getch();

        if (op == '1') { setupGame::setup(); }

        else if (op == '2') { setupGame::instruction(); }

        else if (op == '3') { exit(0); }

    } while (1);

    return 0;
}
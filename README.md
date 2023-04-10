# Dino_Game

## BASIC DESCRIPTION OF THE GAME

This was a project designed for second year programming assignment. 

For the dinosaur designing part, the letter ‘h’, ’b’ and ‘f’ were used to map the dinosaur-looking object where ‘h’ defines the head, ‘b’ defines the body and ‘f’ defines the foot.

The class **TrexMap** holds two functions: **map () and reactTrex ()**, map () function basically draws the set includes the game over text, the score counter, the sky, and the ground. With the “gotoxy” function, this class establishes the position on the x and y coordinates of the console window of the pixels to be turned on to show the described elements. The game over Boolean variable is set to zero when the game is running. The for loop was used to print the map continuously. Also, colour has been added to the characters, which have been used to simulate the sky and ground, which are light blue and green, respectively.

**reactTrex ()** is another function of the same class which prints the body of the dinosaur and makes the foot of the dinosaur moving. The colour of the dinosaur has been added and tried to make it look like a dinosaur as much as possible. The x-coordinate of the dinosaur is constant as it won’t change its position horizontally, but the position hurdle is moving to the left instead. ‘gotoxy ()’ function is being used to print the character in specific coordinate.  Although the x coordinate of the dinosaur is not moving, but the y-coordinate of dino will alter specifically in different condition.

When **“jump”** is set to be ‘0’, y coordinates remain the same, while it is set to be ‘1’, y-coordinate will start decreasing 6 time, changing its position to upside direction making it look like it’s jumping. And finally, when “jump” is set to be 2, y-coordinates start increasing 6 times, putting it back to its original position.

Hurdles class includes one function **“drawHurdle ()”**, two static variables “plantX” and “score” were declared, with an if statement, it is checked if the coordinates of the cactus and those of the dinosaur coincide. If that is the case, the boolean variable “game over” will be set to "true", "Game Over" will be printed, and the background music will be changed. To exit from the “Game Over” screen, user must press any key which is carried out using “_getch” function. The green colour is also added to the characters that make up the obstacles. With the ‘gotoxy’ function, the coordinates for printing the obstacles represented as cactus are established and moved on the x-axis. With an if statement, it is checked whether the obstacles have reached the last possible value in the left part of the screen. In that case, the obstacle value will become "0", and the score will increase by one. 

On the other hand, the speed of the obstacles is established based on the waiting time to print the frame. For this reason, only a few difficulty levels are available. Because since the speed of the dinosaur also increases, increasing the speed of the obstacles would result in a slower game. The function for “drawHurdle” is shown in above flowchart in figure 3 as well.  

The **“setupGame”** class includes the game setup and instruction function. The console window is cleared setup function using **(system(“cls”))** function, and the trexMap function is called again, which remains unchanged, followed by a while loop. In the loop, it is checked whether a key has been pressed. If so, it is checked if the ASCII value of the key mentioned above is equal to the decimal value 32, which corresponds to the space bar key. In that case, the functions trexMap (reactTrex (1)) and hurdles are called first, incrementing them, and then trexMap (reactTrex (2)) and hurdles.

 The main theme and the possibility to press the letter 'p' to pause the game have been also included in the static void setup () function. In the static void instruction () function, the instruction page is declared by adding colour to the text. Specifically, the title is light green, and the instructions are yellow. 

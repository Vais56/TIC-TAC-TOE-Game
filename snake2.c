#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  

int height = 20, width = 20, x, y, fruitX, fruitY, flag, gameend, score;
int tailX[100], tailY[100], piece = 0;

void gotoxy(int x, int y) {
    COORD coord = { y, x };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setup() {
    x = height / 2; 
    y = width / 2;
    fruitX = rand() % (height - 2) + 1;
    fruitY = rand() % (width - 2) + 1;
    gameend = 0; score = 0; piece = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == 0 || i == height || j == 0 || j == width) printf("*");  
            else if (i == x && j == y) printf("O");  
            else if (i == fruitX && j == fruitY) printf("@");  
            else {
                int printed = 0;
                for (int k = 0; k < piece; k++)
                    if (i == tailX[k] && j == tailY[k]) { printf("o"); printed = 1; break; }
                if (!printed) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': if (flag != 2) flag = 1; break;
            case 's': if (flag != 1) flag = 2; break;
            case 'a': if (flag != 4) flag = 3; break;
            case 'd': if (flag != 3) flag = 4; break;
        }
    }
}

void makelogic() {
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x; tailY[0] = y;

    for (int i = 1; i <= piece; i++) {
        prev2X = tailX[i]; prev2Y = tailY[i];
        tailX[i] = prevX; tailY[i] = prevY;
        prevX = prev2X; prevY = prev2Y;
    }

    if (flag == 1) x--; else if (flag == 2) x++;
    else if (flag == 3) y--; else if (flag == 4) y++;

    if (x == 0 || x == height || y == 0 || y == width) gameend = 1;
    
    for (int i = 0; i < piece; i++) 
        if (x == tailX[i] && y == tailY[i]) gameend = 1;

    if (x == fruitX && y == fruitY) {
        piece++; score += 10;
        fruitX = rand() % (height - 2) + 1;
        fruitY = rand() % (width - 2) + 1;
    }
}

void gameOver() {
    system("cls");
    printf("\n\n\tGame Over!\n\tFinal Score: %d\n\tPress any key to exit...\n", score);
    _getch();
}

int main() {
    setup();
    while (!gameend) {
        draw();
        input();
        makelogic();
        Sleep(100);
    }
    gameOver();
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conioex.h"


// printing of the field

void print_row_empty(){ //leere zeile

    for(int i = 0; i<4; i++){
        printf("%c ", 186);
        textcolor(LIGHTRED);
        printf("      ");
        textcolor(LIGHTGRAY);
    }
    printf("%c\n", 186);

}
void print_row(int m[4][4], int z){ //field & zeile

    for(int i = 0; i<4; i++){
        printf("%c ", 186);


        switch(m[z][i]){

            case 0:
                textcolor(LIGHTRED);
                printf("      ");
                break;

            case 2:
                textcolor(LIGHTRED);
                printf("  2   ");
                break;

            case 4:
                textcolor(RED);
                printf("  4   ");
                break;

            case 8:
                textcolor(YELLOW);
                printf("  8   ");
                break;

            case 16:
                textcolor(LIGHTGREEN);
                printf(" 16   ");
                break;

            case 32:
                textcolor(GREEN);
                printf(" 32   ");
                break;

            case 64:
                textcolor(LIGHTCYAN);
                printf(" 64   ");
                break;

            case 128:
                textcolor(CYAN);
                printf(" 128  ");
                break;

            case 256:
                textcolor(LIGHTBLUE);
                printf(" 256  ");
                break;

            case 512:
                textcolor(BLUE);
                printf(" 512  ");
                break;

            case 1024:
                textcolor(LIGHTMAGENTA);
                printf("1024  ");
                break;

            case 2048:
                textcolor(MAGENTA);
                printf("2048  ");
                break;

            default:
                textcolor(RED);
                printf("ERROR!");
                break;

        }

        textcolor(LIGHTGRAY);
    }
    printf("%c\n", 186);

}
void print_field(int m[4][4]){ // zeile

    textcolor(LIGHTGRAY);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 187);
    print_row_empty();
    print_row(m,0);
    print_row_empty();
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,1);
    print_row_empty();
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,2);
    print_row_empty();
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,3);
    print_row_empty();
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 188);
    textcolor(LIGHTGRAY);

}

//game logic

int spawn_num(int feld[4][4]){
    //testest
    int i;
    int j;
    int done = 0;

    srand(time(NULL));

    while(!done)
    {
        i = rand() % (3 + 1 - 0) + 0;
        j = rand() % (3 + 1 - 0) + 0;
        if(feld[i][j]==0)
        {
            feld[i][j]=2;
            done=1;
        }
    }
}

int check_win(int m[4][4]){

    for(int x=0; x<4; x++){

        for(int y=0; y<4; y++){
            if(m[y][x]==2048){
                return 1;
            }
        }

    }

    return 0;

}


int check_down(int m[4][4]) {
    int possible = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 3; y > 0; y--) {
            int over = m[y - 1][x];
            int current = m[y][x];

            if (over == current || current == 0) {
                possible++;
            }
        }
    }
    return (possible > 0) ? 1 : 0;
}

int check_up(int m[4][4]) {
    int possible = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 3; y++) {
            int over = m[y + 1][x];
            int current = m[y][x];

            if (over == current || current == 0) {
                possible++;
            }
        }
    }
    return (possible > 0) ? 1 : 0;
}


int check_left(int m[4][4]) {
    int possible = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
            int over = m[y][x + 1];
            int current = m[y][x];

            if (over == current || current == 0) {
                possible++;
            }
        }
    }
    return (possible > 0) ? 1 : 0;
}

int check_right(int m[4][4]) {
    int possible = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 3; x > 0; x--) {
            int over = m[y][x - 1];
            int current = m[y][x];

            if (over == current || current == 0) {
                possible++;
            }
        }
    }
    return (possible > 0) ? 1 : 0;
}

int check_legal_moves(int m[4][4]) {
    if (check_up(m) || check_down(m) || check_left(m) || check_right(m)) {
        return 1;
    } else {
        return 0;
    }
}

// gravity

void gravity_down(int m[4][4]){

    for(int i =0; i<3; i++){
        if(check_down(m)==1){

            for(int x=0; x<4; x++){

                for(int y=3; y>0; y--){
                    int over = m[y-1][x];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y-1][x];
                        m[y-1][x] = 0;
                    }
                }

            }

        }
    }

}
void gravity_up(int m[4][4]){

    for(int i =0; i<3; i++){
        if(check_up(m)==1){

            for(int x=0; x<4; x++){

                for(int y=0; y<3; y++){
                    int over = m[y+1][x];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y+1][x];
                        m[y+1][x] = 0;
                    }
                }

            }

        }
    }

}

void gravity_left(int m[4][4]){

    for(int i =0; i<3; i++){
        if(check_left(m)==1){

            for(int y=0; y<4; y++){

                for(int x=0; x<3; x++){
                    int over = m[y][x+1];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y][x+1];
                        m[y][x+1] = 0;
                    }
                }

            }

        }

    }

}
void gravity_right(int m[4][4]){

    for(int i =0; i<3; i++){
        if(check_right(m)==1){

            for(int y=0; y<4; y++){

                for(int x=3; x>0; x--){
                    int over = m[y][x-1];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y][x-1];
                        m[y][x-1] = 0;
                    }
                }

            }

        }

    }

}

int main(){

    int field[4][4] =  {{0,0,0,0},
                        {512,0,0,512},
                        {0,0,0,0},
                        {1024,0,0,0}};
    int key_valid = 0;
    int run = 1;
    int win = 0;
    int fail = 0;

    spawn_num(field);

     do {
        srand(time(NULL));
        key_valid = 0;
        clrscr();
        spawn_num(field);
        print_field(field);

        do {
            if (kbhit()) {
                char c = getch();
                switch (c) {
                    case 72:
                        gravity_up(field);
                        key_valid = 1;
                        break;
                    case 80:
                        gravity_down(field);
                        key_valid = 1;
                        break;
                    case 75:
                        gravity_left(field);
                        key_valid = 1;
                        break;
                    case 77:
                        gravity_right(field);
                        key_valid = 1;
                        break;
                }
            }
        } while (!key_valid);

        win = check_win(field);

    } while (run && !win && check_legal_moves(field));

    clrscr();
    print_field(field);

    if (win) {
        printf("You won!\n");
    } else {
        printf("Game over!\n");
    }

    return 0;
}

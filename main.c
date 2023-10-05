#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conioex.h"


// printing of the field

void print_row_empty(){ //empty row

    for(int i = 0; i<4; i++){
        printf("%c ", 186);
        textcolor(LIGHTRED);
        printf("      ");
        textcolor(LIGHTGRAY);
    }
    printf("%c\n", 186);

}
void print_row(int m[4][4], int z){ //field & row

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
void print_field(int m[4][4]){ // row

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

int spawn_num(int feld[4][4]){ //spawning numbers after each move

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

int check_down(int m[4][4]) { // checking if numbers can be moved down
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

int check_up(int m[4][4]) { // checking if numbers can be moved up
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

int check_left(int m[4][4]) { // checking if numbers can be moved to the left
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

int check_right(int m[4][4]) { //checking if numbers can be moved to the right
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

int check_legal_moves(int m[4][4]) { //checking if moves are legal
    if (check_up(m) || check_down(m) || check_left(m) || check_right(m)) {
        return 1;
    } else {
        return 0;
    }
}

int check_free(int field[4][4]){ // checking if there are any free fields
    int i;
    int j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(field[i][j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

// gravity

int gravity_down(int m[4][4]){ //moves numbers downside

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
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_up(int m[4][4]){ // moves numbers up

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
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_left(int m[4][4]){ //moves numbers to the left

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
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_right(int m[4][4]){ // moves numbers to the right

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
        else{
            return 1;
        }
    }
    return 0;

}

int spawn_possible( int field[4][4]){ // checking if numbers need to be spawned
    int i;
    int j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(field[i][j]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}

// main bruh

int main(){

    int field[4][4] =  {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};

    int key_valid = 0;
    int run = 1;
    int win = 0;
    int fail = 0;

    spawn_num(field);

     do {
        srand(time(NULL));
        key_valid = 0;
        clrscr();
        if(spawn_possible(field))
        {
            spawn_num(field);
        }

        print_field(field);

        do {
            if (kbhit()) { // gets input from user
                char c = getch();
                switch (c) {
                    case 72:
                        if(gravity_up(field) && (!check_free(field))){fail=1;}
                        key_valid = 1;
                        break;
                    case 80:
                        if(gravity_down(field) && (!check_free(field))){fail=1;}
                        key_valid = 1;
                        break;
                    case 75:
                        if(gravity_left(field) && (!check_free(field))){fail=1;}
                        key_valid = 1;
                        break;
                    case 77:
                        if(gravity_right(field) && (!check_free(field))){fail=1;}
                        key_valid = 1;
                        break;
                }
            }
        } while (!key_valid);

        win = check_win(field);

    } while (run && !win && check_legal_moves(field) && !fail ); // checking if game needs to be run

    clrscr();
    print_field(field);

    if (win) { // checking win or loss
        printf("You won!\n");
    } else {
        printf("Game over!\n");
    }

    return 0;
}

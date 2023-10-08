#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conioex.h"
#include <windows.h>

// printing of the field

void print_row_empty(){ //empty row

    printf("      ");
    for(int i = 0; i<4; i++){
        printf("%c ", 186);
        textcolor(LIGHTRED);
        printf("      ");
        textcolor(LIGHTGRAY);
    }
    printf("%c     \n", 186);

}
void print_row(int m[4][4], int z){ //field & row

    printf("      ");
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
    printf("%c     \n", 186);

}
void print_field(int m[4][4],int score){ // row

    textcolor(LIGHTGRAY);
    print_score(score);

    printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     \n", 201, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 187);
    print_row_empty();
    print_row(m,0);
    print_row_empty();
    printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     \n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,1);
    print_row_empty();
    printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     \n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,2);
    print_row_empty();
    printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     \n", 204, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 185);
    print_row_empty();
    print_row(m,3);
    print_row_empty();
    printf("      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c     \n", 200, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 188);
    textcolor(LIGHTGRAY);

}
void print_logo(){

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    textcolor(LIGHTRED);
    printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c  %c%c%c %c%c%c%c%c%c \n", 219, 219, 219, 219, 219, 219, 187,  219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 219, 219, 187, 219, 219, 187, 219, 219, 219, 219, 219, 187);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219 ,  219 ,  201 ,  205 ,  205 ,  205 ,  205 ,  188 ,  200 ,  205 ,  205 ,  205 ,  205 ,  219 ,  219 ,  187 ,  219 ,  219 ,  201 ,  205 ,  219 ,  219 ,  219 ,  219 ,  187 ,  219 ,  219 ,  186 ,  32 ,  32 ,  219 ,  219 ,  186 ,  219 ,  219 ,  201 ,  205 ,  205 ,  219 ,  219 ,  187);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219 ,  219 ,  186 ,  32 ,  32 ,  32 ,  32 ,  32 ,  32 ,  219 ,  219 ,  219 ,  219 ,  219 ,  201 ,  188 ,  219 ,  219 ,  186 ,  219 ,  219 ,  201 ,  219 ,  219 ,  186 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  186 ,  200 ,  219 ,  219 ,  219 ,  219 ,  219 ,  201 ,  188);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 219 ,  219 ,  186 ,  32 ,  32 ,  32 ,  32 ,  32 ,  219 ,  219 ,  201 ,  205 ,  205 ,  205 ,  188 ,  32 ,  219 ,  219 ,  219 ,  219 ,  201 ,  188 ,  219 ,  219 ,  186 ,  200 ,  205 ,  205 ,  205 ,  205 ,  219 ,  219 ,  186 ,  219 ,  219 ,  201 ,  205 ,  205 ,  219 ,  219 ,  187);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  187 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  187 ,  200 ,  219 ,  219 ,  219 ,  219 ,  219 ,  219 ,  201 ,  188 ,  32 ,  32 ,  32 ,  32 ,  32 ,  219 ,  219 ,  186 ,  200 ,  219 ,  219 ,  219 ,  219 ,  219 ,  201 ,  188);
    printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200 ,  205 ,  205 ,  205 ,  205 ,  205 ,  188 ,  200 ,  205 ,  205 ,  205 ,  205 ,  205 ,  205 ,  188 ,  32 ,  200 ,  205 ,  205 ,  205 ,  205 ,  205 ,  188 ,  32 ,  32 ,  32 ,  32 ,  32 ,  32 ,  200 ,  205 ,  188 ,  32 ,  200 ,  205 ,  205 ,  205 ,  205 ,  188);
}
void print_score(int score){

    char input[33];

    int totalWidth = 33;
    sprintf(input, "Score: %d", score);
    int inputWidth = strlen(input);


    printf("      ");
    if (inputWidth >= totalWidth) {
        // String is as wide as or wider than the line, print it as is.
        printf("%s\n", input);
    } else {
        // Calculate padding on both sides to center the string.
        int padding = (totalWidth - inputWidth) / 2;

        // Print leading spaces.
        for (int i = 0; i < padding; ++i) {
            printf(" ");
        }

        // Print the string.
        printf("%s", input);

        // Print trailing spaces and newline.
        for (int i = 0; i < padding; ++i) {
            printf(" ");
        }
        printf("\n");
    }

}

// sequences
void zero_field(int m[4][4]){

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            m[y][x]=0;
        }
    }

}

void startup_seq(){

    SetConsoleTitle("  - c2048 -  ");

    HWND wh = GetConsoleWindow();
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    RECT rect;
    COORD newSize;

    GetWindowRect(wh, &rect);
    MoveWindow(wh, rect.left, rect.top, 360, 360, TRUE);

    newSize.X = 45;
    newSize.Y = 20;
    SetConsoleScreenBufferSize(hOut, newSize);

    printf("\e[?25l"); //disable cursor

    clrscr();
    print_logo();

    sleep(2);

}

void windowloop(){

    HWND wh = GetConsoleWindow();

    RECT rect;
    GetWindowRect(wh, &rect);

    MoveWindow(wh, rect.left, rect.top, 360, 360, TRUE);

}

void end_seq_win(){

    gotoxy(18,9);
    textcolor(LIGHTGRAY);
    printf("%c%c%c%c%c%c%c%c%c ", 201, 205, 205, 205, 202, 205, 205, 205, 187);
    gotoxy(18,10);
    textcolor(LIGHTGRAY);
    printf("%c ", 185);
    textcolor(GREEN);
    printf("You Won");
    textcolor(LIGHTGRAY);
    printf("%c",204);
    gotoxy(18,11);
    textcolor(LIGHTGRAY);
    printf("%c%c%c%c%c%c%c%c%c ", 200, 205, 205, 205, 203, 205, 205, 205, 188);
} //y10 x16

void end_seq_loose(){

    gotoxy(17,9);
    textcolor(LIGHTGRAY);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c ", 201, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 187);
    gotoxy(17,10);
    textcolor(LIGHTGRAY);
    printf("%c ", 185);
    textcolor(RED);
    printf("Game Over");
    textcolor(LIGHTGRAY);
    printf(" %c",204);
    gotoxy(17,11);
    textcolor(LIGHTGRAY);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c ", 200, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 188);
} //y10 x16

int end(){

    int valid=0;
    char c;

    textcolor(LIGHTCYAN);
    gotoxy(7,19);
    printf("[R]estart");

    gotoxy(17,19);
    printf("[Q]uit");


    do{
        fflush(stdin);

        c = getch();
        switch(c){

            case 'Q':
            case 'q':
                textcolor(LIGHTGRAY);
                clrscr();
                valid = 1;
                return 0;
                break;

            case 'R':
            case 'r':
                textcolor(LIGHTGRAY);
                clrscr();
                valid = 1;
                return 1;
                break;

            default:
                valid = 0;

        }
    } while (!valid);



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

int gravity_down(int m[4][4], int *score){ //moves numbers downside

    for(int i =0; i<3; i++){
        if(check_down(m)==1){

            for(int x=0; x<4; x++){

                for(int y=3; y>0; y--){
                    int over = m[y-1][x];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y-1][x];
                        *score += m[y-1][x];
                        m[y-1][x] = 0;
                    }
                }

            }

            Sleep(25);
            clrscr();
            print_field(m, *score);

        }
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_up(int m[4][4], int *score){ // moves numbers up

    for(int i =0; i<3; i++){
        if(check_up(m)==1){

            for(int x=0; x<4; x++){

                for(int y=0; y<3; y++){
                    int over = m[y+1][x];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y+1][x];
                        *score += m[y+1][x];
                        m[y+1][x] = 0;
                    }
                }

            }

            Sleep(30);
            clrscr();
            print_field(m, *score);

        }
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_left(int m[4][4], int *score){ //moves numbers to the left

    for(int i =0; i<3; i++){
        if(check_left(m)==1){

            for(int y=0; y<4; y++){

                for(int x=0; x<3; x++){
                    int over = m[y][x+1];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y][x+1];
                        *score += m[y][x+1];
                        m[y][x+1] = 0;
                    }
                }

            }

            Sleep(30);
            clrscr();
            print_field(m, *score);

        }
        else{
            return 1;
        }
    }
    return 0;

}

int gravity_right(int m[4][4], int *score){ // moves numbers to the right

    for(int i =0; i<3; i++){
        if(check_right(m)==1){

            for(int y=0; y<4; y++){

                for(int x=3; x>0; x--){
                    int over = m[y][x-1];
                    int current = m[y][x];

                    if(over==current || current == 0){
                        m[y][x]+= m[y][x-1];
                        *score += m[y][x+1];
                        m[y][x-1] = 0;
                    }
                }

            }

            Sleep(30);
            clrscr();
            print_field(m, *score);

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


    int field[4][4];
    int key_valid = 0;
    int run = 1;
    int win = 0;
    int fail = 0;
    int restart = 0;
    int score = 0;

    startup_seq();

    do{

        zero_field(field);

        key_valid = 0;
        run = 1;
        win = 0;
        fail = 0;
        restart = 0;
        score = 0;

        spawn_num(field);

        do {
            srand(time(NULL));
            key_valid = 0;
            clrscr();
            if(spawn_possible(field))
            {
                spawn_num(field);
            }

            print_field(field, score);

            do {
                windowloop();
                if (kbhit()) { // gets input from user
                    char c = getch();
                    switch (c) {
                        case 72:
                            if(gravity_up(field, &score) && (!check_free(field))){fail=1;}
                            key_valid = 1;
                            break;
                        case 80:
                            if(gravity_down(field, &score) && (!check_free(field))){fail=1;}
                            key_valid = 1;
                            break;
                        case 75:
                            if(gravity_left(field, &score) && (!check_free(field))){fail=1;}
                            key_valid = 1;
                            break;
                        case 77:
                            if(gravity_right(field, &score) && (!check_free(field))){fail=1;}
                            key_valid = 1;
                            break;
                    }
                }
            } while (!key_valid);

            win = check_win(field);

        } while (run && !win && check_legal_moves(field) && !fail ); // checking if game needs to be run

        clrscr();
        print_field(field,score);

        if (win) { // checking win or loss
            end_seq_win();
        } else {
            end_seq_loose();
        }

        restart=end();

    }while(restart);


    printf("\e[?25h");//re-enable cursor

    return 0;
}

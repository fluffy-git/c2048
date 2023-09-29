#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conioex.h"


//start:region printing of the field

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
        textcolor(LIGHTRED);

        switch(m[z][i]){

            case 0:
                printf("      ");
                break;

            case 2:
                printf("  2   ");
                break;

            case 4:
                printf("  4   ");
                break;

            case 8:
                printf("  8   ");
                break;

            case 16:
                printf(" 16   ");
                break;

            case 32:
                printf(" 32   ");
                break;

            case 64:
                printf(" 64   ");
                break;

            case 128:
                printf(" 128  ");
                break;

            case 256:
                printf(" 256  ");
                break;

            case 512:
                printf(" 512  ");
                break;

            case 1024:
                printf("1024  ");
                break;

            case 2048:
                printf("2048  ");
                break;

            default:
                printf("ERROR!");
                break;

        }

        textcolor(LIGHTGRAY);
    }
    printf("%c\n", 186);

}
void print_field(int m[4][4]){ // zeile
//start:region printing of the field

//start:region game logic





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

// gravity

int gravity_down(int m[4][4]){

    int possible = 0;
    for(int i =0; i<3; i++){

        for(int x=0; x<4; x++){

            for(int y=3; y>0; y--){
                int over = m[y-1][x];
                int current = m[y][x];

                if(over==current || current == 0){
                    m[y][x]+= m[y-1][x];
                    m[y-1][x] = 0;
                    possible++;
                }
            }

        }

    }

    return possible;

}
int gravity_up(int m[4][4]){

    int possible = 0;
    for(int i =0; i<3; i++){

        for(int x=0; x<4; x++){

            for(int y=0; y<3; y++){
                int over = m[y+1][x];
                int current = m[y][x];

                if(over==current || current == 0){
                    m[y][x]+= m[y+1][x];
                    m[y+1][x] = 0;
                    possible++;
                }
            }

        }

    }

    return possible;

}

int gravity_left(int m[4][4]){

    int possible = 0;
    for(int i =0; i<3; i++){

        for(int x=0; x<4; x++){

            for(int y=3; y>0; y--){
                int over = m[y-1][x];
                int current = m[y][x];

                if(over==current || current == 0){
                    m[y][x]+= m[y-1][x];
                    m[y-1][x] = 0;
                    possible++;
                }
            }

        }

    }

    return possible;

}
int gravity_right(int m[4][4]){

    int possible = 0;
    for(int i =0; i<3; i++){

        for(int x=0; x<4; x++){

            for(int y=3; y>0; y--){
                int over = m[y-1][x];
                int current = m[y][x];

                if(over==current || current == 0){
                    m[y][x]+= m[y-1][x];
                    m[y-1][x] = 0;
                    possible++;
                }
            }

        }

    }

    return possible;

}

int main()
{
    int field[4][4] =  {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    int key_valid = 0;
    int game = 1;

    spawn_num(field);

    while(1){
        key_valid=0;

        clrscr();
        spawn_num(field);
        print_field(field); //feld ausgeben


        do{ // überprüfung ob die taste gültig ist
            if ( kbhit() )
            {
                char c = getch();
                switch( c ) // entscheiden was passiert
                {
                case 72 :
                    if(gravity_up(field) != 0){
                        game=0;
                    }
                    key_valid=1;
                    break;
                case 80 :
                    if(gravity_down(field) != 0){
                        game=0;
                    }
                    key_valid=1;
                    break;
                case 75 :
                    key_valid=1;
                    break;
                case 77 :
                    key_valid=1;
                    break;
                }
            }
        }while(!key_valid);

    }

    printf("game over!");
    return 0;
}

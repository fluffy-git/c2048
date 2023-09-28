#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conioex.h"

void print_row(int m[4][4], int z){ //field & zeile

    for(int i = 0; i<4; i++){
        printf("%c ", 186);
        textcolor(LIGHTRED);

        if(m[z][i]== 0)
        {
            printf("  ");
        }
        else{
            printf("%d ", m[z][i]);
        }

        textcolor(LIGHTGRAY);
    }
    printf("%c\n", 186);

}

void print_field(int m[4][4]){ // zeile

    textcolor(LIGHTGRAY);

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
    print_row(m,0);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
    print_row(m,1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
    print_row(m,2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
    print_row(m,3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);

    textcolor(LIGHTGRAY);

}
int spawn_num(int feld[4][4])
{
    int i;
    int j;
    srand(time(NULL));
    while(feld[i][j]==0)
    {
        i = rand() % (3 + 1 - 0) + 0;
        j = rand() % (3 + 1 - 0) + 0;
        if(feld[i][j]==0)
        {
            feld[i][j]=2;
        }
    }


}
int main()
{
    int field[4][4] =  {{0,2,0,0},
                        {0,0,0,0},
                        {0,0,8,0},
                        {16,0,0,4}};

    print_field(field);
    spawn_num(field);
    return 0;
}

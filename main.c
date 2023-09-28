#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"

void print_row(int m[4][4], int z){ //field & zeile

    for(int i = 0; i<4; i++){
        printf("%c ", 186);
        textcolor(LIGHTRED);

        if(m[z][i])

        printf("%d ", m[z][i]);
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

int main()
{
    int field[4][4] =  {{0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};

    print_field(field);

    return 0;
}

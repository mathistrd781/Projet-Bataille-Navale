//
// Created by mathi on 14/11/2022.
//

#include "header.h"

///SOURCE CAMPUS ONLINE
void gotoligcol(int lig, int col)
{
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void hide_cursor(int visible)
{
    HANDLE cH=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO inf;
    inf.dwSize=1;
    inf.bVisible=visible;
    SetConsoleCursorInfo(cH,&inf);
}
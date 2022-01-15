// novembre 2015 - version 1
// Change font & background color
// And define a _getch() fonction in linux, like windows.


#ifndef CONSOLEJR_H__
#define CONSOLEJR_H__

//*********************************---Linux---**************************************************************************************
#ifdef __linux__ 

#define BLACK       30
#define RED         31
#define GREEN       32
#define YELLOW      33
#define BLUE        34
#define PURPLE      35
#define CYAN        36
#define WHITE       37

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------------------------------------------------------------------
static void clear()
{
 system("clear");
}

//----------------------------------------------------------------------------------------------------------------------------------
#define gotoxy(x,y) printf("\033[%d;%df", y, x)

//----------------------------------------------------------------------------------------------------------------------------------
#define color(paramChar, paramBackground) printf("\033[1;%dm""\033[1;%dm", paramChar, paramBackground+10)

//----------------------------------------------------------------------------------------------------------------------------------
static int _getch() {
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

//*****************--Windows--***************************************************************************************************
#elif _WIN32

#include <Windows.h>
#include <conio.h>

#define BLACK      0
#define RED        12
#define GREEN      2
#define YELLOW     14
#define BLUE       1
#define PURPLE     5
#define CYAN       11
#define WHITE       15

//---------------------------------------------------------------------------------------------------------------------------------
static void clear() 
{
	system("cls");
}
//---------------------------------------------------------------------------------------------------------------------------------
static void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x - 1;
  coord.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//---------------------------------------------------------------------------------------------------------------------------------
static void color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//---------------------------------------------------------------------------------------------------------------------------------
static void usleep( long long usec)
{
    HANDLE timer;
    LARGE_INTEGER ft;

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL);
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}
#endif
//-----------------------------------------------------------------------------------------------
#endif

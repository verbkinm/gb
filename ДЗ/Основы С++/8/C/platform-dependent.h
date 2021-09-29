#pragma once

#ifdef unix
    #include <termios.h>
    #include <unistd.h>

int getch();

#elif _WIN32
    #include <conio.h>
    #include <windows.h>
#endif

#include <stdio.h>

#define LINE_LENGTH 40
#define LINE_COUNT 30

// Очистка консоли
void consoleClear(void);

// Установка курсора на позицию  x y
void setCursorPos(int x, int y);

// Скрыть курсор
void hideCursor(void);

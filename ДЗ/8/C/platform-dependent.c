#include "platform-dependent.h"

#ifdef unix

void consoleClear()
{
    printf("\033c");
}

void setCursorPos(int x, int y)
{

}

void hideCursor()
{
    printf("\e[?25l");
}

int getch( )
{
    struct termios oldt, newt;
    int ch;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

#elif _WIN32

void consoleClear(void)
{
    setCursorPos(0,0);

    char arr[LINE_LENGTH];
    memset(arr, ' ', LINE_LENGTH - 2);
    arr[LINE_LENGTH - 2] = '\n';
    arr[LINE_LENGTH - 1] = '\0';

    for(int i = 2; i <= LINE_COUNT; i++)
        printf("%s", arr);

    setCursorPos(0,0);
}

void setCursorPos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void hideCursor(void)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle,&structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( handle, &structCursorInfo );
}

#endif


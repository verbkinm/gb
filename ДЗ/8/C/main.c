#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <conio.h>
#include <windows.h>

const char _X = 'X';
const char _0 = '0';

char field[] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};

char* _1 = &field[0];
char* _2 = &field[1];
char* _3 = &field[2];
char* _4 = &field[3];
char* _5 = &field[4];
char* _6 = &field[5];
char* _7 = &field[6];
char* _8 = &field[7];
char* _9 = &field[8];

unsigned char player1Vic = 0;
unsigned char player2Vic = 0;

char playerName[2][10] = { {"Player 1"}, {"Player 2"} };

unsigned char playerNumberMove = 0;
unsigned char moveCount = 0;

unsigned char undoCell = 0;

enum modeName { PC, HUMAN };
char mode = PC;

enum levelName { EASY, NORMAL, HARD};
char level = EASY;

void banner(void);
void enterPressWait(void);

void playersVictories(void);
void playerMove(void);
void setPlayerName(char *name);

// Вывод данных в консоль
void printField(void);
void printCommandName(void);
void printDataGame(void);

// Очистка консоли
void consoleClear(void);

// Ввод команды
char readCommand(void);

// Отмена последнего действия (только при игре с человеком)
void undo(void);

// Перезапуск всей игры
void restartGame(void);

// Обнуление поля
void restartField(void);

// Проверка на победу
void checkField(void);
int checkRow(char *arr);
int checkColumn(char *arr);
int checkDiagonal(char *arr);

// Ход ИИ
char AI_Move(void);

// Если в строке не хватает одного хода до победы или поражения
char AI_OneSymbolBefore(char vicSymbol);

// Провекра на наличие двух одинаковых символов и пустую ячейку
char AI_OneRow(char* arr, char vicSymbol);
char AI_OneColumn(char* arr, char vicSymbol);
char AI_Diagonal(char vicSymbol);

// Выбор режима игры: с человеком или с компьютером
void gameMode(void);

// Уровень сложности
void levelMode(void);

// Установка курсора на позицию  x y
void setCursorPos(int x, int y);
// Скрыть курсор
void hideCursor(void);

int main()
{
    hideCursor();
    gameMode();

    do
    {
        printDataGame();
        checkField();
    }
    while (readCommand() != 'e');

    printf(" Game over!\n");
    return 0;
}

void banner(void)
{
    printf(" Welcome to the game of tic tac toe! =))\n\n");
}

void printField(void)
{
    printf("\t %c | %c | %c\n"
           "\t-----------\n"
           "\t %c | %c | %c\n"
           "\t-----------\n"
           "\t %c | %c | %c\n\n", *_7, *_8, *_9, *_4, *_5, *_6, *_1, *_2, *_3);
}

void playersVictories(void)
{
    printf(" %s (X) victories: %d\n"
           " %s (0) victories: %d\n\n",
           playerName[0], player1Vic, playerName[1], player2Vic);
}

void playerMove(void)
{
    printf(" Move number %d: \n"
           " Player \"%s\" move now.\n\n",
           moveCount + 1, playerName[(int)playerNumberMove]);
}

void printCommandName(void)
{
    printf(" h\t- help\n"
           " 1..9\t- set cell\n");

    if(mode == HUMAN)
        printf(" u\t- undo\n");

    printf(" r\t- reset\n"
           " e\t- exit\n\n");
}

void consoleClear(void)
{
    setCursorPos(0,0);

    char arr[40];
    memset(arr, ' ', 38);
    arr[38] = '\n';
    arr[39] = '\0';

    for(int i = 2; i <= 30; i++)
        printf("%s", arr);

    setCursorPos(0,0);
}

char readCommand(void)
{
    char input = 0;

    if(mode == PC)
    {
        if(playerNumberMove == 1)
            input = getch();
        else
            input = AI_Move();
    }
    else if(mode == HUMAN)
        input = getch();

    switch (input)
    {
    case 'e':
        break;
    case 'r':
        restartGame();
        break;
    case 'h':
        if(mode == PC)
            printf(" Difficulty level: %d\n", level + 1);

        printf("\t 7 | 8 | 9\n"
               "\t-----------\n"
               "\t 4 | 5 | 6\n"
               "\t-----------\n"
               "\t 1 | 2 | 3\n\n");
        enterPressWait();
        break;

    case 'u':
        undo();
        break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        undoCell = input;
        const int index = (input - '0') - 1;

        if(field[index] == _0 || field[index] == _X)
        {
            printf(" Cell %d is not empty!", index + 1);
            enterPressWait();
            break;
        }

        if(playerNumberMove)
            field[index] = _0;
        else
            field[index] = _X;

        playerNumberMove ^= 1;
        moveCount++;
        break;

    default:
        printf(" Incorrect input: '%c'.", input);
        enterPressWait();
        break;
    }

    return input;
}

void restartGame(void)
{
    player1Vic = 0;
    player2Vic = 0;
    playerNumberMove = 0;

    restartField();
}

void restartField(void)
{
    moveCount = 0;
    undoCell = 0;

    memset(field, ' ', 9);
}

int checkRow(char *arr)
{
    if(*arr == *(arr + 1) && *arr == *(arr + 2) && *arr != ' ')
        return 1;

    return 0;
}

int checkColumn(char *arr)
{
    if(*arr == *(arr + 3) && *arr == *(arr + 6) && *arr != ' ')
        return 1;

    return 0;
}

int checkDiagonal(char *arr)
{
    if( arr[4] != ' ' &&
            ((arr[0] == arr[4] && arr[0] == arr[8]) || (arr[2] == arr[4] && arr[2] == arr[6])) )
    {
        return 1;
    }

    return 0;
}

void checkField(void)
{
    if(checkRow(_1) || checkRow(_4) || checkRow(_7) ||
            checkColumn(_1) || checkColumn(_2) || checkColumn(_3) ||
            checkDiagonal(field))
    {
        if(playerNumberMove)
            player1Vic++;
        else
            player2Vic++;

        printf(" Player \"%s\" lost!", playerName[(int)playerNumberMove]);
        enterPressWait();
        restartField();
    }

    if(moveCount == 9)
    {
        restartField();
        printf(" Friendship!");
        enterPressWait();
    }

    printDataGame();
}

void printDataGame(void)
{
    consoleClear();
    banner();
    playersVictories();
    playerMove();
    printField();
    printCommandName();
}

void undo(void)
{
    if(undoCell == 0)
    {
        printf(" You can't use this.");
        enterPressWait();
        return;
    }

    playerNumberMove ^= 1;
    field[undoCell - '0' - 1] = ' ';

    undoCell = 0;
    moveCount--;

    printDataGame();
}

void enterPressWait()
{
    printf(" (Press Enter)");
    while (getch() != 13); // ASCII Enter code
}

char AI_Move(void)
{
    if(level == EASY)
    {
        while(1)
        {
            srand(time(0));
            int result = rand() % 9 + 1;

            if(field[result - 1] == ' ')
                return result + '0';
        }
    }

    // Проверка на один символ, недостающий до победы или поражения.
    if(AI_OneSymbolBefore(_X) != 0)
        return AI_OneSymbolBefore(_X);
    else if(AI_OneSymbolBefore(_0) != 0)
        return AI_OneSymbolBefore(_0);

    // Занять середину, если пуста.
    if(level == HARD && *_5 == ' ')
        return '5';

    // Если сейчас третий ход, а игрок поставил нолик в ячейку 2 или 4 или 6 или 8, то всё...
    // Это проигрышная комбинация для игрока.
    if(level == HARD && moveCount == 2)
    {
        if(*_2 == _0)
            return '7';
        else if(*_4 == _0)
            return '9';
        else if(*_6 == _0 || *_8 == _0)
            return '1';
    }

    // Занять первую пустую угловую ячейку.
    for (int i = 0; i < 9; i += 2)
    {
        if(field[i] == ' ')
            return i + 1 + '0';
    }

    // Занять первую пустую не угловую ячейку.
    for (int i = 1; i < 9; i += 2)
    {
        if(field[i] == ' ') //!= _0 && field[i] != _X)
            return i + 1 + '0';
    }

    // Программа сюда не должена доходить.
    return '!';
}
char AI_OneRow(char* arr, char vicSymbol)
{
    if(*arr == vicSymbol &&
            *(arr + 1) == vicSymbol &&
            *(arr + 2) == ' ')
    {
        return '3';
    }
    else if(*arr == vicSymbol &&
            *(arr + 1) == ' ' &&
            *(arr + 2) == vicSymbol) // X !X X
    {
        return '2';
    }
    else if(*arr == ' ' &&
            *(arr + 1) == vicSymbol &&
            *(arr + 2) == vicSymbol) // !X X X
    {
        return '1';
    }

    return 0;
}

char AI_OneColumn(char* arr, char vicSymbol)
{
    // !X        7 8 9
    // X         4 5 6
    // X         1 2 3
    if(*arr == vicSymbol &&
            *(arr + 3) == vicSymbol &&
            *(arr + 6) ==  ' ')
    {
        return '7';
    }
    // X
    // !X
    // X
    else if(*arr == vicSymbol &&
            *(arr + 3) == ' ' &&
            *(arr + 6) == vicSymbol)
    {
        return '4';
    }
    // X
    // X
    // !X
    else if(*arr == ' ' &&
            *(arr + 3) == vicSymbol &&
            *(arr + 6) == vicSymbol)
        return '1';

    return 0;
}

char AI_Diagonal(char vicSymbol)
{
    //     X
    //   X
    // !X
    if(*_1 == ' ' &&
            *_5 == vicSymbol &&
            *_9 == vicSymbol)
    {
        return *_1;
    }
    //      X
    //   !X
    // X
    else if(*_1 == vicSymbol &&
            *_5 == ' ' &&
            *_9 == vicSymbol)
    {
        return '5';
    }
    //     !X
    //   X
    // X
    else if(*_1 == vicSymbol &&
            *_5 == vicSymbol &&
            *_9 == ' ' )
    {
        return '9';
    }
    // !X
    //    X
    //      X
    else if(*_3 == vicSymbol &&
            *_5 == vicSymbol &&
            *_7 == ' ')
    {
        return '7';
    }
    // X
    //   !X
    //      X
    else if(*_3 == vicSymbol &&
            *_5 == ' ' &&
            *_7 == vicSymbol)
    {
        return '5';
    }
    // X
    //   X
    //     !X
    else if(*_3 == ' ' &&
            *_5 == vicSymbol &&
            *_7 == vicSymbol)
    {
        return '3';
    }

    return 0;
}

char AI_OneSymbolBefore(char vicSymbol)
{
    if(playerNumberMove == 1)
        return 0;

    if(AI_OneRow(_1, vicSymbol) != 0)
    {
        return AI_OneRow(_1, vicSymbol);
    }
    else if(AI_OneRow(_4, vicSymbol) != 0)
    {
        return AI_OneRow(_4, vicSymbol) + 3;
    }
    else if(AI_OneRow(_7, vicSymbol) != 0)
    {
        return AI_OneRow(_7, vicSymbol) + 6;
    }

    if(AI_OneColumn(_1, vicSymbol) != 0)
    {
        return AI_OneColumn(_1, vicSymbol);
    }
    else if(AI_OneColumn(_2, vicSymbol) != 0)
    {
        return AI_OneColumn(_2, vicSymbol) + 1;
    }
    else if(AI_OneColumn(_3, vicSymbol) != 0)
    {
        return AI_OneColumn(_3, vicSymbol) + 2;
    }

    if(AI_Diagonal(vicSymbol) != 0)
        return AI_Diagonal(vicSymbol);

    return 0;
}

void gameMode(void)
{
    banner();

    printf(" Select game mode:\n"
           " 1: Play with PC\n"
           " 2: Play with human\n\n");

    while(1)
    {
        char input = getch();
        if(input == '1')
        {
            mode = PC;

            strcpy(playerName[0], "PC");
            strcpy(playerName[1], "User");

            levelMode();

            break;
        }
        else if(input == '2')
        {
            mode = HUMAN;
            break;
        }
    }

    if(mode == HUMAN)
    {
        setPlayerName(playerName[0]);
        setPlayerName(playerName[1]);
    }
}

void levelMode(void)
{
    printf(" Select difficulty level:\n"
           " 1: easy\n"
           " 2: normal\n"
           " 3: hard\n\n");

    while (1)
    {
        char input = getch();

        if(input == '1')
        {
            level = EASY;
            break;
        }
        else if (input == '2')
        {
            level = NORMAL;
            break;
        }
        else if (input == '3')
        {
            level = HARD;
            break;
        }
    }
}

void setPlayerName(char* name)
{
    printf(" Set a new name for %s ?\n"
           " y\\n \n", name);

    while(1)
    {
        char input = getch();

        if(input == 'y' || input == 'Y')
        {
            printf(" Input name: ");
            scanf("%s", name);
            break;
        }
        else if(input == 'n' || input == 'N')
            break;
    }

}

//установка курсора на позицию  x y
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

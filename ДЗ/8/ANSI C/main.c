#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const char _X = 'X';
const char _0 = '0';

char field[] = {
                  '1', '2', '3',
                  '4', '5', '6',
                  '7', '8', '9'
               };

char player1Vic = 0;
char player2Vic = 0;

char playerNumberMove = 0;
char moveCount = 0;

char undoCell = 0;

void banner(void);
void printField(void);
void playersVictories(void);
void playerMove(void);
void printCommandName(void);
void consoleClear(void);
char readCommand(void);

void restartGame(void);
void restartField(void);

void checkField(void);
int checkRow(char *arr);
int checkColumn(char *arr);
int checkDiagonal(char *arr);

void printDataGame(void);
void undo(void);
void enterPressWait(void);

int main()
{
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
    printf("\t %c | %c | %c\n", field[6], field[7], field[8]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", field[3], field[4], field[5]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n\n", field[0], field[1], field[2]);
}

void playersVictories(void)
{
    printf(" Player 1 (X) victories: %d\n", player1Vic);
    printf(" Player 2 (0) victories: %d\n\n", player2Vic);
}

void playerMove(void)
{
    printf(" Move number %d: \n", moveCount + 1);
    printf(" Player %d move now.\n\n", playerNumberMove + 1);
}

void printCommandName(void)
{
    printf(" 1..9\t- set cell\n"
           " u\t- undo\n"
           " r\t- restart\n"
           " e\t- exit\n\n");
}

void consoleClear(void)
{
    system("@cls||clear");
}

char readCommand(void)
{
    char inputCommand = getch();

    switch (inputCommand)
    {
    case 'e':
        break;
    case 'r':
        restartGame();
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
        undoCell = inputCommand;
        const int index = atoi(&inputCommand) - 1;

        if(field[index] == _0 || field[index] == _X)
        {
            printf(" Cell %d is not empty! (Press Enter)", index + 1);
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
        printf(" Incorrect input: '%c'. (Press Enter)\n", inputCommand);
        enterPressWait();
        break;
    }

    return inputCommand;
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
    // ASCII 49 - '0' 57 - '9'
    for (int i = 49, j = 0; i <= 57; ++i, ++j)
        field[j] = i;
}

int checkRow(char *arr)
{
    if(*arr == *(arr + 1) && *arr == *(arr + 2))
        return 1;

    return 0;
}

int checkColumn(char *arr)
{
    if(*arr == *(arr + 3) && *arr == *(arr + 6))
        return 1;

    return 0;
}

int checkDiagonal(char *arr)
{
    if( (arr[0] == arr[4] && arr[0] == arr[8]) ||
        (arr[2] == arr[4] && arr[2] == arr[6]) )
    {
        return 1;
    }

    return 0;
}

void checkField(void)
{
    if(checkRow(&field[0]) || checkRow(&field[3]) || checkRow(&field[6]) ||
       checkColumn(&field[0]) || checkColumn(&field[1]) || checkColumn(&field[2]) ||
       checkDiagonal(field))
    {
        if(playerNumberMove)
            player1Vic++;
        else
            player2Vic++;

        printf("Player %d wins (Press Enter)", (playerNumberMove ^ 1) + 1);
        enterPressWait();
        restartField();
    }

    if(moveCount == 9)
    {
        restartField();
        printf("Friendship! (Press Enter)");
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
        printf(" You can't use this. (Press Enter)\n");
        enterPressWait();
        return;
    }

    playerNumberMove ^= 1;
    const int index = atoi(&undoCell);
    char buff[2];

    sprintf(buff, "%d", index);
    field[index - 1] = buff[0];

    undoCell = 0;
    moveCount--;

    printDataGame();
}

void enterPressWait()
{
    while (getch() != 13); // ASCII Enter code
}

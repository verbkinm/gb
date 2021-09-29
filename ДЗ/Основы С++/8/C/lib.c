#include "lib.h"
#include "ai.h"

void banner(void)
{
    printf(" Welcome to the game of tic tac toe! =))\n\n");
}

void enterPressWait()
{
    printf(" (Press Enter)");
#ifdef unix
    while (getch() != '\n');
#elif _WIN32
    while (getch() != 13); // ASCII Enter code
#endif
}

void printField(char* field)
{
    printf("\t %c | %c | %c\n"
           "\t-----------\n"
           "\t %c | %c | %c\n"
           "\t-----------\n"
           "\t %c | %c | %c\n\n",
           field[6], field[7], field[8],
            field[3], field[4], field[5],
            field[0], field[1], field[2]);
}

void printCommandName(enum modeName mode)
{
    printf(" h\t- help\n"
           " 1..9\t- set cell\n");

    if(mode == HUMAN)
        printf(" u\t- undo\n");

    printf(" n\t- new game\n"
           " r\t- reset\n"
           " e\t- exit\n\n");
}

void restartField(struct Game *game)
{
    game->moveCount = 0;
    game->undoCell = 0;
    //playerData->playerNumberMove ^= 1;

    memset(game->field, EMPTY, SIZE);
}

void restartGame(struct PlayerData *playerData, struct Game* game)
{
    playerData->player1Win = 0;
    playerData->player2Win = 0;
    playerData->playerNumberMove = 0;

    restartField(game);
}

void playersVictories(struct PlayerData* playerData)
{
    printf(" %s (X) victories: %d\n"
           " %s (0) victories: %d\n\n",
           playerData->playerName[0], playerData->player1Win, playerData->playerName[1], playerData->player2Win);
}

void playerMove(struct Game* game, struct PlayerData* playerData)
{
    printf(" Move number %d: \n"
           " Player \"%s\" move now.\n\n",
           game->moveCount + 1, playerData->playerName[(int)playerData->playerNumberMove]);
}

void setPlayerName(char* name)
{
    printf(" Set a new name for %s ?\n"
           " y\\n \n", name);

    while(1)
    {
        char input = getch();

        if(input == 'y')
        {
            printf(" Input name: ");
            scanf("%s", name);
            break;
        }
        else if(input == 'n')
            break;
    }
}

void printDataGame(struct Game* game, struct PlayerData* playerData)
{
    consoleClear();
    banner();
    playersVictories(playerData);
    playerMove(game, playerData);
    printField(game->field);
    printCommandName(game->mode);
}

void undo(struct Game* game, struct PlayerData* playerData)
{
    if(game->mode == PC || game->undoCell == 0)
    {
        printf(" You can't use this.");
        enterPressWait();
        return;
    }

    playerData->playerNumberMove ^= 1;
    game->field[game->undoCell - '0' - 1] = EMPTY;

    game->undoCell = 0;
    game->moveCount--;

    printDataGame(game, playerData);
}

void levelMode(struct Game* game)
{
    printf(" Select difficulty level:\n"
           " 1: easy\n"
           " 2: hard\n\n");

    while (1)
    {
        char input = getch();

        if(input == '1')
        {
            game->level = EASY;
            break;
        }
        else if (input == '2')
        {
            game->level = HARD;
            break;
        }
    }
}

void gameMode(struct Game* game, struct PlayerData* playerData)
{
    banner();

    printf(" Select game mode:\n"
           " 1: Play with PC\n"
           " 2: Play with human\n\n");

    char input;
    while(1)
    {
        input = getch();
        if(input == '1')
        {
            game->mode = PC;

            strcpy(playerData->playerName[0], "PC");
            strcpy(playerData->playerName[1], "User");

            levelMode(game);

            break;
        }
        else if(input == '2')
        {
            game->mode = HUMAN;
            break;
        }
    }

    if(game->mode == HUMAN)
    {
        setPlayerName(playerData->playerName[0]);
        setPlayerName(playerData->playerName[1]);
    }
}

int checkRow(char *arr)
{
    if(*arr == *(arr + 1) && *arr == *(arr + 2) && *arr != EMPTY)
        return 1;

    return 0;
}

int checkColumn(char *arr)
{
    if(*arr == *(arr + 3) && *arr == *(arr + 6) && *arr != EMPTY)
        return 1;

    return 0;
}

int checkDiagonal(char *arr)
{
    if( arr[4] != EMPTY &&
            ((arr[0] == arr[4] && arr[0] == arr[8]) || (arr[2] == arr[4] && arr[2] == arr[6])) )
    {
        return 1;
    }

    return 0;
}

void checkField(struct Game* game, struct PlayerData* playerData)
{
    if(checkRow(&game->field[0]) || checkRow(&game->field[3]) || checkRow(&game->field[6]) ||
            checkColumn(&game->field[0]) || checkColumn(&game->field[1]) || checkColumn(&game->field[2]) ||
            checkDiagonal(game->field))
    {
        if(playerData->playerNumberMove)
            playerData->player1Win++;
        else
            playerData->player2Win++;

        printf(" Player \"%s\" lost!", playerData->playerName[(int)playerData->playerNumberMove]);
        enterPressWait();
        restartField(game);
    }

    if(game->moveCount == 9)
    {
        restartField(game);
        printf(" Friendship won!");
        enterPressWait();
    }

    printDataGame(game, playerData);
}

char readCommand(struct Game* game, struct PlayerData* playerData)
{
    char input = 0;

    if(game->mode == PC)
    {
        if(playerData->playerNumberMove == 1)
            input = getch();
        else
            input = AI_Move(game, playerData);
    }
    else if(game->mode == HUMAN)
        input = getch();

    switch (input)
    {
    case 'e':
    case 'n':
        break;
    case 'r':
        restartGame(playerData, game);
        break;
    case 'h':
        if(game->mode == PC)
            printf(" Difficulty level: %d\n", game->level + 1);

        printf("\t 7 | 8 | 9\n"
               "\t-----------\n"
               "\t 4 | 5 | 6\n"
               "\t-----------\n"
               "\t 1 | 2 | 3\n\n");
        enterPressWait();
        break;
    case 'u':
        undo(game, playerData);
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
        game->undoCell = input;
        const int index = (input - '0') - 1;

        if(game->field[index] == _0 || game->field[index] == _X)
        {
            printf(" Cell %d is not empty!", index + 1);
            enterPressWait();
            break;
        }

        if(playerData->playerNumberMove)
            game->field[index] = _0;
        else
            game->field[index] = _X;

        playerData->playerNumberMove ^= 1;
        game->moveCount++;
        break;

    default:
        printf(" Incorrect input: '%c'.", input);
        enterPressWait();
        break;
    }

    return input;
}

void initGame(struct Game *game)
{
    game->moveCount = 0;
    game->undoCell = 0;
    game->mode = PC;
    game->level = EASY;

    memset(game->field, EMPTY, SIZE);
}

void initPlayers(struct PlayerData *playerData)
{
    playerData->player1Win = 0;
    playerData->player2Win = 0;
    playerData->playerNumberMove = 0;

    strcpy(playerData->playerName[0], "Player 1");
    strcpy(playerData->playerName[1], "Player 2");
}

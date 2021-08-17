#include "ai.h"

char AI_Move(struct Game* game, struct PlayerData* playerData)
{
    //EASY
    if(game->level == EASY)
    {
        while(1)
        {
            srand(time(0));
            int result = rand() % 9 + 1;

            if(game->field[result - 1] == EMPTY)
                return result + '0';
        }
    }

    // Проверка на один символ, недостающий до победы или поражения.
    char win = AI_OneSymbolBefore(_X, game->field, playerData);
    char lost = AI_OneSymbolBefore(_0, game->field, playerData);
    if( win != 0)
    {
        return win;
    }
    else if(lost != 0)
    {
        return lost;
    }

    // Занять середину, если пуста.
    if(game->level == HARD && game->field[4] == EMPTY)
        return '5';

    // Занять первую пустую угловую ячейку.
    for (int i = 0; i < 9; i += 2)
    {
        if( (game->field[i] == EMPTY) && (i != 4) )
            return i + 1 + '0';
    }

    // Занять первую пустую не угловую ячейку.
    for (int i = 1; i < 9; i += 2)
    {
        if(game->field[i] == EMPTY)
            return i + 1 + '0';
    }

    // Программа сюда не должна доходить, если дошла, это ошибка!
    return '!';
}
char AI_OneRow(char* arr, char symbol)
{
    if(*arr == symbol &&
            *(arr + 1) == symbol &&
            *(arr + 2) == EMPTY)   // X X !X
    {
        return '3';
    }
    else if(*arr == symbol &&
            *(arr + 1) == EMPTY &&
            *(arr + 2) == symbol) // X !X X
    {
        return '2';
    }
    else if(*arr == EMPTY &&
            *(arr + 1) == symbol &&
            *(arr + 2) == symbol) // !X X X
    {
        return '1';
    }

    return 0;
}

char AI_OneColumn(char* arr, char symbol)
{
    // !X        7 8 9
    // X         4 5 6
    // X         1 2 3
    if(*arr == symbol &&
            *(arr + 3) == symbol &&
            *(arr + 6) ==  EMPTY)
    {
        return '7';
    }
    // X
    // !X
    // X
    else if(*arr == symbol &&
            *(arr + 3) == EMPTY &&
            *(arr + 6) == symbol)
    {
        return '4';
    }
    // X
    // X
    // !X
    else if(*arr == EMPTY &&
            *(arr + 3) == symbol &&
            *(arr + 6) == symbol)
        return '1';

    return 0;
}

char AI_Diagonal(char symbol, char *field)
{
    //     X
    //   X
    // !X
    if(field[0] == EMPTY &&
            field[4] == symbol &&
            field[8] == symbol)
    {
        return field[0];
    }
    //      X
    //   !X
    // X
    else if(field[0] == symbol &&
            field[4] == EMPTY &&
            field[8] == symbol)
    {
        return '5';
    }
    //     !X
    //   X
    // X
    else if(field[0] == symbol &&
            field[4] == symbol &&
            field[8] == EMPTY )
    {
        return '9';
    }
    // !X
    //    X
    //      X
    else if(field[2] == symbol &&
            field[4] == symbol &&
            field[6] == EMPTY)
    {
        return '7';
    }
    // X
    //   !X
    //      X
    else if(field[2] == symbol &&
            field[4] == EMPTY &&
            field[6] == symbol)
    {
        return '5';
    }
    // X
    //   X
    //     !X
    else if(field[2] == EMPTY &&
            field[4] == symbol &&
            field[6] == symbol)
    {
        return '3';
    }

    return 0;
}

char AI_OneSymbolBefore(char symbol, char* field, struct PlayerData* playerData)
{
    if(playerData->playerNumberMove == 1)
        return 0;

    if(AI_OneRow(&field[0], symbol) != 0)
    {
        return AI_OneRow(&field[0], symbol);
    }
    else if(AI_OneRow(&field[3], symbol) != 0)
    {
        return AI_OneRow(&field[3], symbol) + 3;
    }
    else if(AI_OneRow(&field[6], symbol) != 0)
    {
        return AI_OneRow(&field[6], symbol) + 6;
    }

    if(AI_OneColumn(&field[0], symbol) != 0)
    {
        return AI_OneColumn(&field[0], symbol);
    }
    else if(AI_OneColumn(&field[1], symbol) != 0)
    {
        return AI_OneColumn(&field[1], symbol) + 1;
    }
    else if(AI_OneColumn(&field[2], symbol) != 0)
    {
        return AI_OneColumn(&field[2], symbol) + 2;
    }

    if(AI_Diagonal(symbol, field) != 0)
        return AI_Diagonal(symbol, field);

    return 0;
}

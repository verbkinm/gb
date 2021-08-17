#include "lib.h"

int main()
{
    struct PlayerData players;
    struct Game game;

    while (1)
    {
        initGame(&game);
        initPlayers(&players);

        consoleClear();
        hideCursor();
        gameMode(&game, &players);

        do
        {
            printDataGame(&game, &players);
            checkField(&game, &players);

            char inputCommand = readCommand(&game, &players);
            if(inputCommand == 'e')
            {
                printf(" Game over!\n");
                exit(0);
            }
            else if(inputCommand == 'n')
                break;
        }
        while (1);
    }

    return 0;
}

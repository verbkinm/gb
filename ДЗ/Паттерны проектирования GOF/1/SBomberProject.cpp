#include <conio.h>
#include <thread>

#include "SBomber.h"
#include "MyTools.h"
#include "Patterns/proxylogger.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    SBomber game;
    game.proxyLog().OpenLogFile("log.txt");

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(300ms);
        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    game.proxyLog().CloseLogFile();

    return 0;
}


#include <conio.h>
#include <thread>

#include "SBomber.h"
#include "MyTools.h"
#include "logsingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    LogSingleton::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(50ms);
        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    LogSingleton::getInstance().CloseLogFile();

    return 0;
}

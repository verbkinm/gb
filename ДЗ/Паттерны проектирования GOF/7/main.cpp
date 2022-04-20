﻿#include "SBomber.h"
#include "MyTools.h"
#include "ScreenSingleton.h"
#include "log.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#if defined(_WIN32) || defined(WIN32)
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>

using namespace std;

int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (!initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
#endif

int main(void)
{
  SBomber game;

  do {
    game.TimeStart();

    game.ProcessKBHit(_kbhit());

    ScreenSingleton::getInstance().ClrScr();

    game.DrawFrame();

    game.MoveObjects();
    game.CheckObjects();

    this_thread::sleep_for(200ms);

    game.TimeFinish();

  } while (!game.GetExitFlag());

  return 0;
}

#include "myvariant.h"

int main()
{
    // 1
    short int _sint = 0;
    int _int = 0;
    long long _ll = 0;
    char ch = '\0';
    bool b = false;
    float f = 0.0;
    double d = 0.0;

    // 2
    enum cellType { _X, _0, EMPTY  };
    enum currentMove { PLAYER_1, PLAYER_2 };

    // 3
    cellType arr[3][3] = { {EMPTY, EMPTY, EMPTY},
                           {EMPTY, _X, EMPTY},
                           {EMPTY, EMPTY, EMPTY} };

    // 4*
    struct game
    {
        enum currentMove { PLAYER_1, PLAYER_2 };
        enum cellType { _X, _0, EMPTY  };
        cellType field[3][3] = { {EMPTY, EMPTY, EMPTY},
                                 {EMPTY, EMPTY, EMPTY},
                                 {EMPTY, EMPTY, EMPTY} };

        size_t player1Wins = 0;
        size_t player2Wins = 0;
        currentMove step = PLAYER_1;
        size_t totalGame = 0;
    };

    // 5**
    MyVariant variant;
    variant = 1;
    std::cout << "integer - " << variant << std::endl;

    variant = 'A';
    std::cout << "char - " << variant << std::endl;

    variant = 0.1f;
    std::cout << "float - " << variant << std::endl;

    variant = 0.1;
    std::cout << "double - " << variant << std::endl;

    return 0;
}

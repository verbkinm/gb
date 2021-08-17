#pragma once

#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "platform-dependent.h"

#define SIZE 9

struct PlayerData
{
    unsigned char player1Win;
    unsigned char player2Win;
    unsigned char playerNumberMove;

    char playerName[2][10];
};

struct Game
{
    unsigned char moveCount;
    unsigned char undoCell;

    char mode : 4;
    char level : 4;

    char field[SIZE];
};

enum symbolCell { _X = 'X', _0 = '0', EMPTY = ' '};
enum modeName { PC, HUMAN };
enum levelName { EASY, HARD};

// Инициализация структук
void initGame(struct Game* game);
void initPlayers(struct PlayerData* playerData);

// Баннер
void banner(void);

// Ожидание нажатия клавиши ENTER
void enterPressWait(void);

// Вывод данных на экран
void printDataGame(struct Game* game, struct PlayerData* playerData);
void printCommandName(enum modeName mode);
void printField(char* field);
void playersVictories(struct PlayerData* playerData);
void playerMove(struct Game* game, struct PlayerData* playerData);

// Обнуление поля
void restartField(struct Game* game);

// Перезапуск всей игры
void restartGame(struct PlayerData* playerData, struct Game *game);

// Ввод имени игрока для игры вдоём
void setPlayerName(char* name);

// Отмена последнего действия (только при игре с человеком)
void undo(struct Game* game, struct PlayerData* playerData);

// Уровень сложности игры с компьютером
void levelMode(struct Game* game);

// Выбор режима игры: с человеком или с компьютером
void gameMode(struct Game* game, struct PlayerData* playerData);

// Проверка на победу
void checkField(struct Game* game, struct PlayerData* playerData);
int checkRow(char *arr);
int checkColumn(char *arr);
int checkDiagonal(char *arr);

// Ввод команды
char readCommand(struct Game* game, struct PlayerData* playerData);



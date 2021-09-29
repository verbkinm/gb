#pragma once

#include "lib.h"

// Ход ИИ
char AI_Move(struct Game *game, struct PlayerData *playerData);

// Если в строке не хватает одного хода до победы или поражения
char AI_OneSymbolBefore(char symbol, char* field, struct PlayerData *playerData);

// Провекра на наличие двух одинаковых символов и пустую ячейку в одной строке/столбце/диагонали
char AI_OneRow(char* arr, char symbol);
char AI_OneColumn(char* arr, char symbol);
char AI_Diagonal(char symbol, char* field);

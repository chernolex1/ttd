#include "colors.h"

#include <curses.h>

TColorsHandler& TColorsHandler::GetInstance() {
    static TColorsHandler instance;
    return instance;
}

TColorsHandler::TColorsHandler() {
    InitializeColors();
}

void TColorsHandler::InitializeColors() {
    init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
    init_pair(FRAME, COLOR_BLACK, COLOR_WHITE);
    init_pair(CURSOR, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(RAIL, COLOR_WHITE, COLOR_GREEN);
    init_pair(TRAIN, COLOR_MAGENTA, COLOR_BLACK);
}

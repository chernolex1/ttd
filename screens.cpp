#include "screens.h"

void TScreen::Draw(const TConsoleMeta& consoleMeta) {
    clear();
    PrepareDrawing(consoleMeta);
    refresh();
};

void TScreen::Print(const std::string& str) const {
    addstr(str.c_str());
}

const uint64_t TMapScreen::GetMinIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size) {
    return std::min(
        offset,
        term_size > map_size
        ? 0ULL
        : map_size - term_size + 2
    );
}

const uint64_t TMapScreen::GetMaxIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size) {
    return std::min(map_size, offset + term_size - 2);
}

const TMapScreen::TDrawIndexes TMapScreen::CalcIndexes(const TConsoleMeta& consoleMeta) const {
    TDrawIndexes indexes;
    const auto& mapSize = TGameMap::GetInstance().size();

    indexes.XBegin = GetMinIndex(HorizontalOffset, mapSize, consoleMeta.Width);
    indexes.YBegin = GetMinIndex(VerticalOffset, mapSize, consoleMeta.Height);
    indexes.XEnd = GetMaxIndex(HorizontalOffset, mapSize, consoleMeta.Width);
    indexes.YEnd = GetMaxIndex(VerticalOffset, mapSize, consoleMeta.Height);

    return indexes;
}

void TMapScreen::PrepareDrawing(const TConsoleMeta& consoleMeta) {
    const auto& map = TGameMap::GetInstance().GetMap();
    CalcOffsetShift(consoleMeta, map->size());
    const auto& indexes = CalcIndexes(consoleMeta);

    attron(COLOR_PAIR(TColorsHandler::TypeColors::FRAME));

    Print("┌");
    for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
        Print("─");
    }
    Print("┐\n");


    for (uint64_t y = indexes.YBegin; y < indexes.YEnd - 1; y++) {
        attron(COLOR_PAIR(TColorsHandler::TypeColors::FRAME));
        Print("│");
        const auto row = (*map)[y];
        for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
            if (x - indexes.XBegin == CursorX && y - indexes.YBegin == CursorY) {
                attron(COLOR_PAIR(TColorsHandler::TypeColors::CURSOR));
                Print("X");
            } else {
                attron(COLOR_PAIR(row[x]->GetColor()));
                Print(row[x]->GetIcon());
            }
        }
        attron(COLOR_PAIR(TColorsHandler::TypeColors::FRAME));
        Print("│\n");
    }

    Print("└");
    for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
        Print("─");
    }
    Print("┘");

    Print("\nXb: " + std::to_string(indexes.XBegin) + "; Xe: " + std::to_string(indexes.XEnd) + "; Yb: " + std::to_string(indexes.YBegin) + "; Ye: " + std::to_string(indexes.YEnd) + "; Cx: " + std::to_string(CursorX) + "; Yc: " + std::to_string(CursorY) + "; W: " + std::to_string(consoleMeta.Width)  + "; H: " + std::to_string(consoleMeta.Height) + "\n\n");
    // std::cout << "┌─┐\n│ │\n└─┘\n";
}

void TMapScreen::ProcessInput(const char input) {
    if (input == 'w') {
        CursorY--;
    }
    if (input == 'W') {
        CursorY -= 10;
    }
    if (input == 's') {
        CursorY += 1;
     }
    if (input == 'S') {
        CursorY += 10;
     }
    if (input == 'a') {
        CursorX--;
    }
    if (input == 'A') {
        CursorX -= 10;
    }
    if (input == 'd') {
        CursorX++;
    }
    if (input == 'D') {
        CursorX += 10;
    }

    if (input == 'b') {
        TGameMap::GetInstance().Build(HorizontalOffset + CursorX, VerticalOffset + CursorY);
    }
}

void TMapScreen::CalcOffsetShift(const TConsoleMeta& consoleMeta, const uint64_t mapSize) {
    if (CursorY < 0) {
        if (VerticalOffset < CursorY * -1) {
            VerticalOffset = 0;
        } else {
            VerticalOffset += CursorY;
        }
        CursorY = 0;
    }
    const int64_t alignerY = static_cast<int64_t>(std::min(mapSize, consoleMeta.Height));
    if (CursorY - alignerY + 4 > 0) {
        VerticalOffset += (CursorY - alignerY + 4);
        CursorY = alignerY - 4;
    }

    if (CursorX < 0) {
        if (HorizontalOffset < CursorX * -1) {
            HorizontalOffset = 0;
        } else {
            HorizontalOffset += CursorX;
        }
        CursorX = 0;
    }
    const int64_t alignerX = static_cast<int64_t>(std::min(mapSize, consoleMeta.Width));
    if (CursorX - alignerX + 4 > 0) {
        HorizontalOffset += (CursorX - alignerX + 4);
        CursorX = alignerX - 4;
    }
}

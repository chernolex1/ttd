#include "console.h"

void TConsoleHelper::Print(const std::string& str) {
    addstr(str.c_str());
}

const TConsoleMeta TConsoleHelper::GetConsoleMeta() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    TConsoleMeta meta;
    meta.Width = w.ws_col;
    meta.Height = w.ws_row;

    return meta;
}

const uint64_t TConsoleHelper::GetMinIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size) {
    return std::min(
        offset,
        term_size > map_size
        ? 0ULL
        : map_size - term_size + 2
    );
}

const uint64_t TConsoleHelper::GetMaxIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size) {
    return std::min(map_size, offset + term_size - 2);
}

const TConsoleHelper::TDrawIndexes TConsoleHelper::CalcIndexes(const TGameState& state, const TConsoleMeta& consoleMeta) {
    TDrawIndexes indexes;

    const auto& map = state.GetMap();

    indexes.XBegin = GetMinIndex(state.HorizontalOffset, map.size(), consoleMeta.Width);
    indexes.YBegin = GetMinIndex(state.VerticalOffset, map.size(), consoleMeta.Height);
    indexes.XEnd = GetMaxIndex(state.HorizontalOffset, map.size(), consoleMeta.Width);
    indexes.YEnd = GetMaxIndex(state.VerticalOffset, map.size(), consoleMeta.Height);

    return indexes;
}

void TConsoleHelper::Draw(const TGameState& state) {
    clear();
    const auto& consoleMeta = GetConsoleMeta();

    const auto& indexes = CalcIndexes(state, consoleMeta);

    Print("┌");
    for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
        Print("─");
    }
    Print("┐\n");


    for (uint64_t y = indexes.YBegin; y < indexes.YEnd - 1; y++) {
        Print("│");
        const auto row = state.GetMap()[y];
        for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
            Print(row[x]->GetIcon());
        }
        Print("│\n");
    }

    Print("└");
    for (uint64_t x = indexes.XBegin; x < indexes.XEnd - 1; x++) {
        Print("─");
    }
    Print("┘");

    // std::cout << "\nXb: " << indexes.XBegin << "; Xe: " << indexes.XEnd << "; Yb: " << indexes.YBegin << "; Ye: " << indexes.YEnd << "\n\n";
    // std::cout << "┌─┐\n│ │\n└─┘\n";
}

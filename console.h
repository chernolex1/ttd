#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

#include "game_state.h"

struct TConsoleMeta {
    uint64_t Width;
    uint64_t Height;
};

class TConsoleHelper {
private:
    struct TDrawIndexes {
        uint64_t XBegin;
        uint64_t XEnd;
        uint64_t YBegin;
        uint64_t YEnd;
    };

public:
    static const TConsoleMeta GetConsoleMeta();

    static void Draw(const TGameState& state);

private:
    static const uint64_t GetMinIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size);
    static const uint64_t GetMaxIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size);
    static const TDrawIndexes CalcIndexes(const TGameState& state, const TConsoleMeta& consoleMeta);
    static void Print(const std::string& str);
};

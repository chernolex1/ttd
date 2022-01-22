#include "map.h"

uint64_t TGameMap::Size = 100;

void TGameMap::Build(const uint64_t x, const uint64_t y) {
    if ((*Map)[y][x]->IsBuildable()) {
        (*Map)[y][x] = std::make_shared<TCross>();
    }
}

#pragma once

#include <vector>

#include "tiles.h"

class TGameState {
public:
    TGameState();
    TGameState(const uint64_t mapSize);

    const std::vector<std::vector<std::shared_ptr<TTile>>> GetMap() const { return Map; }

public:
    uint64_t VerticalOffset = 0;
    uint64_t HorizontalOffset = 0;

public:
    std::vector<std::vector<std::shared_ptr<TTile>>> Map;
};

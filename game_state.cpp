#include "game_state.h"
#include <memory>

TGameState::TGameState() {
    TGameState(100);    
}

TGameState::TGameState(const uint64_t mapSize) {
    Map = std::vector<std::vector<std::shared_ptr<TTile>>>(mapSize, std::vector<std::shared_ptr<TTile>>(mapSize, std::make_shared<TTile>(TTile())));
}

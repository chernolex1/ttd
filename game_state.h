#pragma once

#include "screens.h"

class TGameState {
public:
    TGameState();
    TGameState(const uint64_t mapSize);

    void Draw() const;
    void ProcessInput(const char input);

private:
    std::shared_ptr<TScreen> CurrentScreen;
};

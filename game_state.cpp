#include "game_state.h"
#include <memory>

TGameState::TGameState() {
    TGameState(100);    
}

TGameState::TGameState(const uint64_t mapSize) {
    TGameMap::Initialize(mapSize);
    TGameMap& gameMap = TGameMap::GetInstance();
    CurrentScreen = std::make_shared<TMapScreen>(
        TMapScreen(
            std::make_shared<TMapScreen::TMapScreenParams>(
                TMapScreen::TMapScreenParams(
                    TScreen::TScreenParams()
                )
            )
        )
    );
}

void TGameState::Draw() const {
    CurrentScreen->Draw(TConsoleHelper::GetConsoleMeta());
}

void TGameState::ProcessInput(const char input) {
    CurrentScreen->ProcessInput(input);
}

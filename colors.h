#pragma once

#include <memory>

class TColorsHandler {
public:
    enum TypeColors {
        NONE,
        FRAME,
        CURSOR,
        EMPTY,
        RAIL,
        TRAIN
    };

public:
    static TColorsHandler& GetInstance();

    TColorsHandler(TColorsHandler const&) = delete;
    void operator=(TColorsHandler const&) = delete;

private:
    TColorsHandler();

    void InitializeColors();
};

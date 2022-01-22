#pragma once

#include "colors.h"
#include "console.h"
#include "map.h"

class TScreen {
public:
    struct TScreenParams {
        TScreenParams() = default;
    };

public:
    TScreen(const std::shared_ptr<TScreenParams> params) {};

    void Draw(const TConsoleMeta& consoleMeta);

    virtual void ProcessInput(const char input) = 0;

protected:
    virtual void PrepareDrawing(const TConsoleMeta& consoleMeta) = 0;
    virtual void Print(const std::string& str) const;

protected:
    std::shared_ptr<TScreenParams> Params;
};

class TMapScreen : public TScreen {
public:
    struct TMapScreenParams : TScreenParams {
        TMapScreenParams(const TScreenParams& params) : TScreenParams(params) {};
    };

    struct TDrawIndexes {
        uint64_t XBegin;
        uint64_t XEnd;
        uint64_t YBegin;
        uint64_t YEnd;
    };

public:
    TMapScreen(std::shared_ptr<TMapScreenParams> params) : TScreen(params) {};

    void PrepareDrawing(const TConsoleMeta& consoleMeta) override;

    void ProcessInput(const char input) override;

protected:
    static const uint64_t GetMinIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size);
    static const uint64_t GetMaxIndex(const uint64_t offset, const uint64_t map_size, const uint64_t term_size);
    const TDrawIndexes CalcIndexes(const TConsoleMeta& consoleMeta) const;
    void CalcOffsetShift(const TConsoleMeta& consoleMeta, const uint64_t mapSize);

protected:
    uint64_t HorizontalOffset = 0;
    uint64_t VerticalOffset = 0;
    int64_t CursorX = 0;
    int64_t CursorY = 0;
};

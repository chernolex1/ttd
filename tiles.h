#pragma once

#include <string>

#include "colors.h"

class TTile {
public:
    TTile() = default;
    virtual const std::string GetIcon() const {
        return "*";
    }

    virtual const TColorsHandler::TypeColors GetColor() {
        return TColorsHandler::TypeColors::EMPTY;
    }

    virtual bool IsBuildable() const {
        return true;
    }
};

class TRailTile : public TTile {
public:
    virtual const TColorsHandler::TypeColors GetColor() {
        return TColorsHandler::TypeColors::RAIL;
    }
};

class TVerticalRoad : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┃";
    }
};

class THorizontalRoad : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "━";
    }
};

class TLeftJoint : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┫";
    }
};

class TRightJoint : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┣";
    }
};

class TBottomJoint : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┳";
    }
};

class TUpperJoint : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┻";
    }
};

class TLeftUpCorner : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┛";
    }
};

class TLeftDownCorner : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┓";
    }
};

class TRightUpCorner : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┗";
    }
};

class TRightDownCorner : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "┏";
    }
};

class TCross : public TRailTile {
public:
    const std::string GetIcon() const override {
        return "╋";
    }
};

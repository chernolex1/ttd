#pragma once

#include <string>

class TTile {
public:
    TTile() = default;
    virtual const std::string GetIcon() const {
        return "*";
    }
};

class TVerticalRoad : public TTile {
public:
    const std::string GetIcon() const override {
        return "┃";
    }
};

class THorizontalRoad : public TTile {
public:
    const std::string GetIcon() const override {
        return "━";
    }
};

class TLeftJoint : public TTile {
public:
    const std::string GetIcon() const override {
        return "┫";
    }
};

class TRightJoint : public TTile {
public:
    const std::string GetIcon() const override {
        return "┣";
    }
};

class TBottomJoint : public TTile {
public:
    const std::string GetIcon() const override {
        return "┳";
    }
};

class TUpperJoint : public TTile {
public:
    const std::string GetIcon() const override {
        return "┻";
    }
};

class TLeftUpCorner : public TTile {
public:
    const std::string GetIcon() const override {
        return "┛";
    }
};

class TLeftDownCorner : public TTile {
public:
    const std::string GetIcon() const override {
        return "┓";
    }
};

class TRightUpCorner : public TTile {
public:
    const std::string GetIcon() const override {
        return "┗";
    }
};

class TRightDownCorner : public TTile {
public:
    const std::string GetIcon() const override {
        return "┏";
    }
};

class TCross : public TTile {
public:
    const std::string GetIcon() const override {
        return "╋";
    }
};

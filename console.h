#pragma once

#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

struct TConsoleMeta {
    uint64_t Width;
    uint64_t Height;
};

class TConsoleHelper {
public:
    static const TConsoleMeta GetConsoleMeta();

private:
    static void Print(const std::string& str);
};

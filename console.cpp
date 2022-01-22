#include "console.h"

void TConsoleHelper::Print(const std::string& str) {
    addstr(str.c_str());
}

const TConsoleMeta TConsoleHelper::GetConsoleMeta() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    TConsoleMeta meta;
    meta.Width = w.ws_col;
    meta.Height = w.ws_row;

    return meta;
}



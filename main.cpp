#include <iostream>
#include <memory>
#include <curses.h>

#include "console.h"
#include "game_state.h"

int main() {
    setlocale(LC_ALL, "");

    TGameState state(300);
    state.Map[0][1] = std::make_shared<TVerticalRoad>(TVerticalRoad());

    // state.Map[0][0] = std::make_shared<T>(T());
    state.Map[0][0] = std::make_shared<TRightDownCorner>(TRightDownCorner());
    state.Map[0][1] = std::make_shared<TBottomJoint>(TBottomJoint());
    state.Map[0][2] = std::make_shared<TLeftDownCorner>(TLeftDownCorner());
    state.Map[1][0] = std::make_shared<TRightJoint>(TRightJoint());
    state.Map[1][1] = std::make_shared<TCross>(TCross());
    state.Map[1][2] = std::make_shared<TLeftJoint>(TLeftJoint());
    state.Map[2][0] = std::make_shared<TRightUpCorner>(TRightUpCorner());
    state.Map[2][1] = std::make_shared<TUpperJoint>(TUpperJoint());
    state.Map[2][2] = std::make_shared<TLeftUpCorner>(TLeftUpCorner());

    /*
    char sym = 'a';
    for (auto& i : state.Map) {
        for (auto& j : i) {
            j.Icon = sym;
            sym++;
        }
        std::cout << "\n";
    }
    */

    const auto& consoleMeta = TConsoleHelper::GetConsoleMeta();
    std::cout << "// " <<  consoleMeta.Height << " // " << consoleMeta.Width << "\n";

    std::cout << "\n\n\n";

    state.VerticalOffset = 0;
    state.HorizontalOffset = 0;

    initscr();
    noecho();
    timeout(-1);

    char c = '\0';
    while (c != 'q') {
        if (c == '\0') {
            printw("Press any key to start...");
            refresh();
        }
        c = getch();
        if (c == 'w') {
            if (state.VerticalOffset > 0) {
                state.VerticalOffset -= 1;
            }
        }
        if (c == 's') {
            state.VerticalOffset += 1;
        }
        if (c == 'a') {
            if (state.HorizontalOffset > 0) {
                state.HorizontalOffset -= 1;
            }
        }
        if (c == 'd') {
            state.HorizontalOffset += 1;
        }
        TConsoleHelper::Draw(state);
        refresh();
    }

    endwin();
    
    std::cout << c;

    return 0;
}

#include <iostream>
#include <memory>
#include <curses.h>

#include "colors.h"
#include "console.h"
#include "game_state.h"


int main() {
    setlocale(LC_ALL, "");

    TGameState state(500);
    auto map = TGameMap::GetInstance().GetMap();
    (*map)[0][1] = std::make_shared<TVerticalRoad>(TVerticalRoad());

    // state.Map[0][0] = std::make_shared<T>(T());
    (*map)[0][0] = std::make_shared<TRightDownCorner>(TRightDownCorner());
    (*map)[0][1] = std::make_shared<TBottomJoint>(TBottomJoint());
    (*map)[0][2] = std::make_shared<TLeftDownCorner>(TLeftDownCorner());
    (*map)[1][0] = std::make_shared<TRightJoint>(TRightJoint());
    (*map)[1][1] = std::make_shared<TCross>(TCross());
    (*map)[1][2] = std::make_shared<TLeftJoint>(TLeftJoint());
    (*map)[2][0] = std::make_shared<TRightUpCorner>(TRightUpCorner());
    (*map)[2][1] = std::make_shared<TUpperJoint>(TUpperJoint());
    (*map)[2][2] = std::make_shared<TLeftUpCorner>(TLeftUpCorner());

    const auto& consoleMeta = TConsoleHelper::GetConsoleMeta();
    std::cout << "// " <<  consoleMeta.Height << " // " << consoleMeta.Width << "\n";

    std::cout << "\n\n\n";

    initscr();
    start_color();
    noecho();
    timeout(-1);

    const auto& ch = TColorsHandler::GetInstance();

    char c = '\0';
    while (c != 'q') {
        if (c == '\0') {
            printw("Press any key to start...");
            refresh();
        }
        c = getch();
        state.ProcessInput(c);
        state.Draw();
    }

    endwin();

    return 0;
}

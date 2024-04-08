#include "../../src/mainwindow.h"
#include "../../src/gamestate.h"
#include "../../src/intro.h"

#include <SDL.h>
#include <memory>

int main(int argc, char *argv[])
{
    // MainWindow must be the first object instanciated
    MainWindow win (480, 272, "Simple Pool");
    // MainWindow win (800, 600, "Simple Pool");
    // win.setIcon("./pool_assets/ball8.png");

    std::unique_ptr<GameState> currentState {std::make_unique<Intro>()};

    while (GameState::curr_state != GameStates::Quit)
    {
        currentState->handle_events();
        currentState->logic();
        currentState->render();

        changeState(currentState);
    }

    return 0;
}
#include "include/gameengine.h"

GameEngine::GameEngine() {

}

GameEngine::~GameEngine() {

}

bool GameEngine::Init() {

    title = "Platofrmer";
    width_window = 960;
    height_window = 640;

    if (!InitSDL()) {

        SDL_Log("Error: Cannot init SDL (GameEngine)");
        return false;
    }

    if (!InitGame()) {

        SDL_Log("Error: Cannot init game (GameEngine)");
        return false;
    }

    if (!InitStates()) {

        SDL_Log("Error: Cannot init states (GameEngine)");
        return false;
    }

    return true;
}

void GameEngine::CleanUp() {

    delete render;
    render = nullptr;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

void GameEngine::Start() {

    DeltaTime delta_time;

    running = true;

    while (running) {

        double dt = delta_time.GetDeltaTime();

        //SDL_Log("Delta time: %f", dt);

        game_state_machine.HandleEvents();
        game_state_machine.Update(dt);
        game_state_machine.Render();

        if (game_state_machine.IsGameExit()) {

            running = false;
        }
    }
}

bool GameEngine::InitGame()  {

    bool succes = window.Init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_window, height_window, NULL, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    render = new Render(window.GetRenderer(), SDL_Color {255, 255, 255, 255});
    return succes;
}

bool GameEngine::InitSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {

        SDL_Log("Error: %s", SDL_GetError());
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {

        SDL_Log("Error: %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() != 0) {

        SDL_Log("Error: %s", SDL_GetError());
        return false;
    }

   return true;
}

bool GameEngine::InitStates() {

    bool succes = true;

    game_state_machine.PushBack(MAINGAME_STATE, new MainGameState(width_window, height_window, {0, 0}, render));

    game_state_machine.ChangeState(MAINGAME_STATE);

    // TODO catch state init errors
    return succes;
}

#include <SDL.h>

class AppWindow {
private:
    SDL_Window* window;

public:
    AppWindow() : window(nullptr) {}

    bool initialize(const char* title, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            // Handle error
            return false;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        if (!window) {
            SDL_Quit();
            return false;
        }

        return true;
    }

    void run() {
        bool running = true;
        SDL_Event event;

        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            SDL_UpdateWindowSurface(window);
        }
    }

    ~AppWindow() {
        if (window) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
};

int main(int argc, char** argv) {
    AppWindow appWindow;
    if (!appWindow.initialize("Simple SDL Window", 600, 400)) {
        return 1;
    }

    appWindow.run();

    return 0;
}

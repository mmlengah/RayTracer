#include <SDL.h>
#include <GL/glew.h>

class AppWindow {
private:
    SDL_Window* window;
    SDL_GLContext glContext;

public:
    AppWindow() : window(nullptr), glContext(nullptr) {}

    bool initialize(const char* title, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            // Handle error
            return false;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        if (!window) {
            SDL_Quit();
            return false;
        }

        glContext = SDL_GL_CreateContext(window);
        if (!glContext) {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }

        glewExperimental = GL_TRUE;
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK) {
            SDL_GL_DeleteContext(glContext);
            SDL_DestroyWindow(window);
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
                // Handle other events as needed (e.g. keyboard, mouse)
            }

            // Rendering logic here
            SDL_GL_SwapWindow(window);
        }
    }

    ~AppWindow() {
        if (glContext) {
            SDL_GL_DeleteContext(glContext);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
};

int main(int argc, char** argv) {
    AppWindow appWindow;
    if (!appWindow.initialize("GPU Ray Tracer", 600, 400)) {
        return 1;
    }

    appWindow.run();

    return 0;
}

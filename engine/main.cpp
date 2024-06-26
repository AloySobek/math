#include <cstdint>
#include <iostream>
#include <raylib.h>

#include "src/complex.hpp"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#endif

class Page {
  public:
    Page() = default;

    virtual void draw();

    virtual ~Page() {}

  private:
};

class UI {
  public:
    UI() {}

    void draw() {}

    ~UI() {}

  private:
};

class Render {
  public:
    Render() {}

    void draw() {
        BeginDrawing();

        {
            ClearBackground(BLACK);

            draw_text();
            draw_axis();
        }

        EndDrawing();
    }

    ~Render() {}

  private:
    Complex<float> number{0.0f, 7.0f};

    void draw_text() {
        const char *text = "Postulates";

        int size = MeasureText(text, 50);

        DrawText(text, GetScreenWidth() / 2 - (size / 2), GetScreenHeight() / 10, 50, WHITE);
    }

    void draw_axis() {
        const float height = GetScreenHeight();
        const float width = GetScreenWidth();

        DrawLineV(Vector2{width / 2, 0}, Vector2{width / 2, height}, RAYWHITE);
        DrawLineV(Vector2{0, height / 2}, Vector2{width, height / 2}, RAYWHITE);
    }
};

class Runtime {
  public:
    Runtime() : _render{} {}

    void run() {
        InitWindow(800, 450, "Window");
        SetTargetFPS(60);

        while (!WindowShouldClose()) {
            _render.draw();
        }

        CloseWindow();
    }

    ~Runtime() {}

  private:
    Render _render;
};

int main(int argc, char **argv) {
    Runtime runtime;

    runtime.run();

    return 0;
}

#include <cmath>
#include <format>
#include <iostream>
#include <raylib.h>
#include <string>

#define WIDTH 1280
#define HEIGHT 720

class LinearEquation {
  public:
    LinearEquation(double slope, double intercept) : slope{slope}, intercept{intercept} {}

    void draw() {
        // y = sx + b
        // y - sx = b
        // -sx = -y + b
        // sx = y - b
        // x = (y - b) / s

        double s = abs(slope);

        DrawText((std::string("y = ") + std::format("{:.1f}", slope) + std::string("x + ") +
                  std::format("{:.1f}", intercept))
                     .c_str(),
                 20, 20, 20, DARKGRAY);

        double x =
            ((double)WIDTH / 2.0f) - 40.0f * (((double)HEIGHT / 2.0f / 40.0f + intercept) / s);

        if (x < 0)
            x = 0;

        double y = ((double)HEIGHT / 2.0f) + 40.0f * ((double)WIDTH / 2.0f / 40.0f * s - intercept);

        if (y > HEIGHT)
            y = HEIGHT;

        double x2 =
            ((double)WIDTH / 2.0f) + 40.0f * (((double)HEIGHT / 2.0f / 40.0f - intercept) / s);

        if (x2 > WIDTH)
            x2 = WIDTH;

        double y2 =
            ((double)HEIGHT / 2.0f) - 40.0f * ((double)WIDTH / 2.0f / 40.0f * s + intercept);

        if (y2 < 0)
            y2 = 0;

        if (slope >= 0.0f) {
            DrawLine(x, y, x2, y2, BLACK);
        } else {
            DrawLine(x, ((double)HEIGHT / 2) - (y - ((double)HEIGHT / 2)), x2,
                     ((double)HEIGHT / 2) + ((double)HEIGHT / 2) - y2, BLACK);
        }
    }

    ~LinearEquation() {}

  private:
    double slope;
    double intercept;
};

class CartesianPlane {
  public:
    CartesianPlane(int step = 40, int length = 10) : step{step}, length{length} {}

    void draw() {
        // Abscissa(x-axis)
        DrawLine(0, HEIGHT / 2, WIDTH, HEIGHT / 2, BLACK);

        // Ordinate(y-axis)
        DrawLine(WIDTH / 2, 0, WIDTH / 2, HEIGHT, BLACK);

        for (int i = WIDTH / 2 - step, j = -1; i >= 0; i -= step, --j) {
            DrawLine(i, HEIGHT / 2 - length, i, HEIGHT / 2 + length, BLACK);

            DrawText(std::to_string(j).c_str(), i - MeasureText(std::to_string(j).c_str(), 15) / 2,
                     HEIGHT / 2 + length + 1, 15, BLACK);
        }

        for (int i = WIDTH / 2 + step, j = 1; i <= WIDTH; i += step, ++j) {
            DrawLine(i, HEIGHT / 2 - length, i, HEIGHT / 2 + length, BLACK);

            DrawText(std::to_string(j).c_str(), i - MeasureText(std::to_string(j).c_str(), 15) / 2,
                     HEIGHT / 2 + length + 1, 15, BLACK);
        }

        for (int i = HEIGHT / 2 - step, j = 1; i >= 0; i -= step, ++j) {
            DrawLine(WIDTH / 2 - length, i, WIDTH / 2 + length, i, BLACK);

            Vector2 wh = MeasureTextEx(GetFontDefault(), std::to_string(j).c_str(), 15, 0);

            DrawText(std::to_string(j).c_str(), WIDTH / 2 - length - wh.x - 2, i - wh.y / 2, 15,
                     BLACK);
        }

        for (int i = HEIGHT / 2 + step, j = -1; i <= HEIGHT; i += step, --j) {
            DrawLine(WIDTH / 2 - length, i, WIDTH / 2 + length, i, BLACK);

            Vector2 wh = MeasureTextEx(GetFontDefault(), std::to_string(j).c_str(), 15, 0);

            DrawText(std::to_string(j).c_str(), WIDTH / 2 - length - wh.x - 2, i - wh.y / 2, 15,
                     BLACK);
        }
    }

  private:
    int step;
    int length;
};

int main(void) {
    CartesianPlane plane;
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(WIDTH, HEIGHT, "raylib [shapes] example - basic shapes drawing");

    float rotation = 0.0f;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    double slope = 0.0f;
    double intercept = 0.0f;
    bool asc = false;
    bool asc2 = false;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (slope > 5.0f) {
            asc = false;
        } else if (slope < -5.0f) {
            asc = true;
        }

        if (intercept > 5.0f) {
            asc2 = false;
        } else if (intercept < -5.0f) {
            asc2 = true;
        }

        slope += asc ? 0.1f : -0.1f;
        intercept += asc2 ? 0.1f : -0.1f;
        // // Updat
        // //----------------------------------------------------------------------------------
        // rotation += 0.2f;
        // //----------------------------------------------------------------------------------

        // // Draw
        // //----------------------------------------------------------------------------------
        // BeginDrawing();

        ClearBackground(RAYWHITE);

        // DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

        // // Circle shapes and lines
        // DrawCircle(WIDTH / 5, 120, 35, DARKBLUE);
        // DrawCircleGradient(WIDTH / 5, 220, 60, GREEN, SKYBLUE);
        // DrawCircleLines(WIDTH / 5, 340, 80, DARKBLUE);

        // // Rectangle shapes and lines
        // DrawRectangle(WIDTH / 4 * 2 - 60, 100, 120, 60, RED);
        // DrawRectangleGradientH(WIDTH / 4 * 2 - 90, 170, 180, 130, MAROON, GOLD);
        // DrawRectangleLines(WIDTH / 4 * 2 - 40, 320, 80, 60,
        //                    ORANGE); // NOTE: Uses QUADS internally, not lines

        // // Triangle shapes and lines
        // DrawTriangle((Vector2){WIDTH / 4.0f * 3.0f, 80.0f},
        //              (Vector2){WIDTH / 4.0f * 3.0f - 60.0f, 150.0f},
        //              (Vector2){WIDTH / 4.0f * 3.0f + 60.0f, 150.0f}, VIOLET);

        // DrawTriangleLines((Vector2){WIDTH / 4.0f * 3.0f, 160.0f},
        //                   (Vector2){WIDTH / 4.0f * 3.0f - 20.0f, 230.0f},
        //                   (Vector2){WIDTH / 4.0f * 3.0f + 20.0f, 230.0f}, DARKBLUE);

        // // Polygon shapes and lines
        // DrawPoly((Vector2){WIDTH / 4.0f * 3, 330}, 6, 80, rotation, BROWN);
        // DrawPolyLines((Vector2){WIDTH / 4.0f * 3, 330}, 6, 90, rotation, BROWN);
        // DrawPolyLinesEx((Vector2){WIDTH / 4.0f * 3, 330}, 6, 85, rotation, 6, BEIGE);

        // // NOTE: We draw all LINES based shapes together to optimize internal drawing,
        // // this way, all LINES are rendered in a single draw pass
        plane.draw();
        LinearEquation(slope, intercept).draw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

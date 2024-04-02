#define SUPPORT_FILEFORMAT_JPG
#include "raylib.h"

int screenWidth = 800;
int screenHeight = 1000;

Vector2 trenPos = {20, 20};
float xDir = 1.0;
float yDir = 1.0;
Color color = { 255, 255, 255, 255 };
Texture tren;
Texture poza;

int main() {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    tren = LoadTexture("Untitled design.png");
    poza = LoadTexture("bg.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(poza, {-100, -200}, 0, 1, WHITE);

        float delta = GetFrameTime();

        trenPos = { static_cast<float>(trenPos.x + delta * 100.0 * xDir), static_cast<float>(trenPos.y + delta * 50.0 * yDir) };
        if (trenPos.x > screenWidth - tren.width * 0.2) {
            xDir = -1.0;
            color = { static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), 255 };
        }
        if (trenPos.x < 0) {
            xDir = 1.0;
            color = { static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), 255 };

        }
        if (trenPos.y > screenHeight - tren.height * 0.2) {
            yDir = -1.0;
            color = { static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), 255 };

        }
        if (trenPos.y < 0) {
            yDir = 1.0;
            color = { static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), static_cast<unsigned char>(GetRandomValue(0, 255)), 255 };

        }


        //DrawTexture(tren, trenPos.x, trenPos.y, color);
        DrawTextureEx(tren, trenPos, 0.0, 0.2, color);

        EndDrawing();
    }

    CloseWindow();
}

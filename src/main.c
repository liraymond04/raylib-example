#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame(void); // Update and Draw one frame

const int canvasWidth = 400;
const int canvasHeight = 225;
const float aspect_ratio = (float)canvasWidth / canvasHeight;

const int scale = 2;
const int screenWidth = canvasWidth * scale;
const int screenHeight = canvasHeight * scale;

bool show_fps = true;

RenderTexture2D renderTexture;
Rectangle source = { 0, 0, (float)canvasWidth, (float)-canvasHeight };

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "raylib-example");

    SetTargetFPS(60);

    renderTexture = LoadRenderTexture(canvasWidth, canvasHeight);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // UnloadTexture(texture);       // Texture unloading
    UnloadRenderTexture(renderTexture);

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void UpdateDrawFrame(void) { // Update and Draw one frame

    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginTextureMode(renderTexture);
    {
        ClearBackground(RED);
        DrawText("Hello World!", 0, 150, 20, BLACK);
        DrawRectangle(0, 0, 10, 10, BLUE);
        DrawRectangle(0, 290, 10, 10, BLUE);
        DrawRectangle(290, 0, 10, 10, GREEN);
        DrawRectangle(290, 290, 10, 10, PURPLE);
    }
    EndTextureMode();

    BeginDrawing();
    {
        ClearBackground(BLACK);

        bool wide =
            ((float)GetScreenWidth() / GetScreenHeight()) < aspect_ratio;

        float adjusted_width =
            wide ? GetScreenWidth() : (float)GetScreenHeight() * aspect_ratio;
        float adjusted_height =
            !wide ? GetScreenHeight() : (float)GetScreenWidth() / aspect_ratio;

        float adjusted_x =
            !wide ? (float)(GetScreenWidth() - adjusted_width) / 2 : 0;
        float adjusted_y =
            wide ? (float)(GetScreenHeight() - adjusted_height) / 2 : 0;

        Rectangle dest = { adjusted_x, adjusted_y, adjusted_width,
                           adjusted_height };
        DrawTexturePro(renderTexture.texture, source, dest, (Vector2){ 0, 0 },
                       0.0f, WHITE);

        if (show_fps)
            DrawFPS(16, 16);
    }
    EndDrawing();
    //----------------------------------------------------------------------------------
}

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int canvasWidth = 400;
    const int canvasHeight = 225;
    const float aspect_ratio = (float) canvasWidth / canvasHeight;

    const int scale = 2;
    const int screenWidth = canvasWidth * scale;
    const int screenHeight = canvasHeight * scale;

    bool show_fps = true;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture to image");

    RenderTexture2D target = LoadRenderTexture(canvasWidth, canvasHeight);
    Rectangle source = {0, 0, (float) canvasWidth, (float) -canvasHeight};

    SetTargetFPS(60);

    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginTextureMode(target);
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

            bool wide = ((float) GetScreenWidth() / GetScreenHeight()) < aspect_ratio;

            float adjusted_width = wide ? GetScreenWidth() : (float) GetScreenHeight() * aspect_ratio; 
            float adjusted_height = !wide ? GetScreenHeight() : (float) GetScreenWidth() / aspect_ratio; 

            float adjusted_x = !wide ? (float) (GetScreenWidth() - adjusted_width) / 2 : 0;
            float adjusted_y = wide ? (float) (GetScreenHeight() - adjusted_height) / 2 : 0;

            Rectangle dest = {adjusted_x, adjusted_y, adjusted_width, adjusted_height};
            DrawTexturePro(target.texture, source, dest, (Vector2){0, 0}, 0.0f, WHITE);

            if (show_fps) DrawFPS(16, 16);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    // UnloadTexture(texture);       // Texture unloading
    UnloadRenderTexture(target);

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

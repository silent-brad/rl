/**
 * Displays a 3D cube with Raylib
 */
#include <raylib.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int TARGET_FPS = 60;

void render(Camera3D camera, Vector3 cube_position) {
    BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(camera);

            DrawCube(cube_position, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cube_position, 2.0f, 2.0f, 2.0f, MAROON);

            DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);

    EndDrawing();

    if (!WindowShouldClose()) {
        /*cube_position.x += 0.01f;
        if (cube_position.x > 10.0f) {
            cube_position.x = -10.0f;
        }*/

        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

        render(camera, cube_position);
    }
}

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple 3D Cube in Raylib");

    Camera3D camera = { position: (Vector3){ 0.0f, 10.0f, 10.0f }
                      , target: (Vector3){ 0.0f, 0.0f, 0.0f }
                      , up: (Vector3){ 0.0f, 1.0f, 0.0f }
                      , fovy: 45.0f
                      , projection: CAMERA_PERSPECTIVE
                      };

    Vector3 cube_position = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(TARGET_FPS);

    render(camera, cube_position);

    CloseWindow();
    return 0;
}

/**
 * Displays a 3D cube with Raylib
 */
#include <raylib.h>

int main(void) {
    const int screen_width = 800;
    const int screen_height = 600;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, "Simple 3D Cube in Raylib");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 cube_position = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update your variables here
        /*cube_position.x += 0.01f;
        if (cube_position.x > 10.0f) {
            cube_position.x = -10.0f;
        }*/
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

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
    }

    CloseWindow();
    return 0;
}

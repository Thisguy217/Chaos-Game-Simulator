#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <raylib.h>

void ShiftPoint(Vector2 *p, Vector2 *v) {
    v->x = (p->x + v->x) * 0.5;
    v->y = (p->y + v->y) * 0.5;
}

int main() {
    
    //Random Definition
    srand(time(NULL));

    //Screen Stuff
    const int width = 800;
    const int height = 450;

    //Points
    Vector2 p1 = {10.0, height - 10};
    Vector2 p2 = {(width / 2) - 10, 10.0};
    Vector2 p3 = {width - 10, height - 10};
    
    Vector2 v = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};

    //Other Constants
    int dotRadius = 1;
    int current_iteration = 0;
    int max_depth = 0;
    float time_computed = 0.0f;
    
    printf("Enter a number: (Minimum of 100)\n");
    scanf( "%d", &max_depth);
    //printf("%d \n",  max_depth);
    if (max_depth <= 100) {
        max_depth = 100;
    } else if (max_depth > 1000000) {
        max_depth = 1000000;
    }

    InitWindow(width, height, "Drawing Sierpinskis Triangle");

    //SetTargetFPS(120);
    ClearBackground(BLACK);

    while (!WindowShouldClose()) {
        if (current_iteration < max_depth) {
            int random_num = rand() % 3;
            switch (random_num) {
                case 0:
                    ShiftPoint(&p1, &v);
                    break;
                case 1:
                    ShiftPoint(&p2, &v);
                    break;
                case 2:
                    ShiftPoint(&p3, &v);
                    break;
                default:
                    break;
            }
            //printf("Check me out! %d\n", current_iteration);
            ++current_iteration;
        }

        //Screen shots being taken
        char str[50];
        sprintf(str, "output_%d.png", current_iteration);
        TakeScreenshot(str);

        BeginDrawing();

            //DrawText("Not Sure what I will call this", 190, 200, 20, WHITE);

            DrawCircleV(p1, dotRadius, WHITE);
            DrawCircleV(p2, dotRadius, WHITE);
            DrawCircleV(p3, dotRadius, WHITE);
            DrawCircleV(v , dotRadius, GREEN);

            DrawRectangle(0,0,200,12, BLACK);
            DrawRectangle(0,0,200,12, LIGHTGRAY);
            time_computed = (float)current_iteration / (float)max_depth;
            if (time_computed > 1.0f) {
                time_computed = 1.0f;
            }
            DrawRectangle(0,0,(int)(time_computed*200.0f), 12, MAROON);
        EndDrawing();
    }
    
    CloseWindow();

    //System command calls, I have no idea if these will work on Windows or MacOS.
    system("ffmpeg -framerate 30 -i output_%d.png -c:v libx264 -pix_fmt yuv420p output.mp4 -y");
    system("rm *.png");

    return 0;
}

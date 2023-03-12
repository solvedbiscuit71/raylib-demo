#include "lib/raylib.h"
#include "lib/helper.h"

int main(void)
{
    // Initialization
    // --------------------------------------------------------------------------
    const int screenWidth = 576;
    const int screenHeight = 576;

    int board[BOARDSIZE][BOARDSIZE];
    enum State player;
    enum Status status;
    Vector2 mousePosition, boardLocation;

    ClearBoard(board);
    player = X;
    status = ONGOING;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");

    Font rubik = LoadFontEx("fonts/rubik.ttf", FONTSIZE, 0, GLYPHCOUNT);
    Font rubikBig = LoadFontEx("fonts/rubik.ttf", FONTSIZE * 2, 0, GLYPHCOUNT);

    SetTargetFPS(30);
    // --------------------------------------------------------------------------

    // Game loop
    // --------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
        // Updates
        // --------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        if (status == ONGOING && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            boardLocation = GetBoardLocation(mousePosition);
            if (board[(int)boardLocation.x][(int)boardLocation.y] == EMPTY)
            {
                board[(int)boardLocation.x][(int)boardLocation.y] = player;
                player = player == X ? O : X;
            }
        }
        status = GetBoardStatus(board);


        // Drawing
        // --------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BG);

            switch (status)
            {
                case WIN:
                    DrawWin(player == X ? O : X, &rubikBig, &rubik);
                    break;
                case TIE:
                    DrawTie(&rubikBig, &rubik);
                    break;
                case ONGOING:
                    DrawBoard(board, &rubik);
                    break;
            }

        EndDrawing();
    }
    // --------------------------------------------------------------------------

    // De-Initialization
    // --------------------------------------------------------------------------
    UnloadFont(rubik);
    UnloadFont(rubikBig);

    CloseWindow();
    // --------------------------------------------------------------------------

    return 0;
}
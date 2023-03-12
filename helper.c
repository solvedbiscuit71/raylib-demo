#include "lib/raylib.h"
#include "lib/helper.h"

void ClearBoard(int board[BOARDSIZE][BOARDSIZE])
{
    int i, j;
    for (i = 0; i < BOARDSIZE; i++)
        for (j = 0; j < BOARDSIZE; j++)
            board[i][j] = EMPTY;
}

void DrawBoard(const int board[BOARDSIZE][BOARDSIZE], Font* font)
{
    int i, j;

    DrawLineEx((Vector2){LINE1, PADDING}, (Vector2){LINE1, PADDING + LINELEN}, 5.0f, FG);
    DrawLineEx((Vector2){PADDING, LINE1}, (Vector2){PADDING + LINELEN, LINE1}, 5.0f, FG);

    DrawLineEx((Vector2){LINE2, PADDING}, (Vector2){LINE2, PADDING + LINELEN}, 5.0f, FG);
    DrawLineEx((Vector2){PADDING, LINE2}, (Vector2){PADDING + LINELEN, LINE2}, 5.0f, FG);

    for (i = 0; i < BOARDSIZE; i++)
    {
        for (j = 0; j < BOARDSIZE; j++)
        {
            if (board[i][j] == EMPTY)
                continue;

            DrawTextEx(*font, board[i][j] == X ? "X" : "O", (Vector2){LETTERX + LETTERGAP * i, LETTERY + LETTERGAP * j}, font->baseSize, 2.0f, board[i][j] == X ? BLACK : WHITE);
        }
    }
}

void DrawWin(enum State winner, Font* fontBig, Font* font)
{
    DrawTextEx(*fontBig, winner == X ? "X" : "O", (Vector2){195, 88}, fontBig->baseSize, 2.0f, winner == X ? BLACK : WHITE);
    DrawTextEx(*font, "WINNER!", (Vector2){32, 312}, font->baseSize, 2.0f, BLACK);
}

void DrawTie(Font* fontBig, Font* font)
{
    DrawTextEx(*fontBig, "X", (Vector2){118, 88}, fontBig->baseSize, 2.0f, BLACK);
    DrawTextEx(*fontBig, "O", (Vector2){288, 88}, fontBig->baseSize, 2.0f, WHITE);
    DrawTextEx(*font, "DRAW!", (Vector2){88, 312}, font->baseSize, 2.0f, BLACK);
}

Vector2 GetBoardLocation(const Vector2 mousePos)
{
    int i, j;

    for (i = 0; i < BOARDSIZE; i++)
        for (j = 0; j < BOARDSIZE; j++)
            if (WITHIN(mousePos.x, i) && WITHIN(mousePos.y, j))
                return (Vector2){i, j};
    return (Vector2){-1, -1};
}

enum Status GetBoardStatus(int board[BOARDSIZE][BOARDSIZE])
{
    int i, j, flag;
    for (i = 0; i < BOARDSIZE; i++)
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return WIN;

    for (j = 0; j < BOARDSIZE; j++)
        if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return WIN;
        
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return WIN;

    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return WIN;

    flag = 0;
    for (i = 0; i < BOARDSIZE; i++)
        for (j = 0; j < BOARDSIZE; j++)
            if (board[i][j] == EMPTY)
                flag = 1;
    return flag ? ONGOING : TIE;
}
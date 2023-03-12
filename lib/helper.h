// Colors
#define BG   CLITERAL(Color){ 87, 186, 172, 255 }
#define FG   CLITERAL(Color){ 73, 159, 146, 255 }

#undef BLACK
#undef WHITE

#define BLACK   CLITERAL(Color){ 84, 84, 84, 255 }
#define WHITE   CLITERAL(Color){ 241, 235, 213, 255 }

// Fonts
#define FONTSIZE 138
#define GLYPHCOUNT 127

// Board
#define BOARDSIZE 3

#define PADDING 68

#define LINE1 211
#define LINE2 365
#define LINECOUNT 2
#define LINEGAP 148
#define LINELEN 440

#define LETTERX 100
#define LETTERY 72
#define LETTERGAP 150

enum State
{
    X,
    O,
    EMPTY
};

enum Status
{
    WIN,
    TIE,
    ONGOING
};

// Win & Tie
#define WINPLAYER (Vector2){195, 88}
#define WINLABEL (Vector2){32, 312}

#define TIEX (Vector2){118, 88}
#define TIEO (Vector2){288, 88}
#define TIELABEL (Vector2){88, 312}

// Macros
#define WITHIN(x, i) x > (PADDING + LINEGAP * i) && x < (PADDING + LINEGAP * (i+1))

// Functions
void ClearBoard(int board[BOARDSIZE][BOARDSIZE]);
void DrawBoard(const int board[BOARDSIZE][BOARDSIZE], Font* font);
void DrawWin(enum State winner, Font* fontBig, Font* font);
void DrawTie(Font* fontBig, Font* font);
Vector2 GetBoardLocation(const Vector2 mousePosition);
enum Status GetBoardStatus(int board[BOARDSIZE][BOARDSIZE]);
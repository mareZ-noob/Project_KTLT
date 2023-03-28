#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <windows.h>
#include <fstream>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
HWND hWnd = GetConsoleWindow();

struct Board
{
    int row, col;
    char ch = ' ';
};

char box[5][10] = {
    {" ------- "},
    {"|       |"},
    {"|       |"},
    {"|       |"},
    {" ------- "}};

void getBackground(char bg[][41])
{
    ifstream file("ascii_art\\pikapika.txt");
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            bg[i][j] = file.get();
        }
        file.ignore();
    }
    file.close();
}

void moveCursor(int posX, int posY)
{
    COORD CursorPosition;
    CursorPosition.X = posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void displayBackground(char bg[][41], int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            moveCursor((x + 1) * 10 + j, (y + 1) * 4 + i);
            cout << bg[y * 4 + i][x * 10 + j];
        }
    }
}

void deallocate(Board **board, int _row)
{
    for (int i = 0; i < _row; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}

void deleteBoard(Board &x)
{
}

Board **randomEven(Board **&board, int _row, int _col)
{
    // 1D from vector
    vector<Board> vec;
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            vec.push_back(board[i][j]);
        }
    }

    // Random
    random_shuffle(vec.begin(), vec.end());

    // Push again
    int index = 0;
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            board[i][j] = vec[index++];
        }
    }
    return board;
}

void createBoard(Board **&board, int _row, int _col)
{
    srand(time(0));
    board = new Board *[_row];
    for (int i = 0; i < _row; i++)
    {
        board[i] = new Board[_col];
        for (int j = 0; j < _col; j++)
        {
            board[i][j].row = i;
            board[i][j].col = j;
        }
    }

    if (_col & 1) // _col is odd
    {
        for (int i = 0; i <= _row / 2; i++)
        {
            for (int j = 0; j < _col; j++)
            {
                board[i][j].ch = 65 + rand() % 26;
                board[_row - i - 1][_col - j - 1].ch = board[i][j].ch;
            }
        }
    }
    else // _col is even
    {
        for (int i = 0; i < _row; i++)
        {
            for (int j = 0; j <= _col / 2; j++)
            {
                board[i][j].ch = 65 + rand() % 26;
                board[i][_col - j - 1].ch = board[i][j].ch;
            }
        }
    }
    randomEven(board, _row, _col);
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            if (board[i][j].ch == ' ')
            {
                board[i][j].ch = 65 + rand() % 26;
                board[i][_col - j - 1].ch = board[i][j].ch;
            }
        }
    }
}

// check with line x, from column y1 to y2
bool checkLineX(Board **board, int y1, int y2, int x)
{
    // find point have column max and min
    int min_val = min(y1, y2);
    int max_val = max(y1, y2);
    // run column
    for (int y = min_val; y <= max_val; y++)
    {
        if (board[x][y].ch != ' ')
            return false;
    }
    return true;
}

// check with line y, from row x1 to x2
bool checkLineY(Board **board, int x1, int x2, int y)
{
    int min_val = min(x1, x2);
    int max_val = max(x1, x2);
    for (int x = min_val; x <= max_val; x++)
    {
        if (board[x][y].ch != ' ')
            return false;
    }
    return true;
}

bool check_I(Board **board, int x1, int y1, int x2, int y2)
{
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;

    if (x1 == x2)
    {
        if (checkLineX(board, y1, y2, x1))
            return true;
        else
            return false;
    }
    else if (y1 == y2)
    {
        if (checkLineY(board, x1, x2, y1))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool check_L(Board **board, int x1, int y1, int x2, int y2)
{
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    if (board[x2][y1].ch == ' ' && checkLineX(board, y1, y2, x2) && checkLineY(board, x1, x2, y1))
        return true;
    else if (board[x1][y2].ch == ' ' && checkLineX(board, y1, y2, x1) && checkLineY(board, x1, x2, y2))
        return true;
    else
        return false;
}

bool checkRectX(Board **board, int x1, int x2, int y1, int y2)
{
    int minY = min(y1, y2);
    int maxY = max(y1, y2);

    for (int y = minY + 1; y < maxY; y++)
    {
        if (checkLineX(board, minY, y, x1))
            ;
    }
    return false;
}

// bool checkRectY(int** mang, int x1, int x2, int y1, int y2) {
// 	int minY = findMin(y1, y2);
// 	int maxY = findMax(y1, y2);
// 	int minX = findMin(x1, x2);
// 	int maxX = findMax(x1, x2);

// 	for (int x = minX + 1; x < maxX; x++) {
// 		if (mang[x][minY] != 32)
// 			return false;
// 		if (CheckLineY(mang, x - 1, maxX, maxY) && CheckLineX(mang, minY, maxY + 1, x))
// 			return true;
// 	}
// 	return false;
// }

int main()
{
    Board x{5, 6, ' '};
    Board **board = new Board *[x.row * x.col + 1];
    createBoard(board, x.row, x.col);

    int freq[256] = {0};
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
        {
            cout << board[i][j].ch << " ";
            // freq[board[i][j].ch]++;
        }
        cout << endl;
    }
    while (1)
    {
        int x1, y1, x2, y2;
        cout << "Nhap x1, y1: ";
        cin >> x1 >> y1;
        cout << "Nhap x2, y2: ";
        cin >> x2 >> y2;
        if (check_I(board, x1, y1, x2, y2))
        {
            board[x1][y1].ch = ' ';
            board[x1][y1].ch = ' ';
        }
        else if (check_L(board, x1, y1, x2, y2))
        {
            board[x1][y1].ch = ' ';
            board[x1][y1].ch = ' ';
        }
        for (int i = 0; i < x.row; i++)
        {
            for (int j = 0; j < x.col; j++)
            {
                cout << board[i][j].ch << " ";
            }
            cout << endl;
        }
    }
    // for (int i = 0; i < 256; i++)
    // {
    //     if (freq[i])
    //     {
    //         cout << char(i) << ": " << freq[i] << endl;
    //     }
    // }
    deallocate(board, x.row);

    // char ch[26][41];
    // // getBackground(ch);
    // for (int i = 0; i < 5; i++)
    // {
    //     moveCursor(20, 20 + i);
    //     cout << box[i];
    // }
    // moveCursor(24, 22);
    // cout << "A";
    // cout << "\n\n\n\n";
    // getBackground(ch);
    // // displayBackground(ch, 40, 20);
    system("pause");
    return 0;
}

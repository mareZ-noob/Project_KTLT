#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include "Setup.h"

using namespace std;

struct Board
{
    int row, col;
    char ch = ' ';
};

char box[4][9] = {
    {" ----- "},
    {"|     |"},
    {"|     |"},
    {" ----- "}};

void getBackground(char bg[][41])
{
    ifstream f("ascii_art\\pikapika.txt");
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            bg[i][j] = f.get();
            // cout << bg[i][j];
        }
        f.ignore();
    }
    f.close();
}

void displayBackground(char bg[][41], int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            // moveCursor((x + 1) * 10 + j, (y + 1) * 4 + i);
            cout << bg[y * 4 + i][x * 10 + j];
        }
    }
}

void deallocate(Board &x, int **board)
{
    for (int i = 0; i < x.row; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void deleteBoard(Board &x)
{
}

int **randomEven(int **board, Board &x)
{
    // 1D from vector
    vector<int> vec;
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
        {
            vec.push_back(board[i][j]);
        }
    }

    // Random
    random_shuffle(vec.begin(), vec.end());

    // Push again
    int index = 0;
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
        {
            board[i][j] = vec[index++];
        }
    }
    return board;
}

int **createBoard(Board &x)
{
    srand(time(0));
    int **board;
    board = new int *[x.row];
    for (int i = 0; i < x.row; i++)
    {
        board[i] = new int[x.col];
    }

    if (x.col & 1)
    {
        for (int i = 0; i <= x.row / 2; i++)
        {
            for (int j = 0; j < x.col; j++)
            {
                board[i][j] = 65 + rand() % 26;
                board[x.row - i - 1][x.col - j - 1] = board[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < x.row; i++)
        {
            for (int j = 0; j <= x.col / 2; j++)
            {
                board[i][j] = 65 + rand() % 26;
                board[i][x.col - j - 1] = board[i][j];
            }
        }
    }
    randomEven(board, x);
    return board;
}

int main()
{
    Board x{5, 6, ' '};
    int **board = new int *[x.row * x.col + 1];
    board = createBoard(x);
    // randomEven(board, x.row, x.col);

    int freq[256] = {0};
    for (int i = 0; i < x.row; i++)
    {
        for (int j = 0; j < x.col; j++)
        {
            cout << char(board[i][j]) << " ";
            freq[board[i][j]]++;
        }
        cout << endl;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i])
        {
            cout << char(i) << ": " << freq[i] << endl;
        }
    }
    deallocate(x, board);

    char ch[26][41];
    // getBackground(ch);
    for (int i = 0; i < 4; i++) {
        cout << box[i];
    }
    system("pause");
    return 0;
}

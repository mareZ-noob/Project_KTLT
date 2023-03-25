#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

char box[5][12] = {
    {" --------- "},
    {"|         |"},
    {"|         |"},
    {"|         |"},
    {" --------- "}};

int **createBoard(int row, int col)
{
    srand(time(0));
    int **board;
    board = new int *[row];
    for (int i = 0; i < row; i++)
    {
        board[i] = new int[col];
    }

    if (col & 1)
    {
        for (int i = 0; i <= row / 2; i++)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = 65 + rand() % 26;
                board[row - i - 1][col - j - 1] = board[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j <= col / 2; j++)
            {
                board[i][j] = 65 + rand() % 26;
                board[i][col - j - 1] = board[i][j];
            }
        }
    }
    return board;
}

int **randomEven(int **board, int row, int col)
{
    // 1D from vector
    vector<int> vec;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            vec.push_back(board[i][j]);
        }
    }

    // Random
    random_shuffle(vec.begin(), vec.end());

    // Push again
    int index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = vec[index++];
        }
    }
    return board;
}

int main()
{
    int row = 5, col = 6;
    int **board = createBoard(row, col);
    randomEven(board, row, col);

    int freq[256] = {0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
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

    for (int i = 0; i < row; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    system("pause");
    return 0;
}

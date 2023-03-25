#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

int main()
{
    srand(time(0));
    int row = 10, col = 20;
    int **board;
    board = new int *[row];
    for (int i = 0; i < row; i++)
    {
        board[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <= col / 2; j++)
        {
            board[i][j] = 65 + rand() % 26;
            board[i][col - j - 1] = board[i][j];
        }
    }

     // Tạo mảng 1D từ ma trận
    vector<int> vec;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            vec.push_back(board[i][j]);
        }
    }

    // Random lại các phần tử trong mảng
    random_shuffle(vec.begin(), vec.end());

    // Chuyển các giá trị đã random trở lại vào ma trận
    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = vec[index++];
        }
    }
    
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
    
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            cout << char(i) << ": " << freq[i] << endl;
        }
    }

    
    system("pause");

    return 0;
}
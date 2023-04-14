#include "Check.h"

// check with line x, from column y1 to y2
bool checkLineX(Board **board, int y1, int y2, int x)
{
    // find point have column max and min
    int min_val = min(y1, y2);
    int max_val = max(y1, y2);
    // run column
    for (int y = min_val + 1; y < max_val; y++)
        if (board[x][y].ch != ' ')
            return false;
    return true;
}

// check with line y, from row x1 to x2
bool checkLineY(Board **board, int x1, int x2, int y)
{
    // find point have row max and min
    int min_val = min(x1, x2);
    int max_val = max(x1, x2);
    // run row
    for (int x = min_val + 1; x < max_val; x++)
        if (board[x][y].ch != ' ')
            return false;
    return true;
}

bool check_I(Board **board, int x1, int y1, int x2, int y2)
{
    // use 2 functions above
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    if (x1 == x2)
        if (checkLineX(board, y1, y2, x1))
            return true;
        else
            return false;
    else if (y1 == y2)
        if (checkLineY(board, x1, x2, y1))
            return true;
        else
            return false;
    else
        return false;
}

bool check_L(Board **board, int x1, int y1, int x2, int y2)
{
    // find the juction (call A) of 2 points (B, C)
    // check path B->A, A->C
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    if (board[x2][y1].ch == ' ' && checkLineX(board, y1, y2, x2) && checkLineY(board, x1, x2, y1))
        return true;
    else if (board[x1][y2].ch == ' ' && checkLineX(board, y1, y2, x1) && checkLineY(board, x1, x2, y2))
        return true;
    else
        return false;
}

bool checkRectX(Board **board, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    else
    {
        if (y1 < y2)
        {
            for (int i = y1 + 1; i < y2; i++)
            {
                bool check1 = checkLineX(board, y1, i, x1);

                bool check2;
                if (x1 < x2)
                    check2 = checkLineY(board, x1 - 1, x2 + 1, i);
                else
                    check2 = checkLineY(board, x1 + 1, x2 - 1, i);

                bool check3 = checkLineX(board, y2, i, x2);
                if (check1 && check2 && check3)
                    return true;
            }
        }
        else if (y1 > y2)
        {
            for (int i = y1 - 1; i > y2; i--)
            {
                bool check1 = checkLineX(board, y1, i, x1);

                bool check2;
                if (x1 < x2)
                    check2 = checkLineY(board, x1 - 1, x2 + 1, i);
                else
                    check2 = checkLineY(board, x1 + 1, x2 - 1, i);

                bool check3 = checkLineX(board, y2, i, x2);
                if (check1 && check2 && check3)
                    return true;
            }
        }
        return false;
    }
}

bool checkRectY(Board **board, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    else
    {
        if (x1 < x2)
        {
            for (int i = x1 + 1; i < x2; i++)
            {
                bool check1 = checkLineY(board, x1, i, y1);

                bool check2;
                if (y1 < y2)
                    check2 = checkLineX(board, y1 - 1, y2 + 1, i);
                else
                    check2 = checkLineX(board, y1 + 1, y2 - 1, i);

                bool check3 = checkLineY(board, x2, i, y2);
                if (check1 && check2 && check3)
                    return true;
            }
        }
        else if (x1 > x2)
        {
            for (int i = x1 - 1; i > x2; i--)
            {
                bool check1 = checkLineY(board, x1, i, y1);

                bool check2;
                if (y1 < y2)
                    check2 = checkLineX(board, y1 - 1, y2 + 1, i);
                else
                    check2 = checkLineX(board, y1 + 1, y2 - 1, i);

                bool check3 = checkLineY(board, x2, i, y2);
                if (check1 && check2 && check3)
                    return true;
            }
        }
        return false;
    }
}

bool check_Z(Board **board, int x1, int y1, int x2, int y2)
{
    // use 2 functions above
    return checkRectX(board, x1, y1, x2, y2) ||
           checkRectY(board, x1, y1, x2, y2);
}

bool checkMoreLineX(Board **board, int _row, int _col, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    else
    {
        for (int i = y1 + 1; i <= _col; i++)
        {
            bool check1 = checkLineX(board, y1, i, x1);

            bool check2;
            if (i != _col)
            {
                int startX, endX;
                if (x1 < x2)
                {
                    startX = x1 - 1;
                    endX = x2 + 1;
                }
                else
                {
                    startX = x1 + 1;
                    endX = x2 - 1;
                }
                check2 = checkLineY(board, startX, endX, i);
            }
            else
                check2 = true;

            bool check3 = checkLineX(board, y2, i, x2);
            if (check1 && check2 && check3)
                return true;
        }
        for (int i = y1 - 1; i >= -1; i--)
        {
            bool check1 = checkLineX(board, y1, i, x1);

            bool check2;
            if (i != -1)
            {
                int startX, endX;
                if (x1 < x2)
                {
                    startX = x1 - 1;
                    endX = x2 + 1;
                }
                else
                {
                    startX = x1 + 1;
                    endX = x2 - 1;
                }
                check2 = checkLineY(board, startX, endX, i);
            }
            else
                check2 = true;

            bool check3 = checkLineX(board, y2, i, x2);
            if (check1 && check2 && check3)
                return true;
        }
        return false;
    }
}

bool checkMoreLineY(Board **board, int _row, int _col, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return false;
    if (board[x1][y1].ch != board[x2][y2].ch)
        return false;
    else
    {
        for (int i = x1 + 1; i <= _row; i++)
        {
            bool check1 = checkLineY(board, x1, i, y1);

            bool check2;
            if (i != _row)
            {
                int startY, endY;
                if (y1 < y2)
                {
                    startY = y1 - 1;
                    endY = y2 + 1;
                }
                else
                {
                    startY = y1 + 1;
                    endY = y2 - 1;
                }
                check2 = checkLineX(board, startY, endY, i);
            }
            else
                check2 = true;

            bool check3 = checkLineY(board, x2, i, y2);
            if (check1 && check2 && check3)
                return true;
        }
        for (int i = x1 - 1; i >= -1; i--)
        {
            bool check1 = checkLineY(board, x1, i, y1);

            bool check2;
            if (i != -1)
            {
                int startY, endY;
                if (y1 < y2)
                {
                    startY = y1 - 1;
                    endY = y2 + 1;
                }
                else
                {
                    startY = y1 + 1;
                    endY = y2 - 1;
                }
                check2 = checkLineX(board, startY, endY, i);
            }
            else
                check2 = true;

            bool check3 = checkLineY(board, x2, i, y2);
            if (check1 && check2 && check3)
                return true;
        }
        return false;
    }
}

bool check_U(Board **board, int _row, int _col, int x1, int y1, int x2, int y2)
{
    return checkMoreLineX(board, _row, _col, x1, y1, x2, y2) ||
           checkMoreLineY(board, _row, _col, x1, y1, x2, y2);
}

bool check_All(Board **board, int _row, int _col, int x1, int y1, int x2, int y2)
{
    if (check_I(board, x1, y1, x2, y2))
        return true;
    else if (check_L(board, x1, y1, x2, y2))
        return true;
    else if (check_Z(board, x1, y1, x2, y2))
        return true;
    else if (check_U(board, _row, _col, x1, y1, x2, y2))
        return true;
    return false;
}

bool checkGameWin(Board **board, int _row, int _col)
{
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            if (board[i][j].ch != ' ')
                return false;
        }
    }
    return true;
}

// loop to find valid pair
bool moveSuggestion(Board **board, int _row, int _col, Point &p1, Point &p2)
{
    for (int i = 0; i < _row; i++)
    {
        for (int j = 0; j < _col; j++)
        {
            if (board[i][j].status == 2)
                continue;
            for (int m = 0; m < _row; m++)
            {
                for (int n = 0; n < _col; n++)
                {
                    if (check_All(board, _row, _col, i, j, m, n))
                    {
                        p1.x = i;
                        p1.y = j;
                        p2.x = m;
                        p2.y = n;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
#include "User.h"

bool verify(string email)
{
    int n = email.size();
    string pre = "@clc.fitus.edu.vn";
    string temp = "";
    int k = n - 1;

    while (email[k] != '@')
        k--;
    for (int j = k; j < n; j++)
        temp += email[j];
    if (temp == pre)
        return true;
    else
        return false;
}
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

bool comparePlayers(const Players &p1, const Players &p2)
{
    if (p1.point != p2.point)
    {
        return p1.point > p2.point;
    }
    else
    {
        return p1.time < p2.time;
    }
}

long int fileSize(string file)
{
    const char *file_name = file.c_str();
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        ifstream makeFile;
        makeFile.open(file);
        makeFile.close();
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    fclose(fp);

    return res;
}

void pushRecord(Players p)
{
    long int _size = fileSize("players.bin");
    if (_size < sizeof(Players) * 5)
    {
        ofstream fileIn;
        fileIn.open("players.bin", ios::binary | ios::app);
        fileIn.write(reinterpret_cast<const char *>(&p), sizeof(Players));
        fileIn.close();

        // rewrite and sort
        int curSize = fileSize("players.bin") / sizeof(Players);
        Players players_read[curSize];
        ifstream fi;
        fi.open("players.bin", ios::binary);
        fi.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * curSize);
        fi.close();
        sort(players_read, players_read + curSize, comparePlayers);

        ofstream f("players.bin", ios::binary);
        f.write(reinterpret_cast<const char *>(&players_read), sizeof(Players) * curSize);
        f.close();
    }
    else
    {
        Players players_read[5];
        ifstream file("players.bin", ios::binary);
        file.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * 5);
        for (int i = 4; i >= 0; i--)
        {
            if (players_read[i].point < p.point)
            {
                strcpy(players_read[i].name, p.name);
                players_read[i].point = p.point;
                players_read[i].time = p.time;
                break;
            }
            else if ((players_read[i].point == p.point) && (players_read[i].time > p.time))
            {
                strcpy(players_read[i].name, p.name);
                players_read[i].point = p.point;
                players_read[i].time = p.time;
                break;
            }
        }
        // sort
        sort(players_read, players_read + 5, comparePlayers);
        file.close();

        // rewrite
        ofstream fi("players.bin", ios::binary);
        fi.write(reinterpret_cast<const char *>(&players_read), sizeof(Players) * 5);
        fi.close();
    }
}

void printLeaderboard()
{
    Players players_read[5];
    ifstream infile("players.bin", ios::binary);
    infile.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * 5);
    infile.close();

    read_file_at_pos("ascii_art\\leaderboard.txt", 11, 0, 25, 3);
    TextColor(11);

    drawRectangle(40, 11, 19, 15);
    drawRectangle(61, 11, 9, 15);
    drawRectangle(72, 11, 8, 15);

    button(40, 11, 20, 2, 4, 11, 0, "       NAME");
    button(61, 11, 10, 2, 4, 11, 0, "  POINT");
    button(72, 11, 9, 2, 4, 11, 0, "  TIME");

    for (int i = 0; i < fileSize("players.bin") / sizeof(Players); i++)
    {
        moveCursor(43, 14 + i); cout << players_read[i].name;
        moveCursor(65, 14 + i); cout << players_read[i].point;
        moveCursor(76, 14 + i); cout << players_read[i].time;
    }
}

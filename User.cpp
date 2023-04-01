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

long long unsigned int fileSize(string file)
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
    long long unsigned int _size = fileSize("players.bin");
    if (_size < sizeof(Players) * 5)
    {
        ofstream fileIn;
        fileIn.open("players.bin", ios::binary | ios::app);
        fileIn.write(reinterpret_cast<const char *>(&p), sizeof(Players));
        fileIn.close();

        // rewrite and sort
        long long unsigned int curSize = fileSize("players.bin") / sizeof(Players);
        //Players players_read[curSize];
        Players* players_read = new Players[curSize];
        ifstream fi;
        fi.open("players.bin", ios::binary);
        fi.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * curSize);
        fi.close();
        sort(players_read, players_read + curSize, comparePlayers);

        ofstream f("players.bin", ios::binary);
        f.write(reinterpret_cast<const char *>(&players_read), sizeof(Players) * curSize);
        delete [] players_read;
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

    read_file_at_pos("ascii_art\\leaderboard.txt", OCEAN, BLACK, 20, 3);

    TextColor(CYAN);
    drawRectangle(33, 12, 32, 15);
    drawRectangle(66, 12, 9, 15);
    drawRectangle(76, 12, 8, 15);

    button(33, 12, 33, 2, LIGHT_RED, CYAN, BLACK, "              NAME");
    button(66, 12, 10, 2, LIGHT_RED, CYAN, BLACK, "  POINT");
    button(76, 12, 9, 2, LIGHT_RED, CYAN, BLACK, "  TIME");

    moveCursor(33, 14); cout << char(195);
    moveCursor(66, 14); cout << char(197);
    moveCursor(76, 14); cout << char(197);
    moveCursor(85, 14); cout << char(180);
    moveCursor(66, 12); cout << char(194);
    moveCursor(66, 27); cout << char(193);
    moveCursor(76, 12); cout << char(194);
    moveCursor(76, 27); cout << char(193);

    TextColor(LIGHT_WHITE);
    for (long long unsigned int i = 0; i < fileSize("players.bin") / sizeof(Players); i++)
    {
        moveCursor(35, 15 + i); cout << i + 1 << ". " << players_read[i].name;
        moveCursor(70, 15 + i); cout << players_read[i].point;
        moveCursor(80, 15 + i); cout << players_read[i].time;
    }
}

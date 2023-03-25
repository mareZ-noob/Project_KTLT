#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

long int findSize(char file_name[])
{
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    fclose(fp);

    return res;
}

void pushRecord(Players p)
{
    long int _size = findSize("players.bin");
    if (_size < sizeof(Players) * 5)
    {
        fstream fileIn;
        fileIn.open("players.bin", ios::binary | ios::app);
        fileIn.write(reinterpret_cast<const char *>(&p), sizeof(Players));
        fileIn.close();
    }
    else
    {
        Players players_read[5];
        ifstream file("players.bin", ios::binary);
        file.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * 5);
        for (int i = 5; i >= 0; i--)
        {
            if (players_read[i].point < p.point)
            {
                strcpy(players_read[i].name, p.name);
                players_read[i].point = p.point;
                break;
            } else if ((players_read[i].point == p.point) && (players_read[i].time > p.time)) {
                strcpy(players_read[i].name, p.name);
                players_read[i].point = p.point;
                break;
            }
        }
        file.close();
    }
}

// Define the Players struct
struct Players
{
    char name[20];
    int point;
    int time;
};

bool comparePlayers(const Players &p1, const Players &p2)
{
    return p1.point > p2.point;
}

int main()
{
    // Create an array of Players with 5 elements and initialize them
    Players players[5];
    for (int i = 0; i < 5; i++)
    {
        cin.getline(players[i].name, 20);
        cin >> players[i].point;
        cin >> players[i].time;
        cin.ignore();
    }
    sort(players, players + 5, comparePlayers);
    // Write the first 5 elements of the array of Players to a binary file
    ofstream outfile("players.bin", ios::binary);
    outfile.write(reinterpret_cast<const char *>(&players), sizeof(Players) * 5);
    outfile.close();

    // Read the contents of the binary file into a new array of Players
    Players players_read[5];
    ifstream infile("players.bin", ios::binary);
    infile.read(reinterpret_cast<char *>(&players_read), sizeof(Players) * 5);
    // char s[] = "hy";
    // int n = 25;
    // for (int i = 5; i >= 0; i--)
    // {
    //     if (players_read[i].time > n)
    //     {
    //         strcpy(players_read[i].name, s);
    //         players_read[i].time = n;
    //         break;
    //     }
    // }
    infile.close();

    ofstream file("players.bin", ios::binary);
    file.write(reinterpret_cast<const char *>(&players_read), sizeof(Players) * 5);
    file.close();

    // Print the names and times of the Players that were read from the file
    for (int i = 0; i < 5; i++)
    {
        cout << players_read[i].name << " " << players_read[i].point << " " << players_read[i].time << endl;
    }
    return 0;
}

// string s = "hy";
// int n = 25;
// for (int i = 5; i >= 0; i--) {
//     if (players_read[i].time > n) {
//         players_read[i].name = s;
//         players_read[i].time = n;
//         break;
//     }
// }
// nam
// 20
// 100
// huy
// 30
// 60
// thanh
// 6
// 80
// tri
// 5
// 20
// lan
// 15
// 10

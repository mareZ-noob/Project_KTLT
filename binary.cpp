#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

// Define the Players struct
struct Players
{
    char name[50];
    int point;
    int time;
};

bool comparePlayers(const Players &p1, const Players &p2)
{
    return p1.time < p2.time;
}

int main()
{
    // Create an array of Players with 5 elements and initialize them
    Players players[5];
    for (int i = 0; i < 5; i++)
    {
        cin.getline(players[i].name, 50);
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
    char s[] = "hy";
    int n = 25;
    for (int i = 5; i >= 0; i--)
    {
        if (players_read[i].time > n)
        {
            strcpy(players_read[i].name, s);
            players_read[i].time = n;
            break;
        }
    }
    infile.close();

    ofstream file("players.bin", ios::binary);
    file.write(reinterpret_cast<const char *>(&players_read), sizeof(Players) * 5);
    file.close();

    // Print the names and times of the Players that were read from the file
    for (int i = 0; i < 5; i++)
    {
        cout << players_read[i].name << " " << players_read[i].time << endl;
    }
    system("pause");
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
// huy
// 30
// thanh
// 6
// tri
// 5
// lan
// 15

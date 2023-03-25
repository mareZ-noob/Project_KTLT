#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

double timePass() {
    // Get the current time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform some work
    for (int i = 0; i < 1000000000; i++)
    {
        int count = 1 +i;
    }

    // Get the current time again
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    double count = elapsed_time.count();

    return count/1000;
}

void clockTime() {
    int elapsed_seconds = 0;

    while (true)
    {
        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Update elapsed time
        elapsed_seconds++;

        // Convert elapsed time to minutes and seconds
        int minutes = elapsed_seconds / 60;
        int seconds = elapsed_seconds % 60;

        // format 00:00
        std::cout << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << '\r';
    }
}

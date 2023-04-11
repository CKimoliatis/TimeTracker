#include <chrono>
#include <iostream>
using namespace std;

class Timer
{
private:
    int total;

public:
    Timer() = default;
    void start()
    {
        auto start = chrono::steady_clock::now();
        char choice;
        while (1)
        {
            cout << "Timer started!\n";
            cout << "Press q to quit\n";
            cin >> choice;
            if (choice == 'q')
            {
                auto now = chrono::steady_clock::now();
                auto elapsed = chrono::duration_cast<chrono::seconds>(now - start);
                total = (int)elapsed.count();
                total += 7456; // testing purposes
                break;
            }
        }
        this->print();
    }

    int getTotal()
    {
        return total;
    }

    void print()
    {
        int hours, minutes, seconds;
        hours = total / 3600;
        total %= 3600;
        minutes = total / 60;
        seconds = total % 60;
        cout << "Total elapsed time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
    }
};
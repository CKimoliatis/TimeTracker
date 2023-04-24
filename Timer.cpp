#include "Timer.h"

void Timer::start()
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
            break;
        }
    }
    this->print();
}

int Timer::getTotal()
{
    return total;
}

void Timer::print()
{
    int hours, minutes, seconds, temp;
    temp = total;

    hours = temp / 3600;
    temp %= 3600;
    minutes = temp / 60;
    seconds = temp % 60;

    cout << "Session elapsed time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
}
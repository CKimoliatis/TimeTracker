#include <chrono>
#include <iostream>
#include "Timer.h"
using namespace std;

class User{
private:   
    char username[15];
    char password[15];
    int totalTime;
public:
    User() = default;

};

int main()
{
    Timer *timer = new Timer();
    timer->start();
    delete timer;
    return 0;
}

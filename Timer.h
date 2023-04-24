#include "AllHeader.h"
using namespace std;

class Timer{
private:
    int total;
public:
    Timer() = default;
    void start();
    int getTotal();
    void print();
};
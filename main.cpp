#include "AllHeader.h"
#include "Timer.h"
#include "User.h"
using namespace std;

int main(){
    string n, p;
    cout << "Enter username:\n";
    cin>>n;
    cout << "Enter password:\n";
    cin>>p;
    User* user = new User(n, p);
    user->verifyUser();
    Timer* timer = new Timer();
    timer->start();
    int totalTime = timer->getTotal() + user->getTime();
    user->setTime(totalTime);
    user->updateUserTime();
    user->printUser();

    
    delete user;
    return 0;
}

#include "AllHeader.h"
#include "User.h"
#include "Admin.h"
using namespace std;

bool checkAcc(string, string);

int main(){
    cout << "Welcome to Chris' Time Tracker!\n";
    string n, p;
    cout << "Enter username:\n";
    cin>>n;
    cout << "Enter password:\n";
    cin>>p;
    if(checkAcc(n,p)){
        Admin* admin = new Admin(n,p);
        admin->adminPrompt();
        delete admin;
    }else{
        User* user = new User(n, p);
        user->verifyUser();
        Timer* timer = new Timer();
        timer->start();
        int totalTime = timer->getTotal() + user->getTime();
        user->setTime(totalTime);
        user->updateUserTime();
        user->printUser();
        delete user;
        delete timer;
    }
    return 0;
}

bool checkAcc(string n, string p){
    fstream file("admin.bin", ios::binary|ios:: in);
    AdminInfo* temp = new AdminInfo();
    while(file.read(reinterpret_cast<char*>(temp), sizeof(AdminInfo))){
        if(n.compare(temp->name) == 0 && p.compare(temp->password) == 0){
            file.close();
            delete temp;
            return true;
        }
    }
    file.close();
    delete temp;
    return false;
}
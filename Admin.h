#ifndef ADMIN_H
#define ADMIN_H

#include "AllHeader.h"
#include "User.h"
using namespace std;

struct AdminInfo{
    char name[20];
    char password[20];

    AdminInfo() : name(""), password("") {}
};

class Admin{
private:
    AdminInfo* info;
    vector<UserInfo*> users;
public:
    Admin();
    Admin(string, string);
    ~Admin();
    void adminPrompt();
    void swapActiveUser(string);
    void writeVec();
    void addAdmin(string, string);
    void changeUserPass();
    void changeUserStatus();
    void fillVec();
    void printUsers();
};

#endif /* ADMIN_H */
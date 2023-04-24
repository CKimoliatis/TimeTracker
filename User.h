/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   User.h
 * Author: ckimo
 *
 * Created on April 10, 2023, 6:14 PM
 */

#ifndef USER_H
#define USER_H

#include "AllHeader.h"
#include "Timer.h"

struct UserInfo{
    char name[15];
    char password[15];
    int totalTime;
    bool active;
    
    UserInfo() : name(""), password(""), totalTime(0), active(true) {}
};
class User{
private:   
    UserInfo* info;
public:
    User();
    User(string, string);
    ~User();
    void setTime(int t);
    int getTime();
    void printUser();
    void updateUserTime();
    void verifyUser();
};



#endif /* USER_H */


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
    User(){
        info = new UserInfo();
    }
    User(string n, string p){
        info = new UserInfo();
        strcpy(info->name, n.c_str());
        strcpy(info->password, p.c_str());
    }
    ~User(){
        delete info;
    }
    void setTime(int t){
        info->totalTime = t;
    }
    int getTime(){
        return info->totalTime;
    }

    void printUser(){
        int hours, minutes, seconds, temp;
        temp = info->totalTime;

        hours = temp / 3600;
        temp %= 3600;
        minutes = temp / 60;
        seconds = temp % 60;

        cout << "Total elapsed time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
    }

    void updateUserTime() {
        fstream file("users.bin", ios::binary | ios::in | ios::out);

        UserInfo temp;
        bool userFound = false;

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(UserInfo))) {
            if (strcmp(temp.name, info->name) == 0 && strcmp(temp.password, info->password) == 0) {
                temp.totalTime = info->totalTime;
                file.seekp(-static_cast<int>(sizeof(UserInfo)), ios::cur);
                file.write(reinterpret_cast<const char*>(&temp), sizeof(UserInfo));
                userFound = true;
                break;
            }
        }

        if (!userFound) {
            cout << "User not found in file." << endl;
        }

        file.close();
    }

    void verifyUser()
    {
        bool userFound = false;
        fstream file("users.bin", ios::binary | ios::in);

        // Loop through each UserInfo struct in the file
        UserInfo *temp = new UserInfo;
        while(file.read(reinterpret_cast<char*>(temp),sizeof(UserInfo))){
            if(strcmp(temp->name,info->name) == 0 && strcmp(temp->password, info->password) == 0){
                cout << "\nWelcome back " << temp->name << "!" << endl;
                info = temp; //Need to change in my storefront
                userFound = true;
            }else if(strcmp(temp->name,info->name) == 0 && strcmp(temp->password, info->password) != 0){
                do{
                    cout << "Wrong Password Please Reenter Password:\n";
                    cin >> info->password;
                    userFound = true;
                }while(strcmp(temp->password, info->password) != 0);
                info = temp;
            }
        }
        file.close();

        // If user not found, add them to the file
        if (!userFound)
        {
            file.open("users.bin", ios::binary | ios::app);
            if (!file)
            {
                cerr << "Error opening output file." << endl;
                delete temp;
                return;
            }

            file.write(reinterpret_cast<char *>(info), sizeof(UserInfo));
            cout << "User added to file." << endl;

            file.close();
        }

        delete temp;
    }
};



#endif /* USER_H */


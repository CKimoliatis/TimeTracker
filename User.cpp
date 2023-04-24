#include "User.h"

User::User()
{
    info = new UserInfo();
}
User::User(string n, string p)
{
    info = new UserInfo();
    strcpy(info->name, n.c_str());
    strcpy(info->password, p.c_str());
}
User::~User()
{
    delete info;
}
void User::setTime(int t)
{
    info->totalTime = t;
}
int User::getTime()
{
    return info->totalTime;
}

void User::printUser()
{
    int hours, minutes, seconds, temp;
    temp = info->totalTime;

    hours = temp / 3600;
    temp %= 3600;
    minutes = temp / 60;
    seconds = temp % 60;

    cout << "Total elapsed time: " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
}

void User::updateUserTime()
{
    fstream file("users.bin", ios::binary | ios::in | ios::out);

    char buffer[sizeof(UserInfo)];
    bool userFound = false;

    while (file.read(buffer, sizeof(UserInfo)))
    {
        UserInfo *temp = reinterpret_cast<UserInfo *>(buffer);
        if (strcmp(temp->name, info->name) == 0 && strcmp(temp->password, info->password) == 0)
        {
            temp->totalTime = info->totalTime;
            file.seekp(-static_cast<int>(sizeof(UserInfo)), ios::cur);
            memcpy(buffer, temp, sizeof(UserInfo));
            file.write(buffer, sizeof(UserInfo));
            userFound = true;
            break;
        }
        delete temp;
    }

    if (!userFound)
    {
        cout << "User not found in file." << endl;
    }

    file.close();
}

void User::verifyUser()
{
    bool userFound = false;
    fstream file("users.bin", ios::binary | ios::in);

    // Loop through each UserInfo struct in the file
    UserInfo *temp = new UserInfo;
    while (file.read(reinterpret_cast<char *>(temp), sizeof(UserInfo)))
    {
        if (strcmp(temp->name, info->name) == 0 && strcmp(temp->password, info->password) == 0)
        {
            cout << "\nWelcome back " << temp->name << "!" << endl;
            info->active = temp->active;
            info->totalTime = temp->totalTime;
            userFound = true;
            break;
        }
        else if (strcmp(temp->name, info->name) == 0 && strcmp(temp->password, info->password) != 0)
        {
            do
            {
                cout << "Wrong Password Please Reenter Password:\n";
                cin >> info->password;
                userFound = true;
            } while (strcmp(temp->password, info->password) != 0);
            info->active = temp->active;
            info->totalTime = temp->totalTime;
            break;
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

        UserInfo newUser; // Create a new user object for the new user
        strcpy(newUser.name, info->name);
        strcpy(newUser.password, info->password);
        newUser.totalTime = info->totalTime;
        newUser.active = 1;

        file.write(reinterpret_cast<char *>(&newUser), sizeof(UserInfo));
        cout << "User added to file." << endl;

        file.close();
    }
    delete temp;
}
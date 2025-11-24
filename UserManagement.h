#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct User {
    string username;
    string password;
};

class UserManagement{

    private:
    vector<User> users;
    User* currentUser = nullptr;

    public:
    void saveUsers();
    void loadUsers();
    void registerUser();
    bool login();
    void editProfil();
    
    string getCurrentUsername() {
        if (currentUser) return currentUser->username;
        return "";
    }
};


#endif
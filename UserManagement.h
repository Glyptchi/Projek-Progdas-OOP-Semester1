#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class UserManagement{

    private:
    vector<pair<string, string>> users;
    int currentUser = -1; 

    public:
    void saveUsers();
    void loadUsers();
    void registerUser();
    bool login();
    void editProfil();
    
    string getCurrentUsername() {
        if (currentUser != -1) 
            return users[currentUser].first;
        return "";
    }
};


#endif
#include "UserManagement.h"

#include "UserManagement.h"

void UserManagement::saveUsers() {
    ofstream file("users.txt");
    for (auto &u : users) {
        file << u.first << ";" << u.second << "\n"; 
    }
}


void UserManagement::loadUsers() {
    ifstream file("users.txt");
    if (!file.good()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string uname, pass;

        getline(ss, uname, ';');
        getline(ss, pass, ';');

        if (uname.size()) {
            users.push_back({uname, pass});
        }
    }
}


void UserManagement::registerUser() {
    string uname, pass;

    cout << "\n=== Register Akun ===\n";
    cout << "Username: ";
    getline(cin, uname);
    cout << "Password: ";
    getline(cin, pass);

    users.push_back({uname, pass});

    cout << "Akun berhasil dibuat!\n";
}


bool UserManagement::login() {
    string uname, pass;

    cout << "\n=== Login ===\n";
    cout << "Username: ";
    getline(cin, uname);
    cout << "Password: ";
    getline(cin, pass);

    for (int i = 0; i < users.size(); i++) {
        if (users[i].first == uname && users[i].second == pass) {
            currentUser = i;
            cout << "Login berhasil! Selamat datang, " 
                 << users[i].first << "!\n";
            return true;
        }
    }

    cout << "Login gagal! Username atau password salah.\n";
    return false;
}


void UserManagement::editProfil() {
    if (currentUser == -1) {
        cout << "Anda harus login untuk mengedit profil!\n";
        return;
    }

    cout << "\n=== Edit Profil ===\n";
    cout << "Username saat ini : " << users[currentUser].first << endl;
    cout << "Password saat ini : " << users[currentUser].second << endl;

    string newUser, newPass;

    cout << "\nMasukkan username baru : ";
    getline(cin, newUser);

    cout << "Masukkan password baru : ";
    getline(cin, newPass);

    users[currentUser].first  = newUser;
    users[currentUser].second = newPass;

    cout << "\nProfil berhasil diperbarui!\n";
}

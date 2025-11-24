#include "UserManagement.h"

void UserManagement::saveUsers() {

        ofstream file("users.txt");
        for (auto &u : users) {
            file << u.username << ";" << u.password << "\n";
        }
}

void UserManagement::loadUsers() {
    ifstream file("users.txt");
    if (!file.good()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        User u;
        getline(ss, u.username, ';');
        getline(ss, u.password, ';');
        if (u.username.size()){
            users.push_back(u);
        }
    }
}

void UserManagement::registerUser() {

    User u;
    cout << "\n=== Register Akun ===\n";
    cout << "Username: ";
    getline(cin, u.username);
    cout << "Password: ";
    getline(cin, u.password);

    users.push_back(u);
    cout << "Akun berhasil dibuat!\n";
}

bool UserManagement::login() {
    string uname, pass;
    cout << "\n=== Login ===\n";
    cout << "Username: ";
    getline(cin, uname);
        cout << "Password: ";
        getline(cin, pass);

        for (auto &u : users) {
            if (u.username == uname && u.password == pass) {
                currentUser = &u;
                cout << "Login berhasil! Selamat datang, " << u.username << "!\n";
                return true;
            }
        }

    cout << "Login gagal! Username atau password salah.\n";
    return false;
}

void UserManagement::editProfil() {
    if (!currentUser) {
        cout << "Anda harus login untuk mengedit profil!\n";
        return;
    }

    cout << "\n=== Edit Profil ===\n";
    cout << "Username saat ini : " << currentUser->username << endl;
    cout << "Password saat ini : " << currentUser->password << endl;

    string newUser, newPass;

    cout << "\nMasukkan username baru : ";
    getline(cin, newUser);

    cout << "Masukkan password baru : ";
    getline(cin, newPass);

    // Update currentUser
    currentUser->username = newUser;
    currentUser->password = newPass;

    // Update di vector users
    for (auto &u : users) {
        if (&u == currentUser) {
            u.username = newUser;
            u.password = newPass;
            break;
        }
    }

    cout << "\nProfil berhasil diperbarui!\n";
}
#include "Feedback.h"

void Feedback::simpanFeedback(const string &username, const string &komentar) {
        ofstream file("feedback.txt", ios::app);
        if (file.is_open()) {
            file << username << ";" << komentar << "\n";
            file.close();
            cout << "Feedback berhasil disimpan!\n";
        } else {
            cout << "Gagal membuka file feedback.\n";
        }
    }

void Feedback::berikanFeedback(UserManagement &userMgmt) {
    string username = userMgmt.getCurrentUsername(); 
    string komentar;
    cout << "Masukkan feedback: ";
    getline(cin, komentar);
    simpanFeedback(username, komentar);
}

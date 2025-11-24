#include "Feedback.h"

void Feedback::simpanFeedback(const FeedbackItem &fb) {
    ofstream file("feedback.txt", ios::app);

    file << "User: " << fb.username << "\n";
    file << "Komentar: " << fb.komentar << "\n";
    file << "-----\n";

    file.close();
}

void Feedback::berikanFeedback(UserManagement &userMgmt) {
    FeedbackItem fb;
    
    // Ambil username dari user yang sedang login
    fb.username = userMgmt.getCurrentUsername();

    if (fb.username.empty()) {
        cout << "Anda harus login untuk memberikan feedback!\n";
        return;
    }

    cout << "\nMasukkan feedback: ";
    getline(cin, fb.komentar);

    simpanFeedback(fb);

    cout << "Terima kasih atas feedbacknya!\n";
}

#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "UserManagement.h"

struct FeedbackItem {
    string username;
    string komentar;
};

class Feedback {
public:
    void simpanFeedback(const FeedbackItem &fb);
    void berikanFeedback(UserManagement &userMgmt);
};

#endif

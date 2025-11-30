#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "UserManagement.h"

class Feedback {
public:

    void simpanFeedback(const string &username, const string &komentar);
    void berikanFeedback(UserManagement &userMgmt);
};

#endif

#ifndef __LoginPage_h
#define __LoginPage_h

#include<string>
#include "User_module.h"

// This is Login Page declarationa

class LoginPage : public User
{
    public:
    string login_user_id;
    string login_password;
    string login_time;
    public:
    std::string login();
};

#endif

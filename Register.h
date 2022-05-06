#ifndef __Register_h
#define __Register_h

#include<string>
#include "User_module.h"

// This is Login Page declarationa

class Register : public User
{
    public:
    string user_name1;
    string mobile_no1;
    string user_id1;
    string email_id1;
    string password1;
    string pin1;
    string imei_no1;
    string location1;
    string time1;
    string RegisterPage();
};

#endif

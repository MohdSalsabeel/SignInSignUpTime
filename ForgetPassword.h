#ifndef __ForgetPassword_h
#define __ForgetPassword_h

#include<string>
#include "User_module.h"


class ForgetPassword : public User 
{
    public:
        string pins;
        string times;
        void forget();
};

#endif

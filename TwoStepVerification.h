#ifndef __TwoStepVerification_h
#define __TwoStepVerification_h

#include<string>
#include "User_module.h"
//#include "LoginPage.h"


class TwoStepVerification : public User 
{
    public:
   
    std::string pin_number;
   
    std::string email_id_two;
    std::string correct_pin();
};

#endif

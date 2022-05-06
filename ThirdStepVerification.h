#ifndef __ThirdStepVerification_h
#define __ThirdStepVerification_h

#include<string>
#include "User_module.h"

class ThirdStepVerification : public User
{
    std::string verify_imei_number;
    string verify_current_location;
    string verify_previous_location;
    string verify_mobile_no;
public:
    string correct_third_step();

};

#endif

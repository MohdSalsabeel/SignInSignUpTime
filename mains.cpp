#include <iostream>
#include <math.h>
#include <limits>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#include "User_module.h"
#include "Register.h"
#include "LoginPage.h"
#include "ForgetPassword.h"
#include "TwoStepVerification.h"
#include "ThirdStepVerification.h"
#include "encrypted.h"
using std::cerr;
using std::ios;

using namespace std;

int main()
{

loop1:
    std::cout << "**********************************************************" << endl;
    std::cout << "----------------------------------------------------------" << endl;
    std::cout << "                1. Sign Up           " << endl;
    std::cout << "                2. Already Register/Sign In              " << endl;
    std::cout << "                3. Forget Password                      " << endl;
    std::cout << "                4. Exit                                        " << endl;
    std::cout << "----------------------------------------------------------" << endl;
    std::cout << "***********************************************************" << endl;
    // loop_choice:
    char choice;
    std::cout << "Enter the choice: " << endl;
    std::cin >> choice;
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(choice)
    {
    case '1':{
        system("CLS");
        std::cout << "----------------------------------------------------------" << endl;
        std::cout << "                      Sign up                             " << endl;
        std::cout << "----------------------------------------------------------" << endl;
        Register registerobj;
        if (registerobj.RegisterPage() == "Successful")
        {
            std::cout << endl;
            std::cout << "Successfully Register" << endl;
            std::cout << endl;
            goto loop1;
        }
        else
        {
            std::cout << "Please re-write input: " << endl;
            goto loop1;
        }

        //std::cin.clear();
        //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    
    }
    case '2':{
        system("CLS");
        std::cout << "----------------------------------------------------------" << endl;
        std::cout << "                      Sign in                             " << endl;
        std::cout << "----------------------------------------------------------" << endl;
        LoginPage login_page_obj;
        // Register obj1;

        if (login_page_obj.login() == "Successful")
        {
            std::cout << endl;

            std::cout << "----------------------------------------------------------" << endl;
            std::cout << "Go to Second Step Verification" << endl;
            std::cout << "----------------------------------------------------------" << endl;
            std::cout << endl;
            std::cout << "\n";

        loginLoop:

            TwoStepVerification pin_obj;

            if (pin_obj.correct_pin() == "Successful")
            {
                std::cout << endl;
            thirdStepLoop:
                std::cout << "----------------------------------------------------------" << endl;
                std::cout << "Go to Third Step Verification" << endl;
                std::cout << "**********************************************************" << endl;
                std::cout << endl;
                ThirdStepVerification third_step_verification_obj;
                if (third_step_verification_obj.correct_third_step() == "Successful")
                {
                    std::cout << "**********************************************************" << endl;
                    std::cout << "----------------------------------------------------------" << endl;
                    std::cout << " Main Page" << endl;
                    std::cout << "**********************************************************" << endl;
                    std::cout << "----------------------------------------------------------" << endl;
                    //std::cin.clear();
                    //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else if(third_step_verification_obj.correct_third_step() == "Greater"){
                    cout<<"You exceeded the limit"<<endl;
                    goto loop1;
                }
                else
                {
                    std::cout << endl;
                    std::cout << "Please re-write correct input: " << endl;
                    std::cout << endl;
                    //std::cin.clear();
                    //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    goto thirdStepLoop;
                }
            }
            else if(pin_obj.correct_pin() == "Greater"){
                cout<<"You exceeded the limit"<<endl;
                goto loop1;
            }
            else
            {
                std::cout << endl;
                std::cout << "Invalid pin number" << endl;
                std::cout << endl;
                std::cout << "Please re-write correct pin: " << endl;
                std::cout << endl;
                //std::cin.clear();
                //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                goto loginLoop;
            }
        }
        else
        {
            std::cout << endl;
            std::cout << "Invalid user id and password" << endl;
            std::cout << endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto loop1;
        }
        
        break;
    }
    case '3':
    {
    system("CLS");
    std::cout << "----------------------------------------------------------" << endl;
    std::cout << "                      Forget Password                             " << endl;
    std::cout << "----------------------------------------------------------" << endl;
    forget_loop:
        ForgetPassword forget_password_obj;
        forget_password_obj.forget();

        
        break;
    }
    case '4':
    {
        exit(0);
        break;
    }
    default:
        std::cout << "Enter the correct choice" << endl;
        // break;
        //std::cin.clear();
        //std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto loop1;
        break;
    }

    
    std::cout << std::endl;
    getch();
    return 0;
}

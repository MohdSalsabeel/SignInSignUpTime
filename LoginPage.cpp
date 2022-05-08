#include "LoginPage.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include "encrypted.h"
using namespace std;


string asterikss(string pass){
    int i = 0;
            char a;//a Temp char
            for(i=0;;)//infinite loop
            {
                a=getch();//stores char typed in a
                if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')|| (a=='!')|| (a=='@') || (a=='#') || (a=='$') || (a=='%') || (a=='^') || (a=='&') || (a=='*') || (a=='(') || (a==')'))
                    //check if a is numeric or alphabet
                {
                    //pass[i]=a;//stores a in pass
                    pass.push_back(a);
                    ++i;
                    cout<<"*";
                }
                if(a=='\b'&&i>=1)//if user typed backspace
                    //i should be greater than 1.
                {
                    cout<<"\b \b";//rub the character behind the cursor.
                    --i;
                }
                if(a=='\r')//if enter is pressed
                {
                    //pass[i]='\0';//null means end of string.
                    break;//break the loop
                }
            }
            //cout<<"\nYou entered : "<<obj.password<<endl;
        return pass;
}


string LoginPage::login(){

        // Read the databaseRecordtest file
        std::ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        std::string word;
    
        fstream log_file;
        log_file.open("logfiletest.txt", ios::in);


        fstream login_file;
        login_file.open("loginfiletest.txt",ios::out | ios::app | ios::in);
        
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        
        cout<<"Enter login password: "<<endl;
        //cin>>login_password;
        login_password=asterikss(login_password);
        cout<<'\n';
        //cout<<"Your current login time: "<<endl;
        //cin>>login_time;
        //login_time=__TIME__;
    
        if(log_file.is_open()){
            while(log_file>> user_name>> mobile_no>> user_id>> email_id>> password>> pin>> imei_no>> location>> time){

                if(login_user_id==user_id && login_password==password){
                    login_file<<user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                }
            }
        }

        log_file.close();

        // Here we are reading the file (databaseRecordtest)
        if(database_file.is_open()){
            while(database_file>> user_name>> mobile_no>> user_id>> email_id>> password>> pin>> imei_no>> location>> time){
                
                if(encrypt(login_user_id)==user_id && encrypt(login_password)==password){
                    
                    
                    return "Successful";
                }


            }
        }
        return "False";

};

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

        // Creating the new database file
        std::ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        // We are taking input from user
        // static string login_user_id;
        // string login_password;
        // string login_time;
        
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        
        cout<<"Enter login password: "<<endl;
        //cin>>login_password;
        login_password=asterikss(login_password);
        cout<<'\n';
        //cout<<"Your current login time: "<<endl;
        //cin>>login_time;
        //login_time=__TIME__;

        // Here we are reading the file (databaseRecordtest)
        if(database_file.is_open()){
            while(database_file>> user_name>> mobile_no>> user_id>> email_id>> password>> pin>> imei_no>> location>> time){
                
                if(encrypt(login_user_id)==user_id && encrypt(login_password)==password){
                    
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                        new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    }
                    return "Successful";
                }


            }
        }
        return "False";

};

#include "ForgetPassword.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include "encrypted.h"
#include "User_module.h"
using namespace std;


string asterisked(string pass){
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

bool check(string pins,string times){
    string user_name;
    string email_id;
    string user_id;
    string password;
    string pin;
    string imei_no;
    string location;
    string mobile_no;
    string time;
    ifstream database_file;
    database_file.open("databaseRecordtest.txt", ios::in | ios::app);
        
    while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            if(encrypt(pins)==pin && encrypt(times)==time){
                return true;
            }
        }
    return false;
}

bool specialCharacters(string str){
    for(int i=0;i<str.length();i++)
    {
        if ((str[i]>=48 && str[i]<=57)||
            (str[i]>=65 && str[i]<=90)||
            (str[i]>=97 && str[i]<=122))
            {
            continue;
            }
        else
        {
        //cout<<"String contains special character.\n";
        return true;
        //flag=1;
        //break;
        }
    }
    return false;
}

void ForgetPassword::forget(){
    
        // We have open databaseRecordtest.txt file in read mode
        ifstream database_file;
        database_file.open("databaseRecordtest.txt", ios::in | ios::app);
        

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

          
        forget_above:
        // string pins;
        // string times;
        cout<<"Enter the pin "<<endl;
        //cin>>pins;
        pins=asterisked(pins);
        cout<<'\n';
        cout<<"Enter the sign up time "<<endl;
        cin>>times;

        if(check(pins,times)){
            goto forget_bottom;
        }
        else{
            cout<<"Plese re-write correct pins and time"<<endl;
            goto forget_above;
        }

        //database_file.close();
        forget_bottom:
        //ifstream database_file;
        //database_file.open("databaseRecordtest.txt", ios::in | ios::app);

        

        //forget_above:
        // We are reading the file 
        if(database_file.is_open()){
            while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                // Checking the pins if it is valid or not
                //forget_above:
                //new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                if(encrypt(pins)!=pin && encrypt(times)!=time){
                    
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;

                    
                }
                    
                
                else if(encrypt(pins)==pin && encrypt(times)==time){
                    string new_password;
                    forgetpasswordloop:
                    cout<<"Enter the new password"<<endl;
                    //cin>>new_password;
                    new_password=asterisked(new_password);
                    cout<<'\n';

                    if(new_password.size()>=8 ){                                                 
                        goto specialCharaterBottom;
                    }
                    else{
                        cout<<"Password must be greater than 8 character"<<endl;
                        goto forgetpasswordloop;
                    }

                    specialCharaterBottom:

                    if(specialCharacters(new_password)){
                        goto bottom2;
                    }
                    else{
                        cout<<"Please write strong password"<<endl;
                        goto forgetpasswordloop;    
                    }

                    bottom2:

                    password=encrypt(new_password);
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    //goto forget_above;
                }
                
            }
        }
        database_file.close();
        new_database_file.close();
        remove("databaseRecordtest.txt");
        rename("newDatabaseRecordtest.txt","databaseRecordtest.txt");
        cout<<"Reset password successfully "<<endl;

    //return "False";
   
}

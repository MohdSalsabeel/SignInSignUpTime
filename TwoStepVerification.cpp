#include "TwoStepVerification.h"
#include<fstream>
#include<conio.h>
#include<iostream>

#include "encrypted.h"
//#include "User_module.h"
using namespace std;


string asteriks(string pass){
    int i = 0;
            char a;//a Temp char
            for(i=0;;)//infinite loop
            {
                a=getch();//stores char typed in a
                if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9') || (a=='!')|| (a=='@') || (a=='#') || (a=='$') || (a=='%') || (a=='^') || (a=='&') || (a=='*') || (a=='(') || (a==')'))
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



string TwoStepVerification::correct_pin(){
        

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        int j=0;
        do{
            cout<<'\n';
            cout<<"Enter email id : "<<endl;
            cin>>email_id_two;

            cout<<"Enter pin number : "<<endl;
            //cin>>pin_number;
            pin_number=asteriks(pin_number);  

            

            // We are reading the file
            while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                // checking the condition if pin is valid or not

                    if(encrypt(email_id_two)==email_id && encrypt(pin_number)==pin){
                        //cout<<"Successfully "<<endl;
                        return "Successful";

                    }
                
            }
        ++j;
        if(j==1){
            return "Greater";
        }

        }while(j<=1);
        return "False";
};


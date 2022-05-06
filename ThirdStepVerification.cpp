#include "ThirdStepVerification.h"
#include<fstream>
#include<iostream>
#include "encrypted.h"
#include "User_module.h"
using namespace std;

string ThirdStepVerification::correct_third_step(){

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        int p=0;
        do{
            cout<<'\n';
            cout<<"Enter imei number for verification: "<<endl;
            cin>>verify_imei_number;

            cout<<"Enter current location: "<<endl;
            cin>>verify_current_location;

            cout<<"Enter previous sign up location: "<<endl;
            cin>>verify_previous_location;

            cout<<"Enter mobile number: "<<endl;
            cin>>verify_mobile_no;

            // We are reading the file
            while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                if(encrypt(verify_imei_number)==imei_no && encrypt(verify_previous_location)==location && encrypt(verify_mobile_no)==mobile_no){
                    

                    string token=verify_imei_number+verify_current_location+verify_previous_location+verify_mobile_no;
                    cout<<"Token is generated "<<endl;
                    cout<<token<<endl;
                    cout<<endl;
                    cout<<"Write same token character: "<<endl;
                    //cout<<"Enter token input: "<<endl;
                    string token_character;
                    cin>>token_character;
                    if(token==token_character){
                        
                        return "Successful";
                    }else{
                        // cout<<"Wrong token number"<<endl;
                        // break;
                        return "False";
                    }


                }
            
            }
            ++p;
            cout<<'\n';
            cout<<"Please re-write correct input"<<endl;
            cout<<'\n';
            if(p==1){
                return "Greater";
            }
        }while(p<=1);
        return "False";
    
}

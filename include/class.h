#ifndef CLASS_H 
#define CLASS_H
#include <iostream>
# include"stdlib.h"
# include"function.h"
# include"chrono"
# include"thread"
# include"authentication.h"
using namespace std;
class Traffic_Police_Entry
{
    private:
        int pinNumber = 9869;
        int pin_number_check, count_for_wrong_pin = 3;
        
    public:
        void get_pin_number()
        {
            cout << endl << "Enter PIN: ";
            cin >> pin_number_check;
            this_thread::sleep_for(chrono::milliseconds(1000));
            compare_pin_number();
        }
        void compare_pin_number()
        {
            system("cls");
            if(pin_number_check == pinNumber)
            {
                //Function Call
                loading_page();
                system("cls");
                cout << endl << "Entered Successfully";
            }
            else
            {
                count_for_wrong_pin--;
                if(count_for_wrong_pin == 0)
                {
                    cout << endl << "SUSPICIOUS ACT";
                    this_thread::sleep_for(chrono::milliseconds(400));
                    exit(0);
                }
                if(count_for_wrong_pin<=3)
                {
                    cout << endl << "WRONG PIN";
                    cout << endl << "Total Try Left: " << count_for_wrong_pin;

                }
                
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("cls");
                get_pin_number();
            }
        }
};

class Authentication_Registration;
class Authentication_Login
{
    private:
        char username[100];
        char password[100];
    public:
        void get_login_value()
        {
            cin.ignore();
            cout << "Enter Username: ";
            cin.get(username,100);
            cin.ignore();
            cout << "Enter Password: ";
            cin.get(password,100);
        }
        friend int login_check(Authentication_Login,Authentication_Registration[]);
};

class Authentication_Registration
{
    private:
        char name[100];
        char provience_name[100];
        char address[100];
        int phone_number;
        char username[100];
        char password[100];
    public:
        void get_registration_value()
        {
            cout <<endl << "Name: ";
            cin.get(name,100);
            cin.ignore();
            cout <<endl << "Provience Name: ";
            cin.get(provience_name,100);
            cin.ignore();
            cout <<endl << "Address: ";
            cin.get(address,100);
            cin.ignore();
            cout <<endl << "Phone Number: ";
            cin >> phone_number;
            cin.ignore();
            cout <<endl << "Username: ";
            cin.get(username,100);
            cin.ignore();cout <<endl << "Password: ";
            cin.get(password,100);
        }
        void displayValue()
        {
            cout <<endl << "Username: " << username << "Password: " << password;
        }
        friend int login_check(Authentication_Login,Authentication_Registration[]);

};
#endif
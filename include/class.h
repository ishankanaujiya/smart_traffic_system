#ifndef CLASS_H 
#define CLASS_H
#include <iostream>
# include"conio.h"
# include"stdlib.h"
# include"cstring"
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
                switch_case_for_traffic_police();
                //cout << endl << "Entered Successfully";
            }
            else
            {
                count_for_wrong_pin--;
                if(count_for_wrong_pin == 0)
                {
                    cout << endl << "SUSPICIOUS ACT";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    exit(0);
                }
                if(count_for_wrong_pin<=3)
                {
                    cout << endl << "WRONG PIN";
                    cout << endl << "Total Try Left: " << count_for_wrong_pin;

                }
                
                this_thread::sleep_for(chrono::milliseconds(2000));
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
            fflush(stdin);
            //cin.ignore();
            cout << "Username: ";
            cin.get(username,100);
            cin.ignore();
            cout << "Password: ";
            //cin.get(password,100);
            char ch1;
            int i=0;
            while (1)
            {
                ch1 = _getch();
                if(ch1 == 13)
                {
                    password[i] = '\0';
                    break;
                }
                else if(ch1 == 8)
                {
                    if (i > 0)
                    {
                        i--;
                        printf("\b \b");
                    }
                }
                else if(ch1 == 9 || ch1 == 32)
                {
                    continue;
                }
                else
                {
                    cout << "*";
                    password[i] = ch1;
                    //cout << "*";
                    i++;
                }
		
	        }
        }
        friend int login_check(Authentication_Login,Authentication_Registration[]);
};

class Authentication_Registration
{
    private:
        char name[100];
        int provience_number;
        char address[100];
        int phone_number;
        char username[100];
        char password[100];
    public:
        void get_registration_value()
        {
            cout <<endl << "District Name: ";
            cin.get(name,100);
            cin.ignore();
            flag_for_provience_number:
            cout <<endl << "Province Number: ";
            cin >> provience_number;
            if(provience_number<=0 || provience_number>7)
            {
                cout << endl << "Enter Province Number from 1 to 7";
                goto flag_for_provience_number;
                
            }
            cin.ignore();
            cout <<endl << "Headquarter's Address: ";
            cin.get(address,100);
            cin.ignore();
            cout <<endl << "Headquarter's Contact Number: ";
            cin >> phone_number;
            cin.ignore();
            system("cls");
            cout <<endl << endl << "Username: ";
            cin.get(username,100);
            flag_for_password:
            system("cls");
            display_rules();
            cin.ignore();
            cout <<endl << endl << "Password: ";
            cin.get(password,100);

            //Strong Password
            int count_for_numbers_check = 0, count_for_alphabet_check = 0, count_for_symbol_check = 0;
            char password_check[100];
            strcpy(password_check, password);
            int password_check_len = strlen(password_check);

            if(password_check_len<=6)
            {
                cout << endl << "The Password is too short.... Please Enrter the Password Again";
                this_thread::sleep_for(chrono::milliseconds(2000));
                goto flag_for_password;
            }
            if(password_check_len>=15)
            {
                cout << endl << "The Password is too long.... Please Entrer the Password Again";
                this_thread::sleep_for(chrono::milliseconds(2000));
                goto flag_for_password;
            }
            for(int i=0; password_check[i]!='\0'; i++)
            {
                if(password_check[i]>=48 && password_check[i]<=57)
                {
                    count_for_numbers_check++;
                }
                if(password_check[i]>='A' && password_check[i]<='Z')
                {
                    count_for_alphabet_check++;
                }
                if(password_check[i] == '@' ||password_check[i] == '#' ||password_check[i] == '$' ||password_check[i] == '&')
                {
                    count_for_symbol_check++;
                }
            }
            if(count_for_numbers_check>0 && count_for_alphabet_check>0 && count_for_symbol_check>0)
            {
                cout << endl << "Account Registered Successfully" << endl;
                //system("pause");
            
            }
            else
            {
                cout << endl << "The Entered Password is Not Strong.... Please Enter the Password";
                this_thread::sleep_for(chrono::milliseconds(2000));
                goto flag_for_password;
            }
            
        }
        void displayValue()
        {
            cout <<endl << "Username: " << username << "Password: " << password;
        }

        void display_rules()
        {
            cout << endl << " Password Must Contain: ";
            cout << endl << " 1. Minimum 6 Letters and Maximum 15 Letters";
            cout << endl << " 2. Must Contain atleast One Digit/Number ";
            cout << endl << " 3. Must Contain any of the Symbols '@' , '#' , '$' , '&' ";
            cout << endl << " 4. Must Contain atleast One Capital Letter";

        }

        friend int login_check(Authentication_Login,Authentication_Registration[]);
        friend int allow_registration_after_provience_check(Authentication_Registration, Authentication_Registration[]);

};

class Vehicle_Detail
{
    private:
        int vehicle_number;
        int vehicle_type;
        char name[100];
        long long int phone_number;
        char address[100];
    public:
        void getValue()
        {
            cout << endl << "Vehicle Number: ";
            cin >> vehicle_number;
            cin.ignore();
            cout << endl << "Vehicle Type: ";
            cin >> vehicle_type;
            cin.ignore();
            cout << endl << "Owners Name: ";
            cin.get(name,100);
            cin.ignore();
            cout << endl << "Phone Number: ";
            cin >> phone_number;
            cin.ignore();
            cout << endl << "Address: ";
            cin.get(address,100);
            cin.ignore();
        }
        friend void search_vehicle_record(Vehicle_Detail[]);
};
#endif
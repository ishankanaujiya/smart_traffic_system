#ifndef CLASS_H 
#define CLASS_H
#include <iostream>
# include"stdlib.h"
# include"function.h"
# include"chrono"
# include"thread"
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
#endif
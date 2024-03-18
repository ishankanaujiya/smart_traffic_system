# include"iostream"
# include"class.h"
# include"function.h"
# include"chrono"
# include"thread"


//Class Object
Traffic_Police_Entry Traffic_Entry_Obj;

//Variables
int i=0;
int choice_for_first_login;
char ch_for_loading = 219;

void main_call()
{
    switch_case_for_entry();
    fflush(stdin);
    getchar();
}

//Use of Objects
void call_traffic_police_entry_obj()
{
    system("cls");
    Traffic_Entry_Obj.get_pin_number();
    //Traffic_Entry_Obj.compare_pin_number();
}

//Definition of other Function
void switch_case_for_entry()
{
    flag_for_first_switch_case:
    system("cls");
    cout << endl << "1. Traffic Police" << endl << "2. Admin";
    cout << endl << "Enter Your Choice: ";
    cin >> choice_for_first_login;

    switch (choice_for_first_login)
    {
        case 1:
            
            call_traffic_police_entry_obj();
        break;

        case 2:
            cout << endl << "Case 2";
        break;

        default:
            cout << endl << "Wrong Choice..... Please Enter Choice Again";
            this_thread::sleep_for(chrono::seconds(4));
            goto flag_for_first_switch_case;
        break;
    }
}

void loading_page()
{
    system("cls");
    cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t\t\tLoading ......";
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t";
    for(i=0; i<=25; i++)
    {
        system("COLOR 0B");
        this_thread::sleep_for(chrono::milliseconds(150));
        cout<< ch_for_loading;
    }
    system("COLOR 07");
}
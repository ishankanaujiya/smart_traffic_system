# include"iostream"
# include"stdlib.h"
# include"class.h"
# include"function.h"
# include"chrono"
# include"thread"
# include"authentication.h"
# include"../include/entry.h"


//Class Object
Traffic_Police_Entry Traffic_Entry_Obj;

//Variables
int i=0, return_value_for_login = 0;
int choice_for_first_login, choice_for_admin_entry, choice_for_traffic_police_entry;
int return_value_to_check_vehicle_number;
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
    cout << endl << "1. Traffic Police" << endl << "2. Admin" << endl << "3. Exit";
    cout << endl << "Enter Your Choice: ";
    cin >> choice_for_first_login;

    switch (choice_for_first_login)
    {
        case 1:
            call_traffic_police_entry_obj();
        break;

        case 2:
            switch_case_for_admin_entry();
            //cout << endl << "Case 2";
        break;

        case 3:
            exit(0);
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

void switch_case_for_admin_entry()
{
    flag_for_admin_entry:
    system("cls");
    cout << endl << "1. Login" << endl << "2. Register" << endl << "3. Main Menu";
    cout << endl << "Enter Your Choice: ";
    cin >> choice_for_admin_entry;
    switch (choice_for_admin_entry)
    {
    case 1:
        cin.ignore();
        system("cls");
        return_value_for_login = authentication_login();
        if(return_value_for_login ==1)
        {
            goto flag_for_admin_entry;
        }
        break;
    case 2:
        cin.ignore();
        system("cls");
        authentication_registration();
        goto flag_for_admin_entry;
        break;
    case 3:
        switch_case_for_entry();
        break;
    default:
        cout << endl << "Wrong Choice..... Please Enter Your Choice Again";
        this_thread::sleep_for(chrono::milliseconds(1000));
        goto flag_for_admin_entry;
        break;
    }

}

void switch_case_for_traffic_police()
{
    flag_for_traffic_police_entry:
    cout << endl << "1. Add Vehicle Record" << endl << "2. Search Vehicle Record" << endl << "3. Helpline Numbers" << endl << "4. Exit";
    cout << endl << "Enter Your Choice: ";
    cin >> choice_for_traffic_police_entry;

    switch (choice_for_traffic_police_entry)
    {
    case 1:
        system("cls");
        return_value_to_check_vehicle_number = add_vehicle_record();
        if(return_value_to_check_vehicle_number == 6)
        {
            cout << endl << "Delatils of this Vehicle Number Exists";
            this_thread::sleep_for(chrono::seconds(4));
            system("cls");
            goto flag_for_traffic_police_entry;
        }
        system("cls");
        goto flag_for_traffic_police_entry;
        break;

    case 2:
        system("cls");
        search_vehicle_record();
        system("cls");
        goto flag_for_traffic_police_entry;
        break;

    case 3:

    break;
    case 4:
        exit(0);
        break;
    
    default:
        cout << endl << "Wrong Choice..... Please Enter The Choice Again";
        goto flag_for_traffic_police_entry;
    }

}
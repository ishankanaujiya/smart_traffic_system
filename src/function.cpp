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
int choice_for_first_login, choice_for_admin_entry, choice_for_traffic_police_entry, choice_for_admin;
int return_value_to_check_vehicle_number, value_to_enter_admin;
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
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\tWELCOME";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t1. Traffic Police" << endl << "\t\t\t\t\t\t\t\t\t\t\t2. Admin" << endl << "\t\t\t\t\t\t\t\t\t\t\t3. Exit" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
    cin >> choice_for_first_login;

    switch (choice_for_first_login)
    {
        case 1:
            call_traffic_police_entry_obj();
        break;

        case 2:
            system("cls");
            cout << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl<< endl;
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\tEnter PIN: ";
            cin >>value_to_enter_admin;

            if(value_to_enter_admin == 6531)
            {
                switch_case_for_admin_entry();
            }
            else
            {
                system("cls");
                system("COLOR 0C");
                cout << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl<< endl;
                cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\tWrong PIN....." << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
                system("pause");
                system("COLOR 07");
                goto flag_for_first_switch_case;
            }
            //cout << endl << "Case 2";
        break;

        case 3:
            exit(0);
        break;

        default:
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tWrong Choice..... Please Enter Choice Again" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            system("pause");
            system("cls");
            //this_thread::sleep_for(chrono::seconds(4));
            goto flag_for_first_switch_case;
        break;
    }
}

void loading_page()
{
    system("cls");
    cout << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl<< endl << endl << endl;
    //cout<< endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t\t\t\t\t\t\t\tLoading ......";
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
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
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\tADMIN";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t1. Login" << endl 
    << "\t\t\t\t\t\t\t\t\t\t\t2. Register" << endl 
    << "\t\t\t\t\t\t\t\t\t\t\t3. Main Menu" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
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
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tWrong Choice..... Please Enter Your Choice Again";
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
        goto flag_for_admin_entry;
        break;
    }

}

void switch_case_for_traffic_police()
{
    flag_for_traffic_police_entry:
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**********************************************";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\tTRAFFIC POLICE";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**********************************************" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t1. Add Vehicle Record" 
         << endl << "\t\t\t\t\t\t\t\t\t\t\t2. Search Vehicle Record" 
         << endl << "\t\t\t\t\t\t\t\t\t\t\t3. Helpline Numbers" 
         << endl << "\t\t\t\t\t\t\t\t\t\t\t4. Police Staion Details" 
         << endl << "\t\t\t\t\t\t\t\t\t\t\t5. Display Records" 
         << endl << "\t\t\t\t\t\t\t\t\t\t\t6. Main Menu";

    cout << endl << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
    cin >> choice_for_traffic_police_entry;

    switch (choice_for_traffic_police_entry)
    {
    case 1:
        system("cls");
        return_value_to_check_vehicle_number = add_vehicle_record();
        if(return_value_to_check_vehicle_number == 6)
        {
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tDelatils of this Vehicle Number Exists"  << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            system("pause");
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
        system("cls");
        display_all_emergency_numbers();
        system("pause");
        system("cls");
        goto flag_for_traffic_police_entry;

    break;

    case 4:
        system("cls");
        display_all_details();
        system("pause");
        system("cls");
        goto flag_for_traffic_police_entry;
    break;
     case 5:
        system("cls");
        display_all_records();
        system("pause");
        system("cls");
        goto flag_for_traffic_police_entry;
        break;
    case 6:
        switch_case_for_entry();
        //exit(0);
        break;
    
    default:
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tWrong Choice..... Please Enter The Choice Again" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
        system("cls");
        goto flag_for_traffic_police_entry;
    }

}

void switch_case_for_admin()
{
    flag_for_admin:
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\tADMIN";
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\t1. Add Record" << endl 
         << "\t\t\t\t\t\t\t\t\t\t\t2. Search Record" << endl 
         << "\t\t\t\t\t\t\t\t\t\t\t3. Modify Record" << endl 
         << "\t\t\t\t\t\t\t\t\t\t\t4. Delete Record" << endl 
         << "\t\t\t\t\t\t\t\t\t\t\t5. Display Record" << endl 
         << "\t\t\t\t\t\t\t\t\t\t\t6. Main Menu" << endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter Your Choice: ";
    cin >> choice_for_admin;
    
    switch (choice_for_admin)
    {
        case 1:
            system("cls");
            return_value_to_check_vehicle_number = add_vehicle_record();
            if(return_value_to_check_vehicle_number == 6)
            {
                cout << endl << "\t\t\t\t\t\t\t\t\t\t\tDelatils of this Vehicle Number Exists" << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                system("pause");
                //this_thread::sleep_for(chrono::seconds(4));
                system("cls");
                goto flag_for_admin;
            }
            system("cls");
            goto flag_for_admin;
            
            break;
        case 2:
            system("cls");
            search_vehicle_record();
            system("cls");
            goto flag_for_admin;
            break;
        case 3:
            system("cls");
            modify_vehicle_record();
            system("cls");
            goto flag_for_admin;

            break;
        case 4:
            system("cls");
            delete_vehicle_record();
            system("cls");
            goto flag_for_admin;
            break;
        case 5:
            system("cls");
            display_all_records();
            system("pause");
            system("cls");
            goto flag_for_admin;
            break;
        case 6:
            system("cls");
            switch_case_for_entry();
            break;
        default:
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tWrong Choice..... Please Enter The Choice Again" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            system("pause");
            system("cls");
            goto flag_for_admin;
            break;
    }
}



void display_all_details()
{
    cout << "Police Staion Name                                       " << "Address                            " << "Phone Number"<<endl <<endl <<endl;
    cout << "Nepal Police Headquarters                                " << "Sama Marg                          " << "01-4411210"<<endl<<endl;
    cout << "Kathmandu Valley Police Office                           " << "Ratna Park                         " << "01-4231466"<<endl<<endl;
    cout << "Tudal Devi Police Beat                                   " << "Tudal Devi                         " << "01-426646"<<endl<<endl;
    cout << "Maharajgunj Police Station                               " << "Ring Rd                            " << "985-1283007"<<endl<<endl;
    cout << "Metropolitan Police Circle                               " << "Paknajol Marg                      " << "985-1282799"<<endl<<endl;
    cout << "Police Sector                                            " << "Koteshwor                          " << "01-4600739"<<endl<<endl;
    cout << "Police Office                                            " << "Gangahiti                          " << "01-4425364"<<endl<<endl;
    cout << "Metropolitan Police Circle Jansewa                       " << "New Road                           " << "01-4222757"<<endl<<endl;
    cout << "Temporary Metropolitan Police Division                   " << "Naya Bazar                         " << "01-4389653"<<endl<<endl;
    cout << "Traffic Police Durbar Marg                               " << "Durbar Marg                        " << "985-1281344"<<endl<<endl;
    cout << "Panchakanya Police Station                               " << "Chundevi Marg                      " << "9864321569"<<endl<<endl;
    cout << "Metropolitan Police Beat                                 " << "Bafal                              " << "01-4282100"<<endl<<endl;
    cout << "Mahanagar Police Beat                                    " << "Midbaneshwor                       " << "01-4256346"<<endl<<endl;
    cout << "Metropolitan Police Circle                               " << "Kamalpokhari                       " << "9863563166"<<endl<<endl;
    cout << "Metropolitan Police Witt                                 " << "Milan Marg                         " << "01-42100536"<<endl<<endl;
    cout << "District Police Range                                    " << "Bhansar Marg                       " << "985-1283012"<<endl<<endl;
    cout << "Metropolitan Temporary Police Beat                       " << "MidBaneshor                        " << "985-1283003"<<endl<<endl;
}

void display_all_emergency_numbers()
{
    cout << "Name of Emergency/ Helpline Services                                " << "Number                            " << "Charge"<<endl <<endl <<endl;
    cout << "Nepal Police                                                        " << "100                               " << "Free"<<endl <<endl <<endl;
    cout << "Fire Support                                                        " << "101                               " << "Free"<<endl <<endl <<endl;
    cout << "Ambulance Support                                                   " << "102                               " << "Free"<<endl <<endl <<endl;
    cout << "Traffic Support                                                     " << "103                               " << "Free"<<endl <<endl <<endl;
    cout << "Child Helpline                                                      " << "104                               " << "Free"<<endl <<endl <<endl;
    cout << "CIAA(Commission for the Investigation of Abuse of Authority)        " << "107                               " << "Free"<<endl <<endl <<endl;
    cout << "Missing Child Response                                              " << "1098                              " << "Free"<<endl <<endl <<endl;
    cout << "Armed Police Force Support                                          " << "1114                              " << "Free"<<endl <<endl <<endl;
    cout << "Women Helpline                                                      " << "1145                              " << "Free"<<endl <<endl <<endl;
    cout << "NEA Helpline                                                        " << "1149                              " << "Free"<<endl <<endl <<endl;
    cout << "Patan Mental Hospital                                               " << "1166                              " << "Free"<<endl <<endl <<endl;
}


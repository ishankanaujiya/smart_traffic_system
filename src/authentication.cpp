# include"iostream"
# include"authentication.h"
# include"../include/class.h"
# include"../include/function.h"
# include"fstream"
# include"cstring"
# include"chrono"
# include"thread"
using namespace std;



//Class Object
Authentication_Login login_obj;
Authentication_Registration registration_obj, registration_detail_contained_obj[100], registration_detail_contained_obj_for_check;
Authentication_Registration registration_obj_for_provience_check[100];

//Variable
int return_value_for_correct_login;
int return_value_to_allow_registration;


int authentication_login()
{
    fstream file_for_login;
    fstream file_for_registration_check;

    //Write data to array of objects
    file_for_registration_check.open("resource/login_details.dat", ios::in | ios::binary);
    if(!file_for_registration_check)
    {
        cout << endl << "File Not Found by Registration";
    }
    else
    {
        file_for_registration_check.read((char *)&registration_detail_contained_obj,sizeof(registration_detail_contained_obj));
        /*for(int i=0; i<100; i++)
        {
            registration_detail_contained_obj[i].displayValue();
        }*/
        file_for_registration_check.close();
    }


    //Login

    file_for_login.open("resource/login_details.dat", ios::in | ios::binary);
    if(!file_for_login)
    {
        cout << "File Not Found by Login";
    }
    else
    {
        cout << endl;
        cout << endl << "LOGIN" << endl;
        login_obj.get_login_value();

        //Call for Friend Function
        return_value_for_correct_login = login_check(login_obj,registration_detail_contained_obj);
        if(return_value_for_correct_login == 6)
        {
            loading_page();
            system("cls");
            cout << endl << "Entered Successfully";
            switch_case_for_admin();
            
        }
        else
        {
            cout << endl << "Wrong Password";
            this_thread::sleep_for(chrono::seconds(4));
            return 1;
        }
        file_for_login.close();
    
        fflush(stdin);
        getchar();
        
    }
    return 0;
}


void authentication_registration()
{
    fstream file_for_registration;
    fstream file_for_registration_check;
    fstream file_for_registration_approval;
    int count_for_total_registration = 0;


    //Read the File to check total number of registration
    file_for_registration_check.open("resource/login_details.dat", ios::in | ios::binary);
    if(!file_for_registration_check)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        while(file_for_registration_check.read((char *)&registration_detail_contained_obj_for_check, sizeof(registration_detail_contained_obj_for_check)))
        {
            count_for_total_registration++;
        }
        if(count_for_total_registration>6)
        {
            cout << endl << "Registration for only 7 provience is accepted";
            this_thread::sleep_for(chrono::seconds(4));
            exit(0);
        }
        file_for_registration_check.close();
    }


    //Read the File for Registration Approval
    file_for_registration_approval.open("resource/login_details.dat", ios::in | ios::binary);
    if(!file_for_registration_approval)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_registration_approval.read((char *)&registration_obj_for_provience_check,sizeof(registration_obj_for_provience_check));
        file_for_registration_approval.close();
    }


    //Write the Registration Detail
    file_for_registration.open("resource/login_details.dat", ios::app | ios::binary);
    if(!file_for_registration)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        registration_obj.get_registration_value();
        
        //Call for Friend Function
        return_value_to_allow_registration = allow_registration_after_provience_check(registration_obj,registration_obj_for_provience_check);
        if(return_value_to_allow_registration == 6)
        {
            system("cls");
            cout << endl << "The Detail of This Province is Already Registered" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout << endl << "Account Registered Successfully" << endl;
            system("pause");
            file_for_registration.write((char *)&registration_obj,sizeof(registration_obj));
        }

        file_for_registration.close();
    }
}

int login_check(Authentication_Login authentication_login_check, Authentication_Registration authentication_registration_check[])
{
    int i=0, j=0;
    for(i=0; i<100; i++)
    {
        if(strcmp(authentication_login_check.username,authentication_registration_check[i].username)==0)
        {
            if(strcmp(authentication_login_check.password,authentication_registration_check[i].password)==0)
            {
                return 6;
            }
        }
    
    }
    return 0;
}


int allow_registration_after_provience_check(Authentication_Registration registration_approval_obj, Authentication_Registration registration_obj_to_check_provience_number[])
{
    int i=0;
    for(i=0; i<100; i++)
    {
        if(registration_approval_obj.provience_number == registration_obj_to_check_provience_number[i].provience_number)        
        {
            return 6;
        }
    }
    return 0;
}

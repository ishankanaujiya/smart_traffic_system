# include"iostream"
# include"authentication.h"
# include"../include/class.h"
# include"../include/function.h"
# include"fstream"
# include"cstring"
using namespace std;



//Class Object
Authentication_Login login_obj;
Authentication_Registration registration_obj, registration_detail_contained_obj[100];

//Variable
int return_value_for_correct_login;


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
        return_value_for_correct_login = login_check(login_obj,registration_detail_contained_obj);
        if(return_value_for_correct_login == 6)
        {
            loading_page();
            cout << endl << "Entered Successfully";
            
        }
        else
        {
            cout << endl << "Wrong Password";
            return 1;
        }
        file_for_login.close();
    
        fflush(stdin);
        getchar();
    }
}


void authentication_registration()
{
    fstream file_for_registration;
    file_for_registration.open("resource/login_details.dat", ios::app | ios::binary);
    if(!file_for_registration)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        registration_obj.get_registration_value();
        file_for_registration.write((char *)&registration_obj,sizeof(registration_obj));
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

}

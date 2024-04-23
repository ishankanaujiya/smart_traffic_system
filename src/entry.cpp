# include"iostream"
# include"../include/class.h"
# include"../include/entry.h"
# include"../include/function.h"
# include"fstream"
# include"chrono"
# include"thread"
using namespace std;

//Class Objects
Vehicle_Detail add_vehicle_record_obj, search_vehicle_record_obj[100], vehicle_number_check_obj[100];

//Variables
int return_value_for_vehicle_number_check;

int add_vehicle_record()
{
    fstream file_for_vehicle_detail;
    fstream file_for_vehicle_number_check;

    //Read to check Vehicle Number
    file_for_vehicle_number_check.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_vehicle_number_check)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_vehicle_number_check.read((char *)&vehicle_number_check_obj,sizeof(vehicle_number_check_obj));
        file_for_vehicle_number_check.close();
    }

    //Write Object To File
    file_for_vehicle_detail.open("resource/vehicle_record.dat", ios::app | ios::binary);
    if(!file_for_vehicle_detail)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        add_vehicle_record_obj.getValue();
        return_value_for_vehicle_number_check = vehicle_number_check(add_vehicle_record_obj,vehicle_number_check_obj);
        if(return_value_for_vehicle_number_check == 6)
        {
            return 6;
        }
        else
        {
            file_for_vehicle_detail.write((char *)&add_vehicle_record_obj,sizeof(add_vehicle_record_obj));
            cout << endl << "Vehicle Record Added Successfully";
            system("pause");
            
        }
        file_for_vehicle_detail.close();
    }
    return 0;
}

void search_vehicle_record()
{
    fstream file_for_search_vehicle_record;
    int vehicle_number_check;
    file_for_search_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_search_vehicle_record)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_search_vehicle_record.read((char *)&search_vehicle_record_obj,sizeof(search_vehicle_record_obj));
        file_for_search_vehicle_record.close();
    }
    search_vehicle_record(search_vehicle_record_obj);

}

void search_vehicle_record(Vehicle_Detail map_search_for_vehicle_record_obj[])
{
    int vehicle_number_check;
    int i=0;
    cout << endl << "Enter The Vehicle Number whose detail you want to Searh:  ";
    cin >> vehicle_number_check;

    for(i=0; i<100; i++)
    {
        if(vehicle_number_check == map_search_for_vehicle_record_obj[i].vehicle_number)
        {
            system("cls");
            cout << endl << "Vehicle Number\t    Vehicle Type\t    Owner's Name\t        Phone Number\t    Address: ";
            cout << endl << map_search_for_vehicle_record_obj[i].vehicle_number;
            cout << "\t\t     " << map_search_for_vehicle_record_obj[i].vehicle_type;
            cout << "\t\t\t     " << map_search_for_vehicle_record_obj[i].name;
            cout << "\t\t     " << map_search_for_vehicle_record_obj[i].phone_number;
            cout << "\t\t\t   " << map_search_for_vehicle_record_obj[i].address << endl;
            system("pause");
            
        }
    }

}

int vehicle_number_check(Vehicle_Detail obj_containing_entered_vehicle_detail, Vehicle_Detail obj_with_vehicle_detail[])
{
    int i=0;
    for(i=0; i<100; i++)
    {
        if(obj_containing_entered_vehicle_detail.vehicle_number == obj_with_vehicle_detail[i].vehicle_number)
        {
            return 6;
        }
    }
    return 0;
}

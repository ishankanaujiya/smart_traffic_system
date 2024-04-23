# include"iostream"
# include"../include/class.h"
# include"../include/entry.h"
# include"../include/function.h"
# include"fstream"
using namespace std;

//Class Objects
Vehicle_Detail add_vehicle_record_obj, search_vehicle_record_obj[100];

void add_vehicle_record()
{
    fstream file_for_vehicle_detail;
    file_for_vehicle_detail.open("resource/vehicle_record.dat", ios::app | ios::binary);
    if(!file_for_vehicle_detail)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        add_vehicle_record_obj.getValue();
        file_for_vehicle_detail.write((char *)&add_vehicle_record_obj,sizeof(add_vehicle_record_obj));
        file_for_vehicle_detail.close();
    }

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


# include"iostream"
# include"../include/class.h"
# include"../include/entry.h"
# include"../include/function.h"
# include"fstream"
# include"cstring"
# include"iomanip"
# include"chrono"
# include"thread"

using namespace std;

//Class Objects
Vehicle_Detail add_vehicle_record_obj, search_vehicle_record_obj[100], vehicle_number_check_obj[100], display_all_vehicle_record[100], display_all_vehicle_record_obj;
Vehicle_Detail modify_all_vehicle_record_obj[100];

//Variables
int return_value_for_vehicle_number_check, return_value_from_modify_vehicle_record;
int count_for_total_number_of_vehicle_record;

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
            cout << endl << "Vehicle Record Added Successfully" << endl;
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
            cout << "Vehicle Number"<< setw(40) << "Vehicle Type"<<setw(40) << "Owner's Name"<< setw(40) << "Phone Number" << setw(40) << "Address" << setw(30) << "Amount" <<endl;
            cout << map_search_for_vehicle_record_obj[i].vehicle_number<< setw(40) 
                << map_search_for_vehicle_record_obj[i].vehicle_type <<setw(50) 
                << map_search_for_vehicle_record_obj[i].name << setw(40) 
                << map_search_for_vehicle_record_obj[i].phone_number << setw(40) 
                << map_search_for_vehicle_record_obj[i].address << setw(30)
                << map_search_for_vehicle_record_obj[i].amount <<endl;
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

void display_all_records()
{
    fstream file_for_display_all_vehicle_record;
    fstream file_for_count_total_obj;

    int i=0;

    //Read number of Objects in the File
    file_for_count_total_obj.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_count_total_obj)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        count_for_total_number_of_vehicle_record =0;
        while(file_for_count_total_obj.read((char *)&display_all_vehicle_record_obj, sizeof(display_all_vehicle_record_obj)))
        {
            count_for_total_number_of_vehicle_record++;
        }
    }
    file_for_count_total_obj.close();


    //Read all the Objects form the file
    file_for_display_all_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_display_all_vehicle_record)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_display_all_vehicle_record.read((char *)&display_all_vehicle_record,sizeof(display_all_vehicle_record));
    }
    file_for_display_all_vehicle_record.close();

   display_all_vehicle_records(display_all_vehicle_record);

}


void display_all_vehicle_records(Vehicle_Detail map_display_all_vehicle_record[])
{
    int i=0;
    system("cls");
    cout << "Vehicle Number"<< setw(40) << "Vehicle Type"<<setw(40) << "Owner's Name"<< setw(40) << "Phone Number" << setw(40) << "Address" << setw(30) << "Amount" <<endl;
    for(i=0; i<count_for_total_number_of_vehicle_record; i++)
    {
        cout << map_display_all_vehicle_record[i].vehicle_number<< setw(40) 
            << map_display_all_vehicle_record[i].vehicle_type <<setw(50) 
            << map_display_all_vehicle_record[i].name << setw(40) 
            << map_display_all_vehicle_record[i].phone_number << setw(40) 
            << map_display_all_vehicle_record[i].address << setw(30)
            << map_display_all_vehicle_record[i].amount <<endl;
    }
}

void modify_vehicle_record()
{
    fstream file_for_read_vehicle_record;

    file_for_read_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_read_vehicle_record)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_read_vehicle_record.read((char *)&modify_all_vehicle_record_obj,sizeof(modify_all_vehicle_record_obj));
    }
    file_for_read_vehicle_record.close();
    modify_all_vehicle_record(modify_all_vehicle_record_obj);
    
}

void modify_all_vehicle_record(Vehicle_Detail map_modify_all_vehicle_record[])
{
    int modify_vehicle_number, i=0, flag_for_modify_vehicle_record = 0, j=0;

    int map_vehicle_number;
    int  map_vehicle_type;
    char  map_name[100];
    long long int  map_phone_number;
    char  map_address[100];
    int  map_amount;

    fstream file_for_write_vehicle_record;

    cout << endl << "Enter Vehicle Number whose detail is to be Modified: ";
    cin >> modify_vehicle_number;
    for(i=0; i<100; i++)
    {
        if(modify_vehicle_number == map_modify_all_vehicle_record[i].vehicle_number)
        {
            cout << endl << "Enter New Details";
            flag_for_modify_vehicle_record:
            cout << endl << "Vehicle Number: ";
            cin >> map_vehicle_number;
            cin.ignore();
            cout << endl << "Vehicle Type: ";
            cin >> map_vehicle_type;
            cin.ignore();
            cout << endl << "Owners Name: ";
            cin.get(map_name,100);
            cin.ignore();
            cout << endl << "Phone Number: ";
            cin >> map_phone_number;
            cin.ignore();
            cout << endl << "Address: ";
            cin.get(map_address,100);
            cin.ignore();
            cout << endl << "Amount: ";
            cin >> map_amount;
            cin.ignore();

            for(j=0; j<100; j++)
            {
                if(map_vehicle_number == map_modify_all_vehicle_record[j].vehicle_number)
                {
                    cout << endl << "Detail of this Vehicle Number is Already Registered";
                    system("pause");
                    goto flag_for_modify_vehicle_record;

                }
            }

            file_for_write_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::out | ios::binary);
            if(!file_for_write_vehicle_record)
            {
                cout << endl << "File Not Found";
            }
            else
            {
                map_modify_all_vehicle_record[i].vehicle_number = map_vehicle_number;
                map_modify_all_vehicle_record[i].vehicle_type = map_vehicle_type;
                map_modify_all_vehicle_record[i].phone_number = map_phone_number;
                map_modify_all_vehicle_record[i].amount = map_amount;
                strcpy(map_modify_all_vehicle_record[i].name, map_name);
                strcpy(map_modify_all_vehicle_record[i].address, map_address);
                file_for_write_vehicle_record.seekp(i * sizeof(Vehicle_Detail), ios::beg);
                file_for_write_vehicle_record.write((char *)&map_modify_all_vehicle_record[i], sizeof(Vehicle_Detail));
                //file_for_write_vehicle_record.write((char *)&map_modify_all_vehicle_record,sizeof(Vehicle_Detail));
                file_for_write_vehicle_record.close();
                flag_for_modify_vehicle_record = 0;
                cout << endl << "Vehicle Record Modified Successfully";
                system("pause");
                break;
            }
                
        }

        else
        {
            flag_for_modify_vehicle_record = 1;
        }
    }
    if(flag_for_modify_vehicle_record ==1)
    {
        cout << endl << "No Record Found";
        switch_case_for_admin();

    }
    

}
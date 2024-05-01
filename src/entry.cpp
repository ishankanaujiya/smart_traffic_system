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
Vehicle_Detail modify_all_vehicle_record_obj[100], delete_vehicle_record_obj[100], delete_record_obj, search_record_obj;

//Variables
int return_value_for_vehicle_number_check, return_value_from_modify_vehicle_record;
int count_for_total_number_of_vehicle_record, count_for_total_number_of_obj_to_delete_vehicle_record, count_for_total_search, flag_for_search_record = 0;

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
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************************";
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\t\t\tADD VEHICLE RECORD";
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\t**************************************************" << endl;
        add_vehicle_record_obj.getValue();
        return_value_for_vehicle_number_check = vehicle_number_check(add_vehicle_record_obj,vehicle_number_check_obj);
        if(return_value_for_vehicle_number_check == 6)
        {
            return 6;
        }
        else
        {
            file_for_vehicle_detail.write((char *)&add_vehicle_record_obj,sizeof(add_vehicle_record_obj));
            
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tVehicle Record Added Successfully" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            system("pause");
            
        }
        file_for_vehicle_detail.close();
    }
    return 0;
}

void search_vehicle_record()
{
    fstream file_for_search_vehicle_record;
    fstream file_for_read_vehicle_record;
    int vehicle_number_check, i=0;

    //Initialize Value
    for(i=0; i<100; i++)
    {
        search_vehicle_record_obj[i].initialize_value();
    }


    //Read The File To Change Value
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
    
    read_file_for_search_record();
   

}


void read_file_for_search_record()
{
    fstream file_for_read_vehicle_record;
    int i=0;
    for(i=0; i<100; i++)
    {
        search_vehicle_record_obj[i].initialize_value();
    }
    file_for_read_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_read_vehicle_record)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_read_vehicle_record.read((char *)&search_vehicle_record_obj,sizeof(search_vehicle_record_obj));
        file_for_read_vehicle_record.close();

    }
    search_vehicle_record(search_vehicle_record_obj);


}
void search_vehicle_record(Vehicle_Detail map_search_for_vehicle_record_obj[])
{
    int vehicle_number_check;
    int i=0;
    //vehicle_number_check = 0;
    cin.ignore();
    cout << endl << endl << endl << endl << endl << endl<< endl << endl << endl << endl << endl << endl<< endl;
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter The Vehicle Number whose detail you want to Searh:  ";
    cin >> vehicle_number_check;
    for(i=0; i<100; i++)
    {
        if(vehicle_number_check == map_search_for_vehicle_record_obj[i].vehicle_number)
        {
            system("cls");
            flag_for_search_record = 0;
            cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
            cout << "Vehicle Number"<< setw(40) << "Vehicle Type"<<setw(40) << "Owner's Name"<< setw(40) << "Phone Number" << setw(40) << "Address" << setw(30) << "Amount" <<endl;
            cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________________" << endl << endl;
            cout << map_search_for_vehicle_record_obj[i].vehicle_number<< setw(40) 
                << map_search_for_vehicle_record_obj[i].vehicle_type <<setw(50) 
                << map_search_for_vehicle_record_obj[i].name << setw(40) 
                << map_search_for_vehicle_record_obj[i].phone_number << setw(40) 
                << map_search_for_vehicle_record_obj[i].address << setw(30)
                << map_search_for_vehicle_record_obj[i].amount <<endl <<endl;
            system("pause");
            break;
            
        }
        else
        {
            flag_for_search_record = 1;
        }
    }
    if(flag_for_search_record == 1)
    {
        //system("cls");
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tNo Record Found"  << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
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
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "Vehicle Number"<< setw(40) << "Vehicle Type"<<setw(40) << "Owner's Name"<< setw(40) << "Phone Number" << setw(40) << "Address" << setw(30) << "Amount" << endl;
    cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________________" << endl << endl  ;
    for(i=0; i<count_for_total_number_of_vehicle_record; i++)
    {
        cout << map_display_all_vehicle_record[i].vehicle_number<< setw(40) 
            << map_display_all_vehicle_record[i].vehicle_type <<setw(50) 
            << map_display_all_vehicle_record[i].name << setw(40) 
            << map_display_all_vehicle_record[i].phone_number << setw(40) 
            << map_display_all_vehicle_record[i].address << setw(30)
            << map_display_all_vehicle_record[i].amount <<endl <<endl;
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

    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter Vehicle Number whose detail is to be Modified: ";
    cin >> modify_vehicle_number;
    
    for(i=0; i<100; i++)
    {
        if(modify_vehicle_number == map_modify_all_vehicle_record[i].vehicle_number)
        {
            flag_for_modify_vehicle_record:
            system("cls");
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter New Details" << endl << endl;
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tVehicle Number: ";
            cin >> map_vehicle_number;
            cin.ignore();
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tVehicle Type: ";
            cin >> map_vehicle_type;
            cin.ignore();
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tOwners Name: ";
            cin.get(map_name,100);
            cin.ignore();
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tPhone Number: ";
            cin >> map_phone_number;
            cin.ignore();
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tAddress: ";
            cin.get(map_address,100);
            cin.ignore();
            cout << endl << "\t\t\t\t\t\t\t\t\t\t\tAmount: ";
            cin >> map_amount;
            cin.ignore();


            for(j=0; j<100; j++)
            {
                if(map_vehicle_number == map_modify_all_vehicle_record[j].vehicle_number)
                {
                    //system("cls");
                    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tDetail of this Vehicle Number is Already Registered" << endl;
                    cout << "\t\t\t\t\t\t\t\t\t\t\t";
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

                //Modifying The Vehicle Record
                file_for_write_vehicle_record.seekp(i * sizeof(Vehicle_Detail), ios::beg);
                file_for_write_vehicle_record.write((char *)&map_modify_all_vehicle_record[i], sizeof(Vehicle_Detail));
                file_for_write_vehicle_record.close();

                flag_for_modify_vehicle_record = 0;
                //system("cls");
                cout << endl << "\t\t\t\t\t\t\t\t\t\t\tVehicle Record Modified Successfully" << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
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
        //system("cls");
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tNo Record Found" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
        system("cls");
        switch_case_for_admin();

    }
    

}

void delete_vehicle_record()
{
    fstream file_for_delete_vehicle_record;
    file_for_delete_vehicle_record.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_delete_vehicle_record)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        file_for_delete_vehicle_record.read((char *)&delete_vehicle_record_obj,sizeof(delete_vehicle_record_obj));
    }
    file_for_delete_vehicle_record.close();
    delete_given_vehicle_record(delete_vehicle_record_obj);
}


void delete_given_vehicle_record(Vehicle_Detail map_delete_vehicle_record_obj[])
{
    fstream file_for_delete_given_vehicle_record;
    fstream file_for_total_number_of_obj;

    //Read number of Objects in the File
    file_for_total_number_of_obj.open("resource/vehicle_record.dat", ios::in | ios::binary);
    if(!file_for_total_number_of_obj)
    {
        cout << endl << "File Not Found";
    }
    else
    {
        count_for_total_number_of_obj_to_delete_vehicle_record =0;
        while(file_for_total_number_of_obj.read((char *)&delete_record_obj, sizeof(delete_record_obj)))
        {
            count_for_total_number_of_obj_to_delete_vehicle_record++;
        }
    }
    file_for_total_number_of_obj.close();

    

    int map_vehicle_number_to_delete, i=0, flag_for_delete_vehicle_record = 0;
    string original_filename = "resource/vehicle_record.dat";
    string demo_filename = "resource/demo_vehicle_record.dat";

    //Vehicle Number to Delete Vehicle Record
    cout << endl << "\t\t\t\t\t\t\t\t\t\t\tEnter the Vehicle Number whose Record is to be Deleted: ";
    cin >> map_vehicle_number_to_delete;
    
    for(i=0; i<count_for_total_number_of_obj_to_delete_vehicle_record; i++)
    {
        if(map_vehicle_number_to_delete == map_delete_vehicle_record_obj[i].vehicle_number)
        {
            flag_for_delete_vehicle_record = 0;
            file_for_delete_given_vehicle_record.open("resource/demo_vehicle_record.dat", ios::out | ios::binary);
            if(!file_for_delete_given_vehicle_record)
            {
                cout << endl << "File Not Found";
            }
            else
            {
                for(i=0; i<count_for_total_number_of_obj_to_delete_vehicle_record; i++)
                {
                    if(map_vehicle_number_to_delete != map_delete_vehicle_record_obj[i].vehicle_number)
                    {
                        file_for_delete_given_vehicle_record.write((char *)&map_delete_vehicle_record_obj[i],sizeof(map_delete_vehicle_record_obj[i]));
                    }
                }
            }

            file_for_delete_given_vehicle_record.close();
            remove(original_filename.c_str());
            rename("resource/demo_vehicle_record.dat", original_filename.c_str());
            break;
        }
        else
        {
            flag_for_delete_vehicle_record = 1;
        }

    }

    if(flag_for_delete_vehicle_record == 1)
    {
        //system("cls");
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tNo Record Found" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
    }
    else
    {
        //system("cls");
        cout << endl << "\t\t\t\t\t\t\t\t\t\t\tVehicle Record Deleted Successfully" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        system("pause");
    }
}

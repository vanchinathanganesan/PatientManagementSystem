#include"Includes.h"

list::list()
{
	list::start = 0;
}

void list::add(patient* new_start)
{
    if (start == 0)
    {
        start = new_start;
    }
    else
    {
        new_start->nextpatient(start);
        start = new_start;
    }
}

string list::menu()                       //Main menu for the list
{
    string result;
    cout << endl << "Menu:" << endl;
    cout << "1) New patient" << endl;
    cout << "2) Edit Patient entry" << endl;
    cout << "3) Delete Patients Information" << endl;
    cout << "4) List of Patients" << endl;
    cout << "5) Search" << endl;
    cout << "6) Exit" << endl;
    cout << endl << "Please enter a number to choose from the options above: ";
    cin >> result;
    return result;
}

void list::remove(string rem)    //Deletes patients record from archive
{
    string line;
    string delete_name = "FirstName: " + rem;
    int i = 0;
    ifstream f("Patient_List.txt");
    ofstream o("temp.txt");
    while (getline(f, line))
    {
        if (line == delete_name)
        {
            i = 6;
        }
        else if (line != delete_name && i == 0)
        {
            o << line << endl;
        }
        else
        {
            i--;
        }
    }
    f.close();
    o.close();
    std::remove("Patient_List.txt");
    rename("temp.txt", "Patient_List.txt");
    cout << rem << "'s record has been removed from archive" << endl;
}

void list::search(string find)         //Function to find a record
{
    string line;
    int i = 0;                          //used for iteration. i is the number of lines per patient entry (=6)
    int num = 0;                        //Number of records found
    ifstream f("Patient_List.txt");     //Reading from archive i.e. Patient_List.txt
    ofstream temp("temp_find.txt");     //Reading from temporary file
    ifstream tempw("temp_find.txt");    //Writing to temporary file
    while (getline(f, line))
    {
        if (line == find)
        {
            temp << line << endl;
            i = 6;
            num++;
        }
        else if ( (line != find) && (i == 0) )
        {
            
        }
        else
        {
            temp << line << endl;
            i--;
        }
    }
    cout << tempw.rdbuf();              //Outputs contents of temp_find.txt
    if (num == 1)
    {
        cout << "1 record of patient found " << endl;
    }
    else
    {
        cout << num << "records of patients found" << endl;
    }
    f.close();
    temp.close();
    tempw.close();

}

void list::infooutput()        //Outputs List of Patients
{
    ifstream f("Patient_List.txt");
    cout << f.rdbuf();
}

int list::patientnum()         //Calculates number of Patient entries
{
    int num = 0;                //Number of patients in archive
    string line;
    ifstream f("Patient_List.txt");
    while (f >> line)
    {
        if (line == "FirstName:")
        {
            num++;
        }
    }
    return num;
}
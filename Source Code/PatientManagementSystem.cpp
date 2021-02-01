// PatientManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Includes.h"

int main()
{
    list list;
    bool endLoop = false;
    while (!endLoop) {
        while (true) {
            string first_name;
            string last_name;
            string ins_num;
            int age;
            string bld_grp;
            string result;

            //Main Menu
            result = list.menu();
            if (!result.compare("1"))                        //Add a new Patient
            {
                cout << endl <<"Enter following details:" << endl << "First Name: ";
                cin >> first_name;
                cout << "Last Name: ";
                cin >> last_name;
                cout << "Enter inusrance number: ";
                cin >> ins_num;
                cout << "Enter age: ";
                cin >> age;
                cout << "Blood Group: ";
                cin >> bld_grp;
                patient* pati = new patient(first_name, last_name, ins_num, age, bld_grp);
                list.add(pati);
                break;
            }
            else if(!result.compare("2"))                    //Edit a patient's Record
            {
                string edit_name;
                bool edit;
                cout << "Please enter the name of the person to edit record: ";
                cin >> edit_name;
                if (list.patientnum() == 0)
                {
                    cout << "No records found.";
                }
                else
                {
                    list.search("FirstName: " + edit_name);
                }
                cout << "Please note that the record will be deleted and needs to be added again." << endl << "Would you still like to edit the record? Press 1 for yes and 0 for no: ";
                cin >> edit;
                if (edit)
                {
                    list.remove(edit_name);
                    cout << endl << "Enter following details:" << endl << "First Name: ";
                    cin >> first_name;
                    cout << "Last Name: ";
                    cin >> last_name;
                    cout << "Enter inusrance number: ";
                    cin >> ins_num;
                    cout << "Enter age: ";
                    cin >> age;
                    cout << "Blood Group: ";
                    cin >> bld_grp;
                    patient* pati = new patient(first_name, last_name, ins_num, age, bld_grp);
                    list.add(pati);
                }
                else
                {
                    continue;
                }
            }
            else if (!result.compare("3"))                   //Delete a patient's record
            {
                string remove_name;
                cout << "Enter the first name of the person to be removed: ";
                cin >> remove_name;
                list.remove(remove_name);
                break;
            }
            else if (!result.compare("4"))                   //List all patients
            {
                list.infooutput();
                if (list.patientnum() != 1)
                {
                    cout << "There are " << list.patientnum() << " records of patients in the archive." << endl;
                }
                else
                {
                    cout << "There is one record in the archive " << endl;
                }
            }
            else if (!result.compare("5"))                   //Search for a patient's record
            {
                string find;
                if (list.patientnum() == 0)
                {
                    cout << "No records found.";
                }
                else
                {
                    cout << "Enter the name of the patient: ";
                    cin >> find;
                    list.search("FirstName: " + find);
                }
            }
            else if (!result.compare("6"))                   //Exit
            {
                endLoop = true;
                break;
            }
            else
            {
                cout << "Please enter a valid number." << endl;
            }
        }
    }
}
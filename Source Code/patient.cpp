#include"Includes.h"



patient::patient()
{
    first_name = "John";
    last_name = "Doe";
    ins_num = "N/A";
    age = 0;
    bld_grp = "N/A";
}

patient::patient(string first_name_, string last_name_, string ins_num_, int age_, string bld_grp_) //information
{
    first_name = first_name_;
    last_name = last_name_;
    ins_num = ins_num_;
    age = age_;
    bld_grp = bld_grp_;
    ofstream file("Patient_List.txt", ios::app);
    file << endl << "FirstName: " << first_name << endl;
    file << "LastName: " << last_name << endl;
    file << "Insurance Number: " << ins_num << endl;
    file << "Age: " << age << endl;
    file << "Blood Group: " << bld_grp << endl << endl;
}

void patient::nextpatient(patient* next_)   //assigns next patient
{
    next = next_;
}

patient* patient::nextpatientreturn()       //returns next patient
{
    return next;
}
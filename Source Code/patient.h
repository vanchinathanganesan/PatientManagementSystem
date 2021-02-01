#pragma once
#include<iostream>
#include<string>

using namespace std;
class patient
{
    string first_name;          //first name
    string last_name;           //last name
    string ins_num;             //insurance number
    int age;                    //age
    string bld_grp;             //blood group (RH group)
    patient* next;              //next patientn on the list
public:
    patient();
    patient(string first_name_, string last_name_, string ins_num_, int age_, string bld_grp_);
    void nextpatient(patient* next_);
    patient* nextpatientreturn();;
};
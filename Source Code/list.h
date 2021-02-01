#pragma once

#include"Includes.h"
class list
{
    patient* start;
public:
    list();
    string menu();
    void add(patient* new_start);
    void remove(string rem);
    void search(string find);
    void infooutput();
    int patientnum();
};
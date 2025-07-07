#pragma once
#include <string>
#include <sstream>
#include "MyStruct.h"

using namespace std;

class TaskWithFiles
{
public:

    void createFileF(int n);

    void createFileG();

    bool findAbonent(string phoneNumber, Abonent& abonent);

    double calculateCost(string phoneNumber);

    void printBill(string phoneNumber);

    string generateAbonentData();

    void getPhoneNumbersFromFileF(string phones[], int& count);

};


#include "TaskWithFiles.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;

const char* SURNAMES[] = { "��������", "�������", "��������", "����������", "����������", "���������", "�������", "��������", "���������", "�����������" };
const char* INITIALS[] = { "�.�.", "�.�.", "�.�.", "�.�.", "�.�.", "�.�.", "�.�.", "�.�.", "�.�.", "�.�." };
const char* ADDRESSES[] = { "��. ������ 1", "��. ������ 2", "��. ������ 3", "��. ������ 4", "��. ������ 5", "��. ������ 6", "��. ������ 7", "��. ������ 8", "��. ������ 9", "��. ������ 10" };

string TaskWithFiles::generateAbonentData()
{
    string surname = SURNAMES[rand() % 10];
    string initials = INITIALS[rand() % 10];
    string fio = surname + " " + initials;
    string address = ADDRESSES[rand() % 10];

    string phoneCode = "+375(33)";
    int number1 = rand() % 900 + 100; 
    int number2 = rand() % 90 + 10;  
    int number3 = rand() % 90 + 10;  

    string phone = phoneCode + to_string(number1) + "-" + to_string(number2) + "-" + to_string(number3);

    return fio + "\n" + address + "\n" + phone + "\n---\n";
}

void TaskWithFiles::createFileF(int n)
{
    ofstream f("fileF.txt");

    if (!f) {
        cout << "������ �������� ����� F!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        f << generateAbonentData();
    }

    f.close();
    cout << "���� F ������ � " << n << " ����������!\n";
}

void TaskWithFiles::getPhoneNumbersFromFileF(string phones[], int& count)
{
    count = 0;
    ifstream f("fileF.txt");

    if (!f) {
        cout << "���� F �� ������!\n";
        return;
    }

    string line;
    while (getline(f, line) && count < 100) { 
        if (line == "---") continue;

        string fio = line;
        getline(f, line);
        getline(f, line); 

        phones[count] = line;
        count++;

        getline(f, line);
    }

    f.close();
}

void TaskWithFiles::createFileG()
{
    string phoneNumbers[100];
    int phoneCount = 0;

    getPhoneNumbersFromFileF(phoneNumbers, phoneCount);

    if (phoneCount == 0) {
        cout << "��� ������� ��������� ��� �������� ����� G!\n";
        return;
    }

    ofstream g("fileG.txt");

    if (!g) {
        cout << "������ �������� ����� G!\n";
        return;
    }

    int totalCalls = rand() % 20 + 10;

    for (int i = 0; i < totalCalls; i++) {
        string phone = phoneNumbers[rand() % phoneCount];
        int duration = rand() % 60 + 1;
        double pricePerMinute = (rand() % 36 + 15) / 10.0;

        g << phone << " " << duration << " " << pricePerMinute << "\n";
    }

    g.close();
    cout << "���� G ������ � " << totalCalls << " �������� ����������!\n";
}

bool TaskWithFiles::findAbonent(string phoneNumber, Abonent& abonent)
{
    ifstream f("fileF.txt");

    if (!f) {
        cout << "���� F �� ������!\n";
        return false;
    }

    string line;
    while (getline(f, line)) {
        if (line == "---") continue;

        string fio = line;
        getline(f, line);
        string address = line;
        getline(f, line);
        string phone = line;

        if (phone == phoneNumber) {
            abonent.fio = fio;
            abonent.address = address;
            abonent.phone = phone;
            f.close();
            return true;
        }

        getline(f, line);
    }

    f.close();
    return false;
}

double TaskWithFiles::calculateCost(string phoneNumber)
{
    ifstream g("fileG.txt");

    if (!g) {
        cout << "���� G �� ������!\n";
        return 0;
    }

    string phone;
    int time;
    double price;
    double total = 0;

    while (g >> phone >> time >> price) {

        if (phone == phoneNumber) {
            total += time * price;
        }
    }

    cout << "�����: " << total << " ���.\n";
    g.close();
    return total;
}

void TaskWithFiles::printBill(string phoneNumber)
{

    Abonent abonent;
    if (!findAbonent(phoneNumber, abonent)) {
        return;
    }

    double cost = calculateCost(phoneNumber);

    cout << "\n=== ���� � ������ ===\n";
    cout << "��������� " << abonent.fio << "!\n";
    cout << "�����: " << abonent.address << "\n";
    cout << "�������: " << abonent.phone << "\n";
    cout << "����� � ������ �� ������������� ���������: " << cost << " ���.\n";
    cout << "========================\n";
}
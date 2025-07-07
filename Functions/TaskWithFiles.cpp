#include "TaskWithFiles.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;

const char* SURNAMES[] = { "Каянович", "Жукович", "Ориненко", "Сапковский", "Лукьянович", "Анекдотов", "Куделко", "Барвенов", "Филимонов", "Мартинкевич" };
const char* INITIALS[] = { "В.М.", "М.А.", "А.В.", "П.Г.", "А.Д.", "Е.А.", "Ж.М.", "Н.В.", "И.И.", "Д.В." };
const char* ADDRESSES[] = { "ул. Ленина 1", "ул. Ленина 2", "ул. Ленина 3", "ул. Ленина 4", "ул. Ленина 5", "ул. Ленина 6", "ул. Ленина 7", "ул. Ленина 8", "ул. Ленина 9", "ул. Ленина 10" };

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
        cout << "Ошибка создания файла F!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        f << generateAbonentData();
    }

    f.close();
    cout << "Файл F создан с " << n << " абонентами!\n";
}

void TaskWithFiles::getPhoneNumbersFromFileF(string phones[], int& count)
{
    count = 0;
    ifstream f("fileF.txt");

    if (!f) {
        cout << "Файл F не найден!\n";
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
        cout << "Нет номеров телефонов для создания файла G!\n";
        return;
    }

    ofstream g("fileG.txt");

    if (!g) {
        cout << "Ошибка создания файла G!\n";
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
    cout << "Файл G создан с " << totalCalls << " записями разговоров!\n";
}

bool TaskWithFiles::findAbonent(string phoneNumber, Abonent& abonent)
{
    ifstream f("fileF.txt");

    if (!f) {
        cout << "Файл F не найден!\n";
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
        cout << "Файл G не найден!\n";
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

    cout << "Итого: " << total << " руб.\n";
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

    cout << "\n=== СЧЕТ К ОПЛАТЕ ===\n";
    cout << "Уважаемый " << abonent.fio << "!\n";
    cout << "Адрес: " << abonent.address << "\n";
    cout << "Телефон: " << abonent.phone << "\n";
    cout << "Сумма к оплате за междугородние разговоры: " << cost << " руб.\n";
    cout << "========================\n";
}
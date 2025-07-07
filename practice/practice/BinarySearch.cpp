#include "BinarySearch.h"
#include <ctime>
#include <iostream>
#include <ostream>
#include <sstream>


using namespace std;

void BinarySearch::sortArray(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}

int BinarySearch::findFirst(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int BinarySearch::findLast(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int BinarySearch::countNumbers(int arr[], int n, int target)
{
    int first = findFirst(arr, n, target);
    if (first == -1) {
        return 0;  
    }

    int last = findLast(arr, n, target);
    return last - first + 1;
}

void BinarySearch::generateArray(int arr[], int n)
{

    cout << "Генерирую новый массив случайных чисел от 1 до 10...\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1; 
    }
    sortArray(arr, n);

}

void BinarySearch::displayArray(int arr[], int n)
{

    cout << "Текущий массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

}

void BinarySearch::searchNumber(int arr[], int n)
{

    int target;
    cout << "Введите число для поиска: ";
    cin >> target;

    int count = countNumbers(arr, n, target);

    if (count == 0) {
        cout << "Число " << target << " не найдено в массиве.\n";
    }
    else {
        cout << "Число " << target << " встречается " << count << " раз(а).\n";

        int first = findFirst(arr, n, target);
        int last = findLast(arr, n, target);
        cout << "Первое вхождение на позиции: " << first << "\n";
        cout << "Последнее вхождение на позиции: " << last << "\n";
    }

}

void BinarySearch::showMenu()
{

    cout << "\n========== МЕНЮ ==========\n";
    cout << "Введите цифру 1, чтобы создать новый массив\n";
    cout << "Введите цифру 2, чтобы показать текущий массив\n";
    cout << "Введите цифру 3, чтобы найти число в массиве\n";
    cout << "Введите цифру 4, чтобы выйти\n";
    cout << "==========================\n";
    cout << "Ваш выбор: ";

}

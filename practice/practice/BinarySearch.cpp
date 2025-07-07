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

    cout << "��������� ����� ������ ��������� ����� �� 1 �� 10...\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1; 
    }
    sortArray(arr, n);

}

void BinarySearch::displayArray(int arr[], int n)
{

    cout << "������� ������: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

}

void BinarySearch::searchNumber(int arr[], int n)
{

    int target;
    cout << "������� ����� ��� ������: ";
    cin >> target;

    int count = countNumbers(arr, n, target);

    if (count == 0) {
        cout << "����� " << target << " �� ������� � �������.\n";
    }
    else {
        cout << "����� " << target << " ����������� " << count << " ���(�).\n";

        int first = findFirst(arr, n, target);
        int last = findLast(arr, n, target);
        cout << "������ ��������� �� �������: " << first << "\n";
        cout << "��������� ��������� �� �������: " << last << "\n";
    }

}

void BinarySearch::showMenu()
{

    cout << "\n========== ���� ==========\n";
    cout << "������� ����� 1, ����� ������� ����� ������\n";
    cout << "������� ����� 2, ����� �������� ������� ������\n";
    cout << "������� ����� 3, ����� ����� ����� � �������\n";
    cout << "������� ����� 4, ����� �����\n";
    cout << "==========================\n";
    cout << "��� �����: ";

}

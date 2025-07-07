#include <iostream>
#include "findPrimeFactors.h"
#include "MagicSquare.h"
#include "Horner.h"
#include <locale>
#include <fstream>
#include <string>
#include "LinkedLists.h"
#include "MyStruct.h"
#include "StacksOrQueues.h"
#include "TaskWithFiles.h"
#include "BinaryTree.h"
#include "BinarySearch.h"


using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    while(true){

        cout << "\n===������ �� ��������===\n";
        cout << "\n===������� ����===\n";
        cout << "������� ����� 1, ����� ��������� ����� �� ������� ���������.(������ ������������� ���������, ������� 2)\n";
        cout << "������� ����� 2, ����� ������� ��������� ���������� �������, ���������� ���������� ����������.(��������� ������������ ������, ������� 22)\n";
        cout << "������� ����� 3, ����� �� ����� ������� ���������� �������� ���������� ������� n � ����� �.(����������� ���������, ������� 15)\n";
        cout << "������� ����� 4, ����� ���������� ������ �� ������ � ������� (������� 5).";
        cout << "\n===������������ �������:===\n";
        cout << "������� ����� 5, ����� ���������� ������� ������(����� 1).\n";
        cout << "������� ����� 6, ����� ���������� ����� ��� �������(�����3).\n";
        cout << "������� ����� 7, ����� ��������� �������� ������(����� 2)\n";
        cout << "������� ����� 8, ����� ��������������� �������� �������.(������� 1)\n";
        cout << "������� ����� 9, ����� �����\n";
        cout << "��� �����: ";

        int choice;
        cin >> choice;

        if (choice == 9) break;

        switch (choice) {

           case 1: {

               int n;
               cout << "������� �����, ������� ������ ��������� �� ������� ���������:";
               cin >> n;

               while(n <= 0) {
                   cout << "����� ������ ���� �������������!������� ���������� ������������� �����.\n";
                   cout << "������� �����, ������� ������ ��������� �� ������� ���������:";
                   cin >> n;
               }

               findPrimeFactors task1;
               bool* primes = task1.eratosthenes(n);
               cout << n << " = " << task1.canonicForm(n, primes) << "\n";
               delete[] primes;

               break;
           }

           case 2: {

               int n;
               cout << "������� ������ �������, ������� �������� ���������� ���������(nxn):";
               cin >> n;

               while (n <= 0) {
                   cout << "������ ������� ������ ���� �������������! ������� ����������� ������������� �����.\n";
                   cout << "������� ������ �������, ������� �������� ���������� ���������(nxn):";
                   cin >> n;
               }

               MagicSquare task2;
               int** matrix = task2.createMatrix(n);
               task2.printMatrix(matrix, n);
               task2.deleteMatrix(matrix, n);

               break;
           }

           case 3: {

               int n;
               double x;
               cout << "������� ������� ���������� n: ";
               cin >> n;

               while (n <= 0) {
                   cout << "������� ���������� ������ ���� �������������! ������� ���������� ������������� �����.\n";
                   cout << "������� ������� ���������� n: ";
                   cin >> n;
               }

               Horner task3;
               double* kf = new double[n + 1];

               cout << "������� ������������ ���������� � ��������� ����: " << "\n";
               for (int i = 0; i <= n; ++i)
               {
                   cin >> kf[i];
               }

               cout << "������� �������� x: ";
               cin >> x;

               double result = task3.horner(kf, n, x);
               cout << "�������� ���������� � ����� x: " << result << "\n";

               delete[] kf;

               break;

           }

           case 4: {

               TaskWithFiles task4;

               cout << "��������� ��� ������� ���������� ������\n";
               cout << "======================================\n";

               int choice;
               string phone;




               while (true) {
                   cout << "\n===�������� ��������:===\n";
                   cout << "������� ����� 1, ����� ������� ���� ��������� (F)\n";
                   cout << "������� ����� 2, ����� ������� ���� ���������� (G)\n";
                   cout << "������� ����� 3, ����� ����� �������� � �������� ����\n";
                   cout << "������� ����� 4, ����� �����\n";
                   cout << "��� �����: ";
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       int n;
                       cout << "������� ���������� ���������(�� ������ 100): ";
                       cin >> n;

                       while (n <= 0 || n > 100) {
                           cout << "���������� ��������� ������ ���� ������������� � �� ������ 100!\n";
                           cout << "������� ���������� ���������: ";
                           cin >> n;
                       }

                       task4.createFileF(n);
                       break;
                   }
                   case 2: {
                       task4.createFileG();
                       break;
                   }
                   case 3: {
                       cout << "������� ����� ��������: ";
                       cin.ignore();
                       getline(cin, phone);
                       task4.printBill(phone);
                       break;
                   }
                   case 4: {
                       cout << "��������� ���������!\n";
                       return 0;
                   }
                   default: {
                       cout << "������������ �����!\n";
                       cin.ignore(1000, '\n');
                       break;
                   }
                   }

               }

               break;

           }

           case 5: {

               LinkedLists task5;

               Node* head = nullptr;
               int n, k;

               cout << "������� ���������� ��������� ������: ";
               cin >> n;
               task5.fillRandom(head, n);

               while (n <= 0) {
                   cout << "���������� ��������� ������ ������ ���� ������������� ������! ������� ���������� ������������� �����.\n";
                   cout << "������� ���������� ��������� ������: ";
                   cin >> n;
               }

               cout << "�������� ������: ";
               task5.printList(head);

               cout << "������� k (������� ��������� ��������� ��������): ";
               cin >> k;

               while (k > n) {
                   cout << "���������� ���������� ��������� �� ����� ���� ������ ���������� ���������!\n";
                   cout << "������� k (������� ��������� ��������� ��������): ";
                   cin >> k;
               }

               while (k <= 0) {
                   cout << "���������� ���������, ������� �� ������ ��������, ������ ���� �������������!. ������� ���������� ������������ �����.\n";
                   cout << "������� k (������� ��������� ��������� ��������): ";
                   cin >> k;
               }

               task5.reverse(head, k);

               cout << "������ ����� ���������: ";
               task5.printList(head);

               Node* current = head;
               while (current != nullptr) {
                   Node* temp = current;
                   current = current->next;
                   delete temp;
               }

               break;

           }

           case 6: {

               StacksOrQueues task6;

               int length;
               cout << "������� ����� ������: ";
               cin >> length;

               while (length <= 0) {
                   cout << "����� ������ ������ ���� ������������� ������! ������� ���������� ������������� �����.\n";
                   cout << "������� ����� ������: ";
                   cin >> length;
               }

               string original = task6.generateRandomString(length);
               cout << "�������� ������: " << original << "\n";


               for (char ch : original) {
                   task6.push(ch);
               }

               string reversed;
               while (!task6.isEmpty()) {
                   reversed += task6.pop();
               }

               cout << "����������� ������: " << reversed << "\n";

               break;

           }

           case 7: {

               BinaryTree tree;

               cout << "\n=== ��������� ��� ������ � �������� ������� ===\n";
               cout << "������� �������� ������ �� ���������� �������\n";

               tree.fillRandom(7);

               tree.printTree();

               int depth = tree.getDepth();
               cout << "������� ������: " << depth << " �������\n";

               int choice;
               while (true) {
                   tree.showMenu();
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       int value;
                       cout << "������� ����� �� 1 �� 100: ";
                       cin >> value;

                       if (value < 1 || value > 100) {
                           cout << "������! ����� ������ ���� �� 1 �� 100.\n";
                           break;
                       }

                       if (tree.insert(value)) {
                           cout << "������� ������� ������: " << tree.getDepth() << " �������\n";
                           tree.printTree();
                       }
                       break;
                   }
                   case 2:
                       cout << "������� ������: " << tree.getDepth() << " �������\n";
                       break;
                   case 3: {
                       int count;
                       cout << "������� ��������� ����� ��������? ";
                       cin >> count;
                       if (count > 0) {
                           tree.fillRandom(count);
                           tree.printTree();
                           cout << "������� ������: " << tree.getDepth() << " �������\n";
                       }
                       break;
                   }
                   case 4:
                       cout << "��������� ���������!\n";
                       cout << "�������� ������� ������: " << tree.getDepth() << " �������\n";
                       return 0;
                   default:
                       cout << "�������� �����! ���������� �����.\n";
                   }
               }

               break;

           }

           case 8: {

               BinarySearch task8;

               int n = 0;
               int arr[100];
               bool arrayCreated = false;

               cout << "\n=== ��������� ������ ���������� � ������� ===\n";
               cout << "����� ����������! ������� �������� ������.\n";

               while (true) {
                   task8.showMenu();

                   int choice;
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       cout << "������� ������ ������� (�� 1 �� 100): ";
                       cin >> n;

                       if (n < 1 || n > 100) {
                           cout << "������: ������ ������ ���� �� 1 �� 100!\n";
                           break;
                       }

                       task8.generateArray(arr, n);
                       arrayCreated = true;
                       cout << "������ ������� ������!\n";
                       task8.displayArray(arr, n);
                       break;
                   }

                   case 2: {
                       if (!arrayCreated) {
                           cout << "������ ��� �� ������! ������� �������� ����� 1.\n";
                       }
                       else {
                           task8.displayArray(arr, n);
                       }
                       break;
                   }

                   case 3: {
                       if (!arrayCreated) {
                           cout << "������ ��� �� ������! ������� �������� ����� 1.\n";
                       }
                       else {
                           task8.searchNumber(arr, n);
                       }
                       break;
                   }

                   case 4: {
                       cout << "��������� ���������!\n";
                       return 0;
                   }

                   default: {
                       cout << "������: �������� �����! ����������, �������� ����� �� 1 �� 4.\n";
                       break;
                   }
                   }
               }

               break;
           }

           case 9: {
               cout << "��������� ���������!\n";
               return 0;
           }

           default: {

               cout << "�������� �����!���������� �����.\n";
               break;

           }
               
        }
    }

    return 0;
}
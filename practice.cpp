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

        cout << "\n===Задачи по практике===\n";
        cout << "\n===Главное Меню===\n";
        cout << "Введите цифру 1, чтобы разложить число на простве множители.(Задачи целочисленной ариметики, вариант 2)\n";
        cout << "Введите цифру 2, чтобы создать построить квадратную матрицу, являющейся магическим кваддратом.(Обработка динамических матриц, вариант 22)\n";
        cout << "Введите цифру 3, чтобы по схеме Горнера подсчитать значение многочлена степени n в точке х.(Рекурсивные алгоритмы, вариант 15)\n";
        cout << "Введите цифру 4, чтобы посмотреть задачу на работу с файлами (вариант 5).";
        cout << "\n===Обязательные задания:===\n";
        cout << "Введите цифру 5, чтобы посмотерть Связные списки(номер 1).\n";
        cout << "Введите цифру 6, чтобы посмотреть Стеки или очереди(номер3).\n";
        cout << "Введите цифру 7, чтобы построить бинарное дерево(номер 2)\n";
        cout << "Введите цифру 8, чтобы воспользоваться бианрным поиском.(варинат 1)\n";
        cout << "Введите цифру 9, чтобы выйти\n";
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;

        if (choice == 9) break;

        switch (choice) {

           case 1: {

               int n;
               cout << "Введите число, которые хотите разложить на простые множители:";
               cin >> n;

               while(n <= 0) {
                   cout << "Число должно быть положительным!Введите пожалуйста положительное число.\n";
                   cout << "Введите число, которые хотите разложить на простые множители:";
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
               cout << "Введите размер матрицы, которая является малическим квадратом(nxn):";
               cin >> n;

               while (n <= 0) {
                   cout << "Размер матрицы должно быть положительным! Введите пожалувйста положительное число.\n";
                   cout << "Введите размер матрицы, которая является малическим квадратом(nxn):";
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
               cout << "Введите степень многочлена n: ";
               cin >> n;

               while (n <= 0) {
                   cout << "Степень многочлена должна быть положительная! Введите пожаулйста положительное число.\n";
                   cout << "Введите степень многочлена n: ";
                   cin >> n;
               }

               Horner task3;
               double* kf = new double[n + 1];

               cout << "Введите коэффициенты многочлена и свободный член: " << "\n";
               for (int i = 0; i <= n; ++i)
               {
                   cin >> kf[i];
               }

               cout << "Введите значение x: ";
               cin >> x;

               double result = task3.horner(kf, n, x);
               cout << "Значение многочлена в точке x: " << result << "\n";

               delete[] kf;

               break;

           }

           case 4: {

               TaskWithFiles task4;

               cout << "Программа для расчета телефонных счетов\n";
               cout << "======================================\n";

               int choice;
               string phone;




               while (true) {
                   cout << "\n===Выберите действие:===\n";
                   cout << "Введите число 1, чтобы создать файл абонентов (F)\n";
                   cout << "Введите число 2, чтобы создать файл разговоров (G)\n";
                   cout << "Введите число 3, чтобы найти абонента и показать счет\n";
                   cout << "Введите число 4, чтобы выйти\n";
                   cout << "Ваш выбор: ";
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       int n;
                       cout << "Введите количество абонентов(не больше 100): ";
                       cin >> n;

                       while (n <= 0 || n > 100) {
                           cout << "Количество абонентов должно быть положительным и не больше 100!\n";
                           cout << "Введите количество абонентов: ";
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
                       cout << "Введите номер телефона: ";
                       cin.ignore();
                       getline(cin, phone);
                       task4.printBill(phone);
                       break;
                   }
                   case 4: {
                       cout << "Программа завершена!\n";
                       return 0;
                   }
                   default: {
                       cout << "Неправильный выбор!\n";
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

               cout << "Введите количество элементов списка: ";
               cin >> n;
               task5.fillRandom(head, n);

               while (n <= 0) {
                   cout << "Количестов элементов списка должно быть положительным числом! Введите пожалуйста положительное число.\n";
                   cout << "Введите количество элементов списка: ";
                   cin >> n;
               }

               cout << "Исходный список: ";
               task5.printList(head);

               cout << "Введите k (сколько последних элементов отразить): ";
               cin >> k;

               while (k > n) {
                   cout << "Количесвто отраженных элементов не может быть больше количества элементов!\n";
                   cout << "Введите k (сколько последних элементов отразить): ";
                   cin >> k;
               }

               while (k <= 0) {
                   cout << "Количество элементов, которые вы хотите отразить, должно быть положительным!. Введите пожалуйста положительно число.\n";
                   cout << "Введите k (сколько последних элементов отразить): ";
                   cin >> k;
               }

               task5.reverse(head, k);

               cout << "Список после отражения: ";
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
               cout << "Введите длину строки: ";
               cin >> length;

               while (length <= 0) {
                   cout << "Длина строки должна быть положительным числом! Введите пожалйуста полодительное число.\n";
                   cout << "Введите длину строки: ";
                   cin >> length;
               }

               string original = task6.generateRandomString(length);
               cout << "Исходная строка: " << original << "\n";


               for (char ch : original) {
                   task6.push(ch);
               }

               string reversed;
               while (!task6.isEmpty()) {
                   reversed += task6.pop();
               }

               cout << "Перевёрнутая строка: " << reversed << "\n";

               break;

           }

           case 7: {

               BinaryTree tree;

               cout << "\n=== ПРОГРАММА ДЛЯ РАБОТЫ С БИНАРНЫМ ДЕРЕВОМ ===\n";
               cout << "Сначала создадим дерево со случайными числами\n";

               tree.fillRandom(7);

               tree.printTree();

               int depth = tree.getDepth();
               cout << "Глубина дерева: " << depth << " уровней\n";

               int choice;
               while (true) {
                   tree.showMenu();
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       int value;
                       cout << "Введите число от 1 до 100: ";
                       cin >> value;

                       if (value < 1 || value > 100) {
                           cout << "Ошибка! Число должно быть от 1 до 100.\n";
                           break;
                       }

                       if (tree.insert(value)) {
                           cout << "Текущая глубина дерева: " << tree.getDepth() << " уровней\n";
                           tree.printTree();
                       }
                       break;
                   }
                   case 2:
                       cout << "Глубина дерева: " << tree.getDepth() << " уровней\n";
                       break;
                   case 3: {
                       int count;
                       cout << "Сколько случайных чисел добавить? ";
                       cin >> count;
                       if (count > 0) {
                           tree.fillRandom(count);
                           tree.printTree();
                           cout << "Глубина дерева: " << tree.getDepth() << " уровней\n";
                       }
                       break;
                   }
                   case 4:
                       cout << "Программа завершена!\n";
                       cout << "Итоговая глубина дерева: " << tree.getDepth() << " уровней\n";
                       return 0;
                   default:
                       cout << "Неверный выбор! Попробуйте снова.\n";
                   }
               }

               break;

           }

           case 8: {

               BinarySearch task8;

               int n = 0;
               int arr[100];
               bool arrayCreated = false;

               cout << "\n=== ПРОГРАММА ПОИСКА ПОВТОРЕНИЙ В МАССИВЕ ===\n";
               cout << "Добро пожаловать! Сначала создайте массив.\n";

               while (true) {
                   task8.showMenu();

                   int choice;
                   cin >> choice;

                   switch (choice) {
                   case 1: {
                       cout << "Введите размер массива (от 1 до 100): ";
                       cin >> n;

                       if (n < 1 || n > 100) {
                           cout << "Ошибка: размер должен быть от 1 до 100!\n";
                           break;
                       }

                       task8.generateArray(arr, n);
                       arrayCreated = true;
                       cout << "Массив успешно создан!\n";
                       task8.displayArray(arr, n);
                       break;
                   }

                   case 2: {
                       if (!arrayCreated) {
                           cout << "Массив еще не создан! Сначала выберите пункт 1.\n";
                       }
                       else {
                           task8.displayArray(arr, n);
                       }
                       break;
                   }

                   case 3: {
                       if (!arrayCreated) {
                           cout << "Массив еще не создан! Сначала выберите пункт 1.\n";
                       }
                       else {
                           task8.searchNumber(arr, n);
                       }
                       break;
                   }

                   case 4: {
                       cout << "Программа завершена!\n";
                       return 0;
                   }

                   default: {
                       cout << "Ошибка: неверный выбор! Пожалуйста, выберите число от 1 до 4.\n";
                       break;
                   }
                   }
               }

               break;
           }

           case 9: {
               cout << "Программа завершена!\n";
               return 0;
           }

           default: {

               cout << "Неверный выбор!Попробуйте снова.\n";
               break;

           }
               
        }
    }

    return 0;
}
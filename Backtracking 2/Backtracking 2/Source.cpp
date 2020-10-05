/*Напишите программу, которая выводит все разложения заданного числа N
на слагаемые. Например, если N=4, то это 1+1+1+1, 1+1+2, 1+3, 2+2 и 4.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;                                                      //переменная для пользовательского числа

vector<string> result;                                      //вектор для хранения всех результатов

int input(int bottom, int top, string message) {            //функция для ввода числа
    int p;
    cout << message;
    while (!(cin >> p) || (p < bottom) || (p > top)) {
        cout << "Ввод некорректен. Повторите ввод: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    cin.clear();
    while (cin.get() != '\n');
    cout << endl;
    return p;
}

void decomposition(int n, int i, string str) {              //непосредственно функция решения
    if (n == N) {                                           //условие выхода
        result.push_back(str);                              //если n == N, то сохраняем результат в вектор    
        return;
    }
    if (n > 0) {                                            //механизм добавления с строку с результатом знака +
        str = str + "+";                                    //для всех цифр, кроме первой и последней
    }
    if (n < N) {                                            //условие продолжения
        for (int j = 1; j <= N - n; j++) {                  //цикл для прохождения всех возможных итераций
            if (j >= i)                                     //предотвращение повторяющихся результатов типа 1+2 и 2+1
                decomposition(n + j, j, str + to_string(j));//рекурсивный вызов функции
        }
    }
}

int main(int argc, const char* argv[]) {
    setlocale(NULL, "");
    N = input(0, 50, "Разложение числа N на слагаемые\nВведите число N: "); //ввод числа пользователем
    while (N == 0) {
        cout << "Вы ввели ноль! Повторите ввод: ";
        N = input(0, 50, "\nРазложение числа N на слагаемые\nВведите число N: ");
    }
    string str;                                                             //строка для хранения результата
    decomposition(0, 1, str);                                               //вызов функции
    cout << "Количество разложений числа " << N << ": " << result.size() << endl;
    for (string str : result)                                               //вывод всех результатов
        cout << str << endl;
    return 0;
}
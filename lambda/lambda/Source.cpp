/*Используя функции for_each, count_if, replace_if и лямбда выражение, для данного
одномерного массива найти:
Сумму элементов,
Количество положительных элементов,
Заменить все нечетные значения на 0.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int sum = 0;

int main() {
	setlocale(NULL, "");
	vector<int> numbers; //вектор (одномерный массив)
	cout << "Введите длину вектора: ";
	int length; //пользовательская длина вектора
	cin >> length;

	cout << "Введите элементы вектора через пробел:\n";  //заполнение массива пользователем
	for (int i = 0; i < length; i++) {
		int temp; cin >> temp;
		numbers.push_back(temp);
	}

	cout << "Вектор:\n";
	for (int x : numbers)       //вывод вектора без изменений на экран
		cout << x << " ";

	for_each(numbers.begin(), numbers.end(), [](int n) {  //нахождение суммы элементов массива с помощью
		sum += n;										  //функции for_each() и лямбда-выражения
		});
	cout << "\nСумма: " << sum;							  //вывод суммы

	cout << "\nКоличество положительных элементов: " << count_if(numbers.begin(), numbers.end(), [](int n) {
		if (n > 0) return true;							//нахождение количества положительных элементов
		return false;									//с помощью функции count_if() и лямбда-выражения
		});

	replace_if(numbers.begin(), numbers.end(), [](int n) {
		if (n % 2 != 0) return true;					//замена нечетных элементов с помощью функции					
		return false;									//replace_if() и лямбда-выражения
		}, 0);
	cout << "\nВектор с заменами:\n";					//вывод массива с заменами
	for (int x : numbers)
		cout << x << " ";

	return 0;
}


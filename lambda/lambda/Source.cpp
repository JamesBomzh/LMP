/*��������� ������� for_each, count_if, replace_if � ������ ���������, ��� �������
����������� ������� �����:
����� ���������,
���������� ������������� ���������,
�������� ��� �������� �������� �� 0.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int sum = 0;

int main() {
	setlocale(NULL, "");
	vector<int> numbers; //������ (���������� ������)
	cout << "������� ����� �������: ";
	int length; //���������������� ����� �������
	cin >> length;

	cout << "������� �������� ������� ����� ������:\n";  //���������� ������� �������������
	for (int i = 0; i < length; i++) {
		int temp; cin >> temp;
		numbers.push_back(temp);
	}

	cout << "������:\n";
	for (int x : numbers)       //����� ������� ��� ��������� �� �����
		cout << x << " ";

	for_each(numbers.begin(), numbers.end(), [](int n) {  //���������� ����� ��������� ������� � �������
		sum += n;										  //������� for_each() � ������-���������
		});
	cout << "\n�����: " << sum;							  //����� �����

	cout << "\n���������� ������������� ���������: " << count_if(numbers.begin(), numbers.end(), [](int n) {
		if (n > 0) return true;							//���������� ���������� ������������� ���������
		return false;									//� ������� ������� count_if() � ������-���������
		});

	replace_if(numbers.begin(), numbers.end(), [](int n) {
		if (n % 2 != 0) return true;					//������ �������� ��������� � ������� �������					
		return false;									//replace_if() � ������-���������
		}, 0);
	cout << "\n������ � ��������:\n";					//����� ������� � ��������
	for (int x : numbers)
		cout << x << " ";

	return 0;
}


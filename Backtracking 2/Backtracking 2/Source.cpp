/*�������� ���������, ������� ������� ��� ���������� ��������� ����� N
�� ���������. ��������, ���� N=4, �� ��� 1+1+1+1, 1+1+2, 1+3, 2+2 � 4.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;                                                      //���������� ��� ����������������� �����

vector<string> result;                                      //������ ��� �������� ���� �����������

int input(int bottom, int top, string message) {            //������� ��� ����� �����
    int p;
    cout << message;
    while (!(cin >> p) || (p < bottom) || (p > top)) {
        cout << "���� �����������. ��������� ����: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    cin.clear();
    while (cin.get() != '\n');
    cout << endl;
    return p;
}

void decomposition(int n, int i, string str) {              //��������������� ������� �������
    if (n == N) {                                           //������� ������
        result.push_back(str);                              //���� n == N, �� ��������� ��������� � ������    
        return;
    }
    if (n > 0) {                                            //�������� ���������� � ������ � ����������� ����� +
        str = str + "+";                                    //��� ���� ����, ����� ������ � ���������
    }
    if (n < N) {                                            //������� �����������
        for (int j = 1; j <= N - n; j++) {                  //���� ��� ����������� ���� ��������� ��������
            if (j >= i)                                     //�������������� ������������� ����������� ���� 1+2 � 2+1
                decomposition(n + j, j, str + to_string(j));//����������� ����� �������
        }
    }
}

int main(int argc, const char* argv[]) {
    setlocale(NULL, "");
    N = input(0, 50, "���������� ����� N �� ���������\n������� ����� N: "); //���� ����� �������������
    while (N == 0) {
        cout << "�� ����� ����! ��������� ����: ";
        N = input(0, 50, "\n���������� ����� N �� ���������\n������� ����� N: ");
    }
    string str;                                                             //������ ��� �������� ����������
    decomposition(0, 1, str);                                               //����� �������
    cout << "���������� ���������� ����� " << N << ": " << result.size() << endl;
    for (string str : result)                                               //����� ���� �����������
        cout << str << endl;
    return 0;
}
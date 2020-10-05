/*��������� ���������� ���-�������, ������������ ��������� ��������� � ������� 
E A S Y Q U T I O N � ��������� ������� � ������������� ������ ������� �� M = 5 �������
��� ������������� ������� ������������ � ���� ��������������� �������. ���
�������������� k-�� ����� �������� � ������ ������� ����������� ���-������� 11k
mod M.*/

/*�����:
��� ������ ����� � ����������� ���-�������. � ��� ������������ ������ ��� ��������� �����, ��������� ��������,
��������� ��������, ��������� ���������� �������� � ��� ����������.
���� ������� ������� ���� �������, � ����� ������ �� �� �����.
������� hashFunc �������� �� ������� �������� ���-������� ��� ��������� ��������.
���������� � ������� �������������� �������� addToHashArray. ���� �������� � ������ ������ ��� ���, �� �� ����������� � ������
������. ���� ���������� ��������, �� ������� ����������� ��������� ��������� � ������� ������������.
� ������� ������� �������� �������� ����� ����������� � ������� � ������� ������� addToHashArray.*/

#include <iostream>

using namespace std;

class LinkedHashEntry {
private:
    int key;
    int value;
    LinkedHashEntry* next;
public:
    LinkedHashEntry(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    int getKey() {
        return key;
    }
    int getValue() {
        return value;
    }
    void setValue(int value) {
        this->value = value;
    }
    LinkedHashEntry* getNext() {
        return next;
    }
    void setNext(LinkedHashEntry* next) {
        this->next = next;
    }
};


void clearHashArray(LinkedHashEntry* hashArray[], int k) {
    for (int i = 0; i < k; i++) {
        hashArray[i] = NULL;
    }
}

void coutHashArray(LinkedHashEntry* hashArray[], int k) {
    for (int i = 0; i < k; i++) {
        LinkedHashEntry* iter = hashArray[i];
        while (iter != NULL) {
            cout << " " << iter->getKey() << " " << iter->getValue() << "(" << (char)iter->getValue() << ")  ";
            iter = iter->getNext();
        }
        cout << "  NULL\n";
    }
}

int hashFunc(int value, int M) {
    return 11 * value % M;
}

void addToHashArray(LinkedHashEntry* hashArray[], int M, int value, int len[]) {
    int key = hashFunc(value, M);
    len[key]++;
    LinkedHashEntry* obj = new LinkedHashEntry(key, value);
    if (hashArray[key] == NULL) {
        hashArray[key] = obj;
        return;
    }
    LinkedHashEntry* iter = hashArray[key];
    while (iter->getNext() != NULL) {
        iter = iter->getNext();
    }
    iter->setNext(obj);
}


int main() {
    // E A S Y Q U T I O N
    setlocale(NULL, "");
    const int M = 5;
    cout << "\n������ ���-�������: " << M << endl;
    LinkedHashEntry* hashArray[M];
    int lenOfHashArrayChains[M];
    for (int j = 0; j < M; j++)
        lenOfHashArrayChains[j] = 0;
    clearHashArray(hashArray, M);
    addToHashArray(hashArray, M, (int)'E', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'A', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'S', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'Y', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'Q', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'U', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'T', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'I', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'O', lenOfHashArrayChains);
    addToHashArray(hashArray, M, (int)'N', lenOfHashArrayChains);
    coutHashArray(hashArray, M);
    return 0;
}
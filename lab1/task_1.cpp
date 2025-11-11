#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "Адрес начала массива: " << arr << "\n\n";

    for (int i = 0; i < n; i++) {
        cout << "Элемент arr[" << i << "] = " << arr[i]
             << " | Адрес: " << &arr[i]
             << " | Смещение от начала = " << (char*)&arr[i] - (char*)arr
             << " байт\n";
    }

    delete[] arr;
    system("pause");
    return 0;
}

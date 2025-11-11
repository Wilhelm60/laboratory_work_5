#include <iostream>
#include <string>
#include <windows.h> // чтобы консоль воспринимала кириллицу

using namespace std;

class Publication {
public:
    string name_book;
    float cost_book;

    void getdata() {
        cout << "Введите название книги (без пробелов): " << endl;
        cin >> name_book;
        cout << "Введите цену книги: " << endl;
        cin >> cost_book;
    }
    void putdata() {
        cout << "Название книги: " << name_book << endl;
        cout << "Цена книги: " << cost_book << " рублей" << endl;
    }
};

class Sales {
public:
    float sales_book[3];

    void getdata() {
        cout << "Стоимость продаж книги за последние 3 месяца: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Продажа за " << i + 1 << " месяц: ";
            cin >> sales_book[i];
        }
    }
    void putdata() {
        float sum = 0;
        cout << "Стоимость продаж за последние 3 месяца: ";
        for (int i = 0; i < 3; i++) {
            sum += sales_book[i];
        }
        cout << sum << " рублей" << endl;
    }
};

class Book : public Publication, public Sales {
public:
    int pages_book;

    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц книги: " << endl;
        cin >> pages_book;
        Sales::getdata();
    }
    void putdata() {
        Publication::putdata();
        cout << "Количество страниц книги: " << pages_book << endl;
        Sales::putdata();
    }
};

class Type : public Publication, public Sales {
public:
    float record_time_book;

    void getdata() {
        Publication::getdata();
        cout << "Введите время записи книги в минутах: " << endl;
        cin >> record_time_book;
        Sales::getdata();
    }
    void putdata() {
        Publication::putdata();
        cout << "Время записи книги в минутах: " << record_time_book << endl;
        Sales::putdata();
    }
};

int main() {
    SetConsoleOutputCP(1251); // вывод в кириллице
    SetConsoleCP(1251);       // ввод в кириллице
    setlocale(LC_ALL, "Russian");

    Book book_1;
    cout << "------------Данные книги-------------------" << endl;
    book_1.getdata();
    cout << "------------Ввод закончен------------------" << endl;
    book_1.putdata();
    cout << "------------Вывод закончен-----------------" << endl;
    Type book_2;
    cout << "------------Данные аудиокниги--------------" << endl;
    book_2.getdata();
    cout << "------------Ввод закончен------------------" << endl;
    book_2.putdata();
    cout << "------------Вывод закончен-----------------" << endl;
    system("pause");
    return 0;
}

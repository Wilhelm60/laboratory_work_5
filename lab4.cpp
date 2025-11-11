#include <iostream>
#include <vector>
using namespace std;

class ProgramError {
public:
    virtual const char* what() const = 0;
    virtual ~ProgramError() {}
};

class InvalidPointer : public ProgramError {
public:
    const char* what() const override { return "Ошибочный указатель"; }
};

class InvalidList : public ProgramError {
public:
    const char* what() const override { return "Ошибка работы со списком"; }
};

class InvalidIndex : public ProgramError {
public:
    const char* what() const override { return "Недопустимый индекс"; }
};

class ListOverflow : public ProgramError {
public:
    const char* what() const override { return "Список переполнен"; }
};

template <typename T>
class PointerArray {
private:
    vector<T*> pointers;
public:
    // Проверка размера списка
    PointerArray(size_t size) {
        if (size == 0)
            throw InvalidList();
        pointers.resize(size, nullptr);
    }

    // Деструктор списка
    ~PointerArray() {
        for (auto ptr : pointers)
            delete ptr;
    }

    // Проверка индекса
    T*& operator[](size_t index) {
        if (index >= pointers.size())
            throw InvalidIndex();
        return pointers[index];
    }

    // Проверка указателя
    T* at(size_t index) {
        if (index >= pointers.size())
            throw InvalidIndex();
        if (pointers[index] == nullptr)
            throw InvalidPointer();
        return pointers[index];
    }

    // Проверка переполнения и проверка runtime_error
    void add(T* ptr) {
        if (ptr == nullptr)
            throw runtime_error("Попытка добавить нулевой указатель (runtime_error)");
        for (size_t i = 0; i < pointers.size(); i++) {
            if (pointers[i] == nullptr) {
                pointers[i] = ptr;
                return;
            }
        }
        throw ListOverflow();
    }
};

class Person {
public:
    string name;
    Person(string n) : name(n) {}
    void show() const { cout << "Человек: " << name << endl; }
};

int main() {
    setlocale(LC_ALL, "Rus");

    try {
        PointerArray<Person> emptyList(0); // Ошибка работы со списком
    }
    catch (const ProgramError& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    PointerArray<Person> people(2);
    people.add(new Person("Иван"));
    people.add(new Person("Анна"));
    try {
        people.add(new Person("Петр")); // Список переполнен
    }
    catch (const ProgramError& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        people.at(1)->show();
        people.at(5)->show(); // Недопустимый индекс
    }
    catch (const ProgramError& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        PointerArray<Person> human(3);
        human.at(1)->show(); // Ошибочный указатель
    }
    catch (const ProgramError& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    try {
        people.add(nullptr); // Runtime_error
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    system("pause");
    return 0;
}

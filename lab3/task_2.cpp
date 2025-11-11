#include <iostream>
#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
using namespace std;

class Base {
public:
    virtual ~Base() = default;

    virtual void info() const {
        cout << "Это объект Base" << endl;
    }

    virtual shared_ptr<Base> clone() const {
        return make_shared<Base>(*this);
    }
};

class Derived : public Base {
public:
    void info() const {
        cout << "Это объект Derived" << endl;
    }

    shared_ptr<Base> clone() const {
        return make_shared<Derived>(*this);
    }
};

void add(vector<shared_ptr<Base>>& storage, const Base& obj) {
    storage.push_back(obj.clone());
}


int main() {
    setlocale(LC_ALL, "Rus");

    srand(static_cast<unsigned>(time(nullptr)));

    vector<shared_ptr<Base>> storage;

    for (int i = 0; i < 10; ++i) {
        int random = rand() % 100;

        if (random % 2 == 0) {
            Base baseObj;
            add(storage, baseObj);
            cout << "Создан Base. Число: " << random << endl;
        }
        else {
            Derived derivedObj;
            add(storage, derivedObj);
            cout << "Создан Derived. Число: " << random << endl;
        }
    }

    cout << "Вывод объектов из хранилища:\n";
    for (const auto& item : storage) {
        item->info();
    }
    system("pause");
    return 0;
}

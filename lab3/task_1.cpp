#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Detail {
protected:
	string name;
	Detail(const string& name) : name(name) {}
public:
	virtual ~Detail() = default;
	virtual void print() const = 0;

	template <typename T>
	friend void makeAndStore(vector<shared_ptr<Detail>>& storage, const string& name);
};

class Build : public Detail {
protected:
	Build(const string& name) : Detail(name) {}
public:
	void print() const {
		cout << "Сборка: " << name << endl;
	}
	template <typename T>
	friend void makeAndStore(vector<shared_ptr<Detail>>& storage, const string& name);
};

template <typename T>
void makeAndStore(vector<shared_ptr<Detail>>& storage, const string& name) {
	storage.push_back(shared_ptr<Detail>(new T(name)));
}

int main() {
	setlocale(LC_ALL, "Rus");

	vector<shared_ptr<Detail>> storage;

	makeAndStore<Build>(storage, "Главная сборка");
	makeAndStore<Build>(storage, "Дополнительная сборка");

	cout << "Список созданных объектов:\n";
	for (const auto& item : storage) {
		item->print();
	}
	system("pause");
	return 0;
}

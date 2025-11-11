#include <iostream>
#include <string>
#include <vector>

using namespace std;

//перечисление типов книг
enum BookType {
    FICTION,   //художественная
    TECHNICAL  //техническая
};

class Book {
private:
    string author;
    string title;
    BookType type;

public:
    //конструктор 
    Book(const string& a, const string& t, BookType tp) {
        author = a;
        title = t;
        type = tp;
    }

    BookType getType() const {
        return type;
    }

    void print() const { //const не даст менять книгу внутри цикла
        cout << "Автор: " << author
             << " | Название: " << title
             << " | Тип: " << (type == FICTION ? "Художественная" : "Техническая") //тернарный оператор
             << endl;
    }
};

//вывести библиотеку
void printLibrary(const vector<Book>& library) { //& — передаём по ссылке library
    cout << "\nСодержимое библиотеки:\n";
    for (const auto& book : library) { //range-based for loop - цикл по элементам library, book будет ссылкой на объект book внутри вектора
        book.print();
    }
}

//подсчет через switch
void countBooksSwitch(const vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (const auto& book : library) { 
        switch (book.getType()) { //возвращает тип книги из enum BookType
            case FICTION:
                fictionCount++;
                break;
            case TECHNICAL:
                technicalCount++;
                break;
        }
    }

    cout << "\nПодсчет через switch:\n";
    cout << "Художественных: " << fictionCount << endl;
    cout << "Технических: " << technicalCount << endl;
}

//подсчет через if
void countBooksIf(const vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (const auto& book : library) {
        if (book.getType() == FICTION) {
            fictionCount++;
        } else {
            technicalCount++;
        }
    }

    cout << "\nПодсчет через if:\n";
    cout << "Художественных: " << fictionCount << endl;
    cout << "Технических: " << technicalCount << endl;
}

int main() {
    vector<Book> library = {
        Book("Лев Толстой", "Война и мир", FICTION),
        Book("Фёдор Достоевский", "Преступление и наказание", FICTION),
        Book("Бьерн Страуструп", "Язык программирования C++", TECHNICAL),
        Book("Дональд Кнут", "Искусство программирования", TECHNICAL)
    };

    printLibrary(library);

    countBooksSwitch(library);
    countBooksIf(library);

    return 0;
}

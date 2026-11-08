#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Book: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Newspaper: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

class Library {
private:
    Book* books[10];
    Newspaper* newspapers[10];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book* book) {
        books[bookCount] = book;
        bookCount++;
    }

    void addNewspaper(Newspaper* newspaper) {
        newspapers[newspaperCount] = newspaper;
        newspaperCount++;
    }

    void displayCollection() {
        for (int i = 0; i < bookCount; i++) {
            books[i]->display();
            cout << endl;
        }

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i]->display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i]->getPages() > books[j]->getPages()) {
                    Book* temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[i]->getEdition() > newspapers[j]->getEdition()) {
                    Newspaper* temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getTitle() == title) {
                return books[i];
            }
        }

        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i]->getName() == name) {
                return newspapers[i];
            }
        }

        return nullptr;
    }
};

template <class T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int small = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }

        T temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

template <class T>
int linearSearch(T arr[], int size, T value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}

template <class T>
int binarySearch(T arr[], int size, T value) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (arr[middle] == value) {
            return middle;
        }

        if (value < arr[middle]) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    return -1;
}

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(&book1);
    library.addBook(&book2);
    library.addNewspaper(&newspaper1);
    library.addNewspaper(&newspaper2);

    cout << "Before Sorting:" << endl;
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "After Sorting:" << endl;
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook != nullptr) {
        cout << "Found Book:" << endl;
        foundBook->display();
    } else {
        cout << "Book not found." << endl;
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr) {
        cout << "Found Newspaper:" << endl;
        foundNewspaper->display();
    } else {
        cout << "Newspaper not found." << endl;
    }

    int numbers[5] = {8, 3, 6, 1, 5};

    selectionSort(numbers, 5);

    cout << "Sorted Numbers: ";

    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    cout << "Linear Search: " << linearSearch(numbers, 5, 6) << endl;
    cout << "Binary Search: " << binarySearch(numbers, 5, 6) << endl;

    return 0;
}

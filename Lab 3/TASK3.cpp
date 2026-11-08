#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    virtual void display() = 0;
};

class Book : public Item
{
public:
    string title, author;
    int pages;

    Book(string t = "", string a = "", int p = 0)
    {
        title = t;
        author = a;
        pages = p;
    }

    void display()
    {
        cout << title << " " << author
            << " " << pages << endl;
    }
};

class Newspaper : public Item
{
public:
    string name, date, edition;

    Newspaper(string n = "", string d = "", string e = "")
    {
        name = n;
        date = d;
        edition = e;
    }

    void display()
    {
        cout << name << " " << date
            << " " << edition << endl;
    }
};

class Library
{
public:
    Book books[10];
    Newspaper papers[10];
    int b = 0, n = 0;

    void addBook(Book x)
    {
        books[b] = x;
        b++;
    }

    void addNewspaper(Newspaper x)
    {
        papers[n] = x;
        n++;
    }

    void displayCollection()
    {
        for (int i = 0; i < b; i++)
            books[i].display();

        for (int i = 0; i < n; i++)
            papers[i].display();
    }

    void sortBooksByPages()
    {
        for (int i = 0; i < b - 1; i++)
        {
            for (int j = 0; j < b - 1; j++)
            {
                if (books[j].pages > books[j + 1].pages)
                {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (papers[j].edition > papers[j + 1].edition)
                {
                    Newspaper temp = papers[j];
                    papers[j] = papers[j + 1];
                    papers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string t)
    {
        for (int i = 0; i < b; i++)
        {
            if (books[i].title == t)
                return &books[i];
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(string x)
    {
        for (int i = 0; i < n; i++)
        {
            if (papers[i].name == x)
                return &papers[i];
        }
        return nullptr;
    }
};

int main()
{
    Book book1("The Catcher in the Rye",
        "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird",
        "Harper Lee", 324);

    Newspaper newspaper1("Washington Post",
        "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times",
        "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook != nullptr)
        foundBook->display();
    else
        cout << "Book not found\n";

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr)
        foundNewspaper->display();
    else
        cout << "Newspaper not found\n";

    return 0;
}
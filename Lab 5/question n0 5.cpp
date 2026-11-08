
#include <iostream>
#include <queue>
using namespace std;

class Printer
{
private:
    queue<string> q;

public:

    // Enqueue Function
    void enqueue(string document_name)
    {
        q.push(document_name);
        cout << "Document Added Successfully!" << endl;
    }

    // Dequeue Function
    void dequeue()
    {
        if (q.empty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Printing Document: " << q.front() << endl;
        q.pop();
    }

    // Front Function
    void front()
    {
        if (q.empty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Next Document: " << q.front() << endl;
    }

    // Display Function
    void display()
    {
        if (q.empty())
        {
            cout << "No Pending Documents!" << endl;
            return;
        }

        queue<string> temp = q;

        cout << "Pending Documents:" << endl;

        while (!temp.empty())
        {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main()
{
    Printer p;
    int choice;
    string name;

    do
    {
        cout << "\n1. Add Document";
        cout << "\n2. Print Document";
        cout << "\n3. Front Document";
        cout << "\n4. Display Documents";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Document Name: ";
            cin >> name;
            p.enqueue(name);
            break;

        case 2:
            p.dequeue();
            break;

        case 3:
            p.front();
            break;

        case 4:
            p.display();
            break;

        case 5:
            cout << "Printer System Closed!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
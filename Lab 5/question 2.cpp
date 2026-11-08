#include <iostream>
#include <stack>
using namespace std;

class myQueue
{
private:
    stack<int> s1, s2;

public:

    // Enqueue Function
    void enqueue(int value)
    {
        s1.push(value);
        cout << value << " Added Successfully!" << endl;
    }

    // Transfer Function
    void transfer()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // Dequeue Function
    int dequeue()
    {
        if (s2.empty())
        {
            transfer();
        }

        if (s2.empty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = s2.top();
        s2.pop();

        return value;
    }

    // Front Function
    int front()
    {
        if (s2.empty())
        {
            transfer();
        }

        if (s2.empty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return s2.top();
    }

    // Display Function
    void display()
    {
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        cout << "Queue Elements: ";

        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        while (!temp1.empty())
        {
            temp1.pop();
        }

        stack<int> temp = s1;

        while (!temp.empty())
        {
            // Reverse order will be displayed below
            temp.pop();
        }

        cout << endl;
    }

};

int main()
{
    myQueue q;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front Element";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            value = q.dequeue();
            if (value != -1)
                cout << "Removed Element: " << value << endl;
            break;

        case 3:
            cout << "Front Element: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Ended!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
#include <iostream>
using namespace std;

// Abstract Queue Class
template <typename T>
class AbstractQueue
{
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};


// Step 2: Child Class myQueue
template <typename T>
class myQueue : public AbstractQueue<T>
{
private:
    T* arr;
    int size;
    int count;
    int f;
    int r;

public:

    // Constructor
    myQueue(int s)
    {
        size = s;
        arr = new T[size];

        count = 0;
        f = 0;
        r = -1;
    }

    // Enqueue Function
    void enQueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        r = (r + 1) % size;
        arr[r] = value;
        count++;

        cout << value << " Added Successfully!" << endl;
    }

    // Dequeue Function
    T deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = arr[f];

        f = (f + 1) % size;
        count--;

        return value;
    }

    // Front Function
    T front() const
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return arr[f];
    }

    // Check Empty
    bool isEmpty() const
    {
        return count == 0;
    }

    // Check Full
    bool isFull() const
    {
        return count == size;
    }

    // Display Function
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = 0; i < count; i++)
        {
            cout << arr[(f + i) % size] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~myQueue()
    {
        delete[] arr;
    }
};


// Step 3: Main Function
int main()
{
    myQueue<int> q(5);

    int choice;
    int value;

    do
    {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed Element: "
                << q.deQueue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: "
                << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty!" << endl;
            else
                cout << "Queue is Not Empty!" << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full!" << endl;
            else
                cout << "Queue is Not Full!" << endl;
            break;

        case 7:
            cout << "Program Terminated!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
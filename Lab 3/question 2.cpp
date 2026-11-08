#include <iostream>
using namespace std;

template <class Type>
class List
{
protected:
    Type* arr;
    int maxSize, currentSize;

public:
    List(int m = 10, int c = 0)
    {
        maxSize = m;
        currentSize = c;
        arr = new Type[maxSize];
    }

    List(const List<Type>& obj)
    {
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;
        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = obj.arr[i];
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List()
    {
        delete[] arr;
    }
};

template <class Type>
class MyList : public List<Type>
{
public:
    MyList(int m = 10) : List<Type>(m) {}

    MyList(const MyList<Type>& obj) : List<Type>(obj) {}

    bool empty()
    {
        return this->currentSize == 0;
    }

    bool full()
    {
        return this->currentSize == this->maxSize;
    }

    int size()
    {
        return this->currentSize;
    }

    void addElementAtFirstIndex(Type value)
    {
        if (full())
            return;

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value)
    {
        if (full())
            return;

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd()
    {
        if (empty())
            return Type();

        this->currentSize--;
        return this->arr[this->currentSize];
    }

    void removeElementFromStart()
    {
        if (empty())
            return;

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool insertAt(int index, Type value)
    {
        if (full() || index < 0 || index > this->currentSize)
            return false;

        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    Type last()
    {
        if (empty())
            return Type();

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value)
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            if (this->arr[i] == value)
                return true;
        }

        return false;
    }

    void display()
    {
        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MyList<int> list;
    int choice, value, index;

    do
    {
        cout << "\n1. Add at Start";
        cout << "\n2. Add at End";
        cout << "\n3. Remove from Start";
        cout << "\n4. Remove from End";
        cout << "\n5. Insert at Index";
        cout << "\n6. Check Empty";
        cout << "\n7. Check Full";
        cout << "\n8. Show Size";
        cout << "\n9. Show Last Element";
        cout << "\n10. Search";
        cout << "\n11. Display";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        
            list.removeElementFromStart();
            break;

        
            if (!list.empty())
                cout << "Removed: "
                << list.removeElementFromEnd() << endl;
            else
                cout << "List is empty\n";
            break;

        
            cout << "Enter index and value: ";
            cin >> index >> value;

            if (list.insertAt(index, value))
                cout << "Value inserted\n";
            else
                cout << "Invalid index or list is full\n";
            break;

        
            cout << (list.empty() ? "List is empty\n" : "List is not empty\n");
            break;

        
            cout << (list.full() ? "List is full\n" : "List is not full\n");
            break;

        
            cout << "Size: " << list.size() << endl;
            break;

      
            if (!list.empty())
                cout << "Last: " << list.last() << endl;
            else
                cout << "List is empty\n";
            break;

        
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Value found\n";
            else
                cout << "Value not found\n";
            break;

        
            list.display();
            break;

        
            cout << "Program ended\n";
            break;

        default:
            cout << "Wrong choice\n";
        }

    } while (choice != 0);

    return 0;
}
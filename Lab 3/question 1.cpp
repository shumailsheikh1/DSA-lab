#include <iostream>
using namespace std;

template <class Type>
class List
{
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    // Parameterized constructor
    List(int m = 10, int c = 0)
    {
        maxSize = m;
        currentSize = c;
        arr = new Type[maxSize];
    }

    // Copy constructor
    List(const List<Type>& obj)
    {
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    // Pure virtual functions
    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    // Destructor
    virtual ~List()
    {
        delete[] arr;
    }
};

int main()
{
    return 0;
}
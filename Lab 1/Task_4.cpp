//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, int SIZE>
//int searchBinary(T arr[], T value)
//{
//    int start = 0;
//    int end = SIZE - 1;
//
//    while (start <= end)
//    {
//        int middle = start + (end - start) / 2;
//
//        if (arr[middle] == value)
//        {
//            return middle;
//        }
//
//        if (arr[middle] < value)
//        {
//            start = middle + 1;
//        }
//        else
//        {
//            end = middle - 1;
//        }
//    }
//
//    return -1;
//}
//
//template <typename T>
//void displayResult(int position, T value)
//{
//    if (position >= 0)
//    {
//        cout << "Element " << value
//            << " found at position " << position << endl;
//    }
//    else
//    {
//        cout << "Element " << value
//            << " does not exist in the array" << endl;
//    }
//}
//
//int main()
//{
//    int numbers[5] = { 11, 12, 22, 25, 64 };
//    int searchNumber = 22;
//
//    int position1 = searchBinary<int, 5>(numbers, searchNumber);
//    displayResult(position1, searchNumber);
//
//
//    float decimals[4] = { 0.57, 1.62, 2.71, 3.14 };
//    float searchDecimal = 2.71;
//
//    int position2 = searchBinary<float, 4>(decimals, searchDecimal);
//    displayResult(position2, searchDecimal);
//
//
//    string fruits[4] = { "apple", "banana", "grape", "orange" };
//    string searchFruit = "grape";
//
//    int position3 = searchBinary<string, 4>(fruits, searchFruit);
//    displayResult(position3, searchFruit);
//
//    return 0;
//}
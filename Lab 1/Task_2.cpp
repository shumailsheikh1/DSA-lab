//#include <iostream>
//#include <string>
//using namespace std;
//
//template <class T, int SIZE>
//void displayArray(T(&arr)[SIZE])
//{
//    for (int i = 0; i < SIZE; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//template <class T, int SIZE>
//void sortArray(T(&arr)[SIZE])
//{
//    for (int i = 0; i < SIZE - 1; i++)
//    {
//        int minIndex = i;
//
//        for (int j = i + 1; j < SIZE; j++)
//        {
//            if (arr[j] < arr[minIndex])
//            {
//                minIndex = j;
//            }
//        }
//
//        if (minIndex != i)
//        {
//            T swapValue = arr[i];
//            arr[i] = arr[minIndex];
//            arr[minIndex] = swapValue;
//        }
//    }
//}
//
//int main()
//{
//    int numbers[5] = { 64, 25, 12, 22, 11 };
//
//    cout << "Before sorting (integers): ";
//    displayArray(numbers);
//
//    sortArray(numbers);
//
//    cout << "After sorting (integers): ";
//    displayArray(numbers);
//
//    string fruits[4] = { "apple", "orange", "banana", "grape" };
//
//    cout << "\nBefore sorting (strings): ";
//    displayArray(fruits);
//
//    sortArray(fruits);
//
//    cout << "After sorting (strings): ";
//    displayArray(fruits);
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, int SIZE>
//int findElement(T(&arr)[SIZE], T target)
//{
//    for (int pos = 0; pos < SIZE; pos++)
//    {
//        if (arr[pos] == target)
//        {
//            return pos;
//        }
//    }
//
//    return -1;
//}
//
//template <typename T>
//void showResult(int position, T target)
//{
//    if (position >= 0)
//    {
//        cout << target << " is present at position "
//            << position << endl;
//    }
//    else
//    {
//        cout << target << " is not present in the array" << endl;
//    }
//}
//
//int main()
//{
//    int numbers[5] = { 64, 25, 12, 22, 11 };
//    int numberToFind = 12;
//
//    int result1 = findElement(numbers, numberToFind);
//    showResult(result1, numberToFind);
//
//
//    float values[4] = { 3.14, 2.71, 1.62, 0.57 };
//    float valueToFind = 1.62;
//
//    int result2 = findElement(values, valueToFind);
//    showResult(result2, valueToFind);
//
//
//    string fruits[4] = { "apple", "orange", "banana", "grape" };
//    string fruitToFind = "banana";
//
//    int result3 = findElement(fruits, fruitToFind);
//    showResult(result3, fruitToFind);
//
//    return 0;
//}
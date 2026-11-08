#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;

    int n, value, k;

    cout << "Enter Queue Size: ";
    cin >> n;

    // Input Queue Elements
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element: ";
        cin >> value;
        q.push(value);
    }

    cout << "Enter K: ";
    cin >> k;

    // Check K value
    if (k > n)
        k = n;

    // Reverse first K elements
    if (k > 1)
    {
        for (int i = 0; i < k; i++)
        {
            s.push(q.front());
            q.pop();
        }

        // Push stack elements back into queue
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        // Move remaining elements to the back
        for (int i = 0; i < n - k; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Display Queue
    cout << "Reversed Queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
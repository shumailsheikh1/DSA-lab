#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Package
{
public:
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliverySystem
{
private:
    queue<Package> q;

public:

    // Enqueue Function
    void enqueue(int id, string address, int start, int end)
    {
        Package p;

        p.id = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;

        q.push(p);

        cout << "Package Added Successfully!" << endl;
    }

    // Dequeue Function
    void dequeue()
    {
        if (q.empty())
        {
            cout << "No Packages Available!" << endl;
            return;
        }

        cout << "Package Delivered: " << q.front().id << endl;

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

        Package p = q.front();

        cout << "Package ID: " << p.id << endl;
        cout << "Address: " << p.address << endl;
        cout << "Start Time: " << p.startTime << endl;
        cout << "End Time: " << p.endTime << endl;
    }

    // Time To Deliver Function
    void timeToDeliver(int currentTime)
    {
        if (q.empty())
        {
            cout << "No Packages Available!" << endl;
            return;
        }

        while (!q.empty())
        {
            Package p = q.front();

            if (currentTime <= p.endTime)
            {
                if (currentTime >= p.startTime)
                {
                    cout << "Package " << p.id
                        << " Can Be Delivered!" << endl;

                    dequeue();
                }
                else
                {
                    cout << "Package " << p.id
                        << " Delivery Time Not Started Yet!" << endl;
                }

                break;
            }
            else
            {
                cout << "Package " << p.id
                    << " Expired!" << endl;

                q.pop();
            }
        }
    }

    // Display Function
    void display()
    {
        if (q.empty())
        {
            cout << "No Pending Packages!" << endl;
            return;
        }

        queue<Package> temp = q;

        cout << "\nPending Packages:\n";

        while (!temp.empty())
        {
            Package p = temp.front();

            cout << "\nPackage ID: " << p.id;
            cout << "\nAddress: " << p.address;
            cout << "\nStart Time: " << p.startTime;
            cout << "\nEnd Time: " << p.endTime << endl;

            temp.pop();
        }
    }
};

// Main Function
int main()
{
    DeliverySystem d;

    int choice, id, start, end, currentTime;
    string address;

    do
    {
        cout << "\n===== PACKAGE DELIVERY SYSTEM =====";

        cout << "\n1. Add Package";
        cout << "\n2. Deliver Package";
        cout << "\n3. Front Package";
        cout << "\n4. Display Packages";
        cout << "\n5. Check Delivery Time";
        cout << "\n6. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Package ID: ";
            cin >> id;

            cout << "Enter Address: ";
            cin >> address;

            cout << "Enter Start Time: ";
            cin >> start;

            cout << "Enter End Time: ";
            cin >> end;

            if (start > end)
            {
                cout << "Invalid Time Window!";
                break;
            }

            d.enqueue(id, address, start, end);
            break;

        case 2:
            d.dequeue();
            break;

        case 3:
            d.front();
            break;

        case 4:
            d.display();
            break;

        case 5:
            cout << "Enter Current Time: ";
            cin >> currentTime;

            d.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "Delivery System Closed!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 6);

    return 0;
}
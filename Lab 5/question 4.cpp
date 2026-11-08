#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> tickets;
    int choice, id;

    do
    {
        cout << "\n1. Add New Ticket";
        cout << "\n2. Resolve Ticket";
        cout << "\n3. Next Ticket";
        cout << "\n4. Display Pending Tickets";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> id;

            if (id >= 1000 && id <= 9999)
            {
                tickets.push(id);
                cout << "Ticket Added Successfully!";
            }
            else
            {
                cout << "Invalid Ticket ID!";
            }
            break;

        case 2:
            if (!tickets.empty())
            {
                cout << "Resolved Ticket: "
                    << tickets.front();
                tickets.pop();
            }
            else
            {
                cout << "No Pending Tickets!";
            }
            break;

        case 3:
            if (!tickets.empty())
                cout << "Next Ticket: " << tickets.front();
            else
                cout << "No Pending Tickets!";
            break;

        case 4:
        {
            if (tickets.empty())
            {
                cout << "No Pending Tickets!";
            }
            else
            {
                queue<int> temp = tickets;

                cout << "Pending Tickets: ";

                while (!temp.empty())
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }
            }
            break;
        }

        case 5:
            cout << "Program Ended!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
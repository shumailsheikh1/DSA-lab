#include <iostream>
using namespace std;

class Course
{
public:
    virtual void duration() = 0;
};

class OnlineCourse : public Course
{
public:
    int weeks, hoursPerWeek;

    OnlineCourse(int w, int h)
    {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration()
    {
        cout << "Online Course Duration: "
            << weeks << " weeks" << endl;
        cout << "Hours per week: "
            << hoursPerWeek << endl;
    }
};

class OfflineCourse : public Course
{
public:
    int months, hoursPerDay;

    OfflineCourse(int m, int h)
    {
        months = m;
        hoursPerDay = h;
    }

    void duration()
    {
        cout << "Offline Course Duration: "
            << months << " months" << endl;
        cout << "Hours per day: "
            << hoursPerDay << endl;
    }
};

int main()
{
    OnlineCourse online(8, 5);
    OfflineCourse offline(3, 4);

    online.duration();
    offline.duration();

    return 0;
}
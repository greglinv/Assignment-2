//Name: Gregory Linville

#include <iostream>
#include "single_linked_list.h"
#include "Employee.h"
using namespace std;

int main()
{
    Professional prof("John Doe", 1234, 5000, 20);
    Nonprofessional nonprof("Jane Smith", 5678, 15, 80);

    // Set hours worked for nonprofessional employee
    nonprof.setHoursWorked(40);

    // Calculate weekly salary, health care contributions, and vacation days for each employee
    cout << "Professional employee " << prof.getName() << " (ID: " << prof.getID() << ")\n";
    cout << "Weekly salary: $" << prof.calculateWeeklySalary() << "\n";
    cout << "Health care contributions: $" << prof.computeHealthCareContributions() << "\n";
    cout << "Vacation days earned: " << prof.computeVacationDays() << "\n\n";

    cout << "Nonprofessional employee " << nonprof.getName() << " (ID: " << nonprof.getID() << ")\n";
    cout << "Weekly salary: $" << nonprof.calculateWeeklySalary() << "\n";
    cout << "Health care contributions: $" << nonprof.computeHealthCareContributions() << "\n";
    cout << "Vacation days earned: " << nonprof.computeVacationDays() << "\n\n";

    Single_Linked_List list;
    list.push_front("red");
    cout << list.front();

    list.push_front("blue");
    cout << list.front();

    list.push_back("green");
    list.push_back("teal");
    //list should be blue ,red, green, teal

    cout << list.find("red");
    cout << list.front();
    list.insert(1, "purple");

    list.pop_front();
    cout << list.front();
    return 0;
}

#pragma once
#include <string>
#include <iostream>

using namespace std;


#ifndef Employee_H_
#define Employee_H_

class Employee {
public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual ~Employee() {}

    virtual double calculateWeeklySalary() = 0;
    virtual double computeHealthCareContributions() = 0;
    virtual int computeVacationDays() = 0;
    string getName() { return name; }
    int getID() { return id; }

protected:
    string name;
    int id;
};

#endif

#ifndef Professional_H_
#define Professional_H_
class Professional : public Employee {
public:
    Professional(string name, int id, double monthlySalary, int vacationDays)
        : Employee(name, id), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

    double calculateWeeklySalary() override {
        return monthlySalary / 4; // 4 weeks in a month
    }

    double computeHealthCareContributions() override {
        return monthlySalary * 0.05; // 5% monthly salary
    }

    int computeVacationDays() override {
        return vacationDays / 12; // 12 months in a year
    }

private:
    double monthlySalary;
    int vacationDays;
};

#endif

#ifndef NonProfessional_H_
#define NonProfessional_H_
class Nonprofessional : public Employee {
public:
    Nonprofessional(string name, int id, double hourlyRate, int vacationHours)
        : Employee(name, id), hourlyRate(hourlyRate), vacationHours(vacationHours) {}

    double calculateWeeklySalary() override {
        return hourlyRate * hoursWorked;
    }

    double computeHealthCareContributions() override {
        return hoursWorked * 0.02; // 2% hours worked
    }

    int computeVacationDays() override {
        return vacationHours / 8; // 8 hours in a day
    }

    void setHoursWorked(int hours) { hoursWorked = hours; }

private:
    double hourlyRate;
    int vacationHours;
    int hoursWorked;
};

#endif
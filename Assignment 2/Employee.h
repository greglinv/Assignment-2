#pragma once
#include <string>
#include <iostream>

using namespace std;


#ifndef Employee_H_
#define Employee_H_

//Create Base class
class Employee {
public:
    Employee();
    Employee(string name, int id) : name(name), id(id) {}

    void setName(string name) { name = name; }
    void setID(int id) { id = id; }

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

//Create the Professional sub class
class Professional : public Employee {
public:
    Professional();
    Professional(string name, int id, double monthlySalary, int vacationDays)
        : Employee(name, id), monthlySalary(monthlySalary), vacationDays(vacationDays) {}

    void setMontlySalary(double m) { monthlySalary = m; }
    void setName(string n) { name = n; }
    void setID(int i) { id = i; }
    void setVacationDays(int v) { vacationDays = v; }

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
//Create the Nonprofessional subclass
class Nonprofessional : public Employee {
public:
    Nonprofessional();
    Nonprofessional(string name, int id, double hourlyRate, int vacationHours)
        : Employee(name, id), hourlyRate(hourlyRate), vacationHours(vacationHours) {}

    void setName(string n) { name = n; }
    void setID(int i) { id = i; }
    void setHoursWorked(int hours) { hoursWorked = hours; }
    void setVacationHours(int vhours) { vacationHours = vhours; }
    void setHourlyRate(int rate) { hourlyRate = rate; }

    double calculateWeeklySalary() override {
        return hourlyRate * hoursWorked;
    }

    double computeHealthCareContributions() override {
        return hoursWorked * 0.02; // 2% hours worked
    }

    int computeVacationDays() override {
        return vacationHours / 8; // 8 hours in a day
    }

    

private:
    double hourlyRate;
    int vacationHours;
    int hoursWorked;
};

#endif
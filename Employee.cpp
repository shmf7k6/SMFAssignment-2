//Sadam Farah
//CS303
//Assignment 2
//10-18-2022


#include<iostream>
using namespace std;

//Class employee
class Employee {
	//private data members
private:
	string name;
	string address;

public:
	//constructor
	Employee(string nm, string add)
	{
		name = nm;
		address = add;
	}

	//A print method to output class data
	void print()
	{
		cout << "Name : " << name << endl << "Address : " << address << endl;
	}

	//Virtual functions
	virtual double weeklySalary() = 0;
	virtual int vacations() = 0;
	virtual double insurance() = 0;
};

//A professional employee class that inherits from employee class
class ProfessionalEmployee : public Employee
{
private:
	double monthlySalary;

public:
	//Constructor
	ProfessionalEmployee(string nm, string add, double mSal) : Employee(nm, add)
	{
		monthlySalary = mSal;
	}

	//overriding the virtual methods of parent class
	double weeklySalary()
	{
		return monthlySalary / 4;
	}

	int vacations()
	{
		return 23;
	}

	double insurance()
	{
		return (2.0 * monthlySalary) / 3.0;
	}
};

//A non professional employee class that inherits from employee class
class NonProfessionalEmployee : public Employee
{
private:
	double timeWorked,hourlyRate;


public:
	//constructor
	NonProfessionalEmployee(string nm, string add, double wTime, double hRate) : Employee(nm, add)
	{
		timeWorked = wTime;
		hourlyRate = hRate;
	}

	//overriding the virtual methods of parent class
	double weeklySalary()
	{
		return timeWorked * hourlyRate;
	}

	int vacations()
	{
		return 12;
	}

	double insurance()
	{
		return weeklySalary() / 2.0;
	}
};

//Main function
int main()
{
	//Creating object of Professional employee and displaying his data
	ProfessionalEmployee obj("Daniel", "XYZ", 40000);
	obj.print();
	cout << "Weekly Salary: " << obj.weeklySalary() << endl;
	cout << "Insurance: " << obj.insurance() << endl;
	cout << "Vacations: " << obj.vacations() << endl << endl;

	//Creating object of non professional employee and showing the data
	NonProfessionalEmployee obj1("John", "ABC",80, 1300);
	obj1.print();
	cout << "Weekly Salary: " << obj1.weeklySalary() << endl;
	cout << "Insurance: " << obj1.insurance() << endl;
	cout << "Vacations: " << obj1.vacations() << endl << endl;
}
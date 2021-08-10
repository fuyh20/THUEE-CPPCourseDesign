// 定义了所有系统类中的成员函数

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include "course.h"
#include "student.h"
#include "system.h"

using namespace std;

const string Department[] =
{
	"School_of_architecture", "School_of_civil_engineering_and_water_conservancy", "School_of_environment", "Department_of_mechanical_engineering", "Department_of_precision_instrument", "Department_of_dynamic_engineering", "School_of_vehicle_and_transportation", "Department_of industrial_engineering",
	"School_of_aerospaceand_aeronautics", "Department_of_electronics", "Department_of_computer", "Department_of_automation", "School_of_integrated_circuits", "School_of_software", "School_of_cross_information", "School_of_materials",
	"Department_of_electrical_engineering", "Department_of_Engineering_Physics", "Department_of_chemical_engineering", "Department_of_mathematics", "Department_of_physics", "School_of_life", "School_of_medicine", "School_of_economicsand_management", "School_of_humanities", "School_of_Social_Sciences",
	"School_of_law", "School_of_journalism", "School_of_fine_arts", "Xinya_College", "Zhili_College", "Rixin_College", "Weiyang_College", "Tanwei_College", "Xingjian_College", "Qiuzhen_College"
};

GradeSystem::GradeSystem(ifstream& data) 
{
	int n;
	if (data >> n)
	{
		students = vector<Student>(n);
		for (int i = 0; i < n; i++)
		{
			data >> students[i];
		}
	}
}

void GradeSystem::menu()
{
	cout << "*****************************************************************" << endl;
	cout << "*                Student score management system                *" << endl;
	cout << "*****************************************************************" << endl;
	cout << "------------------------1.Student system-------------------------" << endl; 
	cout << "---------------------2.Administrator system----------------------" << endl;
	cout << "------------------------3.Exit the system------------------------" << endl;
}

void GradeSystem::addStudent()
{
	string name, sex, studentID; int department, i;
	for (i = 0; ; ++i)
	{
		cout << "Please enter the name of the student:"; cin >> name;
		cout << "Please enter gender:"; cin >> sex;
		cout << "Please enter the student number:"; cin >> studentID;
		cout << "Please enter the department number:"; cin >> department;
		cout << "--------------------------------" << endl;
		students.push_back(Student(name, sex, studentID, department));
		students[i].addCourse();
		students[i].computeGPAandCredit();
		char ch;
		while (1)
		{
			cout << "Do you need to continue adding students(y/n):"; cin >> ch;
			if (ch == 'n') break;
			else if (ch != 'y') cout << "Please re-enter(y/n):";
			else break;
		}
		if (ch == 'n') break;
	}
	cout << "A total of " << i+1 << " student has been added" << endl;
	cout << "--------------------------------" << endl;
	sorted();
}

void GradeSystem::setStudent()
{
	int flag = 0;
	string sex, studentID; int department;
	cout << "Please enter the student number of the student who needs to modify the information:"; cin >> studentID;
	for (int i = 0; i < int(students.size()); ++i)
	{
		if (students[i].studentID == studentID)
		{
			cout << "Please input the revised department number:"; cin >> department;
			students[i].department = Department[department];
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << "Wrong student number input" << endl;
}

void GradeSystem::inqurie()
{
	int flag = 0;
	string name, studentID;
	cout << "Please enter the student number of the student you want to query:"; cin >> studentID;
	for (int i = 0; i < int(students.size()); ++i)
	{
		if (students[i].studentID == studentID)
		{
			cout << "The student's transcript is:" << endl;
			students[i].printSchoolReport();
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << "There is no such person" << endl;
}

bool comp(const Student& a, const Student& b) 
{
	return a.getGPA() > b.getGPA();
}


void GradeSystem::sorted()
{
	for (int i = 0; i<int(students.size()); i++)
		students[i].computeGPAandCredit();
	sort(students.begin(), students.end(), comp);
	for (int i = 0; i < int(students.size()); i++)
	{
		students[i].rank = i + 1;
	}
}

void GradeSystem::print()
{
	cout << "The information of all students is:" << endl; int i = 0;
	for (i = 0; i < int(students.size()); i++)
	{
		students[i].printInfo();
	}
	cout << "There is " << i << " student in total" << endl;
}
int GradeSystem::getStudentNumber()
{
	return int(students.size());
}

void GradeSystem::exit(ofstream& data)
{
	sorted();
	studentNumber = int(students.size());
	data << studentNumber << endl;
	for (int i = 0; i < int(students.size()); i++)
	{
		data << students[i];
		for (int j = 0; j<int(students[i].courses.size()); j++)
			delete students[i].courses[j];
	}
}

GradeSystem::~GradeSystem() {};
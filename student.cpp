// 定义了所有学生类中的成员函数

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>

#include "course.h"
#include "student.h"

using namespace std;

const string Department[] =
{
	"School_of_architecture", "School_of_civil_engineering_and_water_conservancy", "School_of_environment", "Department_of_mechanical_engineering", "Department_of_precision_instrument", "Department_of_dynamic_engineering", "School_of_vehicle_and_transportation", "Department_of industrial_engineering",
	"School_of_aerospaceand_aeronautics", "Department_of_electronics", "Department_of_computer", "Department_of_automation", "School_of_integrated_circuits", "School_of_software", "School_of_cross_information", "School_of_materials",
	"Department_of_electrical_engineering", "Department_of_Engineering_Physics", "Department_of_chemical_engineering", "Department_of_mathematics", "Department_of_physics", "School_of_life", "School_of_medicine", "School_of_economicsand_management", "School_of_humanities", "School_of_Social_Sciences",
	"School_of_law", "School_of_journalism", "School_of_fine_arts", "Xinya_College", "Zhili_College", "Rixin_College", "Weiyang_College", "Tanwei_College", "Xingjian_College", "Qiuzhen_College"
};

Student::Student(string name, string sex, string ID, int department) :name(name), sex(sex), studentID(ID), department(Department[department])
{
	totalCredit = 0;
	rank = 0;
	courses = vector <Course*>();
}

void Student::printSchoolReport()
{
	cout << name <<" " << sex <<" " << studentID <<" " << department << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Course number       Course name                Credits    Grade   GPA" << endl;
	for (int i = 0; i < int(courses.size()); i++)
	{
		courses[i]->print();
	}
	cout << "------------------------------------------------------------------------" << endl;
	cout << "GPA: "<< setprecision(2)<<fixed<<GPA << "                   " <<"Ranking: "<< rank << "                " <<"Total Credit: " << totalCredit << endl;
}
void Student::addCourse()
{
	string id, name, grade, type; int credit, i; double gpa;
	for (i = 1; ; ++i)
	{
		cout << "Please input course type.If W, select PF(PF/GPA):"; cin >> type;
		if (type == string("PF"))
		{
			cout << "Please enter the course number:"; cin >> id;
			cout << "Please enter the course name:"; cin >> name;
			cout << "Please enter credits:"; cin >> credit;
			cout << "Please enter the score(P/F/W):"; cin >> grade;
			courses.push_back(new PF_Course(id, name, credit, grade));
		}
		else if (type == string("GPA"))
		{
			cout << "Please enter the course number:"; cin >> id;
			cout << "Please enter the course name:"; cin >> name;
			cout << "Please enter credits:"; cin >> credit;
			cout << "Please enter the score:"; cin >> grade;
			cout << "Please enter the GPA:"; cin >> gpa;
			courses.push_back(new GPA_Course(id, name, credit, grade, gpa));
		}
		char ch;
		while (1)
		{
			cout << "Do you need to continue adding courses(y/n):"; cin >> ch;
			if (ch == 'n') break;
			else if (ch != 'y') cout << "Please re-enter(y/n):";
			else break;
		}
		if (ch == 'n') break;
	}
	computeGPAandCredit();
	cout << "A total of " << i << " Courses" << endl;
	cout << "---------------------------------------" << endl;
}

void Student::reduceCourse()
{
	string id; int i;
	for (i = 0;; i++)
	{
		cout << "Please enter the course number of the course to be deleted:"; cin >> id;
		for (vector<Course*>::iterator iter = courses.begin(); iter != courses.end(); ++iter)
		{
			if ((*iter)->getID() == id)
			{
				courses.erase(iter);
				cout << "Course deleted successfully" << id << endl;
			}
		}
		char ch;
		while (1)
		{
			cout << "Do you want to continue deleting courses（y/n）："; cin >> ch;
			if (ch == 'n') break;
			else if (ch != 'y') cout << "Please re-enter(y/n):";
			else break;
		}
		if (ch == 'n') break;
	}
	computeGPAandCredit();
	cout << "A total of " << i << " course was deleted for the student" << endl;
	cout << "-----------------------------------" << endl;
}

void Student::computeGPAandCredit()
{
	totalCredit = 0;
	double totalGPA = 0;
	for (int i = 0; i < int(courses.size()); ++i)
	{
		if (courses[i]->getType() == "GPA")
		{
			totalGPA += courses[i]->getgpa() * courses[i]->getCredit();
			totalCredit += courses[i]->getCredit();
		}
	}
	GPA = totalGPA / totalCredit;
	for (int i = 0; i < int(courses.size()); ++i)
		if (courses[i]->getType() == "PF")
			totalCredit += courses[i]->getCredit();
}

void Student::printInfo()
{
	cout << name << " " << sex << " " << studentID << " " << department << endl;
}

double Student::getGPA() const
{
	return GPA;
}

string Student::getID() const
{
	return studentID;
}

Student::~Student(){}

ofstream& operator <<(ofstream& out, Student& s)
{
	s.courseNumber = s.courses.size();
	out << s.name << " " << s.sex << " " << s.studentID << " " << s.department << " " << s.courseNumber << " ";
	for (int i = 0; i < int(s.courses.size()); ++i)
		s.courses[i]->toFile(out);
	out << s.GPA <<" " << s.rank << " " << s.totalCredit << endl;
	return out;
}

ifstream& operator >>(ifstream& in,  Student& s)
{
	string id, name, grade, type; int credit; double gpa;
	in >> s.name >> s.sex >> s.studentID >> s.department >> s.courseNumber;
	int n; 
	for (int i = 0; i < s.courseNumber; ++i)
	{
		in >> n;
		if (n == 0)
		{
			in >> id >> name >> credit >> grade;
			s.courses.push_back(new PF_Course(id, name, credit, grade));
		}
		else if (n == 1)
		{
			in >> id >> name >> credit >> grade >> gpa;
			s.courses.push_back(new GPA_Course(id, name, credit, grade, gpa));
		}
	}
	in >> s.GPA >> s.rank >> s.totalCredit;
	return in;
}
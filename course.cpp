// 定义了所有课程类中的成员函数

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>

#include "course.h"

using namespace std;


Course::Course(string id, string name, int credit, string grade) :id(id), name(name), credit(credit), grade(grade) { }
Course::~Course() {}


PF_Course::PF_Course(string id, string name, int credit, string grade) :Course(id, name, credit, grade), type("PF") { }

void PF_Course::print()
{
	cout << id << setw(24) << name << setw(19) << credit << setw(10) << grade << setw(8) << "N/A" << endl;
}

void PF_Course::toFile(ofstream& file)
{
	file << 0 << " ";
	file << id << " " << name << " " << credit << " " << grade << " ";
}


string PF_Course::getID() 
{
	return id;
}

string PF_Course::getType() 
{
	return type;
}

double PF_Course::getgpa() 
{
	return 0;
}

int PF_Course::getCredit() 
{ 
	return credit;
}

PF_Course::~PF_Course() {}


GPA_Course::GPA_Course(string id, string name, int credit, string grade, double gpa) :Course(id, name, credit, grade), gpa(gpa), type("GPA") {}

 void GPA_Course::print()
{
	 cout << id <<setw(24)<< name << setw(19) << credit << setw(10) << grade << setw(8) << setprecision(1) << fixed << gpa << endl;
}

void GPA_Course::toFile(ofstream& file)
{
	file << 1 << " ";
	file << id << " " << name << " " << credit << " " << grade << " " << gpa << " ";
}

string GPA_Course::getID() 
{
	return id; 
}

string GPA_Course::getType() 
{
	return type;
}

double GPA_Course::getgpa() 
{
	return gpa;
}

int GPA_Course::getCredit()
{
	return credit;
}

GPA_Course::~GPA_Course() {}

GPAorPF::GPAorPF() {};
GPAorPF::~GPAorPF() {};
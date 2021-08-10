// 声明了学生类

#pragma once

#include <iostream>

using namespace std;

class Student
{
private:
	string name, sex, studentID, department;//学生的姓名、性别、学号、院系
	int rank, totalCredit;// 排名和课程总学分
	double GPA;// 学生的GPA
	vector <Course*> courses; // 学生所有的课程信息

public:
	Student(string name="", string sex="", string ID="", int department=0); // 学生的构造函数
	friend class GradeSystem; // 将成绩系统声明为学生类的友元类
	void printSchoolReport(); // 打印学生成绩单
	void addCourse(); // 为该同学添加课程
	void reduceCourse(); // 为同学减少课程
	void computeGPAandCredit(); // 计算该学生的总成绩和学分
	void printInfo(); // 打印学生的基本信息
	double getGPA() const; // 获取学生的成绩
	string getID() const; // 获取学生的学号
	friend ofstream& operator <<(ofstream& out, Student& s); // 重载运算符将学生信息存储到文件中
	friend ifstream& operator >>(ifstream& in,  Student& s); // 重载运算符读取文件中的信息
	int courseNumber = 0;
	~Student();
};
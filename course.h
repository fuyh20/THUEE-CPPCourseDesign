//所有关于课程的类
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Course
{
protected:
	string id, name, grade;//课程号、课程名、成绩
	int credit;//学分

public:
	Course(string id="", string name="", int credit=0, string grade="");// 构造函数
	virtual void print() = 0;// 打印该课程的所有信息
	virtual void toFile(ofstream& file) = 0;// 将课程信息导入文件
	virtual string getID() = 0; // 得到课程号的接口
	virtual string getType() = 0; // 得到课程类型
	virtual double getgpa() = 0; // 得到课程的gpa
	virtual int getCredit() = 0;// 得到课程的学分
	virtual ~Course() = 0; // 析构函数
};

// PF课程
class PF_Course :public Course
{
private:
	string type;
	string teachername;

public:
	PF_Course(string id="", string name="", int credit=0, string grade="");
	virtual void print();
	virtual void toFile(ofstream& file);
	virtual string getID();
	virtual string getType();
	virtual double getgpa();
	virtual int getCredit();
	virtual ~PF_Course();
};

//GPA课程
class GPA_Course :public Course
{
private:
	double gpa; string type; string teachername;

public:
	GPA_Course(string id="", string name="", int credit=0, string grade="", double gpa=0);
	virtual void print();
	virtual void toFile(ofstream& file);
	virtual string getID();
	virtual string getType();
	virtual double getgpa();
	virtual int getCredit();
	virtual  ~GPA_Course();
};

class GPAorPF :public GPA_Course, public PF_Course
{
public:
	GPAorPF();
	~GPAorPF();
};
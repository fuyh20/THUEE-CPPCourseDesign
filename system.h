// 声明了成绩系统类
#pragma once

#include <iostream>
#include <vector>

using namespace std;


class GradeSystem
{
public:
	GradeSystem(ifstream& data); // 初始化系统，并将文件中的学生信息导入
	void menu(); // 生成菜单
	void addStudent(); // 添加学生
	void setStudent(); // 修改学生的基本信息
	void inqurie(); // 查询学生的成绩单
	void sorted(); // 将学生按成绩排序
	void print(); // 打印所有学生信息
	int getStudentNumber(); // 得到当前的学生数量
	vector <Student> students; // vector学生
	void exit(ofstream& data); // 退出系统，并把所有信息保存到文件
	~GradeSystem();
	int studentNumber = 0;
};

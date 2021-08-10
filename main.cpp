// 主函数

#include <iostream>
#include <cstdlib>
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

string file = "D:\\data.txt"; // 学生信息储存的文件路径

int main()
{
	int mode, submode, flag = 0;
	string id;	// 一些暂存的变量

	// 系统初始化
	ifstream data1(file);
	GradeSystem System(data1);
	data1.close();

	// 进入程序
	while (1)
	{
		System.menu();
		cout << "Please select mode: ";
		cin >> mode;
		system("cls");
		switch (mode)
		{
		// 查询学生成绩
		case 1: 
			System.inqurie();
			break;
		// 管理学生成绩
		case 2:
			int k;
			cout << "------Welcome Log in Administrator system------" << endl;
			cout << "If you want to add students, please enter the '1'" << endl;
			cout << "If you want to modify students, please enter the '2'" << endl;
			cout << "If you want to add or reduce courses for a studnet, please enter the '3'" << endl;
			cout << "If you want to know students who are registered,please enter the '4'" << endl;
			cin >> k;
			switch (k)
			{
			// 添加学生
			case 1:
				system("cls");
				System.addStudent();
				break;
			// 修改学生信息
			case 2:
				system("cls");
				System.setStudent();
				break;
			// 为特定学生添加课程
			case 3:
				system("cls");
				int m, n;
				cout << "Please enter the StudentID to add or reduce courses for hte students: " << endl;
				cin >> id;
				cout << "add(1) or reduce(2): ";
				cin >> m;
				for (int i = 0; i < System.getStudentNumber(); i++)
				{
					if (id == System.students[i].getID())
					{
						flag = 1;
						n = i;
						break;
					}
				}
				if (flag)
				{
					if (m == 1)
						System.students[n].addCourse();
					if (m == 2)
						System.students[n].reduceCourse();
				}
				if (!flag)
					cout << "There is no such person" << endl;
				System.sorted();
				break;
			// 查询系统中的所有学生
			case 4:
				System.print();
				break;
			default:
				break;
			}
			break;
		default:	
			break;
		}

		// 退出系统
		if (mode == 3)
			break;
		cout << "Enter 1 to exit the system and 2 to return to the menu: ";
		cin >> submode;
		if (submode == 1)
			break;
		else if (submode == 2)
			system("cls");
	}
	// 保存文件并退出
	ofstream data2(file);
	System.exit(data2);
	data2.close();
	return 0;
}
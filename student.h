// ������ѧ����

#pragma once

#include <iostream>

using namespace std;

class Student
{
private:
	string name, sex, studentID, department;//ѧ�����������Ա�ѧ�š�Ժϵ
	int rank, totalCredit;// �����Ϳγ���ѧ��
	double GPA;// ѧ����GPA
	vector <Course*> courses; // ѧ�����еĿγ���Ϣ

public:
	Student(string name="", string sex="", string ID="", int department=0); // ѧ���Ĺ��캯��
	friend class GradeSystem; // ���ɼ�ϵͳ����Ϊѧ�������Ԫ��
	void printSchoolReport(); // ��ӡѧ���ɼ���
	void addCourse(); // Ϊ��ͬѧ��ӿγ�
	void reduceCourse(); // Ϊͬѧ���ٿγ�
	void computeGPAandCredit(); // �����ѧ�����ܳɼ���ѧ��
	void printInfo(); // ��ӡѧ���Ļ�����Ϣ
	double getGPA() const; // ��ȡѧ���ĳɼ�
	string getID() const; // ��ȡѧ����ѧ��
	friend ofstream& operator <<(ofstream& out, Student& s); // �����������ѧ����Ϣ�洢���ļ���
	friend ifstream& operator >>(ifstream& in,  Student& s); // �����������ȡ�ļ��е���Ϣ
	int courseNumber = 0;
	~Student();
};
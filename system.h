// �����˳ɼ�ϵͳ��
#pragma once

#include <iostream>
#include <vector>

using namespace std;


class GradeSystem
{
public:
	GradeSystem(ifstream& data); // ��ʼ��ϵͳ�������ļ��е�ѧ����Ϣ����
	void menu(); // ���ɲ˵�
	void addStudent(); // ���ѧ��
	void setStudent(); // �޸�ѧ���Ļ�����Ϣ
	void inqurie(); // ��ѯѧ���ĳɼ���
	void sorted(); // ��ѧ�����ɼ�����
	void print(); // ��ӡ����ѧ����Ϣ
	int getStudentNumber(); // �õ���ǰ��ѧ������
	vector <Student> students; // vectorѧ��
	void exit(ofstream& data); // �˳�ϵͳ������������Ϣ���浽�ļ�
	~GradeSystem();
	int studentNumber = 0;
};

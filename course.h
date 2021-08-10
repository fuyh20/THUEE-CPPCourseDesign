//���й��ڿγ̵���
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Course
{
protected:
	string id, name, grade;//�γ̺š��γ������ɼ�
	int credit;//ѧ��

public:
	Course(string id="", string name="", int credit=0, string grade="");// ���캯��
	virtual void print() = 0;// ��ӡ�ÿγ̵�������Ϣ
	virtual void toFile(ofstream& file) = 0;// ���γ���Ϣ�����ļ�
	virtual string getID() = 0; // �õ��γ̺ŵĽӿ�
	virtual string getType() = 0; // �õ��γ�����
	virtual double getgpa() = 0; // �õ��γ̵�gpa
	virtual int getCredit() = 0;// �õ��γ̵�ѧ��
	virtual ~Course() = 0; // ��������
};

// PF�γ�
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

//GPA�γ�
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
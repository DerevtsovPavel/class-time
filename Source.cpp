//�����: �������� ����� ���-22
#include <iostream>
#include "c_time.h"


#pragma once

using namespace std;

int main() {
	setlocale(0,"Russian");

	Time *a1=new Time(10,20,30);

	Test();

	//������ ��������
	// -> --- ������������� � ��������� � ������ �������
	string s = a1->to_str();
	cout << "�����: " << s<<endl;

	try {
		a1->add_seconds(32000);//8 53 20
	}
	catch (const exception& error)
	{
		cout << error.what() << endl;
		return -1;
	}
	s = a1->to_str();
	cout << "�����: " << s<<endl;

	int t_h = a1->get_hours();
	cout << "������ " << t_h << " �����" << endl;

	cout << "������� ������ �����? ";
	cin >> t_h;
	try {
		a1->set_hours(t_h);
	}
	catch(const exception &error) {
		cout << error.what() << endl;
		return -1;
	}
	s = a1->to_str();
	cout << "�����: " << s << endl;

	cout << "������� �����" << endl;
	cout << "����: ";
	cin >> t_h;
	int t_m;
	int t_s;
	cout << "������: ";
	cin >> t_m;
	cout << "�������: ";
	cin >> t_s;

	try {
		a1->set_time(t_h, t_m, t_s);
	}
	catch (const exception& error) {
		cout << error.what() << endl;
		return -1;
	}
	s = a1->to_str();
	cout << "�����: " << s << endl;

	t_s = a1->to_seconds();
	cout << "� �������� ��� " << t_s << endl;

	delete a1;

	Time* ob = new Time[3]{ Time(2,4,6), Time(0,9,40)};//������� ������ ��������
	// Time* ob = new Time[3]{ Time(2,4,6), Time(0,9,40) };//������� ������ �������� 
	// Time[0] h=2 m=4 s=6
	// Time[1] h=0 m=9 s=40
	// Time[2] h=0 m=0 s=0


	//������� ����� ��� ��������
	s = ob[0].to_str();
	cout << "����� 0: " << s << endl;

	s = ob[1].to_str();
	cout << "����� 1: " << s << endl;

	s = ob[2].to_str();
	cout << "����� 2: " << s << endl;

	//�������� ���� �� ��� ��������
	t_h = ob[0].get_hours();
	int t_h1, t_h2;
	t_h1 = ob[1].get_hours();
	t_h2 = ob[2].get_hours();

	int sum;
	sum = t_h + t_h1 + t_h2;//���������� ����
	ob[2].add_minutes(sum);//��������� ����� � ������ 3�� �������
	s = ob[2].to_str();
	cout << "����� 2: " << s << endl;

	sum=sum+ob[2].to_seconds();//� ����� ��������� ����� � �������� 3�� ��������
	ob[0].add_seconds(sum);//�������� ����� ������ � 1�� �������, ����������� ������� ������������� � ����, ������, �������
	s = ob[0].to_str();
	cout << "����� 0: " << s << endl;


	delete[]ob;

}
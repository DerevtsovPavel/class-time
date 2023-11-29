#include <string>
#include <cassert>

#pragma once
//�����: �������� ����� ���-22

// ����� ��������� ����� � ������
class Time 
{
	private:		  //0<=����<=23 0<=������<=59   0<=�������<=59
		unsigned char hours, minutes, seconds;
	public:

		//����������� 
		Time(unsigned int h=0, unsigned int m=0, unsigned int s=0);

		//�������� ������ ����
		void set_hours(unsigned char h);

		//�������� ������ ������
		void set_minutes(unsigned char m);

		//�������� ������ �������
		void set_seconds(unsigned char s);

		//���������� ���-�� ������ �� �������
		unsigned short to_seconds();

		//���������� ���-�� ����� �� �������, ������� ���� �����������
		float to_minutes();

		//���������� ���-�� ����� �� �������, ������ � ������� ���� �����������
		float to_hours();

		//������ ����, ������, �������
		void set_time(unsigned char h, unsigned char m, unsigned char s);

		//��������� � �������� ������� k ������
		void add_seconds(unsigned int k);

		//��������� � �������� ������� k �����
		void add_minutes(unsigned int k);

		//��������� � �������� ������� k �����
		void add_hours(unsigned int k);

		//����������� ����� � ������ ������
		std::string to_str();

		//���������� ������� ���-�� �����
		unsigned short get_hours() const;

		//���������� ������� ���-�� �����
		unsigned short get_minutes() const;

		//���������� ������� ���-�� ������
		unsigned short get_seconds() const;

};

void Test();

/// ���������� ������ �������� � ��� ������ n � �������� ���� � ������ name
void Ob_in_file(Time* a,const int n, const std::string& name);

///���������� �� ��������� ����� ������ �������� � ��� ������ 
Time* Ob_out_file(int& n, const std::string& name);

///������ ������� �������� � ��������� ����
void Ob_in_txt(Time* a,int n, const std::string& name);

///���������� �� ���������� ����� ������ �������� � ��� ������
Time* Ob_out_txt(int& n, const std::string& name);

///������� ���-�� �������� � ��������� �����
int kol_ob_in_txt(const std::string& name);

///������ ������ ���������� �� �������
Time** Creat_arr(const int n);

///������� ������ ���������� �� ������� � �������
void del_arr(Time** a, int n);
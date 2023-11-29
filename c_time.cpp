//Автор: Деревцов Павел ВМК-22
#include "c_time.h"
#include <stdexcept>
#include <fstream>


//конструктор 
Time::Time(unsigned int h, unsigned int m, unsigned int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

//изменить только часы
void Time::set_hours(unsigned char h)
{
	if (h < 0 or h>23 or h % 10 > 10) throw std::invalid_argument("Не правильное кол-во часов");
	else hours = h;
}

//изменить только минуты
void Time::set_minutes(unsigned char m)
{
	if (m < 0 or m>59 or m % 10 > 10) throw std::invalid_argument("Не правильное кол-во минут");
	else minutes = m;
}

//изменить только секунды
void Time::set_seconds(unsigned char s)
{
	if (s < 0 or s>59 or s % 10 > 10) throw std::invalid_argument("Не правильное кол-во секунд");
	else seconds = s;
}

//возвращает кол-во секунд во времени
unsigned short Time::to_seconds()
{
	return hours * 3600 + minutes * 60 + seconds;
}

//возврощает кол-во минут во времени, секунды тоже учитываются
float Time::to_minutes()
{
	return hours * 60 + minutes + seconds / 60.0;
}

//возврощает кол-во часов во времени, минуты и секунды тоже учитываются
float Time::to_hours()
{
	return hours + minutes / 60.0 + seconds / 3600.0;
}

//задать часы, минуты, секунды
void Time::set_time(unsigned char h, unsigned char m, unsigned char s)
{
	set_hours(h);
	set_minutes(m);
	set_seconds(s);
}

//добавляет к текущему времени k секунд
void Time::add_seconds(unsigned int k)
{
	if (k < 0 or k % 10>10) throw std::invalid_argument("Неправильное кол-во добавляемых секунд");

	seconds = seconds + (k % 3600) % 60;
	if (seconds >= 60) {
		minutes = minutes + seconds / 60;
		seconds = seconds - 60 * (seconds / 60);
	}

	minutes = minutes + (k % 3600) / 60;
	if (minutes >= 60) {
		hours = hours + minutes / 60;
		minutes = minutes - 60 * (minutes / 60);
	}

	hours = hours + (k / 3600);
	if (hours >= 24) hours = hours - 24;

	if ((hours > 23 or hours < 0) or (minutes > 59 or minutes < 0) or (seconds > 59 or seconds < 0)) throw std::out_of_range("Ошибка add_seconds");
}

//добавляет к текущему времени k минут
void Time::add_minutes(unsigned int k)
{
	if (k < 0 or k % 10>10) throw std::invalid_argument("Неправильное кол-во добавляемых минут");

	minutes = minutes + k % 60;
	if (minutes >= 60)
	{
		hours = hours + minutes / 60;
		minutes = minutes - 60 * (minutes / 60);
	}

	hours = hours + (k / 60);
	if (hours >= 24) hours = hours - 24;

	if ((hours > 23 or hours < 0) or (minutes > 59 or minutes < 0) or (seconds > 59 or seconds < 0)) throw  std::out_of_range("Ошибка add_minutes");
}

//добавляет к текущему времени k часов
void Time::add_hours(unsigned int k)
{
	if (k < 0 or k % 10>10) throw std::invalid_argument("Неправильное кол-во добавляемых часов");

	hours = hours + k;
	if (hours >= 24) hours = hours - 24;
	if ((hours > 23 or hours < 0) or (minutes > 59 or minutes < 0) or (seconds > 59 or seconds < 0)) throw  std::out_of_range("Ошибка add_hours");
}

//преобразует время в единую строку
std::string Time::to_str()
{
	return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}

//возвращает текущее кол-во часов
unsigned short Time::get_hours() const {
	return hours;
}

//возвращает текущее кол-во минут
unsigned short Time::get_minutes() const {
	return minutes;
}

//возвращает текущее кол-во секунд
unsigned short Time::get_seconds() const {
	return seconds;
}

void Test()
{
	Time* a2 = new Time();

	a2->add_seconds(1000);
	assert(a2->get_hours() == 0);
	assert(a2->get_minutes() == 16);
	assert(a2->get_seconds() == 40);

	a2->add_minutes(30);
	assert(a2->get_hours() == 0);
	assert(a2->get_minutes() == 46);

	a2->add_hours(10);
	assert(a2->get_hours() == 10);


	a2->set_time(11, 22, 3);
	assert(a2->get_hours() == 11);
	assert(a2->get_minutes() == 22);
	assert(a2->get_seconds() == 3);

	assert(a2->to_seconds() == 40'923);
	assert((a2->to_minutes() - 682.05) < 0.009);
	assert((a2->to_hours() - 11.36) < 0.009);

	a2->set_hours(3);
	assert(a2->get_hours() == 3);

	a2->set_minutes(2);
	assert(a2->get_minutes() == 2);

	a2->set_seconds(59);
	assert(a2->get_seconds() == 59);

	assert(a2->to_str() == "3:2:59");

	delete a2;
}

/// записываем массив объектов в бинарный файл с именем name
void Ob_in_file(Time* a,const int n, const std::string& name)
{
	if (a == nullptr) throw std::invalid_argument("Zero array");
	else if (name.length() == 0) throw std::length_error("No file name");
	

	else
	{
		std::ofstream f(name,std::ios::binary);

		if (f.is_open())
		{	
			f.write((char*)&n, sizeof(n));//char*-перевести в массив байт
			for (int i = 0; i < n; i++)
			{
				int x = a[i].get_hours();
				f.write((char*)&x, sizeof(x));
				 x = a[i].get_minutes();
				f.write((char*)&x, sizeof(x));
				 x = a[i].get_seconds();
				f.write((char*)&x, sizeof(x));

			}

			f.close();
		}
		else throw std::runtime_error("File not open");
	}
}

///возвращаем из бинарного файла размер массива объектов и массив объектов 
Time* Ob_out_file(int &n,const std::string& name)
{
	Time* a = nullptr;
	int x;
	if (name.length() == 0) throw std::length_error("No file name");
	else 
	{
		std::ifstream f(name, std::ios::binary);
		f.read((char*)&n, sizeof(n));//читаем размер массива
		a = new Time[n];

		if (f.is_open()) 
		{
			for (int i = 0; i < n; i++)
			{
				f.read((char*)&x, sizeof(x));
				a[i].set_hours(x);
				f.read((char*)&x, sizeof(x));
				a[i].set_minutes(x);
				f.read((char*)&x, sizeof(x));
				a[i].set_seconds(x);
			}
			f.close();
		}
		else throw std::runtime_error("File not open");
	}
	return a;
}

///запись массива объектов в текстовый файл
void Ob_in_txt(Time* a, int n, const std::string& name)
{
	if (a == nullptr) throw std::invalid_argument("Zero array");
	else if (name.length() == 0) throw std::length_error("No file name");

	else 
	{
		std::ofstream f(name);
		if (f.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				f << "Время " << i + 1 << ":\n";
				f <<a[i].get_hours() << "\n";
				f <<a[i].get_minutes() << "\n";
				f <<a[i].get_seconds() << "\n";
			}
			
			f.close();
		}
	}
}

/// считаем кол-во объектов в текстовом файле
int kol_ob_in_txt(const std::string& name)
{
	int i = 0;
	std::ifstream f(name);
	std::string s;
	while (!f.eof())
	{
		f >> s;
		i++;
	}
	f.close();
	return i / 5;
}

///возвращаем массив объектов и его размер из текстового файла
Time* Ob_out_txt(int& n, const std::string& name)
{	
	Time* a = nullptr;
	std::string s;
	if (name.length() == 0) throw std::runtime_error("File not open");

	else 
	{
		std::ifstream f(name);
		if (f.is_open())
		{	
			 n = kol_ob_in_txt(name);
			a = new Time[n];
			for (int i = 0; i < n; i++)
			{	
				int d;
				f >> s;
				f >> s;
				f >> d;
				a[i].set_hours(d);
				f >> d;
				a[i].set_minutes(d);
				f >> d;
				a[i].set_seconds(d);
			}
			f.close();
		}
	}
	return a;
}

///создаём массив указателей на объекты
Time** Creat_arr(const int n)
{
	Time** a = new Time * [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new Time();
	}

	return a;
}

///удалить массив указателей на объекты и объекты
void del_arr(Time** a, int n)
{	
	if (a == nullptr) return;
	for (int i = 0; i < n; i++)
		if (a[i]!= nullptr)
		delete a[i];//удаляем объекты
	delete[]a;//удаляем массив указателей
}
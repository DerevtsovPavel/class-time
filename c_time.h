#include <string>
#include <cassert>

#pragma once
//Автор: Деревцов Павел ВМК-22

// класс реализует время в сутках
class Time 
{
	private:		  //0<=часы<=23 0<=минуты<=59   0<=секунды<=59
		unsigned char hours, minutes, seconds;
	public:

		//конструктор 
		Time(unsigned int h=0, unsigned int m=0, unsigned int s=0);

		//изменить только часы
		void set_hours(unsigned char h);

		//изменить только минуты
		void set_minutes(unsigned char m);

		//изменить только секунды
		void set_seconds(unsigned char s);

		//возвращает кол-во секунд во времени
		unsigned short to_seconds();

		//возврощает кол-во минут во времени, секунды тоже учитываются
		float to_minutes();

		//возврощает кол-во часов во времени, минуты и секунды тоже учитываются
		float to_hours();

		//задать часы, минуты, секунды
		void set_time(unsigned char h, unsigned char m, unsigned char s);

		//добавляет к текущему времени k секунд
		void add_seconds(unsigned int k);

		//добавляет к текущему времени k минут
		void add_minutes(unsigned int k);

		//добавляет к текущему времени k часов
		void add_hours(unsigned int k);

		//преобразует время в единую строку
		std::string to_str();

		//возвращает текущее кол-во часов
		unsigned short get_hours() const;

		//возвращает текущее кол-во минут
		unsigned short get_minutes() const;

		//возвращает текущее кол-во секунд
		unsigned short get_seconds() const;

};

void Test();
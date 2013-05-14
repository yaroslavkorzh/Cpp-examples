/* программа считает угол между часовой и минутной стрелкой, запускается через консоль командой вида:
*путь к исполняемому файлу* /YandexTestTask.exe "10:25 AM" rad mech
где "10:25 АМ", rad, mech - три входных параметра отвечающих за время(находится из строки 1 параметра)
вид вывода результата и тип используемых часов

по умолчанию углы отсчитываются для каждой из стрелок от полуночи по часовой стрелке и при надобности сокращаются до значения <360 градусов
далее находится разница между углами и выполняется ряд проверок на значение разницы
после чего результат выводиться в выбранном формате вывода

в случае некорректных данных программа выводит соответсвующую ошибку и завершается
*/

#define _CRT_SECURE_NO_WARNINGS
//подключение библиотек
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class my_angle
{
public:
	double h_angle, m_angle, dif_angle;

public:
	my_angle(void)// конструктор, обнулить значения углов
	{
		h_angle=0;
		m_angle=0;
		dif_angle=0;
	}
	~my_angle(void)// деструктор
	{
		cout<<"Очистка памяти my_angle"<<endl;
	}
	
	
	double check_360(double c_angle)// проверить значение углов на превышение 360 градусов и сократить при превышении
	{
		while (c_angle>=360)
		{
		c_angle=c_angle-360;
		}
		return c_angle;// возвращает значение угла меньше 360 градусов
	}
	double dif_angles(double x_angle, double y_angle)// найти разницу между двумя входящими углами 
	{
		dif_angle=x_angle-y_angle;// разница углов
		dif_angle=abs(dif_angle);// модуль исправляет значение угла в случае отрицательной разницы
		return dif_angle;// возвращает значение разницы между углами
	}
	double check_dif(double dif_angle)// проверить разницу на превышение 180 градусов 
	{
		while (dif_angle>180)// в случае разницы >180 есть другой угол между стрелками, меньше 180 градусов
		{
		dif_angle=dif_angle-360;
		dif_angle=abs(dif_angle);
		}
		return dif_angle;// возвращает проверенное значение разницы между углами
	}
	double output(char *output_selection, double dif_angle)// выбор выходного вида результата
	{
		/* Задание возможных вариантов вывода результата*/
		char *output_deg="deg";
		char *output_rad="rad";
		char *output_dms="dms";
		
		/*Сравнение входной строки вида результата с возможными вариантами
		  В случае совпадения - выводит угол в соответствующем виде*/
		if (strcmp(output_selection, output_deg) == 0)
		{
			cout<<"\nМинимальный угол между стрелками "<<dif_angle<<" градусов"<<endl;
		}
		else if (strcmp(output_selection, output_rad) == 0)
		{
			double pi=3.1415926535897932384626433832795;
			dif_angle=(dif_angle*pi)/180;
			cout<<"\nМинимальный угол между стрелками "<<dif_angle<<" радиан"<<endl;
		}
		else if (strcmp(output_selection, output_dms) == 0)
		{
			double base_min=60;
			dif_angle=dif_angle*base_min;
			cout<<"\nМинимальный угол между стрелками "<<dif_angle<<" минут"<<endl;
		}
		else
		{
			cout<<"\nОшибка ввода! Неправильно введен 2 аргумент.\nСпособ вывода результата не соответствует ни одному из возможных."<<endl;
			cin.get();
			exit(2);
		}
		return dif_angle;
	}

};
class my_clock
{
	public:
	int c_hour, c_min;	// переменные для часов и минут
	time_t rawtime;     // тип данных для хранения количества секунд
	struct tm *timeinfo;// структура даты и времени
	
	public:
	my_clock(void)// конструктор, обнулить значения часов и минут
	{
		c_hour=0;
		c_min=0;
	}
	~my_clock(void)// деструктор
	{
		cout<<"Очистка памяти my_clock"<<endl;
	}

	void update_clock()	// обновить значение часов и минут, также может использоваться для рассчета углов системного времени
{
	rawtime = time(NULL); 
	timeinfo = localtime(&rawtime);
	c_hour = timeinfo->tm_hour;
	c_min = timeinfo->tm_min;
}
	double get_time(string s)// находит значения часов и минут из строки вида "09:15 РМ" 
	{
		int len=s.length();
		int num[20]={0};
		int spot=0;
    
		for (int i = 0; i <= len; i++)
		{
			num[i]=s[i]-'0';
			if (num[i]==10)// находит вхождение : в строку и запоминает его позицию
			{
				spot=i;
			}

		}
		if (spot!=0)// если существует вхождение : в строку
			{
				c_hour=num[(spot-2)]*10+num[(spot-1)];// две цифры слева от двоеточия дают значение часов
				c_min=num[(spot+1)]*10+num[(spot+2)];// две цифры справа от двоеточия дают значение минут
				cout<<"\nЧасы "<<c_hour<<endl;
				cout<<"Минуты "<<c_min<<endl;
			}
		else// если нет вхождения : в строку - выдать ошибку
			{
				cout<<"\nОшибка! Неправильно введен 1 аргумент.\nПроверьте входную строку."<<endl;
				cin.get();
				exit(4);
			}
		return 0;
	}
	double get_quar_h_angle(int c_hour)// посчитать угол который прошла часовая стрелка начиная с полуночи для кварцевых часов
	{
	double h_angle;
	double base_h_angle;
	base_h_angle=30;// значение деления для часовой стрелки
	h_angle=c_hour*base_h_angle;
	return h_angle;// возвращает значение угла часовой стрелки
	}
	double get_mech_h_angle(int c_hour)// посчитать угол который прошла часовая стрелка начиная с полуночи для механических часов
{
	double h_angle;
	double base_h_angle, base_hm_angle;
	base_h_angle=30;
	base_hm_angle=0.5;
	h_angle=c_hour*base_h_angle+c_min*base_hm_angle;
	return h_angle;
}
	double get_m_angle(int c_min)// посчитать угол который прошла минутная стрелка начиная с полуночи для любого типа часов
{
	double  m_angle;
	double base_m_angle;
	base_m_angle=6;// значение деления для минутной стрелки
	m_angle=c_min*base_m_angle;
	return m_angle;// возвращает значение угла минутной стрелки
}
};


int main(int argc, char* argv[])//"09:00 РМ" deg mech
{
	
	setlocale(LC_ALL, "Russian");// включить поддержку русского языка в меню
	system("cls");// очистить экран от предыдущих команд

	/* инициализация искользуемых переменных */
	my_clock cl;
	my_angle ang;
	char *ch_time, *ch_output, *ch_cl_type;//
	ch_time=argv[1];
	ch_output=argv[2];
	ch_cl_type=argv[3];
	/* Проверка наличия аргументов */
	if (ch_time==NULL||ch_output==NULL||ch_cl_type==NULL)
	{
		cout<<"\nОшибка ввода аргументов "<<endl;
		cin.get();
		exit(2);
	}
	/* вывод аргументов передаваемых функции на ее входе*/
	cout<<"Проверка переданных аргументов"<<endl;
	cout<<"1 аргумент "<<ch_time<<endl;
	cout<<"2 аргумент "<<ch_output<<endl;
	cout<<"3 аргумент "<<ch_cl_type<<endl;
	/* найти значения часов и минут из входной строки 1 аргумента*/
	cl.get_time(ch_time);
	/* рассчет углов в зависимости от типа часов*/
	char *output_quar="quar";
	char *output_mech="mech";
	if (strcmp(ch_cl_type, output_quar) == 0)
		{
		ang.h_angle=cl.get_quar_h_angle(cl.c_hour);
		ang.m_angle=cl.get_m_angle(cl.c_min);
		cout<<"\nТип часов "<<ch_cl_type<<endl;
		}
	else if (strcmp(ch_cl_type, output_mech) == 0)
		{
		ang.h_angle=cl.get_mech_h_angle(cl.c_hour);
		ang.m_angle=cl.get_m_angle(cl.c_min);
		cout<<"\nТип часов "<<ch_cl_type<<endl;
		}
	else
		{
			cout<<"\nОшибка! Неправильно введен 3 аргумент.\nВид часов не соответствует ни одному из возможных."<<endl;
			cin.get();
			exit(3);
		}
	/* вывод результата рассчета углов */
	cout<<"\nУгол часовой: "<<ang.h_angle<<endl;
	cout<<"Угол минутной: "<<ang.m_angle<<endl;
		
	/* проверка значений углов на превышение 360 градусов */
	ang.h_angle=ang.check_360(ang.h_angle);
	ang.m_angle=ang.check_360(ang.m_angle);
	cout<<"\nУгол часовой после проверки значений: "<<ang.h_angle<<endl;
	cout<<"Угол минутной после проверки значений: "<<ang.m_angle<<endl;
		
	/* рассчет угла между стрелками */
	ang.dif_angle=ang.dif_angles(ang.h_angle, ang.m_angle);// разница между углами часовой и минутной стрелки
	ang.dif_angle=ang.check_dif(ang.dif_angle);// проверка на наличие меньшего угла между стрелками
	cout<<"\nУгол между стрелками: "<<ang.dif_angle<<endl;
	
	/* вывод результата в зависимости от выбранной размерности*/
	cout<<"\nОтвет: ";
	ang.output(ch_output,ang.dif_angle);
	cin.get();	

	return 0;
}

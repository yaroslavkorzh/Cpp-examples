/* ��������� ������� ���� ����� ������� � �������� ��������, ����������� ����� ������� �������� ����:
*���� � ������������ �����* /YandexTestTask.exe "10:25 AM" rad mech
��� "10:25 ��", rad, mech - ��� ������� ��������� ���������� �� �����(��������� �� ������ 1 ���������)
��� ������ ���������� � ��� ������������ �����

�� ��������� ���� ������������� ��� ������ �� ������� �� �������� �� ������� ������� � ��� ���������� ����������� �� �������� <360 ��������
����� ��������� ������� ����� ������ � ����������� ��� �������� �� �������� �������
����� ���� ��������� ���������� � ��������� ������� ������

� ������ ������������ ������ ��������� ������� �������������� ������ � �����������
*/

#define _CRT_SECURE_NO_WARNINGS
//����������� ���������
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
	my_angle(void)// �����������, �������� �������� �����
	{
		h_angle=0;
		m_angle=0;
		dif_angle=0;
	}
	~my_angle(void)// ����������
	{
		cout<<"������� ������ my_angle"<<endl;
	}
	
	
	double check_360(double c_angle)// ��������� �������� ����� �� ���������� 360 �������� � ��������� ��� ����������
	{
		while (c_angle>=360)
		{
		c_angle=c_angle-360;
		}
		return c_angle;// ���������� �������� ���� ������ 360 ��������
	}
	double dif_angles(double x_angle, double y_angle)// ����� ������� ����� ����� ��������� ������ 
	{
		dif_angle=x_angle-y_angle;// ������� �����
		dif_angle=abs(dif_angle);// ������ ���������� �������� ���� � ������ ������������� �������
		return dif_angle;// ���������� �������� ������� ����� ������
	}
	double check_dif(double dif_angle)// ��������� ������� �� ���������� 180 �������� 
	{
		while (dif_angle>180)// � ������ ������� >180 ���� ������ ���� ����� ���������, ������ 180 ��������
		{
		dif_angle=dif_angle-360;
		dif_angle=abs(dif_angle);
		}
		return dif_angle;// ���������� ����������� �������� ������� ����� ������
	}
	double output(char *output_selection, double dif_angle)// ����� ��������� ���� ����������
	{
		/* ������� ��������� ��������� ������ ����������*/
		char *output_deg="deg";
		char *output_rad="rad";
		char *output_dms="dms";
		
		/*��������� ������� ������ ���� ���������� � ���������� ����������
		  � ������ ���������� - ������� ���� � ��������������� ����*/
		if (strcmp(output_selection, output_deg) == 0)
		{
			cout<<"\n����������� ���� ����� ��������� "<<dif_angle<<" ��������"<<endl;
		}
		else if (strcmp(output_selection, output_rad) == 0)
		{
			double pi=3.1415926535897932384626433832795;
			dif_angle=(dif_angle*pi)/180;
			cout<<"\n����������� ���� ����� ��������� "<<dif_angle<<" ������"<<endl;
		}
		else if (strcmp(output_selection, output_dms) == 0)
		{
			double base_min=60;
			dif_angle=dif_angle*base_min;
			cout<<"\n����������� ���� ����� ��������� "<<dif_angle<<" �����"<<endl;
		}
		else
		{
			cout<<"\n������ �����! ����������� ������ 2 ��������.\n������ ������ ���������� �� ������������� �� ������ �� ���������."<<endl;
			cin.get();
			exit(2);
		}
		return dif_angle;
	}

};
class my_clock
{
	public:
	int c_hour, c_min;	// ���������� ��� ����� � �����
	time_t rawtime;     // ��� ������ ��� �������� ���������� ������
	struct tm *timeinfo;// ��������� ���� � �������
	
	public:
	my_clock(void)// �����������, �������� �������� ����� � �����
	{
		c_hour=0;
		c_min=0;
	}
	~my_clock(void)// ����������
	{
		cout<<"������� ������ my_clock"<<endl;
	}

	void update_clock()	// �������� �������� ����� � �����, ����� ����� �������������� ��� �������� ����� ���������� �������
{
	rawtime = time(NULL); 
	timeinfo = localtime(&rawtime);
	c_hour = timeinfo->tm_hour;
	c_min = timeinfo->tm_min;
}
	double get_time(string s)// ������� �������� ����� � ����� �� ������ ���� "09:15 ��" 
	{
		int len=s.length();
		int num[20]={0};
		int spot=0;
    
		for (int i = 0; i <= len; i++)
		{
			num[i]=s[i]-'0';
			if (num[i]==10)// ������� ��������� : � ������ � ���������� ��� �������
			{
				spot=i;
			}

		}
		if (spot!=0)// ���� ���������� ��������� : � ������
			{
				c_hour=num[(spot-2)]*10+num[(spot-1)];// ��� ����� ����� �� ��������� ���� �������� �����
				c_min=num[(spot+1)]*10+num[(spot+2)];// ��� ����� ������ �� ��������� ���� �������� �����
				cout<<"\n���� "<<c_hour<<endl;
				cout<<"������ "<<c_min<<endl;
			}
		else// ���� ��� ��������� : � ������ - ������ ������
			{
				cout<<"\n������! ����������� ������ 1 ��������.\n��������� ������� ������."<<endl;
				cin.get();
				exit(4);
			}
		return 0;
	}
	double get_quar_h_angle(int c_hour)// ��������� ���� ������� ������ ������� ������� ������� � �������� ��� ��������� �����
	{
	double h_angle;
	double base_h_angle;
	base_h_angle=30;// �������� ������� ��� ������� �������
	h_angle=c_hour*base_h_angle;
	return h_angle;// ���������� �������� ���� ������� �������
	}
	double get_mech_h_angle(int c_hour)// ��������� ���� ������� ������ ������� ������� ������� � �������� ��� ������������ �����
{
	double h_angle;
	double base_h_angle, base_hm_angle;
	base_h_angle=30;
	base_hm_angle=0.5;
	h_angle=c_hour*base_h_angle+c_min*base_hm_angle;
	return h_angle;
}
	double get_m_angle(int c_min)// ��������� ���� ������� ������ �������� ������� ������� � �������� ��� ������ ���� �����
{
	double  m_angle;
	double base_m_angle;
	base_m_angle=6;// �������� ������� ��� �������� �������
	m_angle=c_min*base_m_angle;
	return m_angle;// ���������� �������� ���� �������� �������
}
};


int main(int argc, char* argv[])//"09:00 ��" deg mech
{
	
	setlocale(LC_ALL, "Russian");// �������� ��������� �������� ����� � ����
	system("cls");// �������� ����� �� ���������� ������

	/* ������������� ������������ ���������� */
	my_clock cl;
	my_angle ang;
	char *ch_time, *ch_output, *ch_cl_type;//
	ch_time=argv[1];
	ch_output=argv[2];
	ch_cl_type=argv[3];
	/* �������� ������� ���������� */
	if (ch_time==NULL||ch_output==NULL||ch_cl_type==NULL)
	{
		cout<<"\n������ ����� ���������� "<<endl;
		cin.get();
		exit(2);
	}
	/* ����� ���������� ������������ ������� �� �� �����*/
	cout<<"�������� ���������� ����������"<<endl;
	cout<<"1 �������� "<<ch_time<<endl;
	cout<<"2 �������� "<<ch_output<<endl;
	cout<<"3 �������� "<<ch_cl_type<<endl;
	/* ����� �������� ����� � ����� �� ������� ������ 1 ���������*/
	cl.get_time(ch_time);
	/* ������� ����� � ����������� �� ���� �����*/
	char *output_quar="quar";
	char *output_mech="mech";
	if (strcmp(ch_cl_type, output_quar) == 0)
		{
		ang.h_angle=cl.get_quar_h_angle(cl.c_hour);
		ang.m_angle=cl.get_m_angle(cl.c_min);
		cout<<"\n��� ����� "<<ch_cl_type<<endl;
		}
	else if (strcmp(ch_cl_type, output_mech) == 0)
		{
		ang.h_angle=cl.get_mech_h_angle(cl.c_hour);
		ang.m_angle=cl.get_m_angle(cl.c_min);
		cout<<"\n��� ����� "<<ch_cl_type<<endl;
		}
	else
		{
			cout<<"\n������! ����������� ������ 3 ��������.\n��� ����� �� ������������� �� ������ �� ���������."<<endl;
			cin.get();
			exit(3);
		}
	/* ����� ���������� �������� ����� */
	cout<<"\n���� �������: "<<ang.h_angle<<endl;
	cout<<"���� ��������: "<<ang.m_angle<<endl;
		
	/* �������� �������� ����� �� ���������� 360 �������� */
	ang.h_angle=ang.check_360(ang.h_angle);
	ang.m_angle=ang.check_360(ang.m_angle);
	cout<<"\n���� ������� ����� �������� ��������: "<<ang.h_angle<<endl;
	cout<<"���� �������� ����� �������� ��������: "<<ang.m_angle<<endl;
		
	/* ������� ���� ����� ��������� */
	ang.dif_angle=ang.dif_angles(ang.h_angle, ang.m_angle);// ������� ����� ������ ������� � �������� �������
	ang.dif_angle=ang.check_dif(ang.dif_angle);// �������� �� ������� �������� ���� ����� ���������
	cout<<"\n���� ����� ���������: "<<ang.dif_angle<<endl;
	
	/* ����� ���������� � ����������� �� ��������� �����������*/
	cout<<"\n�����: ";
	ang.output(ch_output,ang.dif_angle);
	cin.get();	

	return 0;
}

#include<iostream>
#include<math.h>
#include<time.h>
#include<stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <sstream> 
using namespace std;
//объ€вление переменных



int main(int argc, char *argv[])
{
    string s = "asahd12:30djfjgf";
	int len=s.length();
    long int sum = 0;
	int num[20]={0};
    int spot;
    
    for (int i = 0; i < s.length(); i++)
    {
		
	num[i]=s[i]-'0';
	cout<<num[i]<<endl;
	if (num[i]==10)
	{
		cout<<": is at "<<i<<endl;
		cout<<"string "<<s[i]<<endl;
		spot=i;
	}

	}
	cin.get();
    system("cls");
	int hours=0;
	int mins=0;
	hours=num[(spot-2)]*10+num[(spot-1)];
	mins=num[(spot+1)]*10+num[(spot+2)];
	cout<<"hours "<<hours<<endl;
	cout<<"minutes "<<mins<<endl;
	
  
    
    system("PAUSE > NULL");
    return EXIT_SUCCESS;
}


/*int main()
{
    stringstream str;
    
    str << "12:20";

    double x;
    str >> x;
	cout<<"Number: " << x <<endl;
	cin.get();
	return 0;
}*/
/*int main()
{// all works good
    char c;
    int i;
    do
    {
        std::cin >> c;
        if((c>='0')&&(c<='9'))//≈сли число
            i=c-'0';
        else
            i=-1;
        std::cout << "Number: " << i << std::endl;
    }
    while(i>=0);
    system("pause");
    return 0;
}*?


/*int main(){
	
char c[]={'1',':','3', '/0'};

for(int i = 0; i < 5; i++)
{
	i++;
int a=c[i]-'0';
printf("%d",a);
cin.get();
}
return 0;
}*/
/*int main(int argc, char *argv[]) // argv - число 
{ 
istringstream isst; 
int chislo=0; 
int chislo2=0; 
char *line_read=argv[1];
char line_read2=line_read[3, 4];
if ( argc<2 ) 
{ 
cout<<"Usage: "<<argv[0]<<" number"<<endl; 
return 1; 
} 
isst.str( line_read ); // »щет число 
isst >> chislo; // сохран€ет 
cout << "The number is " << chislo << endl; 
isst.str( line_read ); // »щет число 
isst >> chislo2; // сохран€ет 
cout << "The number is " << line_read2 << endl; 
return 0; 
}*/